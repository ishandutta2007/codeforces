#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct Line{
	ll k,b;
	Line(ll k=0,ll b=0):k(k),b(b){}
	ll eval(ll x){
		return k*x+b;
	}
};

bool bad(Line L1,Line L2,Line L3){
	return (long double)(L2.b-L1.b)*(L1.k-L3.k)>=(long double)(L1.k-L2.k)*(L3.b-L1.b);
}

ll d[100010];

ll v[100010];
ll s[100010],dp[100010],tmp[100010];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,p;
	cin>>n>>m>>p;
	for(int i=2;i<=n;i++)
		cin>>d[i],d[i]+=d[i-1];
	for(int i=1;i<=m;i++){
		ll h,t;
		cin>>h>>t;
		v[i]=(t-d[h]);
	}
	sort(v+1,v+m+1);
	for(int i=m;i>=1;i--)
		v[i]-=v[1];
	for(int i=1;i<=m;i++)
		s[i]=s[i-1]+v[i];
	for(int i=1;i<=m;i++)
		dp[i]=v[i]*i-s[i];
	for(int P=2;P<=p;P++){
		deque<Line> L;
		L.emplace_back(Line(0,0));
		for(int i=1;i<=m;i++){
			ll x=v[i];
			while(L.size()>=2&&L[0].eval(x)>=L[1].eval(x))
				L.pop_front();
			tmp[i]=L[0].eval(x)+i*x-s[i];
			Line nxt = Line(-i,dp[i]+s[i]);
			while(L.size()>=2&&bad(L[L.size()-2],L.back(),nxt))
				L.pop_back();
			L.emplace_back(nxt);
		}
		swap(tmp,dp);
	}
	cout<<dp[m]<<endl;
}