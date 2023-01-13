#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
#include<cmath>
#include<cstdio>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int N;
int input[26][26] ={0,};
int visit[26][26] ={0,};
int result = 0;
vector<int> sum;
int t = 0;
void solve(int x, int y){
    if(x < 1 || x > N)
        return;
    if(y < 1 || y > N)
        return;
    t += 1;
    visit[x][y] = true;
    if(input[x-1][y]==1 && !visit[x-1][y]){
        solve(x-1, y);
    }
    if(input[x+1][y]==1 && !visit[x+1][y]){
        solve(x+1, y);
    }
    if(input[x][y-1]==1 && !visit[x][y-1]){
        solve(x, y-1);
    }
    if(input[x][y+1]==1 && !visit[x][y+1]){
        solve(x, y+1);
    }
}
int main(void){
    scanf("%d", &N);
    int tmp;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            scanf("%1d", &tmp);
            input[i][j] = tmp;
        }
    }
    //fill(&visit[0][0], &visit[26][26], 0);

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(input[i][j] == 1&&!visit[i][j]){
                result += 1;
                t = 0;
                solve(i, j);
                sum.push_back(t);
            }
        }
    }
    printf("%d\n", result);
    sort(sum.begin(), sum.end());
    for(int i=0; i< sum.size(); i++){
        printf("%d\n", sum[i]);
    }

}