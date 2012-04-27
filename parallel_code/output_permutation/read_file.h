#ifndef __READ_FILE_H__
#define __READ_FILE_H__

#include <includes.h>

using namespace std;
#define infile "../tb/test4.pla"

#include "print_pla.cpp"

//extern char* infile;

void read_file( vector <boost::dynamic_bitset<> >& input, vector <boost::dynamic_bitset<> >& output, int& n );

#endif
