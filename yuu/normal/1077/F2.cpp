#include <bits/stdc++.h>
using namespace std;
int n, k, x;
long long f[5001];
int a[5001];
int main(){
    cin>>n>>k>>x;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) f[i]=-1e18;
    for(int cnt=1; cnt<=x; cnt++){
        deque <pair <long long, int>> q;
        q.push_back(make_pair(f[0], 0));
        f[0]=-1e18;
        for(int i=1; i<=n; i++){
            while(q.front().second<i-k) q.pop_front();
            long long now=q.front().first+a[i];
            while((!q.empty())&&(q.back().first<=f[i])) q.pop_back();
            q.push_back(make_pair(f[i], i));
            f[i]=now;
            //cout<<f[i]<<" \n"[i==n];
        }
    }
    long long ans=-1;
    for(int i=n-k+1; i<=n; i++) ans=max(ans, f[i]);
    cout<<ans<<'\n';
}