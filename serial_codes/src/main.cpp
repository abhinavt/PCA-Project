#include "includes.h"

#include "read_file.c"
#include "simple_algo.cpp"

int main() {


	char ch;
	int n_vars; // number of variables

	vector< boost::dynamic_bitset<> > input(1);
	vector< boost::dynamic_bitset<> > output(1);
	
	read_file ( input, output, n_vars ) ;

	int ret = simple_algo(input,output,n_vars);
	
	cout<<"Got the no_of_gates = " << ret << endl;
	
/*	
	//Printing output array:
	cout<<" Printing the output array: "<<endl;
	for ( int rows = 0 ; rows < 1<<n; rows++) {
			cout << output[rows] <<" " ; // [n- cols]
	//	cout<< "4 Reached here"<<endl;

		cout <<endl;
	}
*/	
	return 0 ;

}
