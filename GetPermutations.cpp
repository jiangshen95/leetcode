#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        vector_qsort(nums,0,nums.size()-1);
        
        vector<vector<int> > permutations;
        getAllPermutations(nums,permutations,0);
        
        for(int i=0;i<permutations.size();i++){
        	for(int j=0;j<permutations[i].size();j++){
        		cout<<permutations[i][j]<<", ";
			}
			cout<<endl;
		}
		
    }
    
    void getAllPermutations(vector<int>& nums,vector<vector<int> >& permutations,int l){
    	if(l==nums.size()-1){
    		vector<int> permutation=nums;
    		permutations.push_back(permutation);
		}else{
			for(int i=l;i<nums.size();i++){
				cout<<"l: "<<l<<"-------"<<"i: "<<i<<endl;
				swap(nums[l],nums[i]);
				getAllPermutations(nums,permutations,l+1);
				swap(nums[l],nums[i]);
			}
		}
	}
	
	void swap(int& x,int& y){
		int v=x;
		x=y;
		y=v;
	}
    
    void vector_qsort(vector<int>& nums,int l,int r){
    	if(l<r){
    		int i=l,j=r;
    		int v=nums[l];
    		while(i<j){
    			while(i<j&&nums[j]>=v) j--;
    			nums[i]=nums[j];
    			while(i<j&&nums[i]<=v) i++;
    			nums[j]=nums[i];
			}
			nums[i]=v;
			vector_qsort(nums,l,i);
			vector_qsort(nums,i+1,r);
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
	solution->nextPermutation(nums);
	
	for(int i=0;i<n;i++){
		cout<<nums.at(i)<<", ";
	}
}
