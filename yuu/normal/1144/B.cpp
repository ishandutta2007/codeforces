#include <bits/stdc++.h>
using namespace std;
int n, a;
vector <int> x[2];
int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a;
        x[a%2].push_back(a);
    }
    sort(x[0].begin(), x[0].end());
    sort(x[1].begin(), x[1].end());
    if(x[0].size()<x[1].size()) swap(x[0], x[1]);
    long long ans=0;
    for(int i=int(x[0].size()-x[1].size())-2; i>=0; i--) ans+=x[0][i];
    cout<<ans<<'\n';
}