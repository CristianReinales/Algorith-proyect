#ifdef _HASH_HPP
#define _HASH_CPP
#include<fstream>
#include <iostream>

template<typename VT>
HashMap<VT>::HashMap(){
  tableSize = TABLE_SIZE;
  count = 0;
  // NotFound = VT(999999999999);
  table = new KeyValueNode<VT>*[tableSize];
  for(int i = 0; i<tableSize; i++){
    table[i] = nullptr;
  }
}

template <typename VT>
HashMap<VT>::~HashMap(){
  KeyValueNode<VT> *tmp;
  for(int i = 0; i < tableSize; ++i){
    tmp = table[i];
    while(tmp != nullptr){
      table[i] = table[i]->link;
      delete tmp;
      tmp = table[i];
    }
  }
  delete[] table;
}


template<typename VT>
void HashMap<VT>::insert(string key, VT val){
   if(count == tableSize) rehash();
  int cell = hash(key) % tableSize;
  KeyValueNode<VT> *temp_1 = findCell(cell, key);
  if(temp_1 == nullptr){
    temp_1 = new KeyValueNode<VT>;
    temp_1->key = key;
    temp_1->link = table[cell];
    table[cell] = temp_1;
    count++;
  }
  temp_1->value = temp_1->value += " , " + val;
}

template<typename VT>
void HashMap<VT>::display()const{
  for(int i =0; i< tableSize; i++){
    KeyValueNode<VT>*cp = table[i];
    cout<<"["<<i<<"] => ";
    while(cp != nullptr){
      cout<<"("<<cp->key<<","<<cp->value<<") --> ";
      cp = cp->link;
    }
    cout<<"//"<<endl;
  }
}

template<typename VT>
void HashMap<VT>::size(){
  cout<<"The size of the hash table is: "<<count<<endl;
}


template<typename VT>
bool HashMap<VT>::empty(){
  return count==0;
}

template<typename VT>
void HashMap<VT>::remove(string key){
  int cell = hash(key) % tableSize;
  KeyValueNode<VT> *cp = table[cell];
  KeyValueNode<VT> *cp2 = findCell(cell,key);
  if(cp2 == nullptr){
    cout<<"Error."<<endl;
  }else if(cp->key == key){
    cp->key = cp->link->key;
    cp->value = cp->link->value;
    cp->link = cp->link->link;
  }else{
    int temp_num = 1;
    while(temp_num != -1){
      if(key == cp->link->key){
        cp->link = cp->link->link;
        temp_num = -1;
      }else{
        cp = cp->link;
      }
    }
  }
}


template<typename VT>
void HashMap<VT>::search(string key){
  int cell = hash(key) % tableSize;
  KeyValueNode<VT> *cp = findCell(cell,key);
  cout<<"Para la fecha: "<<key<<" Esta el siguiente recordatorio: "<<cp->value<<endl;
  Beep(1568, 200);//mover esto a una funcion diferente. con la opciond e tener mas sonidos y que el usuario puea elegir
  Beep(1568, 200);
  Beep(1568, 200);
  Beep(1245, 1000);
  Beep(1397, 200);
  Beep(1397, 200);
  Beep(1397, 200);
  Beep(1175, 1000);
  Beep(1568, 200);
  Beep(1568, 200);
  Beep(1568, 200);
  Beep(1245, 1000);
  Beep(1397, 200);
  Beep(1397, 200);
  Beep(1397, 200);
  Beep(1175, 1000);
}

template <typename VT>
void HashMap<VT>::rehash() {
  int temp_old_table_size = tableSize;
  KeyValueNode<VT> **temp_old_table = table;
  tableSize *= 2;
  table = new KeyValueNode<VT>*[tableSize];
  for(int i = 0; i < tableSize; ++i) table[i] = nullptr;
  count = 0;
  KeyValueNode<VT> *cursor;
  for(int i = 0; i < temp_old_table_size; ++i){
    cursor = temp_old_table[i];
    while(temp_old_table[i] != nullptr){
      insert(cursor->key, cursor->value);
      cursor = cursor->link;
      delete temp_old_table[i];
      temp_old_table[i] = cursor;
    }
  }
  delete[] temp_old_table;
}















#endif
