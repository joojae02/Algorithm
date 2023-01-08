#include<iostream>
#include<vector>
#include <algorithm>
#include<cmath>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int N;
int M;
vector<bool> P(10, false);

int check(int n){
    if(n ==0){
        if(P[n])
            return 0;
        else
            return 1;
    }
    int len = 0; 
    while(n > 0){
        if(P[n%10]){
            return 0;
        }
        len += 1;
        n/=10;
    }
    return len;
}
int main(void) {
    cin >> N;
    cin >> M;
    int tmp;
    if(M > 0)
    {
        for(int i = 0; i<M; i++)
        {
            cin >> tmp;
            P[tmp] = true;
        } 
    }
    int result = abs(N - 100);
    for(int i = 0; i<1000000; i++){
        int num = i;
        int len = check(num);
        if(len > 0){
            int press = abs(num - N);
            if(result > len + press)
                result = len + press;
        }
    }
    printf("%d\n", result);
}