#ifndef _bst_hpp_
#define _bst_hpp_

#include <cstddef>
#include <iostream>
using namespace std;

template<typename keytype>
class bst{

  private:

      struct bstNode{
          string m;
          keytype key;
          bstNode *left;
          bstNode *right;
          // bstNode *parent;
      };

      size_t count; //size_t -> es lo mismo que unsigned pero mejorcito
      bstNode *tree; //points to the tree's root

      bstNode* min(bstNode* root) const;    //:)
      bstNode* max(bstNode* root) const;    //:)
      bstNode* successor(bstNode* root) const;    //:)
      bstNode* predecessor(bstNode* root) const;    //:)

      void remove (bstNode* &root, keytype key);  //**HAY QUE IMPLEMENTAR EL PARENT
      bstNode* copy(bstNode *root)const;
      void clear(bstNode* &root);
      void display(bstNode* root, ostream& out)const; //:)

      void insert(bstNode* &root,const keytype& key,string &m); //:)
      // bstNode* findparent(bstNode* root, keytype key) const;///********************BORRAME
      // bstNode* parn(keytype key)const;//********************
      bstNode* find(bstNode* root, keytype key)const; //:)

  public:

        bst(); //**
        bst(const bst &rhs);  //**
        // ~bst();

        void remove(keytype key);
        bool empty(void) const; //**
        void clear(void);
        string find(keytype key) const;

        void insert(const keytype& key,string &m); //**
        void display(ostream& out = cout)const;
};

#include "bst.cpp"

#endif
