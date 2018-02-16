#include<iostream>
#include<algorithm>

using namespace std;

class Node{
private:
  vector<int> *master_num;
  int value;
  int rank;
  int x;
  int y;
  Node *child[2];
public:
  Node();
  void add_value(int v,int _x,int _y);
  void add_child(int v,int _x,int _y);
  void add_rank(int r);
  void set_master(vector<int> *m);

  void show_value();
  void show_chain();
  void show_rank();
  void show_master();
  int show_master_val();
  int show_master_val_keta(int keta);

  void search(int H,int W);
};

char C[70][70]; // [H][W]
int C_route[70][70];
int route_check[70][70];

Node *compare_node_for_two(Node *n1,Node *n2,int keta);
void compare_node(Node *n,int num,int keta);

int main(void){

  int W,H;


  for(cin >> W,cin >> H;W!=0 && H!=0;cin >> W,cin >> H){
    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
	cin >> C[i][j];
	cout << C[i][j];
      }
      cout << endl;

    }
    cout << "W,H:" << W << "," << H << endl;

    int route_max=0;
    
    for(int i=0;i<W+H-1;i++){
      int init_x,init_y;
      cout << "i:" << i << endl;

      if(i<W){
	init_x=W-1-i;
	init_y=H-1;
      }
      else{
	init_x=0;
	init_y=H-1-(i-W+1);
      }
      
      int x,y;
      for(x=init_x,y=init_y; x<=W-1 && y>=0  ;x++,y--){
	cout << "x,y:" << x << "," << y << endl;
	cout << "C[y][x]:"  <<C[y][x] << endl;
	if(C[y][x] >= '0' && C[y][x] <= '9'){
	  cout << "number!" << endl;
	  if(x<W-1 && y<H-1){
	    cout << "choose max!" << endl;
	    C_route[y][x]=max(C_route[y+1][x],C_route[y][x+1])+1;
	    if(route_max < C_route[y][x]){
		route_max = C_route[y][x];
	    }
	  }
	  else if(x<W-1){
	    if(C_route[y][x+1]>0){
	      cout << "add!" << endl;
	      C_route[y][x]=C_route[y][x+1]+1;
	      if(route_max < C_route[y][x]){
		route_max = C_route[y][x];
	      }
	    }
	    else{
	      C_route[y][x]=1;
	      if(route_max < C_route[y][x]){
		route_max = C_route[y][x];
	      }	      
	    }
	  }
	  else if(y<H-1){
	    if(C_route[y+1][x]>0){
	      cout << "add!" << endl;	      
	      C_route[y][x]=C_route[y+1][x]+1;
	      if(route_max < C_route[y][x]){
		route_max = C_route[y][x];
	      }
	    }
	    else{
	      C_route[y][x]=1;
	      if(route_max < C_route[y][x]){
		route_max = C_route[y][x];
	      }	      
	    }
	  }
	  else{
	    C_route[y][x]=1;
	    if(route_max < C_route[y][x]){
	      route_max = C_route[y][x];
	    }	    
	  }
	}
	else{
	  C_route[y][x]=0;
	}
	
      }

    }

    cout << "max:" << route_max << endl;

    int keta=route_max;

    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
	route_check[i][j] = C_route[i][j];	
      }
    }

    vector<vector<int> > candidate;
    vector<int> tmp(3);

    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
	if(C_route[i][j] == route_max){
	  tmp[0]=C[i][j]-'0';
	  tmp[1]=i;
	  tmp[2]=j;
	  candidate.push_back(tmp);
	}
      }
    }
    
    cout << "candidate:" << candidate.size() << endl;

    vector<int> *candidate_num=nullptr;

    Node *n=nullptr;
    n = new Node[candidate.size()];

    for(int i=0;i<candidate.size();i++){
      candidate_num = new vector<int>(route_max,0);
      cout << "candidate_num.size():" << candidate_num->size() << endl;
      //candidate_num.push_back(i);
      //cout << "digit:" << candidate[i][0] << endl;
      //cout << "y:" << candidate[i][1] << endl;
      //cout << "x:" << candidate[i][2] << endl;
      n[i].set_master(candidate_num);
      n[i].add_value(candidate[i][0],candidate[i][2],candidate[i][1]);
      n[i].show_value();
      n[i].add_rank(route_max);
      n[i].show_rank();
      cout <<"search begin" <<endl;
      n[i].search(H,W);
      n[i].show_chain();
      //n[i].show_master();
      cout <<"~~~~~~~~" <<endl;
    }

    //if(candidate.size()==2){

    //compare_node_for_two(&n[0],&n[1],route_max)->show_master_val();
      
    //}
    
    compare_node(n,candidate.size(),route_max);


    
    cout << "show chain !" << endl;
    //n[0].show_chain();
    cout << endl;

    //n[0].add_child(1,2,3);
    //n[0].add_child(4,5,6);

    //n[0].show_chain();
    cout << endl;    

    vector<int> answer(route_max);

    
    for(int i=route_max;i>0;i--){
      int max_digi=-1;
      for(vector<int> x:candidate){
	cout << "digit:" << x[0] << endl;
	cout << "y:" << x[1] << endl;
	cout << "x:" << x[2] << endl;              
      }
    }

    //debug
    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
	cout << C_route[i][j] << "\t";
      }
      cout << endl;
    }
    int k=candidate.size();
    for(int i=0;i<k;i++){
      candidate.pop_back();
    }
    cout << endl;
  }
  return 0;
}

Node::Node(){
  child[0]=nullptr;
  child[1]=nullptr;
  rank=0;
}


void Node::add_value(int v,int _x,int _y){

  value=v;
  x=_x;
  y=_y;  
}

void Node::add_rank(int r){

  rank=r;
}

void Node::add_child(int v,int _x,int _y){

  if(child[0] == nullptr){
    Node *tmp;
    tmp = new Node;
    tmp->set_master(master_num);
    tmp->add_value(v,_x,_y);
    tmp->add_rank(rank-1);
    child[0]=tmp;
  }
  else if(child[1] == nullptr){
    Node *tmp;
    tmp = new Node;
    tmp->set_master(master_num);    
    tmp->add_value(v,_x,_y);
    tmp->add_rank(rank-1);    
    child[1]=tmp;
  }
  else{
    abort();
  }
    
}

void Node::show_value(){
  cout << "value:" << value << endl;
  cout << "x:" << x << endl;
  cout << "y:" << y << endl;    
}

void Node::show_rank(){

  cout << "rank:" << rank << endl;

}

void Node::show_chain(){

  for(int i=0;i<rank;i++){
    cout << "-";
  }
  
  cout << value << endl;
  
  if(child[0] != nullptr){

    child[0]->show_chain();
  }
  if(child[1] != nullptr){

    child[1]->show_chain();
  }

}

void Node::search(int H,int W){

  /*
  for(int i=0;i<70;i++){
    for(int j=0;j<70;j++){
      cout << C_route[i][j];
    }
    cout << endl;
  }  
  */

  //if(route_check[y][x] == 0) return;
  //else route_check[y][x]=0;
  
  cout << "rank:" << rank << endl;
  cout << "value:" << value << endl;
  cout << "master_size:" << master_num->size() << endl;
  for(int i=0;i<master_num->size();i++){
    cout << (*master_num)[(master_num->size())-i-1];
  }
  cout << endl;
  cout << "C_route[y][x]:" << C_route[y][x] << endl;
  cout << "C[y][x]:" << C[y][x] << endl;    

  if(rank ==1){
    (*master_num)[rank-1]=value;
    return;
  }
  
  if( C_route[y+1][x] == rank-1 && C_route[y][x+1] == rank-1  ){
    if(C[y+1][x] == C[y][x+1]){
      if((*master_num)[rank-1] < value){
	(*master_num)[rank-1]=value;
	for(int i=0;i<rank-1-1;i++){
	  (*master_num)[i]=0;
	}
      }
      
      this->add_child(C[y+1][x]-'0',x,y+1);
      this->add_child(C[y][x+1]-'0',x+1,y);
      
      /*
      Node *tmp;
      tmp = new Node;
      tmp->set_master(master);      
      tmp->add_value(C[y+1][x]-'0',x,y+1);
      tmp->add_rank(rank-1);
      child[0]=tmp;

      Node *tmp2;
      tmp2 = new Node;
      tmp2->set_master(master);      
      tmp2->add_value(C[y][x+1]-'0',x+1,y);
      tmp2->add_rank(rank-1);
      child[1]=tmp2;      
      */
    }
    else if(C[y+1][x] > C[y][x+1]){
      if((*master_num)[rank-1] < value){
	(*master_num)[rank-1]=value;
	for(int i=0;i<rank-1-1;i++){
	  (*master_num)[i]=0;
	}
      }

      this->add_child(C[y+1][x]-'0',x,y+1);      
      /*
      Node *tmp;
      tmp = new Node;
      tmp->set_master(master);      
      tmp->add_value(C[y+1][x]-'0',x,y+1);
      tmp->add_rank(rank-1);
      child[0]=tmp;
      */
    }
    else{
      if((*master_num)[rank-1] < value){
	(*master_num)[rank-1]=value;
	for(int i=0;i<rank-1-1;i++){
	  (*master_num)[i]=0;
	}
      }
      this->add_child(C[y][x+1]-'0',x+1,y);
      /*
      Node *tmp2;
      tmp2 = new Node;
      tmp2->set_master(master);      
      tmp2->add_value(C[y][x+1]-'0',x+1,y);
      tmp2->add_rank(rank-1);
      child[0]=tmp2;
      */
    }
  }
  else if(C_route[y+1][x] == rank-1){
    if((*master_num)[rank-1] < value){
      (*master_num)[rank-1]=value;
      for(int i=0;i<rank-1-1;i++){
	(*master_num)[i]=0;
      }
    }

    this->add_child(C[y+1][x]-'0',x,y+1);      
    /*
    Node *tmp;
    tmp = new Node;
    tmp2->set_master(master);    
    tmp->add_value(C[y+1][x]-'0',x,y+1);
    tmp->add_rank(rank-1);
    child[0]=tmp;
    */
  }
  else if(C_route[y][x+1] == rank-1){
    if((*master_num)[rank-1] < value){
      (*master_num)[rank-1]=value;
      for(int i=0;i<rank-1-1;i++){
	(*master_num)[i]=0;
      }
    }    
      this->add_child(C[y][x+1]-'0',x+1,y);    
    /*
    Node *tmp2;
    tmp2 = new Node;
    tmp2->set_master(master);    
    tmp2->add_value(C[y][x+1]-'0',x+1,y);
    tmp2->add_rank(rank-1);
    child[0]=tmp2;
    */
  }
  else{
    
  }

  if(child[0] != nullptr){
    child[0]->search(H,W);
  }
  if(child[1] != nullptr){
    child[1]->search(H,W);
  }  
  
}

void Node::set_master(vector<int> *m){

  master_num = m;

}

void Node::show_master(){
  cout << "show master:";
  for(int i=0;i<master_num->size();i++){
    cout << (*master_num)[(master_num->size())-i-1];
  }
  cout << endl;
}

int Node::show_master_val(){
  
  for(int i=0;i<master_num->size();i++){
    if(i==0 && (*master_num)[(master_num->size())-i-1]==0) continue;
    else cout << (*master_num)[(master_num->size())-i-1];
  }
  cout << endl;
  return 0;
}

int Node::show_master_val_keta(int keta){

  return (*master_num)[master_num->size()-keta-1];

}

Node *compare_node_for_two(Node *n1,Node *n2,int keta){

  int x,y;

  if(n1==nullptr && n2==nullptr) abort();

  if(n1==nullptr) return n2;
  if(n2==nullptr) return n1;  
  
  for(int i=0;i<keta;i++){

    x=n1->show_master_val_keta(i);
    y=n2->show_master_val_keta(i);

    if(x > y){
      return n1;
    }
    else if(x < y){
      return n2;
    }
    else{
      continue;
    }
    
  }
  
}

void compare_node(Node *n,int num,int keta){

  Node *max_n=nullptr;
  Node *tmp_n=nullptr;  
  
  for(int i=0;i<num;i++){
    //n[i].show_master_val();
    for(int j=0;j<keta;j++){
      cout << n[i].show_master_val_keta(j);
    }
    cout << endl;
    tmp_n=max_n;
    max_n=compare_node_for_two(max_n,&(n[i]),keta);
  }
  cout << "answer is here!:" ; 
  max_n->show_master_val();
  
}
