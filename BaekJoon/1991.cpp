#include <iostream>
#include <map>
#include <algorithm>
#include <string.h>

using namespace std;

int N;

map<char, pair<char, char> > tree;

void preorder(char root)
{
    if (root != '.')
    {
        cout << root;
        preorder(tree[root].first);
        preorder(tree[root].second);
    }
}

void inorder(char root)
{
    if (root != '.')
    {
        inorder(tree[root].first);
        cout << root;
        inorder(tree[root].second);
    }
}

void postorder(char root)
{
    if (root != '.')
    {
        postorder(tree[root].first);
        postorder(tree[root].second);
        cout << root;
    }
}
int main(void)
{
    cin >> N;
    char a, b, c;
    for(int i=0; i<N; i++)
    {
        cin >> a >> b >> c;
        tree[a] = make_pair(b, c);
    }
    preorder('A');
    cout << '\n';

    inorder('A'); 
    cout << '\n';

    postorder('A');
    cout << '\n';
}
