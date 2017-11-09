#include<iostream>
#include<string.h>
#include<map>


using namespace std;

class Solution {
public:
    int romanToInt(string s) {
    	map<char,int> roman;
    	roman['I']=1;
    	roman['V']=5;
    	roman['X']=10;
    	roman['L']=50;
    	roman['C']=100;
    	roman['D']=500;
    	roman['M']=1000;
		int num=0;
		for(int i=s.length()-1;i>=0;i--){
			if(i+1<s.length() && roman[s[i]]<roman[s[i+1]]){
				num-=roman[s[i]];
			}else{
				num+=roman[s[i]];
			}
		}
		
		return num;
    }

};

int main(){
	string s;
	cin>>s;
	Solution *solution=new Solution();
	cout<<solution->romanToInt(s);
	return 0;
}
