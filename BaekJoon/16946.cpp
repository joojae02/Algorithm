#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <string.h>
#include <queue>


using namespace std;

int N, M;
int map[1001][1001] = {0,};
bool visited[1001][1001] = {0,};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(pair<int, int> p)
{
    queue<pair<int, int> > q;
    vector<pair<int, int> > v;
    int cnt = 1;
    int x, y;
    int nx, ny;
    
    q.push(p);
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        visited[x][y] = true;
        q.pop();
        for (int i=0; i<4; i++)
        {
            nx = x + dx[i];
            ny = y + dy[i];
            if (nx > 0 && nx <= N && ny > 0 && ny <= M)
            {    
                if (visited[nx][ny] == false && map[nx][ny] == 0)
                {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                    cnt++;
                }
                else if (visited[nx][ny] == false && map[nx][ny] != 0)
                {
                    visited[nx][ny] = true;
                    v.push_back(make_pair(nx, ny));
                }
            }
        }
    }
    for(int i=0; i<v.size(); i++)
    {
        map[v[i].first][v[i].second] += cnt;
        visited[v[i].first][v[i].second] = false;
    }
}

int main(void)
{
    int tmp;
    char c;
    cin >> N >> M;

    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=M; j++)
        {
            cin >> c;
            map[i][j] = c - '0';
        }
    }
    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=M; j++)
        {
            if (map[i][j] == 0 && !visited[i][j])
                bfs(make_pair(i, j));
        }
    }
    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=M; j++)
        {
            cout << map[i][j];
        }
        cout << '\n';
    }
}