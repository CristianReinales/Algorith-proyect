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
        root->left = root->right = nullptr; // deja apuntando a nada las propiedades de left y right a nullptr
        count++;// el conteo del arbol se aumenta en 1
    }
    else{
        if( root->date != date){// revisa si la llave(fecha) ya fue insertada
          if( root->date < date) //realiza una recursion de insert pero por la derecha
            insert(root->right, date, msg);
          else                  //realiza una recursion de insert pero por la izquierda
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
    if(root->date < date){// Si la llave es mayor a la llave recivida
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
  if(root == nullptr) return nullptr;//Revisa si es un nodo vacio y retorna nullptr
  if(root->left != nullptr) return max(root->left);//Si el left apunta a algo retorna el maximo del subarbol izquierdo
  else{// Si el izquierdo es vacio
    bstNode* temp_tree = nullptr;//Crea un nodo temporal vacio
    bstNode* temp_tree_2 = tree;// Crea otro nodo temporal que apunta al nodo raiz
    while(temp_tree_2 != nullptr){// Mientras el nodo temporal dos no este vacio
      if(temp_tree_2->date < root->date){//Si el key(Fecha) del nodo temporal 2 es menor al nodo al que se le busca el predecesor
        temp_tree = temp_tree_2;// Le asigna al arbol temporal 1 un posible predecesor al nodo al que se le esta buscando
        temp_tree_2 = temp_tree_2->right;// Asigna al arbol temporal 2 el nodo de la derecha
      }else if(temp_tree_2 > root->date){// Si el key(Fecha) del nodo temporal 2 es menor al nodo la que se busca el predecesor
        temp_tree_2 = temp_tree_2->left; // Asigna al arbol temporal 2 el nodo de la izquierda
      }else{
        break;
      }
    }
    return temp_tree;// Retorna nullptr si no tiene predecesor y si lo tiene retorna el predecesor(el nodo de la derecha)
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


#endif
