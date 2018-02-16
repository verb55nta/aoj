#include<iostream>

using namespace std;

char table[8][8];
int available[8][8];

int direct_x(int k);
int direct_y(int k);


int check_mami();
int check_majo();

int check(char cookie);
int place(char cookie);

int main(void){

  const char mami='o';
  const char majo='x';

  char cookie[2]={mami,majo};

  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      cin >> table[i][j];
    }
  }

  int pass[2]={0,0};
  
  for(int cnt1=0; (pass[0]!=1 or pass[1] != 1) and cnt1 < 200 ;cnt1++){

    check(cookie[cnt1%2]);
    if(place(cookie[cnt1%2]) <=0){
      pass[cnt1%2]=1;
    }
    else{
      pass[cnt1%2]=0;
    }

    for(int i=0;i<8;i++){
      for(int j=0;j<8;j++){
	//cout <<  available[i][j];
      }
      //cout << endl;
    }
    //cout << endl;

    for(int i=0;i<8;i++){
      for(int j=0;j<8;j++){
	//cout <<  table[i][j];
      }
      //cout << endl;
    }
    //cout << endl;    
    
  }
  //cout << "game is over!" << endl;
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      cout <<  table[i][j];
    }
    cout << endl;
  }
  
  return 0;
}

//int check_mami(){
int check(char cookie){

  char enemy;

  if(cookie != 'o' and cookie != 'x') abort();
  else if(cookie == 'o') enemy='x';
  else if(cookie == 'x') enemy='o';
  
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      available[i][j]=0;
    }
  }
  
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      if(table[i][j] == 'o' or table[i][j] == 'x') continue; //has been placed?

      for(int k=0;k<9;k++){
	if(!(i+direct_y(k)>=0 and i+direct_y(k)<= 7 and j+direct_x(k)>=0 and j+direct_x(k)<=7) ) continue;
	if(table[i+direct_y(k)][j+direct_x(k)] == enemy){
	  //cout << "you can place at:(" <<i <<","<<j << "),k:"<< k << endl;
	  for(int a=2; i+a*direct_y(k)>=0 and i+a*direct_y(k)<= 7 and j+a*direct_x(k)>=0 and j+a*direct_x(k) <=7 ;a++){
	    if(table[i+a*direct_y(k)][j+a*direct_x(k)] == cookie ){
	      //cout <<"you can get cookie:"<<a-1 << " at k:" <<k << endl;
	      available[i][j] += a-1;
	      break;
	    }
	    else if(table[i+a*direct_y(k)][j+a*direct_x(k)] == enemy ){
	      continue;
	    }
	    else{
	      break;
	    }
	  }
	  
	}
	else continue;
      }
      
    }
  }
  
}

int direct_x(int k){

  return (k%3) - 1;

}

int direct_y(int k){

  return -(k/3) + 1;

}

int place(char cookie){

  int x=0,y=0;
  int max=0;
  //cout << "cookie is :" << cookie << endl;

  char enemy;
  if(cookie != 'o' and cookie != 'x') abort();
  else if(cookie == 'o') enemy='x';
  else if(cookie == 'x') enemy='o';  
  
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      if(cookie=='o'){
	if(available[i][j] > max){
	  //cout << "cookie:o,max reflashed! max:"<< max  << "(x,y)=(" <<x << "," <<y << ")" << endl;
	  max=available[i][j];
	  x=j;
	  y=i;
	}
      }
      else if(cookie == 'x'){
	if(available[i][j] >= max){
	  //cout << "cookie:x,max reflashed! max:"<< max  << "(x,y)=(" <<x << "," <<y << ")" << endl;
	  max=available[i][j];	  
	  x=j;
	  y=i;
	}
      }
    }
  }
  if(max > 0){
    //cout << "cookie will be placed (" <<x << "," <<y << ")" << endl;

    for(int k=0;k<9;k++){
      if(!(y+direct_y(k)>=0 and y+direct_y(k)<= 7 and x+direct_x(k)>=0 and x+direct_x(k)<=7) ) continue;
      if(table[y+direct_y(k)][x+direct_x(k)] == enemy){
	//cout << "you can place at:(" <<x <<","<<y << "),k:"<< k << endl;
	for(int a=2; y+a*direct_y(k)>=0 and y+a*direct_y(k)<= 7 and x+a*direct_x(k)>=0 and x+a*direct_x(k) <=7 ;a++){
	  if(table[y+a*direct_y(k)][x+a*direct_x(k)] == cookie ){
	    //cout <<"you can get cookie:"<<a-1 << " at k:" <<k << endl;
	    //available[i][j] += a-1;

	    for(int b=0;b<a-1+1;b++){
	      table[y+b*direct_y(k)][x+b*direct_x(k)] = cookie;
	    }
	    
	    break;
	  }
	  else if(table[y+a*direct_y(k)][x+a*direct_x(k)] == enemy ){
	    continue;
	  }
	  else{
	    break;
	  }
	}
	  
      }
      else continue;
    }    
    
  }
  else{
    //cout << "you cannot place cookie!" << endl;
  }

  return max;
}
