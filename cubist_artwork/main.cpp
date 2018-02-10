#include<iostream>
#include<algorithm>

using namespace std;

int search_max(int *v,int *c,int num);
int search_max_index(int *v,int *c,int num);
int search_field_front(int f_max,int f_index,int f_num,int *s,int *sc,int s_num,int all_field[][10]);
int search_field_side(int s_max,int s_index,int s_num,int *f,int *fc,int f_num,int all_field[][10]);

int check_complete(int *v,int num);
int sum_field(int all_field[][10],int w,int d);

int main(void){

  int w,d;
  int front_h[10]; // w
  int front_check[10];
  int side_h[10]; // d
  int side_check[10];
  int field[10][10]; // d w

    
  for(cin>>w,cin>>d; w!=0 && d!=0  ;cin>>w,cin>>d){

    for(int i=0;i<10;i++){
      front_h[i]=0;
      side_h[i]=0;      
    }
    
    for(int i=0;i<w;i++){
      cin >> front_h[i];
      front_check[i]=0;
    }

    for(int i=0;i<d;i++){
      cin >> side_h[i];
      side_check[i]=0;      

    }    

    for(int i=0;i<10;i++){
      for(int j=0;j<10;j++){
	field[i][j]=0;
      }
    }
    
    //begin
    for(int i=0;check_complete(front_check,w)!=0 || check_complete(side_check,d)!=0;i++){
      int tmp_max=max(search_max(front_h,front_check,w),search_max(side_h,side_check,d));

      if( tmp_max == search_max(front_h,front_check,w) ){

	int tmp_index=search_max_index(front_h,front_check,w);
	search_field_front(tmp_max,tmp_index,w,side_h,side_check,d,field);
	front_check[tmp_index]=1;
      
      }
      else{

	int tmp_index=search_max_index(side_h,side_check,d);
	search_field_side(tmp_max,tmp_index,d,front_h,front_check,w,field);
	side_check[tmp_index]=1;
      
      }
      
      for(int cnt1=0;cnt1<d;cnt1++){
	for(int cnt2=0;cnt2<w;cnt2++){
	  //cout << field[cnt1][cnt2] << " ";
	}
	//cout << "|";
	//cout << side_h[cnt1] << " | "  << side_check[cnt1] << endl;
      }
      //cout << "--------------------------------------------" << endl;
      for(int cnt1=0;cnt1<w;cnt1++){
	//cout << front_h[cnt1] << " ";
      }
      //cout << endl;      
      for(int cnt1=0;cnt1<w;cnt1++){
	//cout << front_check[cnt1] << " ";
      }      
      //cout << endl;
      //cout << endl;          
    }
    //end
    
    //cout << "----------------------------------------------next---------------------------------------" << endl;    
    cout << sum_field(field,w,d) << endl;
  }
  return 0;
}

int search_max(int *v,int *c,int num){

  int v_max=0;

  for(int i=0;i<num;i++){
    if(c[i] !=1){
      if(v_max < v[i]) v_max=v[i];
    }
    else continue;
  }
  return v_max; // 0 is error
}

int search_max_index(int *v,int *c,int num){
  int index=-1;
  int v_max=0;  
  for(int i=0;i<num;i++){
    if(c[i] !=1){
      if(v_max < v[i]){
	v_max=v[i];
	index=i;
      }
    }
    else continue;
  }
  return index; //-1 is error
}


int search_field_front(int f_max,int f_index,int f_num,int *s,int *sc,int s_num,int all_field[][10]){

  vector<int> candidate;
  vector<int> candidate2;
  int i=0;
  int j=0;
  for(i=0;i<s_num;i++){
    if(all_field[i][f_index]==f_max) return 0;
  }
  
  for(i=0;i<s_num;i++){

    if(s[i] == f_max){
      if(sc[i] != 1){

	for(j=0;j<f_num;j++){
	  if(all_field[i][j] == f_max){
	    candidate2.push_back(i);
	    break;
	  }
	}
	if(j==f_num){
	  all_field[i][f_index]=f_max;
	  vector<int>().swap(candidate);
	  break;
	}
      }
      else{
	candidate.push_back(i);
      }
    }
    else if(s[i] > f_max){
      candidate.push_back(i);
    }
  }
  if(i==s_num){
    if(candidate.size() > 0){
      all_field[candidate[0]][f_index]=f_max;
    }
    else if(candidate2.size() > 0){
      all_field[candidate2[0]][f_index]=f_max;
    }
  }
  vector<int>().swap(candidate);
  vector<int>().swap(candidate2);


  
  return 0;
}


int search_field_side(int s_max,int s_index,int s_num,int *f,int *fc,int f_num,int all_field[][10]){
  vector<int> candidate;
  vector<int> candidate2;  
  int i=0;
  int j=0;  

  for(i=0;i<f_num;i++){
    if(all_field[s_index][i]==s_max) return 0;
  }
  
  for(i=0;i<f_num;i++){

    if(f[i] ==s_max){
      if(fc[i] != 1){
		
	for(j=0;j<s_num;j++){
	  if(all_field[j][i] == s_max){
	    candidate2.push_back(i);
	    break;
	  }
	}
	if(j==f_num){
	  all_field[s_index][i]=s_max;
	  vector<int>().swap(candidate);
	  break;
	}
      }
      else{
	candidate.push_back(i);
      }
    }
    else if(f[i] > s_max){
      candidate.push_back(i);
    }
  }
  if(i==f_num){
    if(candidate.size() > 0){
      all_field[s_index][candidate[0]]=s_max;
    }
    if(candidate2.size() > 0){
      all_field[s_index][candidate2[0]]=s_max;      
    }
  }
  vector<int>().swap(candidate);
  vector<int>().swap(candidate2);
  return 0;
}

int check_complete(int *v,int num){

  for(int i=0;i<num;i++){
    if(v[i] == 0) return -1;
  }

  return 0;
  
}

int sum_field(int all_field[][10],int w,int d){

  int sum=0;
  
    for(int i=0;i<d;i++){
      for(int j=0;j<w;j++){
	sum+=all_field[i][j];
      }
    }
    return sum;
}
