#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string num[10]={" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> letters;
        
        letters.push_back("");
        for(int i=0;i<digits.length();i++){
        	vector<string> temp;
        	string chars=num[digits[i]-'0'];
        	for(int j=0;j<chars.length();j++){
        		for(int k=0;k<letters.size();k++){
        			temp.push_back(letters[k]+chars[j]);
				}
			}
			letters=temp;
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
