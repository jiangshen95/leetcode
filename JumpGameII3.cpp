#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
    	
    	if(nums.size()<2){
    		return 0;
		}
        
        int step=0,currentMax=0,nextMax=0;
        int i=0;
        while(currentMax-i+1>0){
        	step++;
        	for(;i<=currentMax;i++){
        		nextMax=nextMax>nums[i]+i ? nextMax : nums[i]+i;
        		if(nextMax>=nums.size()-1) return step;
			}
			
			currentMax=nextMax;
		}
		
		return 0;
        
    }

};

int main(){
	
	int n;
	cin>>n;
	
	vector<int> nums;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		nums.push_back(num);
	}
	
	Solution *solution=new Solution();
	cout<<solution->jump(nums);
	
	return 0;
	
}
