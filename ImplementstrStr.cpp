#include<iostream>
#include<string.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
    	int l1=haystack.length(),l2=needle.length();
    	if(l2>l1){
    		return -1;
		}
		if(l2==0){
			return 0;
		}
		
		int next[l2+1];
		next[0]=next[1]=0;
		int i,k=0;
		
		for(i=2;i<=l2;i++){
			
			for(;k!=0&&needle[k]!=needle[i-1];k=next[k]);
			
			if(needle[k]==needle[i-1]){
				k++;
			}
			
			next[i]=k;
		}
		
		int result=-1;
		i=0;
		k=0;
		while(i<l1){
			int j;
			for(j=k;j<l2;j++){
				if(i+j>=l1||needle[j]!=haystack[i+j]){
					break;
				}
			}
			if(j==l2){
				result=i;
				break;
			}
			else{
				k=next[j];
				i+=(j==0?1:j-k);
			}
		}
		
		
		return result;
    }
};

int main(){
	string haystack,needle;
	cin>>haystack;
	cin>>needle;
	
	Solution *solution=new Solution();
	cout<<solution->strStr(haystack,needle);
	
	return 0;
}
