#include<iostream>
#include<vector>
#include <algorithm>
#include<cmath>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;
int N, M;
int P[9] = {0,};
bool visit[9] = {0,};
void dfs(int depth){
    if(depth == M){
        for(int i=0; i<M; i++){
            printf("%d ", P[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 1; i <= N; i++)
    {
        if(!visit[i])
        {
            visit[i] = true;
            P[depth] = i;
            dfs(depth+1);
            visit[i] = false;
        }
    }
}

int main(void){
    scanf("%d %d", &N, &M);
    dfs(0);
}