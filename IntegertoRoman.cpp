#include<iostream>
#include<string.h>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
    	string roman="";
        string x[4][10]={
        	{"","I","II","III","IV","V","VI","VII","VIII","IX"},
        	{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
        	{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
        	{"","M","MM","MMM"}
		};
		roman.append(x[3][num/1000]);
		roman.append(x[2][num%1000/100]);
		roman.append(x[1][num%100/10]);
		roman.append(x[0][num%10]);
		
		return roman;
    }
};

int main(){
	int num;
	cin>>num;
	Solution *solution=new Solution();
	cout<<solution->intToRoman(num);
	return 0;
}
