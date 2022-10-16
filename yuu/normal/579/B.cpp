#include <bits/stdc++.h>
using namespace std;
int n;
vector <pair <int, pair <int, int>>> v;
int team[801];
int main(){
    cin>>n;
    for(int i=1; i<=n*2; i++){
        for(int j=1; j<i; j++){
            int c;
            cin>>c;
            v.push_back(make_pair(c, make_pair(i, j)));
        }
    }
    sort(v.begin(), v.end());
    int ans=0;
    while(!v.empty()){
        if(!team[v.back().second.first]&&!team[v.back().second.second]){
            team[v.back().second.first]=v.back().second.second;
            team[v.back().second.second]=v.back().second.first;
        }
        v.pop_back();
    }
    for(int i=1; i<=n*2; i++) cout<<team[i]<<" ";
}