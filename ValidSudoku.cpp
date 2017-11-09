#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
    	
    	for(int i=0;i<9;i++){
        	for(int j=0;j<9;j++){
        		for(int k=0;k<j;k++){
        			if(board[i][j]==board[i][k]&&board[i][j]!='.'){
        				return false;
					}
					if(board[j][i]==board[k][i]&&board[j][i]!='.'){
						return false;
					}
				}
			}
        }
        
        for(int x=0;x<9;x+=3){
        	for(int y=0;y<9;y+=3){
        		vector<int> nums;
        		for(int i=x;i<x+3;i++){
		        	for(int j=y;j<y+3;j++){
		        		for(int k=0;k<nums.size();k++){
		        			if(board[i][j]!='.'&&board[i][j]-'0'==nums.at(k)){
		        				return false;
							}
						}
						if(board[i][j]!='.'){
							nums.push_back(board[i][j]-'0');
						}
					}
				}
			}
		}
        
		
		return true;
    }
};

int main(){
	vector<vector<char> > board;
	for(int i=0;i<9;i++){
		vector<char> line;
		for(int j=0;j<9;j++){
			char ch;
			cin>>ch;
			line.push_back(ch);
		}
		board.push_back(line);
	}
	
	Solution *solution=new Solution();
	cout<<solution->isValidSudoku(board);
	
	return 0;
}
