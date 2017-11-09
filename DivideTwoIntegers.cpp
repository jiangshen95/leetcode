#include<iostream>
#include<cmath>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int MAX_INT=2147483647,MIN_INT=-2147483648;
        
        if(divisor==0){
        	return dividend>0?MAX_INT:MIN_INT;
		}
		if(dividend==MIN_INT&&divisor==-1){
			return MAX_INT;
		}
        
        
        long long x=abs((long)dividend),y=abs((long)divisor);
        int count=0;
        while(x-y>=0){
        	long long temp=1;
        	while(x-y>=0){
        		y<<=1;
        		temp<<=1;
			}
			x-=y>>1;
			count+=temp>>1;
			
			y=abs((long)divisor);
        	
		}
		
		int sign=(dividend>0)^(divisor>0)?-1:1;
        
		return count*sign;
        
        /*for(;x>0;x/=10) m++;
        for(;y>0;y/=10) n++;
        
        cout<<m<<endl;
        cout<<n<<endl;
        
        int result=0;
        
        x=dividend;
        y=divisor;
        for(int i=m;i<=n;i++){
        	
        	int count=0;
        	int zn=1;
        	for(int j=0;j<n-m;j++){
        		x/=10;
        		zn*=10;
			}
        	while(x-y>=0){
        		x-=y;
        		count++;
			}
			result=result*10+count; 
			x=x*zn+
		}*/
    }
};

int main(){
	int dividend,divisor;
	cin>>dividend>>divisor;
	
	Solution *solution=new Solution();
	cout<<solution->divide(dividend,divisor);
	
	return 0;
	
}
