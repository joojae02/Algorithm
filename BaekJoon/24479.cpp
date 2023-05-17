#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int N, M, R;
bool visited[100001] = {false,};
int order[100001];
vector<int> graph[100001];
int s=0;

void dfs(int start){
    if(visited[start]){
        return;
    }
    visited[start] = true;
    s++;
    order[start] = s;
    for(int i = 0;i<graph[start].size();i++){
        int y = graph[start][i];
        dfs(y);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> R;
    int x, y;
    for (int i=0; i<M; i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i=1; i <= N; i++) 
        sort(graph[i].begin(), graph[i].end(), greater<int>());
    dfs(R);
    for (int i=1; i<=N; i++)
        cout << order[i] << '\n';
}