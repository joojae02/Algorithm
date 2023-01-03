#include<iostream>
#include<vector>
#include <algorithm>
#include<cmath>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int P[9];

int main(void)
{
    int i, j;
    int sum = 0;
    int a = 0, b = 0;
    for(i = 0; i<9; i++)
    {
        cin >> P[i];
        sum += P[i];
    }
    sort(P, P+9);

    for(i = 0; i<8; i++){
        for(j = i+1; j<9; j++){
            if(sum - P[i] - P[j] == 100){
                for (int k = 0; k < 9; ++k) {
					if (k != i && k != j) {
                        cout << P[k] << '\n';
					}
				}
                return 0;
            }
        }
    }
}