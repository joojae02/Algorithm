#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
#include<cmath>
#include<cstdio>

#define _CRT_SECURE_NO_WARNINGS
#define INT_MAX 2147483647
using namespace std;
//1000000001
int N;
int A[12] = {0,};
int op[4] = {0,};
int maxN = -1000000001;
int minN = 1000000001;

void func(int depth, int num)
{
	if(depth == N){
		if(num > maxN)
			maxN = num;
		if(num < minN)
			minN = num;
		return;
	}
	for(int i=0; i<4; i++){
		if(op[i] > 0){
			op[i]--;
			if(i == 0){
				func(depth+1, num+A[depth]);
			}
			else if(i == 1){
				func(depth+1, num-A[depth]);
			}
			else if(i == 2){
				func(depth+1, num*A[depth]);
			}
			else if(i == 3){
				func(depth+1, num/A[depth]);
			}
			op[i]++;
		}
	}
}

int main(void){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &A[i]);
    }
	for(int i=0; i<4; i++){
        scanf("%d", &op[i]);
    }
    func(1,A[0]);
	printf("%d\n", maxN);
	printf("%d\n", minN);
}