#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Graph{

private:


  vector<Graph*> tree;
  int value;

public:
  Graph *master;  
  Graph(int _value);
  void append(Graph *obj);
  void set_master(Graph *_master);
  void set_value(int _value);
  int show_value();
  int show_slave_value_all();
  int show_slave_value_index(int i);  
  int show_slave_num();  
  void show_graph();
  void sort_graph();
  void graph_sum_least();  
  
};

bool graph_slave_compare(Graph* a,Graph* b){

  return a->show_value() < b->show_value();
  
}

int main(void){

  int n;
  string line;

  cin >> n;
  //cout << n << endl;

  //while(c != '\n'){c=getchar();}
  
  //for(cin>>n;n!=0;cin>>n){
  for(int i=0;i<n;i++){


    int votes=0;

    Graph g(0);

    Graph *focus;
    Graph *tmp;    

    focus=&g;

    //cout << "debug" << endl;

    cin >> line;
    //cout << line << endl;

    //for(c=getchar();c != '\n';c=getchar()){
    //while(0){
    for(char c:line){
      //cout << "debug" << endl;    
      //cin>>c;

      if(c=='['){
	tmp = new Graph(0);
	focus->append(tmp);
	focus=tmp;

      }
      else if(c==']'){
	//votes=votes/2+1;
	//focus->set_value(focus->show_value()/2+1);
	if(votes != 0){
	  votes=votes/2+1;
	  focus->set_value(votes);  
	}
	focus=focus->master;
	focus->sort_graph();

	int tmp_v=0;
	
	for(int j=0;j<focus->show_slave_num()/2+1;j++){
	  tmp_v += focus->show_slave_value_index(j);
	}
	focus->set_value(tmp_v);
	votes=0;
      }
      else if(c>='0' && c<='9'){
	votes=10*votes+(c-'0');
	
      }
      else{
	
      }
      
    }

    //g.show_graph();
    cout << g.show_value() << endl;
    //cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  }
  
}

Graph::Graph(int _value){

  value=_value;
  
}

void Graph::append(Graph *obj){
  obj->set_master(this);
  tree.push_back(obj);
  
}

void Graph::set_master(Graph *_master){
  master=_master;
}

void Graph::set_value(int _value){
  value=_value;
}

void Graph::show_graph(){

  cout << "value:" << value << endl;

  if(tree.size() > 0){
  
    cout << "show slave" << endl;

    cout << "==================" << endl;
  
    for(Graph *x:tree){
      x->show_graph();
    }

    cout << "slave end" << endl;

    cout << "+++++++++++++++++++++++++" << endl;
  }
  
}

int Graph::show_value(){
  return value;
}

int Graph::show_slave_value_all(){
  int tmp=0;
  for(Graph *x:tree){
    tmp += x->show_value();
  }
  return tmp;
}

void Graph::sort_graph(){

  //std::sort(tree.begin(),tree.end(),graph_slave_compare);
  std::sort(tree.begin(),tree.end(),
	    [](auto x,auto y){ return x->show_value() < y->show_value();});
  //[](Graph* x,Graph* y){ return x->show_value() < y->show_value();});  
  
}

int Graph::show_slave_num(){
  return tree.size();
}

int Graph::show_slave_value_index(int i){
  return this->tree[i]->show_value();
}
