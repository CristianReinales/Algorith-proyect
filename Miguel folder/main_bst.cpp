#include "bst.hpp"
<<<<<<< HEAD
=======

>>>>>>> 39a08cd82c0efc4598f1bd85a729cd4552f55265
using namespace std;

int main(){
  cout<<boolalpha;
<<<<<<< HEAD

  bst<int> tree;
  tree.insert(12,"hola");
  tree.insert(69,"nico");
  tree.insert(-12,"miguel");
  tree.insert(1,"christian");
  tree.insert(7,"nose");
  tree.insert(6,"sera");
  tree.insert(-20,"proyecto");




  cout<<tree.find(7)<<endl;
=======
  bst<int> tree;//Arbol de prueba para poner a prueba el programa
  tree.insert(1545,"Sacar a pasear al perro");//**************************************************
  tree.insert(1230,"Llamar a papá");
  tree.insert(2300,"Seguir jugando lolsito");
  tree.insert(1300,"Estudiar para el parcial de calculo");//Tareas pendientes
  tree.insert(1430,"Aprender a cocinar pescado");
  tree.insert(2150,"Jugar lolsito");
  tree.insert(0030,"Pasta colesterol");//**********************************************************


  //Apartado de preubas find
  cout<<"Mensaje de las 14:30 pm: ";
  tree.find(1430);
  cout<<endl;

  cout<<"Mensaje de las 23:00 pm: ";
  tree.find(2300);
  cout<<endl;

  cout<<"Mensaje de las 15:45 pm: ";
  tree.find(1545);
  cout<<endl;

  //Prueba de la impresion de todas las tareas pendientes
  cout<<endl<<endl;
>>>>>>> 39a08cd82c0efc4598f1bd85a729cd4552f55265
  tree.display();

  return 0;
}
