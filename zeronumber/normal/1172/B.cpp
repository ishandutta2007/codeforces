#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+7;
const ll M=998244353;
int d[maxn],n,u,v;
ll f[maxn],ans;
int main(){
    cin >> n;
    for (int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        d[u]++; d[v]++;
    }
    ans=n; f[0]=1;
    for (int i=1;i<=n;i++) f[i]=f[i-1]*i%M;
    for (int i=1;i<=n;i++) ans=ans*f[d[i]]%M;
    cout << ans << endl;
    return 0;
}