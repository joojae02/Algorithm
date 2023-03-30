#include <iostream>

using namespace std;

int N, K;
int coin[11] = {0,};
int result = 0;

int main(void)
{
    cin >> N >> K;
    for (int i=0; i< N; i++)
        cin >> coin[i];
    for (int i=N-1; i>=0; i--)
    {
        result += K / coin[i];
        K %= coin[i];
    }
    cout << result;
}