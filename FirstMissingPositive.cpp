#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
        	if(nums[i]>0&&nums[i]<=nums.size()&&nums[nums[i]-1]!=nums[i]){
        		int v=nums[nums[i]-1];
        		nums[nums[i]-1]=nums[i];
        		nums[i]=v;
        		i--;
			}
		}
		
		for(int i=0;i<nums.size();i++){
			if(nums[i]!=i+1){
				return i+1;
			}
		}
        
        return nums.size()+1;
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
	cout<<solution->firstMissingPositive(nums);
	
	return 0;
}
