#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<char, vector<char>>> key;
int N;

bool sorting(pair<char, vector<char>> p, pair<char, vector<char>> p2) { // compare 함수
    if (p.first >= p2.first) 
        return p.second > p2.second;
    return p.first < p2.first;
}
int main(void)
{
    string k, c;
    cin >> k >> c;
    int size = c.length() / k.length();
    for (int i= 0; i< k.length(); i++)
    {
        vector<char> tmp(0);
        key.push_back(make_pair(k[i], tmp));
    }
    int a = 0;
    for (int i= 0; i< c.length(); i++)
        key[i / k.length()].second.push_back(c[i]);

    //sort(key.begin(), key.end());
    for (int i= 0; i< k.length(); i++)
    {
        for(int j = 0; j < key[i].second.size(); j++)
            cout << j<<" : "<<key[i].second[j];
    }
}