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
		vector<vector<int> > fourSum(vector<int>& nums,int target){
			vector_sort(nums,0,nums.size()-1);
			
			vector<vector<int> > result;
			
			for(int l=0;l<nums.size();l++){
				if(l>0&&nums.at(l)==nums.at(l-1)){
					continue;
				}
				for(int r=nums.size()-1;r>l+2;r--){
					if(r<nums.size()-1&&nums.at(r)==nums.at(r+1)){
						continue;
					}
					int i=l+1,j=r-1;
					while(i<j){
						if(i>l+1&&nums.at(i)==nums.at(i-1)){
							i++;
							continue;
						}
						if(j<r-1&&nums.at(j)==nums.at(j+1)){
							j--;
							continue;
						}
						int sum=nums.at(l)+nums.at(r)+nums.at(i)+nums.at(j);
						cout<<"sum: "<<sum<<endl;
						if(sum>target){
							j--;
						}
						else if(sum<target){
							i++;
						}
						else{
							vector<int> oknums;
							oknums.push_back(nums.at(l));
							oknums.push_back(nums.at(i));
							oknums.push_back(nums.at(j));
							oknums.push_back(nums.at(r));
							result.push_back(oknums);
							i++;
							j--;
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
	int target;
	cin>>target;
	
	Solution *solution=new Solution();
	vector<vector<int> > sumnums=solution->fourSum(nums,target);
	for(int i=0;i<sumnums.size();i++){
		for(int j=0;j<sumnums.at(i).size();j++){
			cout<<sumnums.at(i).at(j)<<", ";
		}
		cout<<endl;
	}
	
	return 0;
}
