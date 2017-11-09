#include<iostream>
#include<vector>

using namespace std;

class Solution{
	public:
		void vector_sort(vector<int>& nums,int l,int r){
			if(l<r){
				int v=nums.at(l);
				int i=l,j=r;
				while(i<j){
					while(i<j&&nums.at(j)>=v) j--;
					nums[i]=nums[j];
					while(i<j&&nums.at(i)<=v) i++;
					nums[j]=nums[i];
				}
				nums[i]=v;
				vector_sort(nums,l,i);
				vector_sort(nums,i+1,r);
			}
		}
		
		vector<vector<int> > threeSum(vector<int>& nums){
			vector_sort(nums,0,nums.size()-1);
			vector<vector<int> > result;
			
			for(int i=0;i<nums.size();i++){
				if(i>0&&nums[i]==nums[i-1]){
					continue;
				}
				int l=i+1,r=nums.size()-1;
				while(l<r){
					if(l>i+1&&nums.at(l)==nums.at(l-1)){
						l++;
						continue;
					}
					if(r<nums.size()-1&&nums.at(r)==nums.at(r+1)){
						r--;
						continue;
					}
					int s=nums.at(i)+nums.at(l)+nums.at(r);
					if(s<0) l++;
					else if(s>0) r--;
					else{
						vector<int> one;
						one.push_back(nums.at(i));
						one.push_back(nums.at(l));
						one.push_back(nums.at(r));
						result.push_back(one);
						l++;
						r--;
					}
				}
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
	Solution *solution=new Solution();
	vector<vector<int> > result=solution->threeSum(nums);
	for(int i=0;i<result.size();i++){
		for(int j=0;j<result.at(i).size();j++){
			cout<<result.at(i).at(j)<<" ";
		}
		cout<<endl;
	}
	return 0;
}
