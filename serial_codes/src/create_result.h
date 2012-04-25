/**
 * @filename  create_result.h
 *
 * @brief     Implements the functions to save toffoli gate sequence and produce output (.tfc) file 
 *
 * @author    Adil Sadik: ams2378@columbia.edu
 * 	      Abhinav T
 */

#if !defined(_MY_LIB_H_)
#define _MY_LIB_H_

#include <boost/dynamic_bitset.hpp>
#include <bitset>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <list>
using namespace std;


typedef boost::dynamic_bitset<> boost;

enum {
	OUTPUT_MATCHING,
	INPUT_MATCHING,
	BIDIRECTIONAL,
};


vector<boost> op2in_gates;
vector<boost> ip2op_gates;

struct toffgate{
	vector<boost> controls;
	int target;
};

toffgate op2in_gates;
toffgate ip2op_gates;


/**
* function to save sequence of toffoli gate
* @param[in]	c		Control lines
* @param[in]	tar		target line
* @param[in]	save_front	select whether to save in the front or back
* @param[in]	algotype	type of algorithm being used
*/


void add_toff_gate(boost::dynamic_bitset<> >& C, int tar, bool save_front, int algoType){

	if (save_front == 0){				
		op2in_gates.controls.push_back(C);
		op2in_gates.target = tar;
	}
	else{
		ip2op_gates.controls.push_back(C);
		ip2on_gates.target = tar;	
	}
}


/**
* function to create output file
* 
*/



void create_tfc_file(int algoType){


	int num_inputs;
	ofstream output ("output.tfc");

	num_inputs = op2in_gates.controls[0].size();

	/* list the variables*/
	output << "v." << " ";
	for (int i=0; i< num_inputs; i++)	
		output << char(i + 97) << " ";
	output << '\n';

	/* list the inputs*/
	output << "i." << " ";
	for (int i=0; i< num_inputs; i++)	
		output << char(i + 97) << " ";
	output << '\n';

	/* list the outputs*/
	output << "o." << " ";
	for (int i=0; i< num_inputs; i++)	
		output << char(i + 97) << " ";
	output << '\n';

	if (algoType == (OUTPUT_MATCHING){
			for (int count = 0; count < op2in_gates.controls.size(); count++)
				for (int i = 0; i < num_inputs; ++i){
					int number_of_controls = op2in_gates.controls[count].count();
					output << "tf" << (number_of_controls + 1) << " ";
					if (op2in_gates.controls[count].test(i))
						 output <<  char(i + 97) << " " ;
				}
	 		output <<  char(op2in_gates.target + 97) << " " ;
			output << '\n';
			}
			output << "END";	
	output.close();		
	}
	else if (algoType == (INPUT_MATCHING){
			for (int count = 0; count < in2op_gates.controls.size(); count++)
				for (int i = 0; i < num_inputs; ++i){
					int number_of_controls = in2op_gates.controls[count].count();
					output << "tf" << (number_of_controls + 1) << " ";
					if (in2op_gates.controls[count].test(i))
						 output <<  char(i + 97) << " " ;
				}
			output <<  char(ip2op_gates.target + 97) << " " ;
			output << '\n';
			}
	output.close();	
	}
	else if (algoType == (BIDIRECTIONAL){
		int size_of_op2in = op2in_gates.controls.size();
			for (int count = (size_of_op2in-1); count >=0; count--)
				for (int i = 0; i < num_inputs; ++i){
					int number_of_controls = op2in_gates.controls[size_of_op2in-1].count();
					output << "tf" << (number_of_controls + 1) << " ";
					if (op2in_gates.controls[count].test(i))
						 output <<  char(i + 97) << " " ;
				}
			output <<  char(op2in_gates.target + 97) << " " ;
			output << '\n';
			}

			for (int count = 0; count < in2op_gates.controls.size(); count++)
				for (int i = 0; i < num_inputs; ++i){
					int number_of_controls = in2op_gates.controls[count].count();
					output << "tf" << (number_of_controls + 1) << " ";
					if (in2op_gates.controls[count].test(i))
						 output <<  char(i + 97) << " " ;
				}
			output <<  char(ip2op_gates.target + 97) << " " ;
			output << '\n';
			}
	output.close();	
	}
}

#endif  // _MY_LIB_H_
