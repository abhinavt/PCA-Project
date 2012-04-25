/**
 * @filename  create_result.h
 *
 * @brief     Implement the simple output to input matching algorithm
 *
 * @author    Adil Sadik: ams2378@columbia.edu
 * 	      Abhinav T
 */

# include <bitset>
# include <string>
# include <iostream>
# include <boost/dynamic_bitset.hpp>
# include <vector>

using namespace std;

/**
* function to save sequence of toffoli gate
* @param[in]	input		input bitset vector
* @param[in]	output		output bitset vector
* @param[in]	n		number of input/output bits
* 
*/

			
int simple_algo( vector <boost::dynamic_bitset<> >& input, vector <boost::dynamic_bitset<> >& output, int& n )
{

int no_of_gates =0;

boost::dynamic_bitset<> Cp (string(n,'0'));
boost::dynamic_bitset<> Cq (string(n,'0'));
boost::dynamic_bitset<> p (string(n,'0'));
boost::dynamic_bitset<> q (string(n,'0'));

/* Flipping the bits of first minterm */
if (output[0].any()){
    for ( int i=0; i<n; i++){
        if (output[0].test(i) == 1){

            for (int j=0; j< (1<<n); j++){
                output[j].flip(i);           
            }       
        }       
    }
}
   
/* Main loop, looping over all miterms */
for (int i=1; i< (1<<n) ; i++){

    if ( output[i].to_ulong() == i){
        continue;}
    else{ 
        for (int j=0; j<n; j++){
            if (output[i].test(j) == 0 && input[i].test(j) == 1){
                p[j] = 1;}
            else
                p[j] = 0;
        }

        for (int j=0; j<n; j++){
            if (output[i].test(j) == 1 && input[i].test(j) == 0){
                q[j] = 1;}
            else
                q[j] = 0;
        }
    }

    for (int j=0; j<n; j++){
        if (p[j]==1){           
		for (int k=0; k < n; k++){
                    if (output[i].test(k) == 1 )  {
                         if( (k==j) )
                             Cp.reset(k);
                         else
                             Cp.set(k);
                     }
        	}

        	boost::dynamic_bitset<> temp_Cp(string(n,'0'));
        	temp_Cp = Cp;   
	
	        if (Cp.any()){
	            for (int jj=i; jj< (1<<n); jj++){
	                Cp = temp_Cp;
			boost::dynamic_bitset<> out_copy(output[jj]);
	                if ((Cp &= out_copy) == temp_Cp){
				no_of_gates++;
	                   	output[jj].flip(j);
	                }
	            }
	        }

        }
    }   


    for (int j=0; j<n; j++){
	if (q[j]==1){
        	for (int k=0; k <n; k++){
                    if (output[i].test(k) == 1)   {
                         if( (k==j) )
                             Cq.reset(k);
                         else
                             Cq.set(k);
                    }
            	}   

        	boost::dynamic_bitset<> temp_Cq(string(n,'0'));
        	temp_Cq = Cq;   
	
	        if (Cq.any()){
	                for (int jj=i; jj< (1<<n); jj++){
	                    Cq = temp_Cq;
				boost::dynamic_bitset<> out_copy(output[jj]);

	                    if ((Cq &= out_copy) == temp_Cq){
				no_of_gates++;
       		                output[jj].flip(j);
       	             		}
       	         	}
       	     	}
	}       
    } 
  
}

cout << "final output " << endl;       
for (int row=0; row<(1<<n); row++)
	cout << output[row] << endl;


return no_of_gates;

}
