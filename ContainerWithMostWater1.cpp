#include<iostream>
#include<vector>

using namespace std;

class Solution{
	public:
		int maxArea(vector<int>& height){
			int maxArea=0;
			for(int i=0;i<height.size();i++){
				for(int j=i+1;j<height.size();j++){
					int area=(j-i)*(height.at(i)>height.at(j)?height.at(j):height.at(i));
					if(area>maxArea){
						maxArea=area;
					}
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
