#include "print_pla.h"

//			output table			input table 	no_of_vars
void print_pla( vector< boost::dynamic_bitset<> > input, vector< boost::dynamic_bitset<> > output, int n) 
{
	
	// Printing the current PLA:
        cout << "Printing the PLA:" << endl;       
        for (int row=0; row < (n); row++) {  // 1<<
		cout << "Input      " << " Output " << endl;
		cout << input[row] << "        " << output[row] << endl;
	}
}
