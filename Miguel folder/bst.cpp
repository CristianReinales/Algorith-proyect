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

template<typename keytype>//PRIVADO
void bst<keytype>::insert(bstNode* &root, const keytype& date, const string& msg){
    if(root == nullptr){// revisa si esta vacio el arbol
        root = new bstNode; // Crea un nuevo nodo
        root->date = date;// Le asigna la fecha como la llave
        root->msg = msg;// Le asigna el mensaje
        root->left = root->right = nullptr; // deja apuntando a nada las propiedades de left y right a nada
        // root->parent = findparent(tree, key);
        count++;// el conteo del arbol se aumenta en 1
    }
    else{
        if( root->date != date){// revisa la llave(fecha) ya fue insertada
          if( root->date < date) //pone el nodo de la derecha
            insert(root->right, date, msg);
          else                  //pone el nodo de la izquierda
            insert(root->left, date, msg);
        }
    }
}

template<typename keytype>// PUBLICO
void bst<keytype>::insert(const keytype& date,const string& msg){
    insert(tree, date, msg);// llama a la funcion definida en privado
}


template <typename keytype>  //PRIVADO
string bst<keytype>::find(bstNode* root, keytype date)const{   //ese typename está diciendo que trate a bst<keytype>::bstNode* como un tipo
    if(root==nullptr) return nullptr;// retorna null ptr si el arbol esta vacio
    if(root->date == date) return root->msg;// si encuenta la llave retorna su mensaje
    if(root->date < date){// Si la llave es mayor
        return find(root->right, date);// Llama a la funcion recursivamente con el puntero hacia el subarbol de la derecha

    }else{
        return find(root->left, date);// Si no llama a la funcion recursivamente pra el subarbol de la izquierda
    }
}

template <typename keytype>//PUBLICO
void bst<keytype>::find(keytype date)const{
    cout<<find(tree,date)<<endl;//Llama a la funcion del privado tomando como root el arbol
}

template <typename keytype>//PRIVADO
void bst<keytype>::display(bstNode* root, ostream& out)const{ // hacer la prueba a dibujo para entender como funciona.

    if (root != nullptr){//Si el arbol no esta vacio
        display(root->left, out);//Llama a la funcion recursivamente para el subarbol de la izquierda
        out<<root->date<<" ==> "<< root->msg<<endl;// Imprime la fecha con el mensaje asignado del nodo actual
        display(root->right, out  );//Lama a la funciuon recursivamente para el subarbol de la derecha
    }
}

template <typename keytype>//PUBLICO
void bst<keytype>::display(ostream& out)const{
    display(tree, out);//Lama a la funcion del privado con el arbol general
}


template <typename keytype>//MINIMO VALOR EN EL ARBOL
typename bst<keytype>::bstNode* bst<keytype>::min(bstNode* root) const{
  while(root->left != nullptr){// Mientras el puntero del left apunte a algo 4
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
  if(root == nullptr) return nullptr;
  if(root->right != nullptr) return min(root->right);
  else{
    bstNode* temp_tree = nullptr;
    bstNode* temp_tree_2 = tree;
    while(temp_tree_2 != nullptr){
      if(temp_tree_2->date < root->date){
        temp_tree_2 = temp_tree_2->right;
      }else if(temp_tree_2 > root->date){
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
