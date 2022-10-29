#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
typedef pair<ll,ll> pii;
typedef long double ldb;
typedef vector<pair<int,ldb> > O;
const int maxn=3e5+10;
const ldb inf=1e20;
int n,Q;
struct line{
	ll k,b;
	int operator<(const line& A)const{return k>A.k;}
}s[maxn];
ldb cal(line a,line b){return (ldb)(a.b-b.b)/(b.k-a.k);}
inline void build(line* S,int n,O& q){
	q.clear();
	std::sort(S,S+n);
	q.push_back(make_pair(0,inf));
	for(int i=1;i<=n-1;++i){
		while(q.size()>1&&q[q.size()-2].second+1e-8l>=cal(S[q.back().first],S[i]))
			q.pop_back();
		q.back().second=cal(S[q.back().first],S[i]);
		q.push_back(make_pair(i,inf));
	}
	for(auto& a:q)a.first+=S-s;
}
int c,wxh[60];
O q[60];
ll cur;
void walk(int x){
	if(!q[x].size())return;
	while(q[x][wxh[x]].second<cur)wxh[x]++;
}
void add(ll k,ll b){
	s[c++]=(line){k,b};
	int i=1,j=0;
	for(;i!=(c&-c);i<<=1,j++)
		q[j].clear();
	build(s+c-i,i,q[j]);
	wxh[j]=0;
	walk(j);
}
void getans(ll o,ll ov){
	ll ans=9e18,ap=9e18;
	auto chk=[&](int x){
		ll a=s[x].k*cur+s[x].b,b=s[x].k;
		if(a<ans)ans=a,ap=b;
		else if(a==ans&&b<ap)ap=b;
	};
	for(int i=0;i<60;++i)if(q[i].size()){
		chk(q[i][wxh[i]].first);
		if(wxh[i])chk(q[i][wxh[i]-1].first);
		if(wxh[i]+1<q[i].size())chk(q[i][wxh[i]+1].first);
		if(wxh[i]+2<q[i].size())chk(q[i][wxh[i]+2].first);
	}
	printf("%lld %lld\n",ap+o,ans+ov);
}

int main(){
	ll l=1,r,b=0;
	scanf("%lld",&r);
	s[c++]=(line){1ll,0ll};
	build(s,1,q[0]);
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;++i){
		int op,x,y;
		scanf("%d%d",&op,&x);
		if(op==1){
			add(l-x,b-cur*(l-x));
			l-=x;
		}else if(op==2){
			add(r+1,b-cur*(r+1));
			r+=x;
		}else{
			scanf("%d",&y);
			cur+=y;
			b+=y*l-x;
			for(int i=0;i<60;++i)walk(i);
		}
		getans(1-l,-b);
	}
}