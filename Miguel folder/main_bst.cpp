#include "bst.hpp"
using namespace std;

int main(){

  cout<<boolalpha;

  bst<int> tree;
  tree.insert(12,"hola");
  tree.insert(69,"nico");
  tree.insert(-12,"miguel");
  tree.insert(1,"christian");
  tree.insert(7,"nose");
  tree.insert(6,"sera");
  tree.insert(-20,"proyecto");




  cout<<tree.find(7)<<endl;
  tree.display();

  cout<<"Success!"<<endl;
  return 0;
}
