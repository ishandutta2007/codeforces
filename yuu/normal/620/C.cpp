#include <bits/stdc++.h>
using namespace std;
int n, a;
set <int> s;
int main(){
    int start=1;
    vector <pair <int, int>> ans;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a;
        s.insert(a);
        if(s.size()<i-start+1){
            ans.push_back({start, i});
            start=i+1;
            s.clear();
        }
    }
    if(ans.empty()){
        cout<<-1<<'\n';
    }
    else{
        ans.back().second=n;
        cout<<ans.size()<<'\n';
        for(auto &x: ans){
            cout<<x.first<<' '<<x.second<<'\n';
        }
    }
}