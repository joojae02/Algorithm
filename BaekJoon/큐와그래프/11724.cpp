#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
#include<cmath>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int N, M, V;
vector<vector<int>> p;
vector<int> visit;
int result = 0;
void dfs(int start){
    visit[start] = true;
    int tmp;
    for(int i=0; i<p[start].size(); i++){
        tmp = p[start][i];
        if(!visit[tmp]){
            dfs(tmp);
        }
    }
}
int main(void){
    scanf("%d %d", &N, &M);
    p.resize(N+1);
    visit.resize(N+1);
    int a, b;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        p[a].push_back(b);
        p[b].push_back(a);
    }
    fill(visit.begin(), visit.end(), false);

    for(int i=1; i<=N; i++){
        if(!visit[i]){
            dfs(i);
            result += 1;
        }
    }
    printf("%d", result);
}