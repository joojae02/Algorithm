#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
#include<cmath>
#include<cstdio>

#define _CRT_SECURE_NO_WARNINGS
#define INT_MAX 2147483647
using namespace std;
int N, S;
int input[21] = {0,};
int visit[21] = {0,};
int ans = 0;
int sum =0;
void func(int nx,int x)
{
	if (sum == S && nx != 0)		
	{
		ans++;
	}

	for (int i = 0 ; i < N; i++)
	{
		if (visit[i] || x>i) continue;	

		visit[i] = true;
		sum += input[i];
		func(nx + 1,i);

		visit[i] = false;
		sum -= input[i];
	}
}

int main(void){
    scanf("%d %d", &N, &S);
    for(int i=0; i<N; i++){
        scanf("%d", &input[i]);
    }

    func(0,0);
    printf("%d", ans);

}