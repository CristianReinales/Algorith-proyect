
template <typename T>
class AVL{
  public:
    class node{//Clase nodo, nesesaria en este tipo de arbol binario para efectuar la acomodacion.
      public:
        T key;//key del nodo
        int height;//Altura del arbol con el nuevo nodo.
        node * left;
        node * right;
        node(T k){//Constructor por defecto del nodo.
          height = 1;
          key = k;
          left = NULL;
          right = NULL;
        }
    };
    node * root = NULL;//Puntero a los nodos
    int n;//key value

    void insert(T x);
    void remove(T x);
    node * search(T x);
    void inorder();

  private:
    int height(node * head);
    node * rightRotation(node * head);
    node * leftRotation(node * head);
    void inorderUtil(node * head);
    node * insertUtil(node * head, T x);
    node * removeUtil(node * head, T x);
    node * searchUtil(node * head, T x);
};
