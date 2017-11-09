#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Solution{
	public:
		void vector_sort(vector<int>& nums,int l,int r){
			if(l<r){
				int i=l,j=r;
				int v=nums.at(l);
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
		int threeSumClosest(vector<int>& nums,int target){
			vector_sort(nums,0,nums.size()-1);
			int sum;
			if(target>nums.at(nums.size()-1)+nums.at(nums.size()-2)+nums.at(nums.size()-3)){
				return nums.at(nums.size()-1)+nums.at(nums.size()-2)+nums.at(nums.size()-3);
			}
			if(target<nums.at(0)+nums.at(1)+nums.at(2)){
				return nums.at(0)+nums.at(1)+nums.at(2);
			}
			
			int mintotarget,result;
			
			for(int i=0;i<nums.size();i++){
				int l=i+1,r=nums.size()-1;
				while(l<r){
					sum=nums.at(i)+nums.at(l)+nums.at(r);
					cout<<"sum: "<<sum<<endl;
					
					if(i==0&&l==1&&r==nums.size()-1){
						mintotarget=abs(target-sum);
						result=sum;
					}
					else if(abs(target-sum)<mintotarget){
						mintotarget=abs(target-sum);
						result=sum;
					}
					
					cout<<"to target: "<<mintotarget<<endl;
					
					if(sum==target){
						return sum;
					}
					else if(sum>target){
						r--;
					}
					else{
						l++;
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
	int target;
	cin>>target;
	Solution *solution=new Solution();
	cout<<solution->threeSumClosest(nums,target);
	
	return 0;
}
