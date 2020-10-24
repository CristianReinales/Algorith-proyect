#include <iostream>
#include <ctime>///********************************
#include <ratio>//Estas tres librerias nos ayudan a mirar y trabajar con la hora del computador en tiempo actual.
#include <chrono>//*********************************
using namespace std;


int main(){
  AVL<float> t;//****************************************
  t.insert(1.3);
  t.insert(2.4);
  t.insert(3.5);
  t.insert(4.6);
  t.insert(5.7);
  t.insert(6.8);//Poniendo a prueba el prototipo de avl que tenemos en el codigo
  t.insert(7.9);
  t.inorder();
  t.remove(5.7);
  t.remove(6.8);
  t.remove(7.9);
  t.inorder();//*************************************



//********************************************************************
//Codigo de obtencion de hora en tiempo real.
  using chrono::system_clock;
  chrono::duration<int,std::ratio<60*60*24> > one_day (1);
  system_clock::time_point today = system_clock::now();
  system_clock::time_point tomorrow = today + one_day;

  time_t tt;

  tt = system_clock::to_time_t ( today );
  cout << "today is: " << ctime(&tt);

  tt = system_clock::to_time_t ( tomorrow );
  cout << "tomorrow will be: " << ctime(&tt);
//*********************************************************************




  return 0;




}
