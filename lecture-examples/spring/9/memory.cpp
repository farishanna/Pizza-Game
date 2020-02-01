#include "demo.h"
#include <iostream>

using namespace std;

int main()
{
  // can use new to allocate memory on the heap
  double *dptr = new double(2.7683);
  // but it must be freed before the object/type goes out of scope
  delete dptr;

  // can allocate arrays
  int size;
  cout << "'ow big? ";
  cin >> size;
  int *array = new int[size];
  for(int i=0; i< size; i++){
    array[i] = i*i;
    cout << "integer " << array[i] << endl;
  }
  delete [] array;
  
  // Can also allocate objects
  demo *D = new demo(size,2,3);
  cout << "Dynamic D " << D->get_abc() << endl;
  delete D;
  
  return 0;
}
