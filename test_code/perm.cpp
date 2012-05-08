// next_permutation
#include <iostream>
#include <algorithm>
using namespace std;

int main () {
  int myints[] = {1,2,3};

  cout << "The 3! possible permutations with 3 elements:\n";

  sort (myints,myints+3);
  int i =0;
  int end = 2;
  

	  do {
	     cout << myints[0] << " " << myints[1] << " " << myints[2] << endl;
		while (i<end){
			next_permutation (myints,myints+3);
			i++;
		}
	     i = 0;
	  } while( next_permutation (myints,myints+3));	

  return 0;
}
