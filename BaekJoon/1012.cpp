#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string.h>


using namespace std;


int T, M, N, K;
bool graph[51][51] = {0,};
bool visited[51][51] = {0,};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y)
{
	visited[x][y] = true;
	for(int i=0; i<4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M)
		{
			if (graph[nx][ny] == 1)
			{
				if (!visited[nx][ny])
				{
					dfs(nx, ny);
				}
			}
		}
	}
}
int main(void)
{
	int x, y;

	cin >> T;
	for(int t=0; t<T; t++)
	{
		memset(graph, 0, sizeof(graph));
		memset(visited, 0, sizeof(visited));

		int cnt = 0;
		cin >> N >> M >> K;
		for(int i=0; i<K; i++)
		{
			cin >> x >> y;
			graph[x][y] = 1;
		}
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<M; j++)
			{
				if(graph[i][j] == 1)
				{
					if (!visited[i][j])
					{
						cnt++;
						dfs(i, j);
					}
				}
			}	
		}
		cout << cnt << '\n';
	}
}