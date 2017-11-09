#include<iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double s;
        int m=n>0?n:-n;
        
        s=power(x,m);
        
        if(n<0){
        	s=1/s;
		}
        
        return s;
    }
    double power(double x,int n){
    	if(n==0){
    		return 1;
		}
    	double s=x;
    	int i=2;
    	while(i<=n){
        	s*=s;
        	i*=2;
		}
		
		return s*power(x,n-i/2);
	}
};

int main(){
	
	double x;
	int n;
	cin>>x;
	cin>>n;
	
	Solution *solution=new Solution();
	cout<<solution->myPow(x,n);
	
	return 0;
	
}
