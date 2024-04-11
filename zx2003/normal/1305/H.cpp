#include<bits/stdc++.h>
using namespace std;
void E(){puts("-1 -1");exit(0);}
const int N=1e5+5;
typedef long long ll;
int n,m,l1[N],r1[N],q,x,y,i,j,k,low[N],high[N],a[N],le,ri,md,bee;
ll sa[N],sl[N],sr[N],sa1,sa2,t;
bool ck4(ll*s,ll lm){
	ll mn=1ll<<60;
	for(i=0,j=n;i<=m;++i){
		for(;j && s[j]+1ll*(m-i)*(n-j)>s[j-1]+1ll*(m-i)*(n-j+1);--j);
		mn=min(mn,sa[i]+s[j]+1ll*(m-i)*(n-j));
	}
	return mn>=lm;
}
bool ck3(){
	for(i=1;i<=m;++i)sa[i]=sa[i-1]+a[i];
	return ck4(sl,sl[n]) && ck4(sr,t);
}
bool ck2(int z,int v){
	ll tot=0;
	for(i=1;i<=m;++i)tot+=a[i]=i<z?low[i]:v;if(tot>t)return 0;
	for(i=1;i<z;i=j){
		ll ss=0;for(j=i;j<z && high[j]==high[i];++j)ss+=low[j];int zz=j==z?min(v,high[i]):high[i];
		if(tot+1ll*(j-i)*zz-ss>=t){
			for(;j>i && low[j-1]==high[j-1];)ss-=low[--j];
			if(j>i){
				ll ff=t-tot+ss;
				for(k=i;k<j;++k)a[k]=ff/(j-i);for(k=1;k<=ff%(j-i);++k)++a[j-k];
			}
			tot=t;break;
		}
		tot+=1ll*(j-i)*zz-ss;for(k=i;k<j;++k)a[k]=zz;
	}
	return tot>=t && ck3();
}
bool ck(int z){
	ll v;
	if(z<=bee)v=low[m];else v=max(0ll,t-sa2+m-bee-1)/(m-bee)+low[m];if(v>n)return 0;
	return ck2(z,v);
}
int calc(int z){
	if(z<=bee)return low[m];
	int l,r=high[m],mid;
	if(z<=bee)l=low[m];else l=max(0ll,t-sa2+m-bee-1)/(m-bee)+low[m];
	for(;l<r;)mid=l+r+1>>1,ck2(z,mid)?l=mid:r=mid-1;
	return l;
}
int main(){
	scanf("%d%d",&n,&m);for(i=1;i<=n;++i)scanf("%d%d",l1+i,r1+i);
	sort(l1+1,l1+n+1);for(i=1;i<=n;++i)sl[i]=sl[i-1]+l1[i];
	sort(r1+1,r1+n+1);for(i=1;i<=n;++i)sr[i]=sr[i-1]+r1[i];
	memset(high+1,-1,m<<2);memset(low+1,-1,m<<2);
	scanf("%d",&q);for(;q--;)scanf("%d%d",&x,&y),x=m-x+1,low[x]=high[x]=y;high[m+1]=n;
	for(i=m;i;--i)-1==high[i]?high[i]=high[i+1]:0;for(i=1;i<=m;++i)-1==low[i]?low[i]=low[i-1]:0;
	for(i=m;i;--i)if(high[i]>=low[m])le=i;ri=m;for(i=1;i<=m;++i)if(low[i]==high[i] && low[i]==low[m])bee=i;
	for(i=1;i<=m;++i)sa1+=low[i],sa2+=i<=bee?high[i]:low[i];
	scanf("%lld",&t);
	if(t<sa1)E();
	for(;le<ri;){
		md=le+ri>>1;
		if(ck(md))ri=md;else le=md+1;
	}
	if(!ck(le))E();
	printf("%d %d\n",m-le+1,calc(le));
	return 0;
}