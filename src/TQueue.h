#ifndef __TQueue_H__
#define __TQueue_H__

#include <iostream>

template <typename T>
class TQueue
{
protected:
  T* pMem;
  int high;
  int size;
  int bottom;
  int dataCount;
public:
  TQueue();
  TQueue(int _size);
  TQueue(const TQueue& q);
  TQueue(TQueue&& q);
  TQueue& operator=(const TQueue& q);
  ~TQueue();

  bool IsEmpty() const;
  bool IsFull() const;

  void Push(const T& elem);
  T Top() const;
  void Pop();
  T TopPop();

  bool operator==(const TQueue& q) const;
  bool operator!=(const TQueue& q) const;

  void Free();
};

template<typename T>
TQueue<T>::TQueue()
{
  bottom = NULL;
  high = NULL;
  size = NULL;
  dataCount = NULL;
  pMem = nullptr;
}

template<typename T>
TQueue<T>::TQueue(int _size)
{
  if (_size <= 0) { throw "TQueue init error"; }
  Free();
  size = _size;
  pMem = new T[size];
}

template<typename T>
TQueue<T>::TQueue(const TQueue<T>& q)
{
  if (q.pMem == nullptr)
  {
	size = 0;
	pMem = nullptr;
	Free();
  }
  else
  {
	size = q.size;
	bottom = q.bottom;
	high = q.high;
	dataCount = q.dataCount;
	pMem = new T[size];
	if (!(q.IsEmpty()))
	{
	  int j = bottom;
	  for (int i = 0; i < dataCount; i++)
	  {
		pMem[j] = q.pMem[j];
		j--;
		if (j < 0) { j = size - 1; }
	  }
	}
  }
}

template<typename T>
TQueue<T>::TQueue(TQueue<T>&& q)
{
  if (pMem != nullptr) { delete[] pMem; }
  pMem = nullptr;
  size = 0;
  Free();
  std::swap(pMem, q.pMem);
  std::swap(size, q.size);
  std::swap(bottom, q.bottom);
  std::swap(high, q.high);
  std::swap(dataCount, q.dataCount);
}

template<typename T>
TQueue<T>& TQueue<T>::operator=(const TQueue<T>& q)
{
  if (this != &q)
  {
	if (pMem != nullptr) { delete[] pMem; }
	size = q.size;
	pMem = new T[size];
	bottom = q.bottom;
	high = q.high;
	dataCount = q.dataCount;
	if (!(q.IsEmpty()))
	{
	  int j = bottom;
	  for (int i = 0; i < dataCount; i++)
	  {
		pMem[j] = q.pMem[j];
		j--;
		if (j < 0) { j = size - 1; }
	  }
	}
  }
  return *this;
}

template<typename T>
TQueue<T>::~TQueue()
{
  delete[] pMem;
  size = 0;
  Free();
}

template<typename T>
bool TQueue<T>::IsEmpty(void) const
{
  return (dataCount == 0);
}

template<typename T>
bool TQueue<T>::IsFull(void) const
{
  return (dataCount == size);
}

template<typename T>
void TQueue<T>::Push(const T& elem)
{
  if (IsFull()) { throw "TQueue Push error"; }
  pMem[high] = elem;
  high++;
  high = (high < size) ? high : 0;
  dataCount++;
}

template<typename T>
T TQueue<T>::Top() const
{
  if (IsEmpty()) { throw "Queue is empty"; }
  return pMem[bottom];
}

template<typename T>
void TQueue<T>::Pop()
{
  if (IsEmpty()) { throw "Queue is empty"; }
  bottom++;
  bottom = (bottom < size) ? bottom : 0;
  dataCount--;
}

template<typename T>
T TQueue<T>::TopPop()
{
  T Result = Top();
  Pop();
  return Result;
}

template<typename T>
bool TQueue<T>::operator==(const TQueue& q) const
{
  if (dataCount != q.dataCount ) { return false; }
  int j = bottom;
  int k = q.bottom;
  for (int i = 0; i < dataCount; i++)
  {
	if (pMem[j] != q.pMem[k]) { return false; }
	j--;
	j = (j < 0) ? (size - 1) : j;
	k--;
	k = (k < 0) ? (q.size - 1) : k;
  }
  return true;
}

template<typename T>
bool TQueue<T>::operator!=(const TQueue& q) const
{
  return (!(this->operator==(q)));
}

template<typename T>
void TQueue<T>::Free()
{
  high = 0;
  bottom = 0;
  dataCount = 0;
}
#endif