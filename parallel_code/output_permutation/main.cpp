#include "includes.h"

#define NUM_THREADS	1


int factorial (int a);
void *start_output_permutation(void* threadarg);

struct algo_fields{
	int no_of_gates;
	boost::dynamic_bitset<> Cp;
	boost::dynamic_bitset<> Cq;
	boost::dynamic_bitset<> temp_Cp;
	boost::dynamic_bitset<> temp_Cq;
	boost::dynamic_bitset<> p;
	boost::dynamic_bitset<> q;
};

struct thread_data{
   int  thread_id;
   int  n_vars;
   int  factorial_n;
   int  start;
   int  end;
//   algo_fields parameters;
};

int ** permuted_index = 0;
vector< boost::dynamic_bitset<> > input(1);
vector< boost::dynamic_bitset<> > output(1);

int main(int argc, char *argv[]) {



	int no_of_gates  = 0;


	char ch;
	int n_vars; 
	struct thread_data thread_data_values[NUM_THREADS];
	pthread_t threads[NUM_THREADS];

//	vector< boost::dynamic_bitset<> > input(1);
//	vector< boost::dynamic_bitset<> > output(1);
	
	/* read input pla file */
	read_file ( input, output, n_vars ) ;

/*	boost::dynamic_bitset<> Cp (string(n_vars,'0'));
	boost::dynamic_bitset<> Cq (string(n_vars,'0'));
	boost::dynamic_bitset<> temp_Cp (string(n_vars,'0'));
	boost::dynamic_bitset<> temp_Cq (string(n_vars,'0'));
	boost::dynamic_bitset<> p (string(n_vars,'0'));
	boost::dynamic_bitset<> q (string(n_vars,'0'));
*/
	/* create an array of index locations for output bits */
	int* index = new int[n_vars];	
	for (int i=n_vars-1; i>=0; i--)
		index[n_vars-i-1] = i;

	/* doing factorial to find out total number of permutation possible */

	int factorial_n = factorial(n_vars);

	cout << "factorial " << factorial_n << endl;

	/* creating an array to hold all the permuted indexes of output */
//	int ** permuted_index = 0;
	permuted_index = new int *[factorial_n/n_vars] ;

	cout << "&&&&&&&& debug &&&&&&&&&" << endl;

	for( int i = 0 ; i < factorial_n ; i++ )
		permuted_index[i] = new int[n_vars];

	/* reset the first row of permuted_index with default index */
	for( int i = 0 ; i < n_vars ; i++ ){
		permuted_index[0][i] = index[i];
	}

	/* doing permutation on the index locations of output bits */	
	int temp=0;
	sort (index,index+n_vars);
	do {
		for (int temp_index = 0; (temp_index < n_vars); temp_index++){			
			permuted_index[temp][temp_index] = index[temp_index];
		}	
		temp++;
	} while ( next_permutation (index,index+n_vars) );

	for (int j=0; j<factorial_n; j++){
		for (int i=0; i<n_vars; i++)	
			cout << permuted_index[j][i] << " ";
	cout << '\n';
	}

	
	/* permutation is done; now rearrange the output column and send to simple_algo */	
//	int perm_row = 1;
//	int row = 0;
//	int output_row = 0;

	cout << "read output " << endl;       
	for (int row=0; row<(1<<n_vars); row++)
	cout << output[row] << endl;
	cout << "-------------------" << endl;

	/* creating threads*/

	int interval = factorial_n/NUM_THREADS;

	int rc;
	for(int t=0;t<NUM_THREADS;t++) {

		thread_data_values[t].thread_id 	= 	t;
		thread_data_values[t].n_vars 		= 	n_vars;
		thread_data_values[t].factorial_n 	= 	factorial_n;
		thread_data_values[t].start 		= 	interval*t;
		thread_data_values[t].end		= 	(interval*t) + (interval-1);

/*		thread_data_values[t].parameters.no_of_gates		=	0;
		thread_data_values[t].parameters.Cp			=	Cp;
		thread_data_values[t].parameters.Cq			=	Cq;
		thread_data_values[t].parameters.temp_Cp		=	temp_Cp;
		thread_data_values[t].parameters.temp_Cq		=	temp_Cq;
		thread_data_values[t].parameters.p			=	p;
		thread_data_values[t].parameters.q			=	q;
*/
			

//		printf("Creating thread %d\n", t);
		rc = pthread_create(&threads[t], NULL, start_output_permutation, (void *) &thread_data_values[t]);	
		if (rc) {
		    printf("ERROR; return code from pthread_create() is %d\n", rc);
		    exit(-1);
		    }
	}

	pthread_exit(NULL);
// 		start_output_permutation(n_vars, factorial_n);

//	return 0;
}


/* factorial */
int factorial(int a){
	int computed_factorial = 1;
	for(int i = 1; i <= a; i++){
		computed_factorial *= i;
	}
return computed_factorial;
}


//void start_output_permutation(int n_vars, int factorial_n){
/* threads */
void *start_output_permutation(void *threadarg){

	struct thread_data *thread_pointer;
	thread_pointer =  (struct thread_data *) threadarg;
	int taskid, n_vars, factorial_n, start, end;

	taskid 		= 	thread_pointer->thread_id;
	n_vars 		= 	thread_pointer->n_vars;
	factorial_n 	= 	thread_pointer->factorial_n;
	start		= 	thread_pointer->start;
	end	 	= 	thread_pointer->end;

	int n = n_vars;
	int perm_row	=	start;
	int row = 0;
/*-----------------------------------------------------------
	boost::dynamic_bitset<> Cp;
	boost::dynamic_bitset<> Cq;
	boost::dynamic_bitset<> temp_Cp;
	boost::dynamic_bitset<> temp_Cq;
	boost::dynamic_bitset<> p;
	boost::dynamic_bitset<> q;

/*	struct algo_fields parameters;
	no_of_gates 	=	thread_pointer->parameters.no_of_gates;
	Cp	 	=	thread_pointer->parameters.Cp;
	Cq 		=	thread_pointer->parameters.Cq;
	temp_Cp 	=	thread_pointer->parameters.temp_Cp;
	temp_Cq 	= 	thread_pointer->parameters.temp_Cq;
	p 		=	thread_pointer->parameters.p;
	q 		=	thread_pointer->parameters.q;
*/
	int no_of_gates  = 0;
	boost::dynamic_bitset<> Cp (string(n,'0'));
	boost::dynamic_bitset<> Cq (string(n,'0'));
	boost::dynamic_bitset<> temp_Cp (string(n,'0'));
	boost::dynamic_bitset<> temp_Cq (string(n,'0'));
	boost::dynamic_bitset<> p (string(n,'0'));
	boost::dynamic_bitset<> q (string(n,'0'));

/*-----------------------------------------------------------*/

	cout << " &&&&&&&&&&&&&& THREAD " << taskid <<  " is working start : " << start << "  end : " << end << endl;

	while (perm_row < end){
		vector< boost::dynamic_bitset<> > temp_output = output;
	
	cout << " now thread " << taskid << " is working on permutation " << endl;
	for (int i=0; i<n_vars; i++)	
		cout << permuted_index[perm_row][i] << " ";
	cout << '\n';

		while(row < (1<<n_vars)){
			for (int i=0; i<n_vars; i++){
				if(i != permuted_index[perm_row][i]){
					for (int j=i+1; j<n_vars; j++){
						if(i == permuted_index[perm_row][j]){
							if (temp_output[row][i] != temp_output[row][j]){
								temp_output[row].flip(i);
								temp_output[row].flip(j);
							}
						}
					}
				}
			}
			row++;
		}

/*	cout << "permuted output for thread " << taskid << endl;       
	for (int r=0; r<(1<<n_vars); r++)
	cout << temp_output[r] << endl;
	cout << "-------------------" << endl;
*/

	int ret = simple_algo(input,temp_output,n_vars, no_of_gates, Cp, Cq, temp_Cp, temp_Cq, p, q );
	create_tfc_file(OUTPUT_MATCHING, n_vars);
	

/*	cout << "final output for thread " << taskid << endl;       
	for (int r=0; r<(1<<n_vars); r++)
	cout << temp_output[r] << endl;
	cout << "-------------------" << endl;
*/
	cout << " NUMBER OF GATES :: " 	<< ret << endl;
	perm_row++;
	row = 0;
	}
pthread_exit(NULL);
}

