#include <bits/stdc++.h>
using namespace std;
#define left Kafuu
#define right Chino
int n;
string l, r;
vector <int> left[256];
vector <int> right[256];
vector <int> releft;
vector <int> reright;
vector <pair <int, int>> ans;
int main(){
    cin>>n>>l>>r;  
    {
        int pos=0;
        for(auto c: l){
            pos++;
            left[c].push_back(pos);
        }
    }
    {
        int pos=0;
        for(auto c: r){
            pos++;
            right[c].push_back(pos);
        }
    }
    
    for(char c='a'; c<='z'; c++){
        while(left[c].size()&&right[c].size()){
            ans.push_back(make_pair(left[c].back(), right[c].back()));
            left[c].pop_back();
            right[c].pop_back();
        }
        for(auto pos: left[c]) releft.push_back(pos);
        for(auto pos: right[c]) reright.push_back(pos);
    }
    while(left['?'].size()&&reright.size()){
        ans.push_back(make_pair(left['?'].back(), reright.back()));
        reright.pop_back();
        left['?'].pop_back();
    }
    while(right['?'].size()&&releft.size()){
        ans.push_back(make_pair(releft.back(), right['?'].back()));
        releft.pop_back();
        right['?'].pop_back();
    }
    while(left['?'].size()&&right['?'].size()){
        ans.push_back(make_pair(left['?'].back(), right['?'].back()));
        left['?'].pop_back();
        right['?'].pop_back();
    }
    cout<<ans.size()<<'\n';
    for(auto p: ans) cout<<p.first<<' '<<p.second<<'\n';
}