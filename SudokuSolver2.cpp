#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<char> >& board){
		solve(board);
	}
    bool solve(vector<vector<char> >& board) {
    	for(int i=0;i<board.size();i++){
    		for(int j=0;j<board[i].size();j++){
    			
    			if(board[i][j]=='.'){
    				for(char ch='1';ch<='9';ch++){
    					if(isValid(board,i,j,ch)){
    						board[i][j]=ch;
    						if(solve(board)){
    							return true;
							}
							else{
								board[i][j]='.';
							}
							
						}
					}
					return false;
				}
			}
		}
		return true; 
    }
    
    bool isValid(vector<vector<char> >& board,int i,int j,char ch){
    	for(int x=0;x<9;x++){
    		if(board[i][x]!='.'&&board[i][x]==ch) return false;
    		if(board[x][j]!='.'&&board[x][j]==ch) return false;
    		if(board[i/3*3+x/3][j/3*3+x%3]!='.'&&board[i/3*3+x/3][j/3*3+x%3]==ch) return false;
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
	solution->solveSudoku(board);
	
	for(int i=0;i<board.size();i++){
		for(int j=0;j<board[i].size();j++){
			cout<<board[i][j]<<"  ";
		}
		cout<<endl;
	}
	
	return 0;
}
