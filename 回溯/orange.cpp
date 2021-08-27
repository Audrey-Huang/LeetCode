#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {
    vector<vector<int>>grid={{2,1,1},{1,1,0},{0,1,1}};
    int m=grid.size(),n=grid[0].size();
    queue<vector<int>>temp;
    int total=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2){
                temp.push({i,j});
            }
            if(grid[i][j]!=0){
                total++;
            }
        }
    }
    int decay=0;
    int time=-1;
    vector<vector<int>>move={{0,1},{0,-1},{1,0},{-1,0}};
    while(!temp.empty()){
        int m=temp.size();
        decay+=m;
        time++;
        while(m){
            vector<int> node=temp.front();
            temp.pop();
            for(vector<int> step:move){
                int ni=node[0]+step[0];
                int nj=node[1]+step[1];
                if(ni>=0&&ni<m&&nj>=0&&nj<n&&grid[ni][nj]==1){
                    temp.push({ni,nj});
                    grid[ni][nj]=2;
                }        
            }
            m--;
        }
    }
    cout<<decay<<total<<endl;
    if(decay==total) return time;
    return -1;
}