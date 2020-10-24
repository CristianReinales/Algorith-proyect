// system_clock example
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
using namespace std;

int main (){
  using chrono::system_clock;
  chrono::duration<int,std::ratio<60*60*24> > one_day (1);
  system_clock::time_point today = system_clock::now();
  system_clock::time_point tomorrow = today + one_day;

  time_t tt;

  tt = system_clock::to_time_t ( today );
  cout << "today is: " << ctime(&tt);

  tt = system_clock::to_time_t ( tomorrow );
  cout << "tomorrow will be: " << ctime(&tt);

  return 0;
}
