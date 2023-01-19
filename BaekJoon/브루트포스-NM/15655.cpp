#include<iostream>
#include<vector>
#include <algorithm>
#include<cmath>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;
int N, M;
int P[9] = {0,};
int NP[9];
bool visit[9] = {0,};
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
        if(!visit[i])
        {
            visit[i] = true;
            P[depth] = NP[i];
            dfs(depth+1);
            visit[i] = false;
        }
    }
}

int main(void){
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &NP[i]);
    }
    sort(NP+1, NP+N+1);
    dfs(0);
}