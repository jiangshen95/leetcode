#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(int i=0;i<nums.size();i++){
        	if(nums.at(i)==val){
        		for(int j=i;j<nums.size()-1;j++){
        			nums[j]=nums[j+1];
				}
				nums.pop_back();
				i--;
			}
		}
		
		for(int i=0;i<nums.size();i++){
			cout<<nums.at(i)<<endl;
		}
		
		return nums.size();
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
	
	int val;
	cin>>val;
	
	Solution *solution=new Solution();
	cout<<solution->removeElement(nums,val);
}
