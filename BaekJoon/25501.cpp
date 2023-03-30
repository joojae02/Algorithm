#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int T;
int check = 0;
int recursion(const char *s, int l, int r){
    check++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    check = 0;
    return recursion(s, 0, strlen(s)-1);
}

int main(void)
{
    cin >> T;
    char tmp[1001];
    for(int i=0; i<T;i++)
    {
        cin >> tmp;
        cout << isPalindrome(tmp) << " ";
        cout << check << '\n';
    }

}  