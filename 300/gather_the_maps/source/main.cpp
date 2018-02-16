#include<iostream>
#include<vector>

using namespace std;

int main(void){

  int n;
  int **schedule;
  int **tmp_schedule;  
  int answer=-1;

  for(cin>>n;n!=0;cin>>n){
    int day_max=0;
    answer=-1;    
    schedule = new int*[n];
    tmp_schedule = new int*[n];
    
    for(int i=0;i<n;i++){
      int k;
      cin >> k;
      schedule[i] = new int[30+1];
      tmp_schedule[i] = new int[30+1];      

      for(int j=0;j<30;j++){
	schedule[i][j+1]=0;
      }
      
      for(int j=0;j<k;j++){
	int day;
	cin >> day;
	if(day > day_max){
	  day_max=day;
	}
	schedule[i][day]=1;
      }
    }
    //debug print begin

    
    for(int i=0;i<n;i++){
      //cout << i << ":";
      //cout << schedule[i][0];
      //cout << "|" ;
      for(int j=1;j<day_max+1;j++){
	//cout << schedule[i][j] << " ";
      }      
      //cout << endl;

    }
    //cout << endl;
    //debug print end

    int check_finish=0;
    
    for(int i=day_max;i>=1 ;i--){

      //cout << "day " << i << " challenge:" << endl;
      
      for(int j=0;j<n;j++){

	for(int k=0;k<30+1;k++){
	  tmp_schedule[j][k] = schedule[j][k];
	  //cout << tmp_schedule[j][k] << " ";
	}
	//cout << endl;
      }
      //cout << endl;      


      
      for(int j=i;j>=1 ;j--){
	vector<int> pair;

	for(int k=0;k<n;k++){
	  //cout << "tmp_schedule["<< k << "][0]:" << tmp_schedule[k][0] << endl;
	  if(tmp_schedule[k][0] == 1) {
	    //cout << "skip!"<< endl;
	    continue;
	  }
	  else{
	    //cout << "tmp_schedule["<< k << "][j]:" << tmp_schedule[k][j] << endl;	    
	    if(tmp_schedule[k][j] == 1){
	      pair.push_back(k);
	    }
	  }
	}
	//cout << "day " << j << " :" << endl;	
	//cout << "pair:" << endl;
	for(int x:pair){
	  //cout << x << endl;
	}
	//cout << endl;

	if(pair.size() > 1){
	  //cout << "pair exists !" << endl;
	  //cout << "pair[0]:"<< pair[0] << endl;	  
	  for(int k=1;k<day_max+1;k++){
	    for(int x:pair){
	      //tmp_schedule[pair[0]][k] |= tmp_schedule[x][k];
	      if(tmp_schedule[x][k] != 0){
		tmp_schedule[pair[0]][k]=1;
	      }
	    }
	  }
	  int dup=0;

	  for(int x:pair){
	      if(x != pair[0]){
		tmp_schedule[x][0]=1;
	      }
	      else{
		tmp_schedule[x][0]=2;		
	      }
	  }
	  int two_cnt=0;
	  for(int k=0;k<n;k++){
	    if(tmp_schedule[k][0] == 2){
	      two_cnt++;
	    }
	  }
	  if(two_cnt > 1){
	    //cout << "root dupulicate!" << endl;
	    //continue;
	    break;	    
	  }
	}

	for(int cnt1=0;cnt1<n;cnt1++){
	  for(int cnt2=0;cnt2<i+1;cnt2++){
	    //cout << tmp_schedule[cnt1][cnt2] << " ";	    
	  }
	  //cout << endl;
	}
	//cout << endl;	
	
	vector<int>().swap(pair);
	
      }
      //answer=i;
      int judge;
      for(judge=1;judge<n;judge++){
	if(tmp_schedule[judge][0] !=1) break;
      }

      if(judge == n) answer=i;
      
    }    

    //cout << "answer:" << answer << endl;
    cout << answer << endl;        
    //cout << "day_max:" << day_max << endl;
    
  }
  return 0;
}
