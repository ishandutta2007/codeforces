#include <bits/stdc++.h>
using namespace std;
vector <pair <int, int>> v;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int sum=0;
    string ans;
    for(int i=0, a, g; i<n; i++){
        ans+='A';
        cin>>a>>g;
        sum+=a;
        v.push_back({-g-a, i});
    }
    sort(v.begin(), v.end());
    for(auto &x: v){
        if(abs(sum)<=500) continue;
        sum+=x.first;
        ans[x.second]='G';
    }
    cout<<ans<<'\n';
}