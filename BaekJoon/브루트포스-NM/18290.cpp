#include<iostream>
#include<vector>
#include <algorithm>
#include<cmath>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;
int N, M, K;
int P[11] = {0,};
int NP[11][11];
bool visit[11] = {0,};
bool check(){
    for(int i=0; i<M-1; i++){
        if(P[i] > P[i+1])
            return false;
    }
    return true;
}
void dfs(int depth){
    if(depth == M){
        if(check())
        {        
            for(int i=0; i<M; i++){
                printf("%d ", P[i]);
            }
            printf("\n");
        }
        return;
    }
    for(int i = 1; i <= N; i++)
    {

            visit[i] = true;
            P[depth] = NP[i];
            dfs(depth+1);
            visit[i] = false;
    }
}

int main(void){
    scanf("%d %d %d", &N, &M, &K);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            scanf("%d", &NP[i][j]);
    dfs(0);
}