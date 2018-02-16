#include<iostream>

using namespace std;

int main(void){
  
  int d_num;
  
  for(cin >> d_num;d_num !=0;cin >> d_num){
    //cout << "d_num:" << d_num << endl;
    int ref_num;
    cin >> ref_num;
    //cout << "ref_num:" << ref_num << endl;
    //int **ref_arr = new int*[ref_num];
    int ref_arr[10][2];

    //cout << "[ref]" << endl;
    
    for(int i=0;i<ref_num;i++){
      int x,y;
      cin >> x;
      cin >> y;
      //ref_arr[i] = new int[2];
      ref_arr[i][0]=x;
      ref_arr[i][1]=y;
      //cout << ref_arr[i][0] << "," << ref_arr[i][1] << endl;
    }
    
    //operation for reference
    
    for(int i=0;i<d_num;i++){
      int d_each_num;
      int match=0;			
      cin >> d_each_num;
      //cout << "d_each_num:" << d_each_num << endl;
      //int **d_arr = new int*[d_each_num];
      int d_arr[10][2];
      for(int j=0;j<d_each_num;j++){
	int x,y;
	cin >> x;
	cin >> y;					
	//d_arr[j] = new int[2];
	d_arr[j][0]=x;
	d_arr[j][1]=y;
	if(i==3){ 
	  //cout << d_arr[j][0] << "," << d_arr[j][1] << endl;
	}
      }
      if(ref_num != d_each_num) continue;  
      //operation for d_arr
      
      int k;
      int dx,dy;
      int ref_dx,ref_dy;
      int pre_dx=0,pre_dy=0;
      int ref_pre_dx=0,ref_pre_dy=0;
      for(k=0;k<d_each_num-1;k++){
	//operation
	dx = d_arr[k+1][0] - d_arr[k][0];
	ref_dx = ref_arr[k+1][0] - ref_arr[k][0];
	dy = d_arr[k+1][1] - d_arr[k][1];
	ref_dy = ref_arr[k+1][1] - ref_arr[k][1];
	
	//cout << "dx,dy:"  <<dx << "," << dy;
	//cout << "ref_dx,ref_dy:"  <<ref_dx << "," << ref_dy;
	//cout << endl;
	
	if( dx*dx + dy*dy != ref_dx*ref_dx + ref_dy*ref_dy  ) break;
	
	if( pre_dx*dy - dx*pre_dy != ref_pre_dx*ref_dy - ref_dx*ref_pre_dy ) break;
	
	pre_dx=dx;
	pre_dy=dy;
	ref_pre_dx=ref_dx;
	ref_pre_dy=ref_dy;
	
      }
      //cout << "k:" << k << endl;
      if(k==d_each_num-1){
	match=1;
      }
      
      if(match!=1){
      int pre_dx=0,pre_dy=0;
      int ref_pre_dx=0,ref_pre_dy=0;	
	for(k=0;k<d_each_num-1;k++){
	  //operation
	  dx = d_arr[k+1][0] - d_arr[k][0];
	  ref_dx = ref_arr[d_each_num-1-(k+1)][0] - ref_arr[d_each_num-1-k][0];
	  dy = d_arr[k+1][1] - d_arr[k][1];
	  ref_dy = ref_arr[d_each_num-1-(k+1)][1] - ref_arr[d_each_num-1-k][1];
	  
	  //cout << "dx,dy:"  <<dx << "," << dy;
	  //cout << "ref_dx,ref_dy:"  <<ref_dx << "," << ref_dy;
	  //cout << endl;				  
	  
	  if( dx*dx + dy*dy != ref_dx*ref_dx + ref_dy*ref_dy  ) break;
	  
	  if( pre_dx*dy - dx*pre_dy != ref_pre_dx*ref_dy - ref_dx*ref_pre_dy ) break;
	  
	  pre_dx=dx;
	  pre_dy=dy;
	  ref_pre_dx=ref_dx;
	  ref_pre_dy=ref_dy;
	  
	}
	//cout << "k:" << k << endl;
	if(k==d_each_num-1){
	  match=1;
	}
      //delete[] d_arr;
      }
      if(match == 1){
	cout << i+1  << endl; // need to answer
      }	    
    }
  
  //delete[] ref_arr;
    cout << "+++++" << endl; // need to answer
  
  
  }
  return 0;
}
