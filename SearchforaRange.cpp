#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    	
        int l=0,r=nums.size()-1;
        int _l=0,_r=nums.size()-1;
        while(l<r||_l<_r){
        	cout<<"l:"<<l<<"------"<<"r: "<<r<<endl;
        	cout<<"_l: "<<_l<<"------"<<"_r: "<<_r<<endl;
        	int mid=(l+r)/2;
        	int _mid=(_l+_r)/2+(_l+_r)%2;
        	if(nums[_mid]>target) _r=_mid-1;
        	else _l=_mid;
        	if(nums[mid]>=target) r=mid;
        	else l=mid+1;
		}
		
		vector<int> result;
		
		if(l>=nums.size()||nums.at(l)!=target){
			result.push_back(-1);
			result.push_back(-1);
		}else{
			result.push_back(l);
			result.push_back(_l);
		}
		
		return result;
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
	
	int target;
	cin>>target;
	
	Solution *solution=new Solution();
	vector<int> result=solution->searchRange(nums,target);
	for(int i=0;i<result.size();i++){
		cout<<result.at(i)<<", ";
	}
	
	return 0;
}
