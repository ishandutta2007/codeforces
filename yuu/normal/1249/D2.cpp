#include <bits/stdc++.h>
using namespace std;
int n, k;
vector <pair <pair <int, int>, int>> p;
set <pair <int, int>> s;
int main(){
    cin>>n>>k;
    p.resize(n);
    int cnt=0;
    for(auto &x: p){
        cin>>x.first.first>>x.first.second;
        cnt++;
        x.second=cnt;
    }
    sort(p.begin(), p.end());
    vector <int> bad;
    int old=0;
    for(auto x: p){
        if(x.first.first!=old){
            while(s.size()>k){
                bad.push_back((*s.rbegin()).second);
                s.erase(*s.rbegin());
            }
            while((!s.empty())&&((*s.begin()).first<x.first.first)) s.erase(*s.begin());
        }
        s.insert(make_pair(x.first.second, x.second));
        old=x.first.first;
    }
    while(s.size()>k){
        bad.push_back((*s.rbegin()).second);
        s.erase(*s.rbegin());
    }
    sort(bad.begin(), bad.end());
    cout<<bad.size()<<'\n';
    for(auto x: bad) cout<<x<<' ';
    cout<<'\n';
}