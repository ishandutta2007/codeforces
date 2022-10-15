#include<bits/stdc++.h>
using namespace std;
#define re register ll
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
#define I inline void
#define IN inline ll
template<class D>I read(D &res){
	res=0;register D g=1;register char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')g=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	res*=g;
}
const ll INF=1e16;
typedef pair<ll,ll>pii;
pii nd;
ll P,n,m,k,p,h[101000],a[101000],b[101000];
priority_queue<pii,vector<pii>,greater<pii> >q;
ll ck(ll x){
	while(!q.empty())q.pop();
	F(i,1,n){
		if((h[i]+a[i]*m)>x){q.emplace(make_pair(x/a[i],i));b[i]=x;}
	}
	F(i,1,m){
		if(q.empty())return 1;
		if(q.top().first<i)return 0;
		F(j,1,k){
			nd=q.top();q.pop();P=nd.second;
			b[P]+=p;
			if(h[P]+a[P]*m>b[P])q.emplace(make_pair(b[P]/a[P],P));
			if(q.empty())return 1;
		}
	}
	if(q.empty())return 1;
	return 0;
}
IN divided(ll x,ll y){
	if(x==y)return x;
	re mid=(x+y)>>1;
	if(ck(mid))y=mid;
	else x=mid+1;
	return divided(x,y);
}
int main(){
	read(n);read(m);read(k);read(p);
	F(i,1,n)read(h[i]),read(a[i]);
	cout<<divided(0,INF);
	return 0;
}