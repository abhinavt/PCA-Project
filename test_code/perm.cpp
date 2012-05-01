// next_permutation
#include <iostream>
#include <algorithm>
using namespace std;

int main () {
//  int myints[] = {1,2,3, 4};
  int myints[] = {0,1,2};
  int size = 3;
  cout << "The 3! possible permutations with 3 elements:\n";

  sort (myints,myints+size);
//  reverse (myints,myints+size);

  do {
    cout << myints[0] << " " << myints[1] << " " << myints[2] << endl;
  } while ( next_permutation (myints,myints+size) );

  return 0;
}
