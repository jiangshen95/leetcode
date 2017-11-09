/*
 *Time Limit Exceeded
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        
        int last=nums.size()-1;
        int step=0;
        while(last>0){
        	int i;
        	for(i=0;i<last;i++){
        		if(last-i<=nums[i]){
        			break;
				}
			}
			
			step++;
			last=i;
			
		}
        
        return step;
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
