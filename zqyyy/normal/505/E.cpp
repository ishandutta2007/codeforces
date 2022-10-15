#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1e5+7;
int n,m,K;
ll p,h[N],a[N],b[N],c[N];
priority_queue<pair<ll,ll> >q;
inline bool check(ll mid){
    while(!q.empty())q.pop();
    for(int i=1;i<=n;i++){
		c[i]=0;
		if(mid-a[i]*m<h[i])q.push({-(mid/a[i]),i});
    }
    for(int i=1;i<=m && !q.empty();i++)
		for(int j=1;j<=K && !q.empty();j++){
	    	ll t=-q.top().first,id=q.top().second;q.pop();
		    if(t<i)return 0;c[id]++;
		    if(mid+c[id]*p-a[id]*m<h[id])
				q.push({-((mid+c[id]*p)/a[id]),id});
		}
    return q.empty();
}
int main(){
    n=read(),m=read(),K=read(),p=read();
    for(int i=1;i<=n;i++)h[i]=read(),a[i]=read();
    ll l=0,r=6e12;
    while(l<=r){
		ll mid=(l+r)>>1;
		check(mid)?r=mid-1:l=mid+1;
    }
    printf("%lld\n",l);
    return 0;
}