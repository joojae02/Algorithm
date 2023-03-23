#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int N, M;
vector<int> p[10001];
vector<bool> visit;
vector<int> result;
int ans = 0;

void dfs(int n)
{
    result[n]++;
    ans = max(ans, result[n]);
    for(int i=0; i < p[n].size(); i++){
        int next = p[n][i];

        if(!visit[next]){
            visit[next] = 1;
            dfs(next);
        }
    }
}

int main(void)
{
    cin >> N >> M;
    int n, m;

    result=vector<int> (N +1 ,0);

    for(int i =1; i<= M; i++)
    {
        cin >> n >> m;
        p[n].push_back(m);
    }

    for(int i=1;i<=N;i++){
        visit = vector<bool> (N+1 ,0);
        visit[i] = 1;
        dfs(i);
    }

    for(int i=1; i<= N; i++)
    {
        if (result[i] == ans)
            cout << i << " ";
    }
}