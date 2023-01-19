#include<iostream>
#include<vector>
#include <algorithm>
#include<cmath>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;
int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
int main(void){
    int T;
    int j;
    int M, N, x, y;

    scanf("%d", &T);
    for(int i=0; i<T; i++)
    {
        scanf("%d %d %d %d", &M, &N, &x, &y);
        int limit = lcm(M, N);
        for(j= x; j<=limit; j+=M){
            int temp = (j%N == 0) ? N : j % N;
            if (temp == y) {
                printf("%d\n", j);
                break;
            }
        }
        if (j > limit)
            printf("-1\n");
    }
}