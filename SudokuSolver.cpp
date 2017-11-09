#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char> >& board) {
        
        int clumn[9][10]={0},row[9][10]={0},box[9][10]={0};
        for(int i=0;i<board.size();i++){
        	for(int j=0;j<board[i].size();j++){
        		if(board[i][j]!='.'){
        			clumn[i][board[i][j]-'0']++;
        			row[j][board[i][j]-'0']++;
        			box[i/3*3+j/3][board[i][j]-'0']++;
				}
			}
		}
		
		int i_count=0,j_count=0;
		vector<int> ev_i_count;
		vector<int> ev_j_count;
		vector<int> ev_num;
		
		bool is_back=false;
		
		int i,j;
		
		for(i=0;i<board.size();i++){
			for(j=0;j<board[i].size();j++){
				
				if(is_back){
					cout<<"back i: "<<i<<endl;
					cout<<"back j: "<<j<<endl;
					board[i][j]='.';
				}
				
				if(board[i][j]=='.'){
					if(!is_back){
						ev_i_count.push_back(i_count);
						ev_j_count.push_back(j_count);
					}
					cout<<"is_back: "<<is_back<<endl;
					cout<<"i: "<<i<<"------"<<"j: "<<j<<endl;
					cout<<"i_count: "<<i_count<<"------"<<"j_count: "<<j_count<<endl;
					i_count=0;
					j_count=0;
					
					int num;
					
					if(!is_back){
						num=1;
					}else{
						num=ev_num.back();
						clumn[i][num]--;
						row[j][num]--;
						box[i/3*3+j/3][num]--;
						ev_num.pop_back();
						num++;
					}
					
					cout<<"num: "<<num<<endl;
					
					is_back=false;
					
					for(;num<=9;num++){
						if(clumn[i][num]==0&&row[j][num]==0&&box[i/3*3+j/3][num]==0){
							board[i][j]='0'+num;
							clumn[i][num]++;
							row[j][num]++;
							box[i/3*3+j/3][num]++;
							
							ev_num.push_back(num);
							
							break;
						}
					}
					
					cout<<"2 num: "<<num<<endl;
					
					//system("pause");
					
					if(num==10){
						
						if(ev_i_count.size()<=1&&ev_j_count.size()<=1){
							return;
						}
						
						is_back=true;
						
						i-=ev_i_count.back();
						j-=ev_j_count.back();
						
						ev_i_count.pop_back();
						ev_j_count.pop_back();
						
						if(j<0) j+=9;
						
						j--;
						
						
					}
					
				}
				
				j_count++;
				
			}
			i_count++;
		}
		
        
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
