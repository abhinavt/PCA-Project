/**
 * @filename  create_result.h
 *
 * @brief     read input file
 *
 * @author    Abhinav T
 * 	      
 */

#include "read_file.h" 

void read_file( vector <boost::dynamic_bitset<> >& input, vector <boost::dynamic_bitset<> >& output, int& n )
{
	int flush;
	int minterms = 0;
	char ch1, ch2, ch;
	int cubes = 0;
	ifstream FileIn (infile);
	if ( FileIn.is_open()) { 
		FileIn >> ch1;
		FileIn >> ch2;
		FileIn >> n; // Inputs size
		FileIn >> ch1;
		FileIn >> ch2;
		FileIn >> flush;
		
		int exp_n = 1<<n;

		input.resize( exp_n );
		output.resize( exp_n );

		for( int i =0; i< (exp_n); i++ ) {	
			input[i].resize(n);
			output[i].resize(n);	
		}

		
	for ( int iter =0; iter < (exp_n); iter++ )   { 

			for ( int in = 0; in <n; in++ ) {
				//cout<< "2-"<<in<<" Reached here"<<endl;
				FileIn >> ch;
				input[cubes][(n-1) - in] = (ch == '1')? true : false;
			}
			
			for ( int out = 0; out <n; out++ ) {
				FileIn >> ch;
				output[cubes][(n-1) - out] = (ch == '1')? true : false;
			}

			cubes++;
		}

	} else 	cout << " File Opening Error!"<< endl;
	
		FileIn >> ch2;
		if( ch2 == '.' ) {;
			cout<< " File successfully Read! "<< ch2 << endl;
		}
		cout << "No. of Cubes = "<< cubes<<endl;	
	
//	print_pla( input, output, cubes);

}


