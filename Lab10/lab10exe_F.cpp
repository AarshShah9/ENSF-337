// lab10exe_F.cpp
// ENSF 337 - LAB 10 Exercise F
//
// Author: S. A. Norman

#include "OLList2.h"
#include <iostream>
using namespace std;

int main()
{
  {
    OLList x;
    x.insert(450);
    x.insert(350);
    x.insert(250);
    x.insert(150);
    cout << "Items of x just before x is destroyed:\n";
    x.print();
  }

  OLList source;
  OLList a(source);

  source.insert(1000);
  OLList b(source);

  source.insert(2000);
  source.insert(3000);
  OLList c(source);

  cout << "Items of a (should be empty):\n";
  a.print();
  cout << "Items of b (should be 1000):\n";
  b.print();
  cout << "Items of c (should be 1000, 2000, 3000):\n";
  c.print();

  return 0;
}
