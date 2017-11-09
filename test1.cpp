#include<iostream>

using namespace std;

int main(){
	
	int a[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	bool is_back=false;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(is_back){
				cout<<"back i: "<<i<<endl;
				cout<<"back j: "<<j<<endl;
				system("pause");
			}
			if(a[i][j]==11){
				cout<<"i: "<<i<<endl;
				cout<<"j: "<<j<<endl;
				i--;
				j--;
				is_back=true;
			}
		}
	}
	
}
