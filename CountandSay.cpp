#include<iostream>
#include<string.h>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
        	return "1";
		}
		else{
			string last=countAndSay(n-1);
			string result="";
			char ch=last[0];
			int count=1;
			for(int i=1;i<last.length();i++){
				if(last[i]==ch){
					count++;
				}else{
					result.append(1,count+'0');
					result.append(1,ch);
					count=1;
					ch=last[i];
				}
			}
			result.append(1,count+'0');
			result.append(1,ch);
			
			return result;
		}
    }
};

int main(){
	int n;
	cin>>n;
	
	Solution *solution=new Solution();
	cout<<solution->countAndSay(n);
	
	return 0;
}
