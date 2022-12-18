#include "TQueue.h"

#include <gtest.h>

TEST(TQueue, can_create_queue_with_positive_length)
{
  ASSERT_NO_THROW(TQueue<int> q(5));
}

TEST(TQueue, cant_create_queue_with_negative_length)
{
  ASSERT_ANY_THROW(TQueue<int> q(-5));
}

TEST(TQueue, can_copy_queue)
{
  TQueue<int> s1(10);
  ASSERT_NO_THROW(TQueue<int> q2(s1));
}

TEST(TQueue, copied_queue_is_equal_to_source_one)
{
  TQueue<int> q1(10);
  q1.Push(2);
  q1.Push(5);
  q1.Push(11);
  TQueue<int> q2(q1);
  EXPECT_EQ(true, q1 == q2);
}

TEST(TQueue, copied_queue_is_different_object)
{
  TQueue<int> q1(10);
  for (int i = 0; i < 3; i++)
	q1.Push(i);
  TQueue<int> q2(q1);
  q2.Pop();
  q2.Push(123);
  EXPECT_EQ(true, q1 != q2);
}

TEST(TQueue, can_push_and_get_top_element)
{
  TQueue<int> q(5);
  q.Push(5);
  q.Push(6);
  EXPECT_EQ(5, q.Top());
}

TEST(TQueue, can_pop_element)
{
  TQueue<int> q(5);
  q.Push(5);
  q.Push(6);
  q.Pop();
  EXPECT_EQ(6, q.Top());
}

TEST(TQueue, can_get_and_pop_element)
{
  TQueue<int> q(5);
  q.Push(5);
  q.Push(6);
  EXPECT_EQ(5, q.TopPop());
  EXPECT_EQ(6, q.TopPop());
}

TEST(TQueue, can_check_emptyness)
{
  TQueue<int> q(5);
  EXPECT_EQ(true, q.IsEmpty());
  q.Push(11);
  EXPECT_EQ(false, q.IsEmpty());
  q.Pop();
  EXPECT_EQ(true, q.IsEmpty());
}

TEST(TQueue, can_check_fullness)
{
  TQueue<int> q(5);
  EXPECT_EQ(false, q.IsFull());
  q.Push(0);
  EXPECT_EQ(false, q.IsFull());
  for (int i = 0; i < 4; i++)
	q.Push(i);
  EXPECT_EQ(true, q.IsFull());
}

TEST(TQueue, cant_push_into_full)
{
  TQueue<int> q(5);
  for (int i = 0; i < 5; i++)
	q.Push(i * 2);
  ASSERT_ANY_THROW(q.Push(0));
}

TEST(TQueue, cant_pop_from_empty)
{
  TQueue<int> q(5);
  q.Push(0);
  q.Pop();
  ASSERT_ANY_THROW(q.Pop());
}

TEST(TQueue, can_assign_queue_to_itself)
{
  TQueue<int> q(5);
  ASSERT_NO_THROW(q = q);
}

TEST(TQueue, assign_queue_of_equal_size_works_correctly)
{
  TQueue<int> q1(5), q2(5);
  q1.Push(15);
  q1.Push(16);
  q2 = q1;
  q2.Pop();
  q2.Pop();
  q2.Push(16);
  q2.Push(15);
  EXPECT_NE(15, q2.TopPop());
  EXPECT_NE(16, q2.Top());
}

TEST(TQueue, assign_queue_of_different_size_works_correctly)
{
  TQueue<int> q1(2), q2(1);
  q1.Push(100);
  q1.Push(200);
  q2.Push(0);
  q2 = q1;
  EXPECT_EQ(100, q2.TopPop());
  EXPECT_EQ(200, q2.TopPop());
}

TEST(TQueue, compare_queues_returns_correct)
{
  TQueue<int> q1(5), q2(5);
  q1.Push(5);
  q1.Push(6);
  q1.Push(7);
  q2.Push(5);
  q2.Push(6);
  q2.Push(7);
  EXPECT_EQ(true, q1 == q2);
}

TEST(TQueue, compare_queue_with_itself_returns_true)
{
  TQueue<int> q(5);
  q.Push(0);
  EXPECT_EQ(true, q == q);
}

TEST(TQueue, compare_different_size_queues_returns_correct)
{
  TQueue<int> q1(5), q2(5);
  q1.Push(5);
  q1.Push(6);
  q2.Push(5);
  EXPECT_EQ(true, q1 != q2);
}

TEST(TQueue, compare_same_data_queues_returns_correct)
{
  TQueue<int> q1(5), q2(10);
  q1.Push(5);
  q1.Push(6);
  q2.Push(5);
  q2.Push(6);
  EXPECT_EQ(true, q1 == q2);
}

TEST(TQueue, test_queue_circular_buffer)
{
  TQueue<int> q(4);
  q.Push(12);
  q.Push(13);
  q.Push(14);
  q.Push(15);
  EXPECT_EQ(true, q.IsFull());
  q.Pop();
  EXPECT_EQ(false, q.IsFull());
  ASSERT_NO_THROW(q.Push(16));
  q.Pop();
  ASSERT_NO_THROW(q.Push(17));
  EXPECT_EQ(14, q.TopPop());
  EXPECT_EQ(15, q.TopPop());
  EXPECT_EQ(16, q.TopPop());
  EXPECT_EQ(17, q.TopPop());
  EXPECT_EQ(true, q.IsEmpty());
}