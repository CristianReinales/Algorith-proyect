#include "hash.hpp"
using namespace std;

void opciones(HashMap<string> temp_hasht_user);//Se ejecuta la lista de opciones para el usuario y ademas desde esta se re dirigen a cada opcion en especifico.
void CreateAlarm(HashMap<string> temp_hasht_user);
void LookCal(HashMap<string> temp_hasht_user);
void DeleteAlarm(HashMap<string> temp_hasht_user);
void SeacrchAlarm(HashMap<string> temp_hasht_user);

int main(){
   // using chrono::system_clock;
   HashMap<string> temp_hasht_user;
   cout<<endl<<endl<<"Bienvenido a PersonalCalendary."<<endl<<"Recuerda que el formato para el ingreso de tus alarmas es el siguiente:"<<endl<<endl<<"Para definir el mes:"<<endl<<endl<<"    Enero = JAN    |  Febrero = FEB  |  Marzo = MAR    |  Abril = APR    |  Mayo = MAY  |  Junio = JUN    |  Julio = Jul   "<<endl<<"            Agosto = AUG   |  Septiembre = SEP  |  Octubre = OCT   |  Noviembre = NOV    |   Diciembre = DEC"<<endl<<endl<<"Para definir el dia:"<<endl<<endl<<"    Lunes = MON  |  Martes = TUE  |  Miercoles = WED   |  Jueves = THU   |  Viernes = FRI  |  Sabado = SAT | Domingo = SUN"<<endl<<endl<<"Y la hora esta definida en un formato de 24 horas y primero se ingresa la hora del dia y despues agregas los minutos."<<endl<<endl;

   opciones(temp_hasht_user);






  return 0;
};

void opciones(HashMap<string> temp_hasht_user){
   cout<<"\a";
      cout<<"Ingrese la opcion que desea de la lista a continuacion. "<<endl<<"                    ________________________________________________"<<endl<<"                    |                                              |"<<endl<<"                    |       Crear nueva alarma 'CreateAlarm'       |"<<endl<<"                    |                                              |"<<endl<<"                    |  Borrar una alarma existente 'DeleteAlarm'   |"<<endl<<"                    |                                              |"<<endl<<"                    |    Imprimir alarmas programadas 'LookCal'    |"<<endl<<"                    |                                              |"<<endl<<"                    |          Buscar Alarma 'SearchAlarm'         |"<<endl<<"                    |                                              |"<<endl<<"                    |       Para terminar el proceso 'Finish'      |"<<endl<<"                    |                                              |"<<endl<<"                    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl<<"Por favor ingrese que opcion desea ejecutar: ";
   string temp_user_string;
   cin>>temp_user_string;

   if(temp_user_string == "CreateAlarm"){
      CreateAlarm(temp_hasht_user);//fino
      temp_user_string = "";
   }else if(temp_user_string == "DeleteAlarm"){
      DeleteAlarm(temp_hasht_user);//Teiene erro en el hpp del hpp
   }else if(temp_user_string == "LookCal"){
      LookCal(temp_hasht_user);//Imprime todas las alarmas que el usuario tiene pendientes, MODIFICAR!!!!
   }else if(temp_user_string == "SearchAlarm"){
      SeacrchAlarm(temp_hasht_user);//
   }else if(temp_user_string == "Finish"){
   }else{
      cout<<endl<<"La opcion que ingreso es invalida."<<endl;
      temp_user_string = "";
      opciones(temp_hasht_user);
   }
}


void LookCal(HashMap<string> temp_hasht_user){
   cout<<"|==========================================================================|"<<endl;
   temp_hasht_user.display();
   cout<<endl;
   opciones(temp_hasht_user);
}

void CreateAlarm(HashMap<string> temp_hasht_user){
   cout<<endl<<"Ingrese cuantas alarmas desea ingresar: ";
   int temp_user_int;
   string temp_day;
   string temp_month;
   string temp_year;
   string temp_hour;
   string temp_minutes;
   string temp_message;
   string temp_am_pm = "fallo";
   cin>>temp_user_int;
   for(int i = 0; i < temp_user_int; i++){
      cout<<"|=======================================================================|"<<endl<<"Programacion alarma num ["<<i+1<<"]"<<endl;
      cout<<"Ingrese el año: ";
      cin>>temp_year;
      cout<<"Ingrese el mes: ";
      cin>>temp_month;
      cout<<"Ingrese el dia: ";
      cin>>temp_day;
      cout<<"Ingrese la hora: ";
      cin>>temp_hour;
      cout<<"Ingrese los minutos: ";
      cin>>temp_minutes;
      if(temp_hour == "1"){
         temp_am_pm = " am";
      }else if(temp_hour == "2"){
         temp_am_pm = " am";
      }else if(temp_hour == "3"){
         temp_am_pm = " am";
      }else if(temp_hour == "4"){
         temp_am_pm = " am";
      }else if(temp_hour == "5"){
         temp_am_pm = " am";
      }else if(temp_hour == "6"){
         temp_am_pm = " am";
      }else if(temp_hour == "7"){
         temp_am_pm = " am";
      }else if(temp_hour == "8"){
         temp_am_pm = " am";
      }else if(temp_hour == "9"){
         temp_am_pm = " am";
      }else if(temp_hour == "10"){
         temp_am_pm = " am";
      }else if(temp_hour == "11"){
         temp_am_pm = " am";
      }else if(temp_hour == "12"){
         temp_am_pm = " am";
      }else if(temp_hour == "13"){
         temp_am_pm = " pm";
      }else if(temp_hour == "14"){
         temp_am_pm = " pm";
      }else if(temp_hour == "15"){
         temp_am_pm = " pm";
      }else if(temp_hour == "16"){
         temp_am_pm = " pm";
      }else if(temp_hour == "17"){
         temp_am_pm = " pm";
      }else if(temp_hour == "18"){
         temp_am_pm = " pm";
      }else if(temp_hour == "19"){
         temp_am_pm = " pm";
      }else if(temp_hour == "20"){
         temp_am_pm = " pm";
      }else if(temp_hour == "21"){
         temp_am_pm = " pm";
      }else if(temp_hour == "22"){
         temp_am_pm = " pm";
      }else if(temp_hour == "23"){
         temp_am_pm = " pm";
      }else if(temp_hour == "24"){
         temp_am_pm = " pm";
      }else{
         cout<<"La fecha que ingreso es invalida. "<<endl;
         temp_am_pm = "fallo";
      }
      if(temp_am_pm == "fallo"){
         cout<<"No se pudo ingresar su alarma."<<endl;
      }else{
         string temp_key = temp_day + " ";
         temp_key += temp_month + " " + temp_year + " " + temp_hour + ":" + temp_minutes + temp_am_pm;
         cout<<"La fecha completa que ingreso fue: "<<temp_key<<endl;
         cout<<"Ingrese la etiqueta de la alarma: ";
         cin>>temp_message;//El unico problema que tengo aca en esta parte es el lecho de que el mensaje me toca ingresarlo con '_' en vez de ' '.
         temp_hasht_user.insert(temp_key, temp_message);
      }
      cout<<"|=======================================================================|"<<endl;
   }
   opciones(temp_hasht_user);
}

void SeacrchAlarm(HashMap<string> temp_hasht_user){
   cout<<"|=======================================================================|"<<endl;
   cout<<"Iingrese la fecha en la cual hay una alarma que desea buscar: "<<endl;
   string temp_day;
   string temp_month;
   string temp_year;
   string temp_hour;
   string temp_minutes;
   string temp_message;
   string temp_am_pm = "fallo";
   cout<<"Ingrese el año: ";
   cin>>temp_year;
   cout<<"Ingrese el mes: ";
   cin>>temp_month;
   cout<<"Ingrese el dia: ";
   cin>>temp_day;
   cout<<"Ingrese la hora: ";
   cin>>temp_hour;
   cout<<"Ingrese los minutos: ";
   cin>>temp_minutes;
   if(temp_hour == "1"){
      temp_am_pm = " am";
   }else if(temp_hour == "2"){
      temp_am_pm = " am";
   }else if(temp_hour == "3"){
      temp_am_pm = " am";
   }else if(temp_hour == "4"){
      temp_am_pm = " am";
   }else if(temp_hour == "5"){
      temp_am_pm = " am";
   }else if(temp_hour == "6"){
      temp_am_pm = " am";
   }else if(temp_hour == "7"){
      temp_am_pm = " am";
   }else if(temp_hour == "8"){
      temp_am_pm = " am";
   }else if(temp_hour == "9"){
      temp_am_pm = " am";
   }else if(temp_hour == "10"){
      temp_am_pm = " am";
   }else if(temp_hour == "11"){
      temp_am_pm = " am";
   }else if(temp_hour == "12"){
      temp_am_pm = " am";
   }else if(temp_hour == "13"){
      temp_am_pm = " pm";
   }else if(temp_hour == "14"){
      temp_am_pm = " pm";
   }else if(temp_hour == "15"){
      temp_am_pm = " pm";
   }else if(temp_hour == "16"){
      temp_am_pm = " pm";
   }else if(temp_hour == "17"){
      temp_am_pm = " pm";
   }else if(temp_hour == "18"){
      temp_am_pm = " pm";
   }else if(temp_hour == "19"){
      temp_am_pm = " pm";
   }else if(temp_hour == "20"){
      temp_am_pm = " pm";
   }else if(temp_hour == "21"){
      temp_am_pm = " pm";
   }else if(temp_hour == "22"){
      temp_am_pm = " pm";
   }else if(temp_hour == "23"){
      temp_am_pm = " pm";
   }else if(temp_hour == "24"){
      temp_am_pm = " pm";
   }else{
      cout<<"La fecha que ingreso es invalida."<<endl;
      temp_am_pm = "fallo";
   }
   if(temp_am_pm == "fallo"){
      cout<<"No se logro buscar la alarma"<<endl;
   }else{//lega hasta aca si los datos ingresados son correctos, pero hay un error en el remove
      string temp_key = temp_day + " ";
      temp_key += temp_month + " " + temp_year + " " + temp_hour + ":" + temp_minutes + temp_am_pm;
      temp_hasht_user.search(temp_key);
      cout<<"Listo."<<endl;
   }
   cout<<"|=======================================================================|"<<endl;
   opciones(temp_hasht_user);
}

void DeleteAlarm(HashMap<string> temp_hasht_user){
   cout<<"|=======================================================================|"<<endl;
   cout<<"Iingrese la fecha en la cual hay una alarma que desea borrar: "<<endl;
   string temp_day;
   string temp_month;
   string temp_year;
   string temp_hour;
   string temp_minutes;
   string temp_message;
   string temp_am_pm = "fallo";
   cout<<"Ingrese el año: ";
   cin>>temp_year;
   cout<<"Ingrese el mes: ";
   cin>>temp_month;
   cout<<"Ingrese el dia: ";
   cin>>temp_day;
   cout<<"Ingrese la hora: ";
   cin>>temp_hour;
   cout<<"Ingrese los minutos: ";
   cin>>temp_minutes;
   if(temp_hour == "1"){
      temp_am_pm = " am";
   }else if(temp_hour == "2"){
      temp_am_pm = " am";
   }else if(temp_hour == "3"){
      temp_am_pm = " am";
   }else if(temp_hour == "4"){
      temp_am_pm = " am";
   }else if(temp_hour == "5"){
      temp_am_pm = " am";
   }else if(temp_hour == "6"){
      temp_am_pm = " am";
   }else if(temp_hour == "7"){
      temp_am_pm = " am";
   }else if(temp_hour == "8"){
      temp_am_pm = " am";
   }else if(temp_hour == "9"){
      temp_am_pm = " am";
   }else if(temp_hour == "10"){
      temp_am_pm = " am";
   }else if(temp_hour == "11"){
      temp_am_pm = " am";
   }else if(temp_hour == "12"){
      temp_am_pm = " am";
   }else if(temp_hour == "13"){
      temp_am_pm = " pm";
   }else if(temp_hour == "14"){
      temp_am_pm = " pm";
   }else if(temp_hour == "15"){
      temp_am_pm = " pm";
   }else if(temp_hour == "16"){
      temp_am_pm = " pm";
   }else if(temp_hour == "17"){
      temp_am_pm = " pm";
   }else if(temp_hour == "18"){
      temp_am_pm = " pm";
   }else if(temp_hour == "19"){
      temp_am_pm = " pm";
   }else if(temp_hour == "20"){
      temp_am_pm = " pm";
   }else if(temp_hour == "21"){
      temp_am_pm = " pm";
   }else if(temp_hour == "22"){
      temp_am_pm = " pm";
   }else if(temp_hour == "23"){
      temp_am_pm = " pm";
   }else if(temp_hour == "24"){
      temp_am_pm = " pm";
   }else{
      cout<<"La fecha que ingreso es invalida."<<endl;
      temp_am_pm = "fallo";
   }
   if(temp_am_pm == "fallo"){
      cout<<"No se logro eliminar la alarma"<<endl;
   }else{//lega hasta aca si los datos ingresados son correctos, pero hay un error en el remove
      string temp_key = temp_day + " ";
      temp_key += temp_month + " " + temp_year + " " + temp_hour + ":" + temp_minutes + temp_am_pm;
      temp_hasht_user.remove(temp_key);
      cout<<"Listo."<<endl;
   }
   cout<<"|=======================================================================|"<<endl;
   opciones(temp_hasht_user);
}//tiene un error en el remove del hpp











// Para




// chrono::duration<int,std::ratio<60*60*24> > one_day (1);
// system_clock::time_point today = system_clock::now();
// time_t tt;
// tt = system_clock::to_time_t ( today );
// string temp_string = ctime(&tt);
//

// temp_hasht_user.insert(temp_string,"tomese la pasta padre");
// temp_hasht_user.insert(temp_string,"chao");
//
//
// temp_hasht_user.display();
