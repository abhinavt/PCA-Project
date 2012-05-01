#include "includes.h"


int simple_algo( vector <boost::dynamic_bitset<> >& input, vector <boost::dynamic_bitset<> >& output, int& n )
{

int no_of_gates =0;

boost::dynamic_bitset<> Cp (string(n,'0'));
boost::dynamic_bitset<> Cq (string(n,'0'));
boost::dynamic_bitset<> p (string(n,'0'));
boost::dynamic_bitset<> q (string(n,'0'));

// Flipping the bits of first minterm:
if (output[0].any()){
no_of_gates = no_of_gates + output[0].count();
    for ( int i=0; i<n; i++){
        if (output[0].test(i) == 1){
            for (int j=0; j< (1<<n); j++){
                output[j].flip(i);           
            }
//	cout << "Cp for first minterm : " << Cp << endl;
//	add_toff_gate( Cp , i , true, OUTPUT_MATCHING );
        }
    }
}

// Main loop, looping over all miterms:
for (int i=1; i< (1<<n) ; i++){

	// Printing the current PLA:
//	print_pla ( input, output, n );

    if ( output[i].to_ulong() == i){
        continue;}
    else{   // Find the p vector:

//cout << "@@@@@@@@@@@@@ entered simple algo; now in else part" << endl;

        for (int j=0; j<n; j++){
            if (output[i].test(j) == 0 && input[i].test(j) == 1)
                p[j] = 1;
            else
                p[j] = 0;
        }
	    // Find the q vector:
        for (int j=0; j<n; j++){
            if (output[i].test(j) == 1 && input[i].test(j) == 0)
                q[j] = 1;
            else
                q[j] = 0;
        }
    }
   
//    cout << "p and q ::  " << p << "    " << q << "  when i is ::  " << i << endl;
	
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
      	//	cout << "Cp for i : " << i << " j : " << j << " cp : " << Cp << endl;
        	boost::dynamic_bitset<> temp_Cp(string(n,'0'));
        	temp_Cp = Cp;   
	//	cout << " no_of_gates get called " << endl;
			no_of_gates++;
	//		cout << "toffoli controls : " << Cp << endl;
	//		add_toff_gate( Cp , j , true, OUTPUT_MATCHING );		
		// Applying the toffoli corresponding to "p":
	        if (Cp.any()){
	            for (int jj=i; jj< (1<<n); jj++){
	                Cp = temp_Cp;
			boost::dynamic_bitset<> out_copy(output[jj]);
	                if ((Cp &= out_copy) == temp_Cp){
	      //          cout << "p is flipping; output : " << output[jj] << "  for Cp : " << Cp <<  "  when i " << i << "  target :: " << j << endl;
			output[jj].flip(j);
	                //    Cp = temp_Cp;
	                }
	            //    else    
	            //        continue;
	            }
	        }
		/* edited: 4/25	*/
		Cp.reset();
        }
    }   // End of processing for p

    //    cout << "after applying toffoi for p when i " << i << endl;
    //    for (int row=0; row<8; row++)
    //        cout << output[row] << endl;


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
       //	 cout << "Cq for i : " << i << " j : " << j << " cq :" << Cq << endl;
        	boost::dynamic_bitset<> temp_Cq(string(n,'0'));
        	temp_Cq = Cq;   
	//	cout << " no_of_gates get called " << endl;
				no_of_gates++;
	//		cout<< "toffoli controls : " << Cp << endl;
	//			add_toff_gate( Cq , j , true, OUTPUT_MATCHING );
	
		// Applying the toffoli corresponding to "p":
	        if (Cq.any()){
	                for (int jj=i; jj< (1<<n); jj++){
	                    Cq = temp_Cq;
				boost::dynamic_bitset<> out_copy(output[jj]);
	                    //cout << "Cq &= output[jj] :: " << (Cq &= output[jj]) <<"  output[jj] ::" << output[jj] << " Cq : " << Cq << endl;
				
	                    if ((Cq &= out_copy) == temp_Cq){
	                 //   	cout << "q is flipping; output : " << output[jj] << "  Cq : " << Cq <<  "  when i " << i << "  target : " << j << " jj is :" << jj << endl;
       		                output[jj].flip(j);
       	                 //	cout << "temp_Cq :: " << temp_Cq << endl;
       	             		}
       	         	}
       	     	}

		Cq.reset();

	}       

//        cout << "after applying toff for q when i is " << i << endl;       
//        for (int row=0; row<8; row++)
//            cout << output[row] << endl;


    } 
}  

ofstream log ("output.txt");
/*cout << "final output " << endl;    */   
for (int row=0; row<(1<<n); row++){
		cout << output[row];
		log << output[row] << '\n';
cout << '\n';
}
	
return no_of_gates;

}
