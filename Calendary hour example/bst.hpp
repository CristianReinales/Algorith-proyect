#ifndef _bst_hpp_
#define _bst_hpp_

#include <cstddef>
#include <iostream>
#include <string>
using namespace std;

template<typename keytype>
class bst{//creamos la clase
  private:
    struct bstNode{
      keytype date;//este keytype seria la hora de nuestro calendario
      string msg;//este seria para nuestro mensaje de recordatorio
      bstNode *left;//nodo derecho
      bstNode *right;//nodo izquierdo
      bstNode *parent;//padre del nodo
    };

    size_t count; //size_t -> es lo mismo que unsigned pero mejorcito
    bstNode *tree; //points to the tree's root


    bstNode* min(bstNode* root) const;    //encuentra el minimo
    bstNode* max(bstNode* root) const;    //encuentra el maximo
    bstNode* successor(bstNode* root) const;    //el siguiente
    bstNode* predecessor(bstNode* root) const;    //el anterior

    void remove (bstNode* &root, keytype date);  //remueve lo que vota la alarma
    bstNode* copy(bstNode *root)const;//copia un nodo
    void clear(bstNode* &root);//limpia un nodo
    void display(bstNode* root, ostream& out)const; //muestra el resultado de nuestro arbol

    void insert(bstNode* &root, const keytype& date, const string& msg); //inserta un nodo a nuestro arbol
    // bstNode* findparent(bstNode* root, keytype key) const;///********************BORRAME
    // bstNode* parn(keytype key)const;//********************
    string find(bstNode* root, keytype date)const; //encuentra nuestra hora para votar el mensaje y que sepa que le toca hacer la actividad que anoto

  public:
    bst(); //constructor
    bst(const bst &rhs);  //**constructor copia
    void remove(keytype date);//funcion que llama a la funcion privada
    bool empty(void) const; //funcion que llama a la funcion privada
    void clear(void);//funcion que llama a la funcion privada
    void find(keytype date) const;//funcion que llama a la funcion privada

    void insert(const keytype& date,const string& msg); //funcion que llama a la funcion privada
    void display(ostream& out = cout)const;//funcion que llama a la funcion privada
};

#include "bst.cpp"

#endif
