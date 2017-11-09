#include<iostream>
#include<vector>

using namespace std;

class Solution{
	public:
		int maxArea(vector<int>& height){
			int maxArea=0;
			int area;
			int i=0;
			int j=height.size()-1;
			while(i<j){
				area=(j-i)*(height.at(i)>height.at(j)?height.at(j):height.at(i));
				/*if((height.at(i+1)>height.at(j)?height.at(j):height.at(i+1))>(height.at(j-1)>height.at(i)?height.at(i):height.at(j-1))){
					j--;
				}else{
					i++;
				}*/
				if(height.at(i)>height.at(j)){
					j--;
				}else{
					i++;
				}
				if(area>maxArea){
					maxArea=area;
				}
			}
			return maxArea;
		}
};

int main(){
	int n;
	cin>>n;
	vector<int> height;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		height.push_back(a);
	}
	Solution *solution=new Solution();
	cout<<solution->maxArea(height);
}
