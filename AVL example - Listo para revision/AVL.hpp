#ifndef _AVL_HPP_
#define _AVL_HPP_
#include <cstddef>
#include <iostream>
#include <ctime>///********************************
#include <ratio>//Estas tres librerias nos ayudan a mirar y trabajar con la hora del computador en tiempo actual.
#include <chrono>//*********************************
using namespace std;

template <typename Timetype>
class AVL{
  public:
    class node{//Clase nodo, nesesaria en este tipo de arbol binario para efectuar la acomodacion.
      public:
        Timetype key;//key del nodo
        int height;//Altura del arbol con el nuevo nodo.
        node * left;
        node * right;
        node(Timetype k){//Constructor por defecto del nodo.
          height = 1;
          key = k;
          left = NULL;
          right = NULL;
        }
    };
    node * root = NULL;//Puntero a los nodos
    int n;//key value

    void insert(Timetype x);
    void remove(Timetype x);
    node * search(Timetype x);
    void inorder();

  private:
    int height(node * head);
    node * rightRotation(node * head);
    node * leftRotation(node * head);
    void inorderUtil(node * head);
    node * insertUtil(node * head, Timetype x);
    node * removeUtil(node * head, Timetype x);
    node * searchUtil(node * head, Timetype x);
};

#include "AVLexample.cpp"
#endif
