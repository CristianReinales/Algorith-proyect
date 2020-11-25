#ifndef _HASH_HPP
#define _HASH_HPP
#include<string>
#include<ratio>
#include<chrono>
#include<ctime>
#include<conio.h>
#include<windows.h>
#include<iostream>
#include<fstream>
using namespace std;

const int TABLE_SIZE = 20;

template <typename VT>
struct KeyValueNode{
  string key;
  VT value;
  KeyValueNode<VT> *link;
};

template <typename VT>
class HashMap{
private:

  KeyValueNode<VT> **table;

  int tableSize;
  int count;
  // VT NotFound;

  KeyValueNode<VT> *findCell(int cell,string key) {
    KeyValueNode<VT> *cp = table[cell];
    while (cp != nullptr && key != cp->key){
      cp = cp->link;
    }
    return cp;
  }

  int temp_num_1 = 5381;
  int temp_num_2 = 33;
  int temp_num_3 = unsigned(-1) >> 1;
  unsigned int hash(string key){
    unsigned int hashVal = temp_num_1;
    int n = key.length();
    for(int i = 0; i < n ; i++){
      hashVal = temp_num_2 * hashVal + key[i];
    }
    return  int(hashVal & temp_num_3);
  }

  void rehash();

public:
  HashMap();//nice
  ~HashMap();

  void size();//nice
  bool empty();//nice
  void clear();
  void display()const;//nice

  VT get(string key);

  void search(string key);//nice
  void insert(string key, VT value);//nice
  void remove(string key);//nice

  void distribution(const string &filename);

};

#include "hash.cpp"
#endif
