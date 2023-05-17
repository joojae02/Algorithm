#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string.h>


using namespace std;


int A, B;
int answer = 2147483647;
int check = 0;
void solve(long long tmp, int cnt)
{
    if (tmp == B)
    {
        if (answer > cnt)
            answer = cnt;
        check = 1;
        return ;
    }
    else if (tmp > B)
        return ;
    solve(tmp*2, cnt+1);
    solve(tmp*10 + 1, cnt+1);
}
int main(void)
{
    cin >> A >> B;
    solve(A, 1);
    if (check)
        cout << answer;
    else
        cout << -1;
}