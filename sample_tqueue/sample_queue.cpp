#include <iostream>
#include "TQueue.h"

int main()
{
  TQueue<int> q(3);
  q.Push(12);
  std::cout << q.TopPop() << std::endl;
  q.Push(12);
  q.Push(13);
  q.Push(14);
  q.Pop();
  q.Push(15);
  std::cout << q.Top() << std::endl;
  q.Pop();
  q.Push(16);
  std::cout << q.Top() << std::endl;
  return 0;
}