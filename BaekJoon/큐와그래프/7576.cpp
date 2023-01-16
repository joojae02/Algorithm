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
int input[1001][1001] ={0,};
int visit[1001][1001] ={0,};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int, int> > q; 

void BFS() 
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop(); 
		for (int i = 0; i < 4; i++) 
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (0 < next_x && next_x <= N && 0 < next_y && next_y <= M)
			{
				if (input[next_x][next_y] == 0 && visit[next_x][next_y] == 0)
				{
                    visit[next_x][next_y] = 1;
                    input[next_x][next_y] = input[x][y] + 1;
					q.push(make_pair(next_x, next_y)); 
				}

			}

		}
	}

}
int main(void){
    scanf("%d %d", &M, &N);
    int tmp;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            scanf("%d", &tmp);
            if(tmp == 1)
                q.push(make_pair(i,j));
            input[i][j] = tmp;
        }
    }
    if(q.size() == M*N){
        printf("0\n");
        return 0;
    }

    BFS();

    int result = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(input[i][j] == 0){
                printf("-1\n");
                return 0;
            }
            if (result < input[i][j]) {
                result = input[i][j];
            }
        }
    }       
    printf("%d\n", result-1);

}