#include<bits/stdc++.h>
using namespace std;
typedef vector<int>V;
const int N=3e5+5;
int n,nn,a[N],i,j,g[N],id[N],zz;
int gfa(int x){return g[x]==x?x:g[x]=gfa(g[x]);}
V f[N],v;
pair<int,int>aa[N];
V uni(V a,V b,int x){
	x=a.size()+b.size()-x>>1;
	int j;
	for(j=0;j<=x;++j)g[gfa(a[j])]=gfa(b[j]);
	V ret={a[0]};
	for(j=a.size()-1;j>=x;--j)ret.push_back(a[j]);
	for(j=x+1;j<b.size();++j)ret.push_back(b[j]);
	return ret;
}
V uni3(V a,V b,V c){
	g[gfa(a[0])]=g[gfa(b[0])]=gfa(c[0]);
	g[gfa(a[1])]=gfa(b[1]);
	g[gfa(a[2])]=gfa(c[1]);
	g[gfa(b[2])]=gfa(c[2]);
	return {a[1],a[2],b[2]};
}
int calc(int x,int y){
	if(x<y)swap(x,y);
	return x==y?4:x-y+2;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",a+i);
		f[i].resize(a[i]);
		for(j=0;j<a[i];++j)f[i][j]=++nn;
		aa[i]={a[i],i};
	}
	for(i=1;i<=nn;++i)g[i]=i;
	sort(aa+1,aa+n+1);
	v=f[aa[n].second];
	int tot=0;for(i=1;i<n;++i)tot+=aa[i].first-1;
	if(tot<=aa[n].first-1 && aa[n].first>3){
//		for(i=n-1;i;--i)v=uni(v,f[aa[i].second],calc(aa[i].first,v.size()));
		int lst=0,j,p,q,r=aa[n].second;
		for(i=1;i<n;++i){
			tie(p,q)=aa[i];
			for(j=0;j<p;++j)g[gfa(f[q][j])]=gfa(f[r][lst++]);--lst;
		}
	}else{
		for(i=n-1;i;--i){
//			if(aa[i].first==3)break;
			if(v.size()==3)break;
			int x=v.size()-aa[i].first+2,y=aa[i-1].first;
			if(v.size()==aa[i].first)x=4;
			if(x>4 && x>y){
				int l1=v.size(),l2=aa[i].first;
				for(j=0;j<l2;++j)g[gfa(f[aa[i].second][j])]=gfa(v[l1-l2+j]);
				int tt=v.back();for(;v.size()>=l1-l2+2;v.pop_back());v.push_back(tt);
				continue;
			}
			if(x<y)x=(y-x)%2==0?y:y+1;
			v=uni(v,f[aa[i].second],x);
		}
		if(i){
			V u=f[aa[1].second];
			for(j=2;j+1<=i;j+=2)u=uni3(u,f[aa[j].second],f[aa[j+1].second]);
			if(j==i){
					if(v.size()==3)u=uni3(u,f[aa[i].second],v);
					else u=uni(u,f[aa[i].second],4),v=uni(u,v,calc(u.size(),v.size()));
			}else v=uni(u,v,calc(u.size(),v.size()));
		}
	}
	for(i=1;i<=nn;++i)if(gfa(i)==i)id[i]=++zz;
	printf("%d\n",zz);
	for(i=1;i<=n;++i){for(int x:f[i])printf("%d ",id[gfa(x)]);puts("");}
	return 0;
}