#include "includes.h"

#include "read_file.c"
#include "simple_algo.cpp"

#include <fstream>



int main() {


	char ch;
	int n_vars; 

	vector< boost::dynamic_bitset<> > input(1);
	vector< boost::dynamic_bitset<> > output(1);
	
	read_file ( input, output, n_vars ) ;

	int ret = simple_algo(input,output,n_vars);
	
	create_tfc_file(OUTPUT_MATCHING, n_vars);

	cout << "number of gates : " << ret << endl;

	return 0 ;

}
