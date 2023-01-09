#include<iostream>
#include<vector>
#include <algorithm>
#include<cmath>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;
int N, M, K;
int P[11][11];
bool visit[11][11] = {0,};
pair<int,int> ans[11];
int result = -1e4;
bool check(int x, int y, int depth){
    for(int i=1; i<=depth; i++){
        if(ans[i].first + 1 == x)
            if(ans[i].second == y)
                return false;
        if(ans[i].first == x)
            if(ans[i].second + 1 == y)
                return false;
        if(ans[i].first - 1 == x)
            if(ans[i].second == y)
                return false;
        if(ans[i].first == x)
            if(ans[i].second - 1 == y)
                return false;
    }
    return true;
}

void dfs(int depth, int sum){
    //printf("depth = %d, sum = %d\n",depth, sum);
    if(depth == K){
        if(result < sum)
            result = sum;
        return;
    }
    for(int i=1; i <= N; i++)
    {
        for(int j=1; j<=M; j++)
        {
            if(!visit[i][j])
            {
                if(check(i,j,depth))
                {    
                    visit[i][j] = true;
                    ans[depth+1] = {i,j};
                    dfs(depth+1, sum + P[i][j]);
                    visit[i][j] = false;
                }
            }
        }
    }
}

int main(void){
    scanf("%d %d %d", &N, &M, &K);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            scanf("%d", &P[i][j]);
    dfs(0,0);
    printf("%d", result);
}