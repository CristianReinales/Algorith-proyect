#ifdef _bst_hpp_
#define _bst_cpp_

#include <iostream>

/*constructors & destructor*/
template <typename keytype>
bst<keytype>::bst(){
    count = 0;
    tree = nullptr;
}

template <typename keytype>
bst<keytype>::bst(const bst &rhs){
    count = rhs.count;
    tree = rhs.tree;
}


/*Setters*/
template <typename keytype>//PRIVADO
void bst<keytype>::insert(bstNode* &root, const keytype& key){
    if(root == nullptr){
        root = new bstNode;
        root->key = key;
        root->left = root->right = nullptr;
        // root->parent = findparent(tree, key);
        count++;
    }
    else{
        if( root->key != key){
          if( root-> key < key) //pone el nodo de la derecha
              insert(root->right, key);
          else                  //pone el nodo de la izquierda
              insert(root->left, key);
        }
    }
}

template <typename keytype>// PUBLICO
void bst<keytype>::insert(const keytype &key){
    insert(tree, key);
}


template <typename keytype>  //PRIVADO
typename bst<keytype>::bstNode* bst<keytype>::find(bstNode* root, keytype key)const{   //ese typename está diciendo que trate a bst<keytype>::bstNode* como un tipo
    if(root==nullptr) return nullptr;
    if(root->key == key) return root;
    if(root->key < key){
        return find(root->right, key);

    }else{
        return find(root->left, key);
    }
}

template <typename keytype>//PUBLICO
bool bst<keytype>::find(keytype key)const{

    return nullptr != find(tree,key);
}

template <typename keytype>//PRIVADO
void bst<keytype>::display(bstNode* root, ostream& out)const{ // hacer la prueba a dibujo para entender como funciona.

    if (root != nullptr){
        display(root->left, out);
        out<<root->key<<endl;
        display(root->right, out  );
    }
}

template <typename keytype>//PUBLICO
void bst<keytype>::display(ostream& out)const{
    display(tree, out);
}


template <typename keytype>//MINIMO VALOR EN EL ARBOL
typename bst<keytype>::bstNode* bst<keytype>::min(bstNode* root) const{
  while(root->left != nullptr){
    root = root->left;
  }
  return root;
}

template <typename keytype>//MAXIMO VALOR EN EL ARBOL
typename bst<keytype>::bstNode* bst<keytype>::max(bstNode* root) const{
  while(root->right != nullptr){
    root = root->right;
  }
  return root;
}

template <typename keytype>//PREDECESSOR
typename bst<keytype>::bstNode* bst<keytype>::predecessor(bstNode* root) const{
  if(root == nullptr) return nullptr;
  if(root->left != nullptr) return max(root->left);
  else{
    bstNode* temp_tree = nullptr;
    bstNode* temp_tree_2 = tree;
    while(temp_tree_2 != nullptr){
      if(temp_tree_2->key < root->key){
        temp_tree = temp_tree_2;
        temp_tree_2 = temp_tree_2->right;
      }else if(temp_tree_2 > root->key){
        temp_tree_2 = temp_tree_2->left;
      }else{
        break;
      }
    }
    return temp_tree;
  }
}

template <typename keytype>
typename bst<keytype>::bstNode* bst<keytype>::successor(bstNode* root) const{
  if(root == nullptr) return nullptr;
  if(root->right != nullptr) return min(root->right);
  else{
    bstNode* temp_tree = nullptr;
    bstNode* temp_tree_2 = tree;
    while(temp_tree_2 != nullptr){
      if(temp_tree_2->key < root->key){
        temp_tree_2 = temp_tree_2->right;
      }else if(temp_tree_2 > root->key){
        temp_tree = temp_tree_2;
        temp_tree_2 = temp_tree_2->left;
      }else{
        break;
      }
    }
    return temp_tree;
  }
}


// template <typename keytype>
// typename bst<keytype>::bstNode* bst<keytype>::findparent(bstNode* root, keytype key) const{BORRAME
//   if(root==nullptr) return nullptr;
//   if(root->key == key) return nullptr;
//   if(root->key == root->left->key) return root;
//   if(root->key == root->right->key) return root;
//   if(root->key < key){
//       return find(root->right, key);
//   }else{
//       return find(root->left, key);
//   }
// }

// template <typename keytype>//PUBLICO
// typename bst<keytype>::bstNode* bst<keytype>::parn(keytype key)const{
//   return findparent(tree,key);
// }






/*Modifiers*/


#endif