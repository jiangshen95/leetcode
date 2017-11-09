#include<iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        
        if(n==0){
        	return 1;
		}
		else if(n<0){
			if(n==-2147483648){
				n=2147483647;
				x=1/x;
				return x*myPow(x,n);
			}
			n=-n;
			x=1/x;
		}
		
		return n%2==0 ? myPow(x*x,n/2) : x*myPow(x*x,n/2);
        
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
