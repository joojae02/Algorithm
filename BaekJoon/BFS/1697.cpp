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

void BFS(int next, int x) 
{
    if(0 <= next&&next < 100001){
        if (input[next] == 0)
        {
            input[next]= input[x] + 1;
            q.push(next); 
        }
    }
}
int main(void){
    scanf("%d %d",&N,&K);
    q.push(N);
    input[N] = 1;
	while (!q.empty())
	{
		int x = q.front();
		
		q.pop(); 
        BFS(x*2, x);
        BFS(x-1, x);
        BFS(x+1, x);
    }
    printf("%d\n", input[K]-1);

}