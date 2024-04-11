#include <bits/stdc++.h>
using namespace std;
int n;
int a[200002];
int maxl[200002];
int maxr[200002];
vector <int> ans;
int main(){
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    maxl[0]=-1e9;
    for(int i=1; i<=n; i++) maxl[i]=max(maxl[i-1], a[i]);
    maxr[n+1]=-1e9;
    for(int i=n; i>=1; i--) maxr[i]=max(maxr[i+1], a[i]);
    long long sum=0;
    for(int i=1; i<=n; i++) sum+=a[i];
    for(int i=1; i<=n; i++){
        int maxre=max(maxl[i-1], maxr[i+1]);
        if(maxre*2==sum-a[i]) ans.push_back(i);
    }
    cout<<ans.size()<<'\n';
    for(int x: ans) cout<<x<<' ';
}