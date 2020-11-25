// system_clock example
#include <iostream>
#include <ctime>
#include<string>
#include <ratio>
#include <chrono>
using namespace std;

int main (){
  using chrono::system_clock;
  system_clock::time_point today = system_clock::now();

  time_t tt;

  tt = system_clock::to_time_t ( today );
  cout << "today is: " << ctime(&tt);

  string temp = ctime(&tt);
  cout<<temp<<endl;
  string month_str = temp.substr(4,3);
  cout<<month_str<<"->"<<month_str.size()<<endl;
  // string::size_type sz; //alias of size_t
  // int int_month = stoi(month_str, &sz);
  // cout<<int_month<<" +1 -> "<<int_month+1<<endl;


  return 0;
}


//1. verificar año valido osea, comparar con ctime y que el año que este ingresando el usuario sea mayor o igual "comparar con ctime"
//2. verificar que el mes ingresado sea valido, osea no sea un mes que ya paso en el año. "corarar con ctime"
//3. verificar que los dias si esten dentro del numero de dias de cada mes, que sea un numero valido <- "comparar con ctime"
//4. horas verificar una hora valida "comparar con ctime"
//5. minutos verificar que sean validos "comprobar con ctime"
//https://www.cplusplus.com/reference/string/stoi/?kw=stoi
