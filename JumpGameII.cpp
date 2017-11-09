/*
 *Time Limited Out
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        
        vector<int> allstep;
        where(nums,0,0,allstep);
        
        int minstep=allstep.at(0);
        cout<<allstep.at(0)<<endl;
        for(int i=1;i<allstep.size();i++){
        	cout<<allstep.at(i)<<endl;
        	if(allstep.at(i)<minstep){
        		minstep=allstep.at(i);
			}
		}
		
		return minstep;
        
    }
    
    void where(vector<int>& nums,int curr,int step,vector<int>& allstep){
    	if(curr==nums.size()-1){
    		allstep.push_back(step);
		}
		else if(curr<nums.size()-1){
			int max=nums[curr];
			for(int i=1;i<=max;i++){
				where(nums,curr+i,step+1,allstep);
			}
		}
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
