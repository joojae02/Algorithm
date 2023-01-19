#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
#include<cmath>
#include<cstdio>


#define _CRT_SECURE_NO_WARNINGS
#define INT_MAX 2147483647
using namespace std;

int N, M;
int input[101][101] ={0,};
int visit[101][101] ={INT_MAX,};
queue<pair<int, int>> q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(){
    q.push(make_pair(1,1));
    visit[1][1] = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            //if(0>=nx||nx>N || 0>=ny||ny>M)
            //    continue;
            if(0<nx&&nx<=N&&0<ny&&ny<=M){
                if(input[nx][ny] == 1){
                    if(visit[nx][ny]>visit[x][y]+1){
                        visit[nx][ny] = visit[x][y]+1;
                        q.push(make_pair(nx, ny));
                    }
                }
                else if(input[nx][ny] == 0){
                    if(visit[nx][ny]>visit[x][y]){
                        visit[nx][ny] = visit[x][y];
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
}
int main(void){
    scanf("%d %d", &M, &N);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            scanf("%1d", &input[i][j]);
            visit[i][j] = INT_MAX;
        }
    }
    BFS();
    printf("%d", visit[N][M]);
}