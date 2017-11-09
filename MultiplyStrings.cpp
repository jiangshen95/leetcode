#include<iostream>
#include<string.h>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        
        int flag=0;
        string res="";
        
        for(int i=num1.length()-1;i>=0;i--){
        	
        	flag=0;
        	string onesum="";
        	
        	for(int j=num2.length()-1;j>=0;j--){
        		
        		
        		int last;
        		last=(num1[i]-'0')*(num2[j]-'0');
        		last+=flag;
        		onesum+=last%10+'0';
        		flag=last/10;
        		
			}
			
			if(flag>0){
				onesum+=flag+'0';
			}
			
			flag=0;
			int k;
			for(k=0;k<onesum.length()&&k+(num1.length()-i-1)<res.length();k++){
				
				int sum=(onesum[k]-'0')+(res[k+(num1.length()-i-1)]-'0')+flag;
				res[k+(num1.length()-i-1)]=sum%10+'0';
				flag=sum/10;
				
			}
			for(;k<onesum.length();k++){
				int sum=onesum[k]-'0'+flag;
				res+=sum%10+'0';
				flag=sum/10;
			}
			if(flag>0){
				res+=flag+'0';
			}
			
			cout<<res<<endl;
			
			system("pause");
		}
        
        for(int i=0;i<res.length()/2;i++){
        	char v=res[i];
        	res[i]=res[res.length()-i-1];
        	res[res.length()-i-1]=v;
		}
		
		if(res.length()<=0||res[0]=='0'){
			return "0";
		}
		
		return res;
    }
};

int main(){
	string num1,num2;
	cin>>num1;
	cin>>num2;
	
	Solution *solution=new Solution();
	cout<<solution->multiply(num1,num2);
	
	return 0;
}
