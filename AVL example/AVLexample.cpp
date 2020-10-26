#ifdef _AVL_HPP_
#define _AVL_CPP_
#include<iostream>
using namespace std;

//APARTADO PUBLICO

template <typename Timetype>
void AVL<Timetype>::insert(Timetype x){
  root=insertUtil(root, x);
}

template <typename Timetype>
void AVL<Timetype>::remove(Timetype x){
  root=removeUtil(root, x);
}
template <typename Timetype>
typename AVL<Timetype>::node* AVL<Timetype>::search(Timetype x){
  return searchUtil(root,x);
}
template <typename Timetype>
void AVL<Timetype>::inorder(){
  inorderUtil(root);
  cout<<endl;
}

//APARTADO PRIVADO

template <typename Timetype>
int AVL<Timetype>::height(node * head){
  if(head==NULL) return 0;
  return head->height;
}

template <typename Timetype>
typename AVL<Timetype>::node* AVL<Timetype>::rightRotation(node * head){
  node * newhead = head->left;
  head->left = newhead->right;
  newhead->right = head;
  head->height = 1+max(height(head->left), height(head->right));
  newhead->height = 1+max(height(newhead->left), height(newhead->right));
  return newhead;
}

template <typename Timetype>
typename AVL<Timetype>::node* AVL<Timetype>::leftRotation(node * head){
  node * newhead = head->right;
  head->right = newhead->left;
  newhead->left = head;
  head->height = 1+max(height(head->left), height(head->right));
  newhead->height = 1+max(height(newhead->left), height(newhead->right));
  return newhead;
}

template <typename Timetype>
void AVL<Timetype>::inorderUtil(node * head){
  if(head==NULL) return ;
  inorderUtil(head->left);
  cout<<head->key<<" ";
  inorderUtil(head->right);
}

template <typename Timetype>
typename AVL<Timetype>::node* AVL<Timetype>::insertUtil(node * head, Timetype x){
  if(head==NULL){
    n+=1;
    node * temp = new node(x);
    return temp;
  }
  if(x < head->key) head->left = insertUtil(head->left, x);
  else if(x > head->key) head->right = insertUtil(head->right, x);
  head->height = 1 + max(height(head->left), height(head->right));
  int bal = height(head->left) - height(head->right);
  if(bal>1){
    if(x < head->left->key){
      return rightRotation(head);
    }else{
      head->left = leftRotation(head->left);
      return rightRotation(head);
    }
  }else if(bal<-1){
    if(x > head->right->key){
      return leftRotation(head);
    }else{
      head->right = rightRotation(head->right);
      return leftRotation(head);
    }
  }
  return head;
}

template <typename Timetype>
typename AVL<Timetype>::node* AVL<Timetype>::removeUtil(node * head, Timetype x){
  if(head==NULL) return NULL;
  if(x < head->key){
    head->left = removeUtil(head->left, x);
  }else if(x > head->key){
    head->right = removeUtil(head->right, x);
  }else{
    node * r = head->right;
    if(head->right==NULL){
      node * l = head->left;
      delete(head);
      head = l;
    }else if(head->left==NULL){
      delete(head);
      head = r;
    }else{
      while(r->left!=NULL) r = r->left;
      head->key = r->key;
      head->right = removeUtil(head->right, r->key);
    }
  }
  if(head==NULL) return head;
  head->height = 1 + max(height(head->left), height(head->right));
  int bal = height(head->left) - height(head->right);
  if(bal>1){
    if(x > head->left->key){
      return rightRotation(head);
    }else{
      head->left = leftRotation(head->left);
      return rightRotation(head);
    }
  }else if(bal < -1){
    if(x < head->right->key){
      return leftRotation(head);
    }else{
      head->right = rightRotation(head->right);
      return leftRotation(head);
    }
  }
  return head;
}

template <typename Timetype>
typename AVL<Timetype>::node* AVL<Timetype>::searchUtil(node * head, Timetype x){
  if(head == NULL) return NULL;
  Timetype k = head->key;
  if(k == x) return head;
  if(k > x) return searchUtil(head->left, x);
  if(k < x) return searchUtil(head->right, x);
}

#endif
