#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
#include<cmath>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int N, M, V;
vector<vector<int>> p;
bool result = false;
vector<bool> visit;
void dfs(int depth, int start){

    visit[start] = true;
    printf("%d ", start);
    int tmp;
    for(int i=0; i<p[start].size(); i++){
        tmp = p[start][i];
        if(!visit[tmp]){
            dfs(depth+1, tmp);
        }
    }
}
void bfs(int start){
    queue<int> queue;

    visit[start] = true;
    queue.push(start);
    int tmp, front;
    while(queue.size() > 0){
        front = queue.front();
        queue.pop();
        printf("%d ", front);
        for(int i=0; i<p[front].size(); i++){
            tmp = p[front][i];
            if(!visit[tmp]){
                queue.push(tmp);
                visit[tmp] = true;
            }
        }
    }
}
int main(void){
    scanf("%d %d %d", &N, &M, &V);
    p.resize(N+1);
    visit.resize(N+1);
    int a, b;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        p[a].push_back(b);
        p[b].push_back(a);
    }
    for(int i=0; i<=N; i++)
        sort(p[i].begin(), p[i].end());
    fill(visit.begin(), visit.end(), false);
    dfs(1, V);
    printf("\n");
    fill(visit.begin(), visit.end(), false);

    bfs(V);
    

}