#include<iostream>
#include<list>
#include<vector>

using namespace std;


int main(void){

  int n;
  int h,w;
  char screen[50][50];

  int item[26][5]; //A~Z //min_x,min_y,max_x,max_y
  //char layer[7];
  //vector<list<int>> obj(26);
  int layer[26][26];

  cin>>n;
  //cout << n << endl;

  for(int i=0;i<n;i++){
    cin>>h;
    //cout << "h:"<<h << endl;
    cin>>w;
    //cout << "w:"<<w << endl;

    for(int j=0;j<50;j++){
      for(int k=0;k<50;k++){
        screen[j][k]=0;
      }
    }

    for(int j=0;j<26;j++){
      item[j][0]=0;
    }

    for(int j=0;j<26;j++){
      for(int k=0;k<26;k++){
        layer[j][k]=0;
      }
    }

    for(int j=0;j<h;j++){
      for(int k=0;k<w;k++){
        cin>>screen[j][k];
      }
    }


    for(int j=0;j<h;j++){
      for(int k=0;k<w;k++){
        //cout<<screen[j][k];
      }
      //cout << endl;
    }
    //cout << endl;

    for(int j=0;j<h;j++){
      for(int k=0;k<w;k++){
        if(screen[j][k]>='A' && screen[j][k]<= 'Z'){
          if(item[screen[j][k]-'A'][0]==0){
            item[screen[j][k]-'A'][0]=1;
            item[screen[j][k]-'A'][1]=k;//min_x
            item[screen[j][k]-'A'][2]=j;//min_y
            item[screen[j][k]-'A'][3]=k;//max_x
            item[screen[j][k]-'A'][4]=j;//max_y
          }
          else if(item[screen[j][k]-'A'][0]==1){
            if(k<item[screen[j][k]-'A'][1]) item[screen[j][k]-'A'][1]=k;//min_x
            if(j<item[screen[j][k]-'A'][2]) item[screen[j][k]-'A'][2]=j;//min_y
            if(k>item[screen[j][k]-'A'][3]) item[screen[j][k]-'A'][3]=k;//max_x
            if(j>item[screen[j][k]-'A'][4]) item[screen[j][k]-'A'][4]=j;//max_y
          }
        }
      }
    }

    for(int j=0;j<26;j++){
      if(item[j][0]==1){
        //cout<<(char)(j+'A')<<":"<<endl;
        //cout<<"(min_x,min_y)=(" <<item[j][1] << "," <<item[j][2]  << ")" << endl;
        //cout<<"(max_x,max_y)=(" <<item[j][3] << "," <<item[j][4]  << ")" << endl;

        int min_x=item[j][1];
        int min_y=item[j][2];
        int max_x=item[j][3];
        int max_y=item[j][4];


        for(int cnt1=min_y;cnt1<=max_y;cnt1++){
          for(int cnt2=min_x;cnt2<=max_x;cnt2++){
            //cout << cnt2 << "," << cnt1 << endl;
            if(screen[cnt1][cnt2] != j+'A' ){
              //cout << (char)(j+'A');
              //cout << screen[cnt1][cnt2];

              if(screen[cnt1][cnt2] >= 'A' && screen[cnt1][cnt2] <= 'Z'){

                int upper_c = screen[cnt1][cnt2]-'A';
                //cout << (char) (upper_c+'A') << endl;
                //cout << j << endl;
                if(layer[j][upper_c] == -1){
                  //cout << "SUSPICIOUS1" << endl;
                  goto SUS;
                }
                else{
                  if(layer[j][upper_c] == -1){
                    //cout << "SUSPICIOUS2" << endl;
                    goto SUS;
                  }
                  else{
                    layer[j][upper_c] = 1;
                    //cout << "added!" << endl;
                  }
                  for(int cnt3=0;cnt3<26;cnt3++){
                    if(layer[upper_c][cnt3]==1){
                      layer[j][cnt3]=layer[upper_c][cnt3];
                    }
                  }
                }
                for(int cnt3=0;cnt3<26;cnt3++){
                  for(int cnt4=0;cnt4<26;cnt4++){
                    if(layer[cnt3][cnt4]*layer[cnt4][cnt3] == 1 ){
                      //cout << "SUSPICIOUS3" << endl;
                      goto SUS;
                    }
                    else{
                      if(layer[cnt4][cnt3]!=0){
                        layer[cnt3][cnt4] = layer[cnt4][cnt3]*-1;
                      }
                    }
                  }
                }

                for(int cnt3=0;cnt3<26;cnt3++){
                  for(int cnt4=0;cnt4<26;cnt4++){
                      //cout << layer[cnt3][cnt4] << " ";
                  }
                  //cout << endl;
                }

              }

              else{
                //cout << "SUSPICIOUS4" << endl;
                goto SUS;
                break;
              }
            }
          }
        }
        //cout << endl;
      }
    }
    //cout << "This is Safe" << endl;
    cout << "SAFE" << endl;
    continue;
    SUS:
      //cout << "This is SUSPICIOUS!" << endl;
      cout << "SUSPICIOUS" << endl;

  }
  return 0;
}
