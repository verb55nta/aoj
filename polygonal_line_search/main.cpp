#include<iostream>

using namespace std;

int main(void){

	int d_num;
	
	for(cin >> d_num;d_num !=0;cin >> d_num){
		cout << "d_num:" << d_num << endl;
		int ref_num;
		cin >> ref_num;
		cout << "ref_num:" << ref_num << endl;
		int **ref_arr = new int*[ref_num];
		
		for(int i=0;i<ref_num;i++){
			int x,y;
			cin >> x;
			cin >> y;
			ref_arr[i] = new int[2];
			ref_arr[i][0]=x;
			ref_arr[i][1]=y;
			cout << ref_arr[i][0] << "," << ref_arr[i][1] << endl;
		}
		
		//operation for reference

		for(int i=0;i<d_num;i++){
			int d_each_num;
			cin >> d_each_num;
			cout << "d_each_num:" << d_each_num << endl;

			if(ref_num != d_each_num) break;
			else{
				int **d_arr = new int*[d_each_num];			
				for(int j=0;j<d_each_num;j++){
					int x,y;
					cin >> x;
					cin >> y;					
					d_arr[j] = new int[2];
					d_arr[j][0]=x;
					d_arr[j][1]=y;
					cout << d_arr[j][0] << "," << d_arr[j][1] << endl;					
				}

				//operation for d_arr
				
				delete[] d_arr;		
			}

		}
		
		delete[] ref_arr;
		cout << "+++++" << endl; // need to answer

		
	}
	return 0;
}
