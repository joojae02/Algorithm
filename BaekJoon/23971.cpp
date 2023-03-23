#include <iostream>

using namespace std;

int H, W, N, M;
int ans = 0;

int main(void)
{
    cin >> H >> W >> N >> M;
    cout << ((H - 1) / (N + 1) + 1) * ((W - 1) / (M + 1) + 1);
}