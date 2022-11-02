#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const int maxn=1e6+12;
const int M=1000000007;
int cnt[20],n,a[maxn];
ll ans;
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        int x;scanf("%d",&x);
        for (int j=0;j<20;j++) if (x&(1<<j)) cnt[j]++;
    }
    for (int i=0;i<20;i++)
        for (int j=0;j<cnt[i];j++) a[j]|=1<<i;
    for (int i=0;i<n;i++) ans+=(ll)a[i]*a[i];
    printf("%lld\n",ans);
    return 0;
}