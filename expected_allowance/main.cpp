#include<iostream>
#include<iomanip>

using namespace std;

int main(void){

  int n,m,k;
  double *v_table,*v_table_tmp;
  //unsigned long long *v_table,*v_table_tmp;

  for(cin>>n,cin>>m,cin>>k;n!=0 or m!=0 or k!=0;cin>>n,cin>>m,cin>>k){

    v_table = new double[n*m+1];
    //v_table = new unsigned long long[n*m+1];
    v_table_tmp = new double[n*m+1];
    //v_table_tmp = new unsigned long long[n*m+1];    
    
    //cout << n << "," << m << "," << k << endl;
    
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
	v_table[i*m+j+1] = 0;
	v_table_tmp[i*m+j+1] = 0;	
      }
    }
    v_table[0] = 1.0;
    
    for(int i=1;i<=n;i++){

      for(int c_i=0;c_i<n;c_i++){
	for(int c_j=0;c_j<m;c_j++){
	  v_table_tmp[c_i*m+c_j+1] = 0;	
	}
      }
      
      for(int j=i;j<=i*m;j++){

	for(int k=j-m;k<j;k++){
	  if(k < 0) continue;
	  else{
	    v_table_tmp[j] += v_table[k]/m;
	    //v_table_tmp[j] += v_table[k];	    
	  }
	}
	
      }

      for(int c_i=0;c_i<n;c_i++){
	for(int c_j=0;c_j<m;c_j++){
	  v_table[c_i*m+c_j+1] = v_table_tmp[c_i*m+c_j+1];
	}
      }
      v_table[0] = 0;

      for(int c_i=0;c_i<n;c_i++){
	for(int c_j=0;c_j<m;c_j++){
	  //cout << "v[" << c_i*m+c_j+1 << "]:" << v_table[c_i*m+c_j+1] << endl;
	}
      }
      //cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }
    

    double exp=0;

    for(int c_i=0;c_i<n;c_i++){
      for(int c_j=0;c_j<m;c_j++){
	//cout << "v[" << c_i*m+c_j+1 << "]:" << v_table[c_i*m+c_j+1] << endl;
	if(c_i*m+c_j+1 <= k){
	  exp += v_table[c_i*m+c_j+1];
	}
	else{
	  exp += (c_i*m+c_j+1-k)*v_table[c_i*m+c_j+1];	    
	}
      }
    }
    //cout << "exp:" << exp << endl;
    cout << fixed << setprecision(8) << exp << endl;        
    delete[] v_table;      
    //cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;    
    
  }
  return 0;
}
