#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int su[N],lst[N],n,i,a,lim;
ll ans;
pair<int,int>b[N];int xb;
inline int calc(int k){
	int i,j;ll s=0,ans=-1,x,y,z;xb=0;
	for(i=0;i*k<N;++i){
		s+=1ll*i*(su[min(N-1,(i+1)*k-1)]-(i?su[i*k-1]:0));
		x=lst[min(N-1,(i+1)*k)];
		if(x && x>=i*k){
			y=su[x]-su[x-1]>1?x:lst[x];
			if(y>=i*k)b[++xb]=make_pair(i,y-i*k);
			b[++xb]=make_pair(i,x-i*k);
		}
	}
	for(i=1;i<=xb;++i){
		z=2*s-b[i].second;
		x=z<=0?0:(z-1)/(k+2)+1;
		if(x<=b[i].first)ans=max(ans,s-x);
	}
	y=-1;
if(k==7){
++k,--k;
}
	for(i=xb;i;--i){
		if(y>=0){
			z=s-min(1ll*b[i].second,y);
			x=z<=0?0:(z-1)/(k+2)+1;
			if(x<=b[i].first)ans=max(ans,s-x*2);
		}
		y=max(y,1ll*b[i].second);
	}
	y=-1;
	for(i=xb;i;--i){
		if(b[i].first<b[xb].first){
			z=s-1-b[i].second;
			x=z<=0?0:(z-1)/(k+2)+1;
			if(x<=b[i].first)ans=max(ans,s-x*2-1);
		}
		if(y>=0){
			z=s+1+k-y;
			x=z<=0?0:(z-1)/(k+2)+1;
			if(x<=b[i].first)ans=max(ans,s-x*2+1);
		}
		y=max(y,1ll*b[i].second);
	}
	return ans==-1?lim:(ans<2?0:ans);
}
int main(){
	scanf("%d",&n);for(i=0;i<n;++i)scanf("%d",&a),++su[a];
	for(i=1;i<N;++i)lst[i]=su[i-1]?i-1:lst[i-1];
	a=lst[N-1];lim=max(a/2,su[a]>1?a:lst[a]);
	for(i=1;i<N;++i)su[i]+=su[i-1];
	for(i=2;i<N;++i)ans=max(ans,1ll*i*calc(i));
	printf("%lld\n",ans);
	return 0;
}