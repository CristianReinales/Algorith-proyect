#include "bst.hpp"

using namespace std;

int main(){

  cout<<boolalpha;

  bst<int> tree;
  tree.insert(12);
  tree.insert(69);
  tree.insert(-12);
  tree.insert(1);
  tree.insert(7);
  tree.insert(6);
  tree.insert(-20);




  cout<<tree.find(7)<<endl;
  tree.display();

  cout<<"Success!"<<endl;
  return 0;
}
