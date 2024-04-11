#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int N=1e5+5;
int n,k,i,j,q,l,r,ans[N];
vector<pii>v[N],qu[N];
inline pii operator-(const pii&a,const pii&b){
	int x=a.first-b.first,y=a.second-b.second,g=abs(__gcd(x,y));
	return pii(x/g,y/g);
}
map<pii,int>mp;
int bi[N];
inline void add(int x,int v){for(;x<=n;x+=x&-x)bi[x]+=v;}
inline int ask(int x){int ans=0;for(;x;x-=x&-x)ans+=bi[x];return ans;}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&k);v[i].resize(k);
		for(j=0;j<k;++j)scanf("%d%d",&v[i][j].first,&v[i][j].second);
	}
	scanf("%d",&q);
	for(i=1;i<=q;++i)scanf("%d%d",&l,&r),qu[l].push_back(pii(r,i));
	for(i=n;i;--i){
		add(i,v[i].size());
		for(j=0;j<v[i].size();++j){
			pii dt=j?v[i][j]-v[i][j-1]:v[i][0]-v[i].back();
			auto it=mp.insert(make_pair(dt,0));
			if(!it.second)add(it.first->second,-1);
			it.first->second=i;
		}
		for(pii u:qu[i])ans[u.second]=ask(u.first);
	}
	for(i=1;i<=q;++i)printf("%d\n",ans[i]);
	return 0;
}