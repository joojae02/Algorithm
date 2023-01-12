#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
#include<cmath>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int N, M, V, K, E;
vector<vector<int>> p;
vector<int> visit;
int result = 0;
void dfs(int start){
    if(!visit[start]) visit[start] = 1;
    int tmp;
    for(int i=0; i<p[start].size(); i++){
        tmp = p[start][i];
        if(!visit[tmp]){
            if(visit[start] == 1) visit[tmp] = 2;
            else if(visit[start] == 2) visit[tmp] = 1;
            dfs(tmp);
        }
    }
}
bool check(){
    for(int cur = 1; cur <= V; cur++){
        for(int i = 0; i < p[cur].size(); i++){
            int next = p[cur][i];
            if(visit[cur] == visit[next])   return false;
        }
    }
    return true;
}
int main(void){
    scanf("%d", &K);
    for(int t=0; t<K; t++){
        scanf("%d %d", &V, &E);
        p.clear();
        visit.clear();
        p.resize(V+1);
        visit.resize(V+1);
        int a, b;
        for(int i=0; i<E; i++){
            cin>>a>>b;
            p[a].push_back(b);
            p[b].push_back(a);
        }
        fill(visit.begin(), visit.end(), 0);

        for(int i=1; i<=V; i++){
            if(!visit[i]){
                dfs(i);
            }
        }
        if(check()) printf("YES\n");
        else printf("NO\n");
    }
    
    
}