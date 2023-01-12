#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
#include<cmath>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int N, M;
vector<vector<int>> p;
bool result = false;
vector<bool> visit;
void dfs(int depth, int start){
    visit[start] = true;
    if(depth == 5){
        result = true;
        return;
    }
    int tmp;
    for(int i=0; i<p[start].size(); i++){
        tmp = p[start][i];
        if(!visit[tmp]){
            dfs(depth+1, tmp);
        }
    }
    visit[start] = false;

}
int main(void){
    scanf("%d %d", &N, &M);
    p.resize(N);
    visit.resize(N);
    int a, b;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        p[a].push_back(b);
        p[b].push_back(a);
    }
    for(int i=0; i<N; i++){
        if(result)
            break;
        fill(visit.begin(), visit.end(), false);
        dfs(1, i);
    }
    if(result)
        printf("1");
    else   
        printf("0");

}