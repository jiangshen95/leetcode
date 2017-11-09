#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int> > result;
        vector<int> one;
        
        vector_qsort(candidates,0,candidates.size()-1);
        
        vector<int> index;
        
        int sum=target;
        int last_pop;
        
        for(int i=0;i<candidates.size();i++){
        	
        	if(i>0&&candidates.at(i)==last_pop&&candidates[i]==candidates[i-1]){
        		while(index.size()>0&&i==candidates.size()-1){
					i=index.back();
					sum+=one.back();
					last_pop=one.back();
					index.pop_back();
					one.pop_back();
				}
        		continue;
			}
        	
        	if(sum>candidates.at(i)){
        		one.push_back(candidates[i]);
        		
        		cout<<"----1-----"<<endl;
        			for(int x=0;x<one.size();x++){
        				cout<<one.at(x)<<", ";
					}
					cout<<endl;
        		
        		sum-=candidates[i];
        		index.push_back(i);
        		
        		while(index.size()>0&&i==candidates.size()-1){
        			i=index.back();
        			index.pop_back();
        			sum+=one.back();
        			last_pop=one.back();
        			one.pop_back();
        			cout<<"i: "<<i<<"-----"<<"last_pop: "<<last_pop<<endl;
				}
        		
			}
			else if(sum==candidates.at(i)){
				one.push_back(candidates[i]);
				result.push_back(one);
				last_pop=one.back();
				
				cout<<"----2-----"<<endl;
        			for(int x=0;x<one.size();x++){
        				cout<<one.at(x)<<", ";
					}
					cout<<endl;
				
				one.pop_back();
				
				if(index.size()>0){
					i=index.back();
					index.pop_back();
					sum+=one.back();
					last_pop=one.back();
					one.pop_back();
					
					while(index.size()>0&&i==candidates.size()-1){
						i=index.back();
						sum+=one.back();
						last_pop=one.back();
						one.pop_back();
						index.pop_back();
					}
				}
				
			}
			else{
				if(index.size()>0){
					i=index.back();
					index.pop_back();
					sum+=one.back();
					
					
					cout<<"----3-----"<<endl;
        			for(int x=0;x<one.size();x++){
        				cout<<one.at(x)<<", ";
					}
					cout<<endl;
					
					last_pop=one.back();
					one.pop_back();
					
					while(index.size()>0&&i==candidates.size()-1){
						i=index.back();
						sum+=one.back();
						last_pop=one.back();
						index.pop_back();
						one.pop_back();
					}
				}
			}
        	
		}
        
        
        
        return result;
        
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
	
	vector<int> candidates;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		candidates.push_back(num);
	}
	
	int target;
	cin>>target;
	
	Solution *solution=new Solution();
	vector<vector<int> > result=solution->combinationSum2(candidates,target);
	for(int i=0;i<result.size();i++){
		for(int j=0;j<result[i].size();j++){
			cout<<result[i][j]<<", ";
		}
		cout<<endl;
	}
	
	return 0;
}
