#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
#include<cmath>
#include<cstdio>

#define _CRT_SECURE_NO_WARNINGS
#define INT_MAX 2147483647
using namespace std;
int N;
int input[21] = {0,};
int visit[21] = {0,};
int sum =0;
bool result[10000000] = {0,};
//vector<int> result;
void func(int nx,int x)
{
	if(sum != 0){
		result[sum] = true;
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
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &input[i]);
    }
	sort(&input[0], &input[0] + N);
    func(0,0);
	//sort(result.begin(), result.end());

	int i = 1;
	while(1){
		if(result[i] == false){
			printf("%d", i);
			break;
		}
		i++;
	}
}