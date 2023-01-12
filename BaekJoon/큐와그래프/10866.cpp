#include<iostream>
#include<vector>
#include<deque>
#include <algorithm>
#include<cmath>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int N;
deque<int> q; 

int main(void){
    scanf("%d", &N);
    string input;
    int num;
    for(int i=0; i<N; i++){
        cin>>input;
        if(input == "push_front"){
            cin>>num;
            q.push_front(num);
        }
        else if(input == "push_back"){
            cin>>num;
            q.push_back(num);
        }
        else if(input == "pop_front"){
            if(q.empty())
                cout<<"-1"<<'\n';
            else{
                cout<<q.front()<<'\n';
                q.pop_front();
            }
        }
        else if(input == "pop_back"){
            if(q.empty())
                cout<<"-1"<<'\n';
            else{
                cout<<q.back()<<'\n';
                q.pop_back();
            }
        }
        else if(input == "size"){
            cout<<q.size()<<'\n';
        }
        else if(input == "empty"){
            cout<<q.empty()<<'\n';
        }
        else if(input == "front"){
            if(q.empty())
                cout<<"-1"<<'\n';
            else
                cout<<q.front()<<'\n';
        }
        else if(input == "back"){
            if(q.empty())
                cout<<"-1"<<'\n';
            else
                cout<<q.back()<<'\n';
        }
    }
}