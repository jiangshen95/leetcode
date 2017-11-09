#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        
        reverse(matrix);
        
        for(int i=0;i<matrix.size();i++){
        	for(int j=i+1;j<matrix[i].size();j++){
        		swap(matrix[i][j],matrix[j][i]);
			}
		}
    }
    
    void swap(int& x,int& y){
    	int v=x;
    	x=y;
    	y=v;
	}
	
	void reverse(vector<vector<int> >& matrix){
		vector<int> line;
		int i=0;
		int j=matrix.size()-1;
		while(i<j){
			line=matrix[i];
			matrix[i]=matrix[j];
			matrix[j]=line;
			i++;
			j--;
		}
	}
};

int main(){
	
	int n;
	cin>>n;
	
	vector<vector<int> > matrix;
	
	for(int i=0;i<n;i++){
		vector<int> line;
		for(int j=0;j<n;j++){
			int num;
			cin>>num;
			line.push_back(num);
		}
		matrix.push_back(line);
	}
	
	Solution *solution=new Solution();
	solution->rotate(matrix);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<matrix[i][j]<<", ";
		}
		cout<<endl;
	}
	
}
