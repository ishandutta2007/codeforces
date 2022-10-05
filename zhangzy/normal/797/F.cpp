#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define P first
#define S second
#define pq priority_queue
using namespace std;

ll n,m,x,y,las;
ll ans;
pll a[10100],o,tp;
pq<pll>q;
pq<ll>q2;

int main(){
  cin>>n>>m;
	for (int i=las=n;i--;) cin>>a[i].P, a[i].S=-1;
	for (int i=m;i--;) cin>>a[n].P>>a[n].S, las-=a[n++].S;
	if (las>0) return 0*puts("-1");
	sort(a,a+n);
	ll c,t; q.push((pll){-1e12,1e5});
	for (int i=0;i<n;++i){
		o=a[i];
		if (~o.S){
			for (;o.S&&!q2.empty()&&(t=q2.top())>o.P;--o.S){
				ans-=c=t-o.P; q2.pop();
				q.push((pll){o.P-c,1});
			}
			if (o.S) q.push(o);
		}else{
			tp=q.top(); q.pop();
			c=o.P-tp.P;
			if (--tp.S) q.push(tp);
			ans+=c; q2.push(o.P+c);
		}
	}
	cout<<ans;
}