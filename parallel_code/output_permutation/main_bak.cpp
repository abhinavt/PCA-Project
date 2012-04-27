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

//	vector<int> store_resulting gates;

//	vector< boost::dynamic_bitset<> > temp_output(1);
//	temp_output = &output;
	int tempo = 0;
	
	/* read input pla file */
	read_file ( input, output, n_vars ) ;

//	vector< boost::dynamic_bitset<> >& temp_output = output;

/*			cout << "temp output " << endl;       
			for (int row=0; row<(1<<n_vars); row++)
				cout << temp_output[row] << endl;
			cout << "-------------------" << endl;

*/


//	int ret = simple_algo(input,output,n_vars);
//	cout << " NUMBER OF GATES :: " 	<< ret << endl;

	/* create an array of index locations for output bits */
	int* index = new int[n_vars];	
	for (int i=n_vars-1; i>=0; i--)
		index[n_vars-i-1] = i;

/*	cout << "index " << endl;
	for (int i=0; i<n_vars; i++)
		cout << index[i] << " ";
	cout << '\n';
*/
	/* doing factorial to find out total number of permutation possible */
	int factorial_n = factorial(n_vars);

	/* creating an array to hold all the permuted indexes of output */
	int ** permuted_index = 0;
	permuted_index = new int *[factorial_n] ;

	for( int i = 0 ; i < factorial_n ; i++ )
		permuted_index[i] = new int[n_vars];

	/* reset the first row of permuted_index with default index */
	for( int i = 0 ; i < n_vars ; i++ ){
		permuted_index[0][i] = index[i];
	}

	/* doing permutation on the index locations of output bits */	
	int temp=0;
	sort (index,index+n_vars);
	do {
		for (int temp_index = 0; (temp_index < n_vars); temp_index++){			
			permuted_index[temp][temp_index] = index[temp_index];
		}	
		temp++;
	} while ( next_permutation (index,index+n_vars) );

	/* debug:: check permuted index 
	for (int r=0; r<factorial_n; r++){
		for (int c=0; c<n_vars; c++){
			cout << permuted_index[r][c] << " "; 
		}
		cout << '\n';
	}				*/
	
	/* permutation is done; now rearrange the output column and send to simple_algo */	
	int perm_row = 1;
	int row = 0;
	int output_row = 0;

/*	cout << "permuted indexes" << endl;
	for (int r=0; r<factorial_n; r++){
		for (int c=0; c< n_vars; c++){
			cout << permuted_index[r][c] << " "; 
		}
		cout << '\n';
	}
	cout << "-------------------" << endl;
*/

			cout << "read output " << endl;       
			for (int row=0; row<(1<<n_vars); row++)
				cout << output[row] << endl;
			cout << "-------------------" << endl;


	while (perm_row < factorial_n){
		vector< boost::dynamic_bitset<> > temp_output = output;
/*		cout << "perm_row :: " << perm_row << endl;

		for (int i=0; i<3; i++)
			cout << permuted_index[perm_row][i] << " ";
		cout << "+++++++++++" << endl; 

			cout << " temp_output inside while " << endl;       
			for (int r=0; r<(1<<n_vars); r++)
				cout <<  temp_output[r] << endl;
			cout << "-------------------" << endl;
*/
		
		
		while(row < (1<<n_vars)){
			for (int i=0; i<n_vars; i++){
				if(i != permuted_index[perm_row][i]){
					for (int j=i+1; j<n_vars; j++){
						if(i == permuted_index[perm_row][j]){
							if (temp_output[row][i] != temp_output[row][j]){
//								cout << "flipping i and j for i :  " << i << "  j : " << permuted_index[perm_row][j]<< " row : " << row << endl;
//								cout << "output[row][i] before flipping :  " << output[row] << endl;
								temp_output[row].flip(i);
								temp_output[row].flip(j);
//								cout << "output[row][i] after flipping :  " << output[row] << endl;
							}
						}
					}
				}
			}
			row++;
		}
		
/*			cout << "permuted output " << endl;       
			for (int r=0; r<(1<<n_vars); r++)
				cout << temp_output[r] << endl;
			cout << "-------------------" << endl;

*/

	int ret = simple_algo(input,temp_output,n_vars);
	cout << " NUMBER OF GATES :: " 	<< ret << endl;
	perm_row++;
	row = 0;
	}

// create_tfc_file(OUTPUT_MATCHING, n_vars);

	return 0;
}


int factorial(int a){
	int computed_factorial = 1;
	for(int i = 1; i <= a; i++){
		computed_factorial *= i;
	}
return computed_factorial;
}

