#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mo=998244353,N=55,iv6=166374059,iv2=499122177;
int n,t,x[N],y[N],ans,i,ii,j;
int ad[N*5],T[N*5],s[N*5],M;
inline void upd(int x){if(ad[x]>0)T[x]=s[x];else T[x]=x<M?T[x<<1]+T[x<<1|1]:0;}
inline void mdy(int l,int r,int v){
	for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1,upd(l),upd(r)){
		if(!(l&1))ad[l^1]+=v,upd(l^1);
		if(r&1)ad[r^1]+=v,upd(r^1);
	}
	for(;l;l>>=1,upd(l));
}
inline ll calc(int z){
	static pair<int,int>x1[N*2],y1[N*2];int xxb=0,yxb=0,i,k;ll ret=0;
	static int x2[N],x3[N],y2[N*2],y3[N];
	for(i=1;i<=n;++i){
		x1[++xxb]={x[i]-z,i};x1[++xxb]={x[i]+z+1,-i};
		y1[++yxb]={y[i]-z,i};y1[++yxb]={y[i]+z+1,-i};
	}
	sort(x1+1,x1+xxb+1);sort(y1+1,y1+yxb+1);
	for(M=1;M<xxb+2;M<<=1);memset(s,0,sizeof s);memset(ad,0,sizeof ad);memset(T,0,sizeof T);
	for(i=1;i<=xxb;++i){
		k=x1[i].second;if(k>0)x2[k]=i;else x3[-k]=i;
		if(i<xxb)s[i+M]=x1[i+1].first-x1[i].first;
	}
	for(i=M-1;i;--i)s[i]=s[i<<1]+s[i<<1|1];
	for(i=1;i<=yxb;++i){
		k=y1[i].second;
		if(k>0)mdy(x2[k],x3[k]-1,1);else mdy(x2[-k],x3[-k]-1,-1);
		if(i<yxb)ret+=1ll*(y1[i+1].first-y1[i].first)*T[1];
	}
	return ret;
}
int main(){
	scanf("%d%d",&n,&t);for(i=1;i<=n;++i)scanf("%d%d",x+i,y+i);
	for(i=0;i<t;){
		if(i+4>=t){for(;i<t;++i)ans=(ans+calc(i))%mo;break;}
		ll y0=calc(i),y1=calc(i+1),y2=calc(i+2),y3=calc(i+3);
		auto ck=[&](int ii){
			if(ii>=t)return false;
			int x=ii-i;
			ll y=calc(ii);
			return 2*y==(y0+y2-2*y1)*x*x+(-3*y0+4*y1-y2)*x+2*y0;
		};
		if(!ck(i+3)){ans=(ans+y0+y1+y2)%mo;i+=3;continue;}
		for(j=0;;++j)
			if(!ck(i+(1<<j)))
				break;
		ii=i;
		for(;--j>=0;)if(ck(ii+(1<<j)))ii+=1<<j;
		int x=ii-i;
		y0%=mo;y1=(y1+y0)%mo;y2=(y2+y1)%mo;y3=(y3+y2)%mo;
		ans=(ans+1ll*(x-1)*(x-2)%mo*(x-3)%mo*iv6%mo*(mo-y0)+1ll*x*(x-2)%mo*(x-3)%mo*iv2%mo*y1
			+1ll*x*(x-1)%mo*(x-3)%mo*iv2%mo*(mo-y2)+1ll*x*(x-1)%mo*(x-2)%mo*iv6%mo*y3)%mo;
		i=ii+1;
	}
	ans=(calc(t)%mo*t+mo-ans)%mo;
	printf("%d\n",ans);
	return 0;
}