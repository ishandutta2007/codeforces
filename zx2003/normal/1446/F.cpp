#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const double eps=1e-12,pi=acos(-1);
inline int dcmp(const double&x){return fabs(x)>eps?x>0?1:-1:0;}
inline double norm(const double&x){return x>pi?x-2*pi:x<=-pi?x+2*pi:x;}
int n,i,p3[N],p4[N],x,y;
long long k,tot;
double l=0,r=2e4,m,d[N],ang[N];
int bi[N*2];
pair<double,int*>aa[N*2];int xb,zz;
inline void add(int x){for(;x<=zz;x+=x&-x)++bi[x];}
inline int ask(int x){int ans=0;for(;x;x-=x&-x)ans+=bi[x];return ans;}
bool bb[N];
vector<int>ve[N*2];
int main(){
	scanf("%d%lld",&n,&k);for(i=1;i<=n;++i)scanf("%d%d",&x,&y),d[i]=sqrt(x*x+y*y),ang[i]=atan2(y,x);
	for(;r-l>1e-8;){
		m=(l+r)/2;xb=zz=0;tot=1ll*n*(n-1)/2;memset(bb+1,0,n);
		for(i=1;i<=n;++i)if(dcmp(d[i]-m)>0){
			double A=acos(m/d[i]);
			aa[++xb]={norm(ang[i]-A),p3+i};aa[++xb]={norm(ang[i]+A),p4+i};bb[i]=1;
		}
		sort(aa+1,aa+xb+1);
		for(i=1;i<=xb;++i)*aa[i].second=zz+=i==1 || dcmp(aa[i].first-aa[i-1].first)>0;
		for(i=1;i<=zz;++i)ve[i].clear();memset(bi+1,0,zz<<2);
		for(i=1;i<=n;++i)if(bb[i]){
			if(p3[i]>p4[i])swap(p3[i],p4[i]);
			if(p3[i]<p4[i])ve[p3[i]].push_back(p4[i]);
		}
		for(i=1;i<=zz;++i){
			for(int x:ve[i])tot-=ask(x-1)-ask(i);
			for(int x:ve[i])add(x);
		}
		if(tot>=k)r=m;else l=m;
	}
	printf("%.8f\n",l);
}