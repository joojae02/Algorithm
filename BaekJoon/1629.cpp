#include <iostream>

using namespace std;
typedef long long ll;

ll A, B, C;

ll func(ll b)
{
    if (b == 1)
        return A%C;

    ll tmp = func(b/2)%C;
    if (b%2 == 0)
        return tmp * tmp % C;
    else
        return tmp * tmp % C * A % C;
    
}

int main(void)
{
    cin >> A >> B >> C;
    cout << func(B);
}