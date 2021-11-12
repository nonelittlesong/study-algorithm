// https://blog.csdn.net/pointer_y/article/details/52350045

#define _CRT_SECURE_NO_WARNINGS 1

#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include<iostream>
#include<string>

using namespace std;

template <typename T>
class Seqlist
{
  template <typename T>
  friend ostream &operator<<<T>(ostream &os, const Seqlist<T> &list); // 输出运算符重载
public:
  Seqlist();
  ~Seqlist();
  Seqlist(const Seqlist &list);
  Seqlist<T>& operator=(const Seqlist<T> &list);
  T& operator[](const int index);
  void push(T x); // 尾插
  T& pop(); // 尾删
  void unshift(T x); // 头插
  T& shift(); // 头删
private:
  void reverse(int sz);
  T* _data;
  int _sz;
  int _capacity;
}

template <typename T>
void Seqlist<T>::reverse(int sz) {
  if (_capacity <= sz) {

  }
}