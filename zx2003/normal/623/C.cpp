#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const int N=1e5+5;
inline pii operator+(const pii&a,const pii&b){return pii(min(a.first,b.first),max(a.second,b.second));}
ll l,r,m;
int n,x[N],y[N],i,j,k,a[N],nxt[N],pre[N],mm;
pii s1[N],s2[N];
inline bool cmp(const int&i,const int&j){return x[i]<x[j];}
inline ll sqr(int x){return 1ll*x*x;}
inline bool ck(const pii&a,pii b){
	b.first=min(b.first,0);b.second=max(b.second,0);
	return a.second-a.first<=mm && b.second-b.first<=mm && (b.first>2e8 || sqr(max(a.second,-a.first))+
		sqr(max(b.second,-b.first))<=m);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;for(i=1;i<=n;++i)cin>>x[i]>>y[i],a[i]=i;x[0]=1e9;
	sort(a+1,a+n+1,cmp);s1[0]=s2[n+1]=pii(1e9,-1e9);
	for(i=1;i<=n;++i)s1[i]=s1[i-1]+pii(y[a[i]],y[a[i]]),pre[i]=x[a[i]]==x[a[i-1]]?pre[i-1]:i-1;
	for(i=n;i;--i)s2[i]=s2[i+1]+pii(y[a[i]],y[a[i]]),nxt[i]=x[a[i]]==x[a[i+1]]?nxt[i+1]:i+1;
	for(l=0,r=sqr(min(x[a[n]]-x[a[1]],s1[n].second-s1[n].first));l<r;){
		bool fl=0;
		m=(l+r)>>1;mm=sqrt(m);for(;1ll*mm*mm>m;--mm);
		for(i=n;i && x[a[i]]>mm;--i);
		for(j=i,k=1;!fl && i>=k && x[a[i]]>=0;--i){
			for(;j && x[a[i]]-x[a[j]]<=mm;--j);++j;
			for(;k<i && abs(x[a[k]])>abs(x[a[i]]);++k);
			if(x[a[i]]>=-x[a[j]] && ck(pii(min(0,x[a[j]]),x[a[i]]),s1[pre[j]]+s2[nxt[i]]))
				fl=1;
			if(k<=i && ck(pii(min(0,x[a[k]]),x[a[i]]),s1[pre[k]]+s2[nxt[i]]))
				fl=1;
		}
		for(i=1;i<=n && x[a[i]]<-mm;++i);
		for(j=i,k=n;!fl && i<=k && x[a[i]]<=0;++i){
			for(;j<=n && x[a[j]]-x[a[i]]<=mm;++j);--j;
			for(;k>i && abs(x[a[k]])>abs(x[a[i]]);--k);
			if(x[a[j]]<=-x[a[i]] && ck(pii(x[a[i]],max(0,x[a[j]])),s1[pre[i]]+s2[nxt[j]]))
				fl=1;
			if(i<=k && ck(pii(x[a[i]],max(0,x[a[k]])),s1[pre[i]]+s2[nxt[k]]))
				fl=1;
		}
		if(fl)r=m;else l=m+1;
	}
	cout<<l<<endl;
	return 0;
}