#include "bst.hpp"

using namespace std;

int main(){
  cout<<boolalpha;
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
  tree.display();

  return 0;
}
