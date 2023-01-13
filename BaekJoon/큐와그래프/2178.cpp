#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
#include<cmath>
#include<cstdio>

#define _CRT_SECURE_NO_WARNINGS
#define INT_MAX 2147483647
using namespace std;

int N,M;
int input[101][101] ={0,};
int check[101][101] = {0,};
int visit[101][101] = {0,};
int result = INT_MAX;
int t = 0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void BFS(int x, int y) 
{
	visit[x][y] = 1;

	queue<pair<int, int> > q; 
	q.push(make_pair(x, y)); 
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop(); 

		for (int i = 0; i < 4; i++) 
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (0 < next_x && next_x <= N && 0 < next_y && next_y <= M) // 미로의 범위
			{
				// 길이 존재하고 이전에 방문했던적이 없는 경우
				if (input[next_x][next_y] == 1 && !visit[next_x][next_y])
				{
					check[next_x][next_y] = check[x][y] + 1;
					visit[next_x][next_y] = 1;
					q.push(make_pair(next_x, next_y)); 
				}

			}

		}
	}

}
int main(void){
    scanf("%d %d", &N, &M);
    int tmp;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            scanf("%1d", &tmp);
            input[i][j] = tmp;
        }
    }
    BFS(1,1);
    printf("%d\n", check[N][M] + 1);

}