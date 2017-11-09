#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string num[10]={" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> letters;
        vector<string> numofletter;
        int sum=1;
        int n=digits.length();
        if(n==0){
        	return letters;
		}
        for(int i=0;i<n;i++){
        	numofletter.push_back(num[digits[i]-'0']);
        	sum*=num[digits[i]-'0'].length();
		}

		int sub;
		for(int i=0;i<sum;i++){
			
			string letter="";
			int j;
			for(j=0;j<n-1;j++){
				sub=i;
				for(int k=n-1;k>=j+1;k--){
					sub/=numofletter.at(k).length();
				}
				cout<<"sub: "<<sub<<"---";
				
				char ch=numofletter[j][sub%numofletter[j].length()];
				cout<<"char: "<<ch<<endl;
				letter.append(1,ch);
			}
			cout<<"mode: "<<numofletter[j].length()<<endl;
			char ch=numofletter[j][i%numofletter[j].length()];
			letter.append(1,ch);
			
			letters.push_back(letter);
		}
		
		return letters;
    }
};

int main(){
	string digits;
	cin>>digits;
	Solution *solution=new Solution();
	vector<string> letters=solution->letterCombinations(digits);
	for(int i=0;i<letters.size();i++){
		cout<<letters.at(i)<<endl;
	}
	return 0;
}
