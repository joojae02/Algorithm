#include<iostream>
#include<vector>
#include <algorithm>
#include<cmath>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

vector<bool> vcheck(1000001, true);
int main(void) 
{
    for(int i = 3; i*i <= 1000000; i += 2){
        if (!vcheck[i]) continue;
        for (int j=i*i ; j<=1000000; j+=i) 
            vcheck[j] = false;
    }
    while(1){
        int tmp = -1;
        int a = 0;
        bool check = false;
        scanf("%d", &tmp);
        if(tmp == 0)
            break;
        for(int i = 3; i <= tmp / 2; i+=2){
            if(vcheck[i]){
                a = tmp - i;
                if(vcheck[a]){
                    check = true;
                    printf("%d = %d + %d\n", tmp, i, a);
                    break;
                }
            }
        }
        if(!check)
            printf("Goldbach's conjecture is wrong.");
    }
}