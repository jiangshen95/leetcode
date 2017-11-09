#include<iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        
        double res=1;
        long m=long(n)>0 ? long(n) : -long(n);
        while(m>0){
        	if((m&1)==1) res*=x;
        	m>>=1;
        	x*=x;
		}
		
		return n>0 ? res : 1/res;
        
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
