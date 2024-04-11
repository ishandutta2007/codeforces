#include <cstdio>
const int N=1e5+10;
int T,n,t,ans,len[2],a[N],b[N],pa[N],pb[N];
struct pr{
	int l,r;pr(){};
	pr(int l,int r):l(l),r(r){};
	bool chk(int x){
		int res=0;
		for(int i=l;i<=r;++i)res+=((a[i]>>x)&1)+((b[i]>>x)&1);
		return res==r-l+1;
	}
}f[2][N];
void split(pr p,int w){
	int x=p.l,y=p.r,l=x,r=y;
	for(int i=x;i<=y;++i){
		if(!((a[i]>>w)&1))pa[l++]=a[i];
		else pa[r--]=a[i];
	}
	if(x<=r)f[t^1][++len[t^1]]=pr(x,r);
	if(l<=y)f[t^1][++len[t^1]]=pr(l,y);
	l=x,r=y;
	for(int i=x;i<=y;++i){
		if((b[i]>>w)&1)pb[l++]=b[i];
		else pb[r--]=b[i];
	}
	for(int i=x;i<=y;++i)a[i]=pa[i],b[i]=pb[i];
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),ans=0;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=1;i<=n;++i)scanf("%d",&b[i]);
		len[t=0]=1,f[0][1]=pr(1,n);
		for(int i=29;~i;--i){
			len[t^1]=0;bool tag=true;
			for(int j=1;j<=len[t];++j)tag&=f[t][j].chk(i);
			if(!tag)continue;ans|=1<<i;
			for(int j=1;j<=len[t];++j)split(f[t][j],i);
			t^=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}