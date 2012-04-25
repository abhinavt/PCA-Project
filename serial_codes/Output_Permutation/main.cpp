#include "includes.h"
#include <algorithm>
#include "read_file.c"
#include "simple_algo.cpp"


int factorial (int a);

int main() {


	char ch;
	int n_vars; 

	vector< boost::dynamic_bitset<> > input(1);
	vector< boost::dynamic_bitset<> > output(1);
	
	/* read input pla file */
	read_file ( input, output, n_vars ) ;

	/* create an array of index locations for output bits */
	int* index = new int[n_vars];	

	/* doing factorial to find out total number of permutation possible */
	int factorial_n = factorial(n_vars);

	/* creating an array to hold all the permuted indexes of output */
	int ** permuted_index = 0;
	permuted_index = new int *[factorial_n] ;

	for( int i = 0 ; i < factorial_n ; i++ )
		permuted_index[i] = new int[n_vars];

	/* reset the first array of permuted_index with default index */
	for( int i = 0 ; i < n_vars ; i++ )
		permuted_index[0][i] = index[i];

	/* doing permutation on the index locations of output bits */	
	int temp=0;
	sort (index,index+n_vars);
	do {
		for (int temp_index = 0; (temp_index < n_vars); temp_index++){			
			permuted_index[temp][temp_index] = index[temp_index];
		}	
		cout << '\n';
		temp++;
	} while ( next_permutation (index,index+n_vars) );

	/* permutation is done; now rearrange the output column and send to simple_algo */	
	int perm_row = 0;
	int row = 0;
	int output_row = 0;
	while (perm_row < factorial_n){
		while(row < (1<<n_vars)){
			for (int i=0; i<n_vars; i++){
				if(i != permuted_index[perm_row][i]){
					for (int j=0; j<n_vars; j++){
						if(i == permuted_index[perm_row][j]){
							output[row][i] = output[row][i]^output[row][j];
							output[row][j] = output[row][i]^output[row][j];
							output[row][i] = output[row][i]^output[row][j]; 
						}		
					}
				}
			}
			row++;
		}
	int ret = simple_algo(input,output,n_vars);	
	perm_row++;
	}
	return 0 ;
}

int factorial(int a){
	int computed_factorial = 1;
	for(int i = 1; i <= a; i++){
		computed_factorial *= i;
	}
return computed_factorial;
}
