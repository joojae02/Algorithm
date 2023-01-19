#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
#include<cmath>
#include<cstdio>


#define _CRT_SECURE_NO_WARNINGS
#define INT_MAX 2147483647
using namespace std;

int T, I;
int input[301][301] ={0,};
int visit[301][301] ={0,};
int nx, ny;
int tx, ty;
int dx[8] = {1,2,-1,-2, 1,2,-1,-2};
int dy[8] = {2,1,2,1, -2,-1,-2,-1};
queue<pair<int, int> > q; 

void BFS() 
{
    input[nx][ny] = 1;
    visit[nx][ny] = 1;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop(); 
		for (int i = 0; i < 8; i++) 
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (0 <= next_x && next_x < I && 0 <= next_y && next_y < I)
			{
				if (visit[next_x][next_y] == 0)
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
    scanf("%d", &T);
    
    while(T>0){
        scanf("%d", &I);
        scanf("%d %d", &nx, &ny);
        scanf("%d %d", &tx, &ty);
        fill(&input[0][0], &input[300][300], 0);
        fill(&visit[0][0], &visit[300][300], 0);
        q.push(make_pair(nx, ny));
        BFS();

        printf("%d\n", input[tx][ty] -1);
        
        T--;
    }
}