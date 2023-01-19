#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
#include<cmath>
#include<cstdio>


#define _CRT_SECURE_NO_WARNINGS
#define INT_MAX 2147483647
using namespace std;

int N = 0,K=0;
int input[100001] = {0,};
int visit[100001] = {0,};
queue<int> q; 

void BFS(int next, int x, int check) 
{
    if(0 <= next&&next < 100001){
        if (input[next] == 0)
        {
            input[next]= input[x] + check;
            visit[next] = x;
            q.push(next); 
        }
    }
}
int main(void){
    scanf("%d %d",&N,&K);
    for(int i=0; i<100001; i++)
        visit[i] = i;
    q.push(N);
    input[N] = 1;
	while (!q.empty())
	{
		int x = q.front();
		q.pop(); 
        BFS(x*2, x, 0);
        BFS(x-1, x, 1);
        BFS(x+1, x, 1);
    }
    printf("%d\n", input[K]-1);


}