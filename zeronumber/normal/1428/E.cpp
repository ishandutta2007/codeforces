#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,int> pi;
const int maxn=1e6+11;
const int M=1000000007;
int n,k,b[maxn];
ll a[maxn],ans;

ll sqr(ll x){return x*x;}
ll calc(ll n,ll k){
    int m=n%k;
    return sqr(n/k)*(k-m)+sqr(n/k+1)*m;
}
priority_queue<pi> q;
int main(){
    cin >> n >> k;
    for (int i=1;i<=n;i++) {
        cin >> a[i];
        b[i]=1; ans+=a[i]*a[i];
        q.push((pi){calc(a[i],1)-calc(a[i],2),i});
    }
    for (int i=0;i<k-n;i++){
        pi tmp=q.top(); q.pop();
        ans-=tmp.F;
        int x=tmp.S;
        b[x]++; q.push((pi){calc(a[x],b[x])-calc(a[x],b[x]+1),x});
    }
    cout << ans << endl;
}