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


//typedef boost::dynamic_bitset<> boost;

enum {
	OUTPUT_MATCHING,
	INPUT_MATCHING,
	BIDIRECTIONAL,
};

//vector<boost::dynamic_bitset<> > op2in_gates;
//vector<boost::dynamic_bitset<> > ip2op_gates;

struct toffgate{
	vector<bool> isSWAP;
	vector<boost::dynamic_bitset<> > controls;
	vector<int> target;
};

struct circuit{
	int ng;
	int id;
	struct toffgate gates; 
};

struct templ{
	circuit reference;
	circuit replacement;
};



//toffgate op2in_gates;
//toffgate ip2op_gates;


/**
* function to save sequence of toffoli gate
*
*/


void add_toff_gate(boost::dynamic_bitset<> & C, int tar, bool save_front, int algoType, struct toffgate &op2in_gates, /*vector <circuit>& circuit  list<circuit>& circuit*/ struct circuit& circuit, int& id){

struct circuit ckt;

	if (save_front == 1){			
/*		circuit[id].op2in_gates.isSWAP.push_back(0);					
		circuit[id].op2in_gates.controls.push_back(C);
		circuit[id].op2in_gates.target.push_back(tar);
		ckt.gates = op2in_gates;
		f_circuits.push_back(ckt);
*/
		circuit.gates.isSWAP.push_back(0);
		circuit.gates.controls.push_back(C);
		circuit.gates.target.push_back(tar);
		}
	else{
	//	ip2op_gates.controls.push_back(C);
	//	ip2op_gates.target.push_back(tar);	
	}

//	cout << "circuit.size() :: " << (int)circuit.size() << endl;

}


/**
* function to create output file
*
*/


void create_tfc_file(int algoType, int n, struct toffgate &op22in_gates, struct toffgate &op2in_gates, int& id){

	int num_inputs;
	ofstream output ("output.tfc");

	num_inputs = n; //op2in_gates.controls[0].size();

	//  list the variables
	output << "v." << " ";
	for (int i=0; i< num_inputs; i++)	
		output << char(i + 97) << " ";
	output << '\n';

	// list the inputs
	output << "i." << " ";
	for (int i=0; i< num_inputs; i++)	
		output << char(i + 97) << " ";
	output << '\n';

	// list the outputs
	output << "o." << " ";
	for (int i=0; i< num_inputs; i++)	
		output << char(i + 97) << " ";
	output << '\n';
	output << "BEGIN" << '\n';
	

	if (algoType == (OUTPUT_MATCHING) ){
			for (int count = 0; count < (int) op2in_gates.controls.size(); count++) {
				int number_of_controls = op2in_gates.controls[count].count();
				output << "tf" << (number_of_controls + 1) << " ";
				for (int i = 0; i < num_inputs; ++i){
					if (op2in_gates.controls[count].test(i)) {
						 output <<  char(i + 97) << " " ;
					}
				}
	 			output <<  char(op2in_gates.target[count] + 97) << " " ;
				output << '\n';
			}
			output << "END";	
			output.close();			
	}

}

	/*
	else if (algoType == (INPUT_MATCHING) ){
			for (int count = 0; count < ip2op_gates.controls.size(); count++) {
				for (int i = 0; i < num_inputs; ++i){
					int number_of_controls = ip2op_gates.controls[count].count();
					output << "tf" << (number_of_controls + 1) << " ";
					if (ip2op_gates.controls[count].test(i))
						 output <<  char(i + 97) << " " ;
				}
				output <<  char(ip2op_gates.target + 97) << " " ;
				output << '\n';
			}
			output.close();	
	}
	else if (algoType == (BIDIRECTIONAL) ){
		int size_of_op2in = op2in_gates.controls.size();
			for (int count = (size_of_op2in-1); count >=0; count--)     {
				for (int i = 0; i < num_inputs; ++i){
					int number_of_controls = op2in_gates.controls[size_of_op2in-1].count();
					output << "tf" << (number_of_controls + 1) << " ";
					if (op2in_gates.controls[count].test(i))
						 output <<  char(i + 97) << " " ;
				}
				output <<  char(op2in_gates.target + 97) << " " ;
				output << '\n';
			}

			for (int count = 0; count < ip2op_gates.controls.size(); count++)  {
				for (int i = 0; i < num_inputs; ++i){
					int number_of_controls = ip2op_gates.controls[count].count();
					output << "tf" << (number_of_controls + 1) << " ";
					if (ip2op_gates.controls[count].test(i))
						 output <<  char(i + 97) << " " ;
				}
				output <<  char(ip2op_gates.target + 97) << " " ;
				output << '\n';
			}
			output.close();	
	}
*/


#endif  // _MY_LIB_H_
