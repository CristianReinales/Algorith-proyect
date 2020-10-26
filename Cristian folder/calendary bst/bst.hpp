#ifndef _bst_hpp_
#define _bst_hpp_

#include <cstddef>
#include <iostream>
#include <string>
using namespace std;

template<typename keytype>
class bst{
  private:
    struct bstNode{
      keytype date;
      string msg;
      bstNode *left;
      bstNode *right;
      bstNode *parent;
    };

    size_t count; //size_t -> es lo mismo que unsigned pero mejorcito
    bstNode *tree; //points to the tree's root

    bstNode* min(bstNode* root) const;    //:)
    bstNode* max(bstNode* root) const;    //:)
    bstNode* successor(bstNode* root) const;    //:)
    bstNode* predecessor(bstNode* root) const;    //:)

    void remove (bstNode* &root, keytype date);  //**HAY QUE IMPLEMENTAR EL PARENT
    bstNode* copy(bstNode *root)const;
    void clear(bstNode* &root);
    void display(bstNode* root, ostream& out)const; //:)

    void insert(bstNode* &root, const keytype& date, const string& msg); //:)
    // bstNode* findparent(bstNode* root, keytype key) const;///********************BORRAME
    // bstNode* parn(keytype key)const;//********************
    string find(bstNode* root, keytype date)const; //:)

  public:
    bst(); //**
    bst(const bst &rhs);  //**


    void remove(keytype date);
    bool empty(void) const; //**
    void clear(void);
    void find(keytype date) const;

    void insert(const keytype& date,const string& msg); //**
    void display(ostream& out = cout)const;
};

#include "bst.cpp"

#endif
