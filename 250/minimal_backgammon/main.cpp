#include<iostream>
#include<iomanip>

using namespace std;

int main(void){

  double probability;

  unsigned long long sum;
  
  int N,T,L,B;
  int *L_arr;
  int *B_arr;
  double *N_arr;
  double *N_arr_tmp;
  double check;

  for(cin >> N,cin >> T, cin >> L, cin >> B; N!=0 or T!=0 or L !=0 or B!=0 ;cin >> N,cin >> T, cin >> L, cin >> B){

    //cout << N << "," << T << "," << L << "," << B << "," << endl;

    probability=0.0;

    sum=1;
    
    L_arr = new int[L];
    B_arr = new int[B];
    N_arr = new double[N+1];
    N_arr_tmp = new double[N+1];
    
    for(int i=0;i<L;i++){
      cin >> L_arr[i];
      //cout << L_arr[i] << endl;      
    }
    for(int i=0;i<B;i++){
      cin >> B_arr[i];
      //cout << B_arr[i] << endl;      
    }    
    
    //begin algo
    
    for(int i=0;i<N+1;i++){
      N_arr[i]=0.0;
    }
    N_arr[0]=1.0;

    double **L_order = new double*[L];

    for(int i=0;i<L;i++){
      L_order[i] =new double[2];
      //L_order[i][0]=L_arr[i];
      L_order[i][0]=0.0; // use for skip count
      L_order[i][1]=0.0; // use for normal
    }

    //loop

    //for(int cnt=0;cnt < T and cnt < 2;cnt++){
    for(int cnt=0;cnt < T;cnt++){

      //cout << "cnt:" << cnt << endl;
      //operation for normal
      check=0.0;
      for(int i=0;i<N+1;i++){
	N_arr_tmp[i]=0.0;
      }
    
      for(int i=0;i<N;i++){
	for(int j=1;j<=6;j++){
	  if(i+j > N){
	    N_arr_tmp[2*N-(i+j)] += N_arr[i]/6;
	  }
	  else{
	    N_arr_tmp[i+j] += N_arr[i]/6;
	  }
	}
      }

      for(int i=0;i<N+1;i++){
	//cout << "(i,N_i,Ntmp_i):" << i << "," << N_arr[i] << "," << N_arr_tmp[i] << endl;
      }    
      //cout << endl;

      //cout << "L Phase ! " << endl;
      
      for(int i=0;i<L;i++){
	//cout << "L_order[i][0]: " << L_order[i][0] << endl;
	//cout << "L_order[i][1]: " << L_order[i][1] << endl;
	//cout << "L_order[i][2]: " << L_order[i][2] << endl;		
	for(int j=1;j<=6;j++){
	  if(L_arr[i]+j > N){
	    N_arr_tmp[2*N-(L_arr[i]+j)] += L_order[i][1]/6;
	  }
	  else{
	    N_arr_tmp[L_arr[i]+j] += L_order[i][1]/6;
	  }
	}
      }
    
      for(int i=0;i<L;i++){
	L_order[i][1]=L_order[i][0];
	L_order[i][0]=N_arr_tmp[L_arr[i]];
	N_arr_tmp[L_arr[i]]=0.0;
	//cout << "(L_i0,L_i1,L_i2):" << L_order[i][0] << "," << L_order[i][1] << "," << L_order[i][2] << endl;	
      }
      //cout << endl;

      for(int i=0;i<N+1;i++){
	//cout << "(i,N_i,Ntmp_i):" << i << "," << N_arr[i] << "," << N_arr_tmp[i] << endl;
      }    
      //cout << endl;      
    
      for(int i=0;i<B;i++){
	N_arr_tmp[0] += N_arr_tmp[B_arr[i]];
	N_arr_tmp[B_arr[i]]=0.0;      
      }


      
      for(int i=0;i<N;i++){
	N_arr[i]=N_arr_tmp[i];
	//cout << "(i,N_i,Ntmp_i):" << i << "," << N_arr[i] << "," << N_arr_tmp[i] << endl;	
      }

      N_arr[N]=N_arr[N]+N_arr_tmp[N];

      for(int i=0;i<N+1;i++){
	//cout << "(i,N_i,Ntmp_i):" << i << "," << N_arr[i] << "," << N_arr_tmp[i] << endl;
	check += N_arr[i];
      }    
      //cout << endl;

      for(int i=0;i<L;i++){
	//cout << "(L_arr[i],L_i0,L_i1):" << L_arr[i] << "," << L_order[i][0] << "," << L_order[i][1] << endl;
	check += L_order[i][0] + L_order[i][1];
      }
      //cout << endl;      

      //cout << "check:" << check << endl;
      
      //probability += (double)(N_arr_tmp[N] / (double)sum);
      //probability += probability + (double)N_arr_tmp[N]/(double)6;
      
    }

    //cout << "N_arr[N]:" << N_arr[N] << endl;
    //cout << "probability:" << probability << endl;
    //cout << probability << endl;
    cout << fixed << setprecision(6) << N_arr[N] << endl;    
    
    //end loop    
    
    delete[] L_arr;
    delete[] B_arr;
    delete[] N_arr;
    for(int i=0;i<L;i++){
      delete[] L_order[i];
      L_order[i]=0;
    }    
    delete[] L_order;
    //cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~"  << endl;    
    
  }
  return 0;
}
