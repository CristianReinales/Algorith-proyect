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

template<typename keytype>//PRIVADO:en el promer if revisa si el arbol esta vacio, si esta vacio crea un nodo nuevo
void bst<keytype>::insert(bstNode* &root, const keytype& date, const string& msg){
    if(root == nullptr){
        root = new bstNode;
        root->date = date;
        root->msg = msg;
        root->left = root->right = nullptr;
        // root->parent = findparent(tree, key);
        count++;
    }
    else{
        if( root->date != date){
          if( root->date < date) //pone el nodo de la derecha
            insert(root->right, date, msg);
          else                  //pone el nodo de la izquierda
            insert(root->left, date, msg);
        }
    }
}

template<typename keytype>// PUBLICO
void bst<keytype>::insert(const keytype& date,const string& msg){
    insert(tree, date, msg);
}


template <typename keytype>  //PRIVADO
string bst<keytype>::find(bstNode* root, keytype date)const{   //ese typename está diciendo que trate a bst<keytype>::bstNode* como un tipo
    if(root==nullptr) return nullptr;
    if(root->date == date) return root->msg;
    if(root->date < date){
        return find(root->right, date);

    }else{
        return find(root->left, date);
    }
}

template <typename keytype>//PUBLICO
void bst<keytype>::find(keytype date)const{
    cout<<find(tree,date)<<endl;
}

template <typename keytype>//PRIVADO
void bst<keytype>::display(bstNode* root, ostream& out)const{ // hacer la prueba a dibujo para entender como funciona.

    if (root != nullptr){
        display(root->left, out);
        out<<root->date<<" ==> "<< root->msg<<endl;
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
typename bst<keytype>::bstNode* bst<keytype>::predecessor(bstNode* root) const{//encontrar predecesor
  if(root == nullptr) return nullptr;
  if(root->left != nullptr) return max(root->left);
  else{
    bstNode* temp_tree = nullptr;
    bstNode* temp_tree_2 = tree;
    while(temp_tree_2 != nullptr){
      if(temp_tree_2->date < root->date){
        temp_tree = temp_tree_2;
        temp_tree_2 = temp_tree_2->right;
      }else if(temp_tree_2 > root->date){
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
  if(root == nullptr) return nullptr;//mira si esta vacio si si retorna nullptr
  if(root->right != nullptr) return min(root->right);//Revisa el nodo derecho, si tiene algo me va a retornar el minimo del nodo de la derecha y en el caso de que no ->
  else{
    bstNode* temp_tree = nullptr;//creamos un puntero a nullptr  || nodo que se retornara
    bstNode* temp_tree_2 = tree;//creamos un puntero a la raiz del arbol || nodo movil
    while(temp_tree_2 != nullptr){//mientras el nodo no sea nullptr
      if(temp_tree_2->date < root->date){//el nodo movil tiene una fecha menos a la del nodo que estamos buscando su sucesor
        temp_tree_2 = temp_tree_2->right;//me iguala el nodo que se retornara con el nodo movil pero ahora desde la hoja derecha
      }else if(temp_tree_2 > root->date){//el nodo movil tiene una fecha mayor a la del nodo que estamos buscando su sucesor
        temp_tree = temp_tree_2;//el nodo que se retornada toma el valor del nodo movil
        temp_tree_2 = temp_tree_2->left;//el nodo movil es igual al nodo movil por la izquierda
      }else{
        break;
      }
    }
    return temp_tree;//retorna el nodo sucesor
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
