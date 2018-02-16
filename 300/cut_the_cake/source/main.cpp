#include<iostream>
#include<algorithm>

class Cake{
  
private:

  int x; // dependent on w;
  int y; // dependent on d;
  int w;
  int d;

public:
  Cake *next; 
  Cake(int _w,int _d,int _x,int _y);
  void val_set(int _w,int _d,int _x,int _y);
  void show();
  void show_everything();  
  int show_val_of_index(int index);
  int count_index();
  Cake *cut_the_cake(int index,int s);
  void push(Cake *c);
  void remove(int index);
  
  int x_val();
  int y_val();
  int w_val();
  int d_val();  
  
};

using namespace std;

int main(void){

  int n,w,d;
  
  for(cin>>n,cin>>w,cin>>d;n!=0 or w!=0 or d!=0;cin>>n,cin>>w,cin>>d){

    Cake c(w,d,0,0);  

    Cake *cc;

    cc=&c;
    

    
    //cout << cc->count_index() << endl;


    
    int p,s;
    
    //cc->show_everything();
    
    for(int i=0;i<n;i++){
      
      cin >> p;
      cin >> s;
      //cout << "p,s:" << p << "," << s << endl;

      cc=cc->cut_the_cake(p,s);
      //cc->show_everything();          
      
    }

    //cout << cc->count_index() << endl;

    int *array;
    int cnt=cc->count_index();
    array = new int[cnt];

    //array[0] = cc->val_w() *cc->val_d();
    
    for(int i=0;cc->next != nullptr;i++){
      array[i] = cc->w_val() * cc->d_val();
      //cout << "array[i]:" << array[i] << endl;
      cc=cc->next;      
    }

    array[cnt-1]=cc->w_val() * cc->d_val();
    //cout << "array[i]:" << array[cnt-1] << endl;    

    sort(array,array+cnt);

    for(int i=0;i<cnt;i++){
      //cout << "array[i]:" << array[i] << endl;
      cout << array[i] ;
      if(i != cnt-1) cout << " ";
    }
    cout << endl;
    
    delete[] array;
    //cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  }
  
  return 0;
}

Cake::Cake(int _w,int _d,int _x,int _y){

  w=_w;
  d=_d;
  x=_x;
  y=_y;
  next=nullptr;
  
}

void Cake::val_set(int _w,int _d,int _x,int _y){
  w=_w;
  d=_d;
  x=_x;
  y=_y;
  next=nullptr;
}

void Cake::show(){

  cout << "w:" << w << endl;
  cout << "d:" << d << endl;
  cout << "x:" << x << endl;
  cout << "y:" << y << endl;
  cout << endl;
  
}

int Cake::show_val_of_index(int index){

  Cake *cc=this;
  
  for(int i=1;i<index;i++){
    cc=cc->next;
  }

  cc->show();
  
  return 0;
}

void Cake::show_everything(){

  Cake *cc=this;
  
  cout << "show everything:" << endl;
  
  cc->show();
  while(cc->next!=nullptr){
    cc=cc->next;
    cc->show();    
  }

}

Cake *Cake::cut_the_cake(int index,int s){

  Cake *cc=this;
  Cake *cc_before=nullptr;


  
  for(int i=1;i<index;i++){
    cc_before=cc;
    cc=cc->next;
  }
  //cout << "c_index:" << endl;
  //cc->show();
  
  Cake *c1;
  Cake *c2;

  int cc_x=cc->x_val();
  int cc_y=cc->y_val();
  int cc_w=cc->w_val();
  int cc_d=cc->d_val();  

  int r=s%(2*(cc_w+cc_d));
  //cout << "r:" << r << endl;
  
  if(r < cc_w){
    if(r <= cc_w/2){
      c1 = new Cake(r,cc_d,cc_x,cc_y);
      c2 = new Cake(cc_w-r,cc_d,cc_x+r,cc_y);
    }
    else{
      c2 = new Cake(r,cc_d,cc_x,cc_y);
      c1 = new Cake(cc_w-r,cc_d,cc_x+r,cc_y);
    }
  }
  else if(r > cc_w && r < cc_w+cc_d){
    if(r-cc_w <= cc_d/2){
      c1 = new Cake(cc_w,r-cc_w,cc_x,cc_y);
      c2 = new Cake(cc_w,cc_d-(r-cc_w),cc_x,cc_y+(r-cc_w));            
    }
    else{
      c2 = new Cake(cc_w,r-cc_w,cc_x,cc_y);
      c1 = new Cake(cc_w,cc_d-(r-cc_w),cc_x,cc_y+(r-cc_w));            
    }
  }
  else if(r > cc_w+cc_d && r < 2*cc_w+cc_d){
    if(r-(cc_w+cc_d) <= cc_w/2){
      c1 = new Cake(r-(cc_w+cc_d),cc_d,cc_x+(cc_w-(r-(cc_w+cc_d))),cc_y);      
      c2 = new Cake(cc_w-(r-(cc_w+cc_d)),cc_d,cc_x,cc_y);
    }
    else{
      c2 = new Cake(r-(cc_w+cc_d),cc_d,cc_x+(cc_w-(r-(cc_w+cc_d))),cc_y);      
      c1 = new Cake(cc_w-(r-(cc_w+cc_d)),cc_d,cc_x,cc_y);
    }
  }
  else if(r > 2*cc_w+cc_d && r < 2*cc_w+2*cc_d){
    if(r-(2*cc_w+cc_d) <= cc_d/2){
      c1 = new Cake(cc_w,r-(2*cc_w+cc_d),cc_x,cc_y+(cc_d-(r-(2*cc_w+cc_d))));
      c2 = new Cake(cc_w,cc_d-(r-(2*cc_w+cc_d)),cc_x,cc_y);                  
    }
    else{
      c2 = new Cake(cc_w,r-(2*cc_w+cc_d),cc_x,cc_y+(cc_d-(r-(2*cc_w+cc_d))));
      c1 = new Cake(cc_w,cc_d-(r-(2*cc_w+cc_d)),cc_x,cc_y);                  
    }
  }
  else{
    cout << "error about r" << endl;
    abort();
  }
  //cout << "c1:" << endl;
  //c1->show();
  push(c1);
  //cout << "c2:" << endl;  
  //c2->show();        
  push(c2);  

  //this->show_everything();

  if(cc_before == nullptr){
    return cc->next;
  }
  else{
    cc_before->next = cc->next;
    return this;
  }
  


}

int Cake::count_index(){

  Cake *cc=this;
  int i;
  
  for(i=1;cc->next != nullptr;i++){
    cc=cc->next;
  }

  return i;
  
}

void Cake::push(Cake *c){

  Cake *cc=this;

  //cout << "of push:" << endl;
  //c->show();

  //cc->show();    
  
  while(cc->next != nullptr){
    cc=cc->next;
    //cc->show();        
  }

  cc->next = c;
  
}
void Cake::remove(int index){

  

}

int Cake::x_val(){
  return x;
}
int Cake::y_val(){
  return y;
}
int Cake::w_val(){
  return w;
}
int Cake::d_val(){
  return d;
}
