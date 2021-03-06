# include <bitset>
//# include "parameter.h"
//# include "toffoli.cpp"
# include <string>
# include <iostream>
#include <boost/dynamic_bitset.hpp>
#include <vector>

using namespace std;

//#define n 3
			
int simple_algo( vector <boost::dynamic_bitset<> >& input, vector <boost::dynamic_bitset<> >& output, int& n )
{

int no_of_gates =0;

boost::dynamic_bitset<> Cp (string(n,'0'));
boost::dynamic_bitset<> Cq (string(n,'0'));
boost::dynamic_bitset<> p (string(n,'0'));
boost::dynamic_bitset<> q (string(n,'0'));

// Flipping the bits of first minterm:
if (output[0].any()){
    for ( int i=0; i<n; i++){
        if (output[0].test(i) == 1){

            for (int j=0; j< (1<<n); j++){
                output[j].flip(i);           
            }       
        }       
    }
}
   
// Main loop, looping over all miterms:
for (int i=1; i< (1<<n) ; i++){

/*-    -    -    -    -    -    -    -    -    -    */
	// Printing the current PLA:
//	print_pla ( input, output, n );
        cout << "before applying toff when i is " << i << endl;       
        for (int row=0; row<(1<<n); row++)
            cout << output[row] << endl;

/*-    -    -    -    -    -    -    -    -    -    */

    if ( output[i].to_ulong() == i){
        continue;}
    else{   // Find the p vector:
        for (int j=0; j<n; j++){
            if (output[i].test(j) == 0 && input[i].test(j) == 1){
                p[j] = 1;}
            else
                p[j] = 0;
        }
	    // Find the q vector:
        for (int j=0; j<n; j++){
            if (output[i].test(j) == 1 && input[i].test(j) == 0){
                q[j] = 1;}
            else
                q[j] = 0;
        }
    }
   
    cout << "p and q ::" << p << "    " << q << "when i is ::" << i << endl;
	
	//Processing for "p" ::
    for (int j=0; j<n; j++){
	//Forming the Control lines
        if (p[j]==1){           
		for (int k=0; k < n; k++){
                    if (output[i].test(k) == 1 )  {
                         if( (k==j) )
                             Cp.reset(k);
                         else
                             Cp.set(k);
                     }
        	}
      		cout << "Cp for i : " << i << " j : " << j << " cp :" << Cp << endl;
        	boost::dynamic_bitset<> temp_Cp(string(n,'0'));
        	temp_Cp = Cp;   
	
		// Applying the toffoli corresponding to "p":
	        if (Cp.any()){
	            for (int jj=i; jj< (1<<n); jj++){
	                Cp = temp_Cp;
			boost::dynamic_bitset<> out_copy(output[jj]);
	                if ((Cp &= out_copy) == temp_Cp){
	                cout << "p is flipping; output : " << output[jj] << "  for Cp : " << Cp <<  "  when i " << i << "  target :: " << j << endl;
			no_of_gates++;
	                    output[jj].flip(j);
	                //    Cp = temp_Cp;
	                }
	            //    else    
	            //        continue;
	            }
	        }

        }
    }   // End of processing for p

/*        cout << "after applying toffoi for p when i " << i << endl;
        for (int row=0; row<8; row++)
            cout << output[row] << endl;
*/

	// Processing for "q" :: 
    for (int j=0; j<n; j++){
	//Forming the Control lines
	if (q[j]==1){
        	for (int k=0; k <n; k++){
                    if (output[i].test(k) == 1)   {
                         if( (k==j) )
                             Cq.reset(k);
                         else
                             Cq.set(k);
                    }
            	}   
        	cout << "Cq for i : " << i << " j : " << j << " cq :" << Cq << endl;
        	boost::dynamic_bitset<> temp_Cq(string(n,'0'));
        	temp_Cq = Cq;   
	
		// Applying the toffoli corresponding to "p":
	        if (Cq.any()){
	                for (int jj=i; jj< (1<<n); jj++){
	                    Cq = temp_Cq;
				boost::dynamic_bitset<> out_copy(output[jj]);
	                    //cout << "Cq &= output[jj] :: " << (Cq &= output[jj]) <<"  output[jj] ::" << output[jj] << " Cq : " << Cq << endl;
				
	                    if ((Cq &= out_copy) == temp_Cq){
	                    	cout << "q is flipping; output : " << output[jj] << "  Cq : " << Cq <<  "  when i " << i << "  target : " << j << " jj is :" << jj << endl;
				no_of_gates++;
       		                output[jj].flip(j);
       	                 	cout << "temp_Cq :: " << temp_Cq << endl;
       	             		}
       	         	}
       	     	}
	}       

/*        cout << "after applying toff for q when i is " << i << endl;       
        for (int row=0; row<8; row++)
            cout << output[row] << endl;
*/

    } // End of processing for q 
  
}  // End of main looping over all minterms
// Printing out the final output:

cout << "final output " << endl;       
for (int row=0; row<(1<<n); row++)
	cout << output[row] << endl;


return no_of_gates;

}
