/*
  Time Limit Exceeded
*/
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
			int mid;
			for(int i=0;i<nums.size();i++){
				if(i==nums.size()-1 || nums.at(i)==0 || (nums.at(i)<0&&nums.at(i+1)>0)){
					mid=i;
					break;
				}
			}
			if(mid==nums.size()-1){
				return result;
			}
			for(int i=0;i<=mid;i++){
				if(i>0&&nums.at(i)==nums.at(i-1)){
					continue;
				}
				for(int j=i+1;j<nums.size();j++){
					if(j>i+1&&nums.at(j)==nums.at(j-1)){
						continue;
					}
					int x=0-(nums.at(i)+nums.at(j));
					for(int k=(mid+1>j+1?mid+1:j+1);k<nums.size();k++){
						if(nums.at(k)==x&&k!=j){
							vector<int> one;
							one.push_back(nums.at(i));
							one.push_back(nums.at(j));
							one.push_back(x);
							result.push_back(one);
							break;
						}
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
