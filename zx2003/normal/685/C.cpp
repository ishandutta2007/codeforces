#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,aa[8]={-1,0,1,-1,2,-1,-1,-1},bb[8]={-1,-1,-1,2,-1,1,0,-1};
typedef long long ll;
int T,n,i,j;
ll l,r,m,a[N],b[N],c[N],x,y,z,mn[8],u[4],d[4];
inline bool ckk(ll p,ll q,ll r){
	for(x=q+r-2>>1;x<=q+r+2>>1;++x)
		for(y=r+p-2>>1;y<=r+p+2>>1;++y)
			for(z=p+q-2>>1;z<=p+q+2>>1;++z)if(
				d[0]<=-x+y+z && -x+y+z<=u[0] && 
				d[1]<=x-y+z && x-y+z<=u[1] && 
				d[2]<=x+y-z && x+y-z<=u[2] && 
				d[3]<=x+y+z && x+y+z<=u[3])
					return 1;
	return 0;
}
inline bool ck(ll D){
	for(i=0;i<8;++i)mn[i]=8e18;
	for(i=1;i<=n;++i)
		for(j=0;j<8;++j)mn[j]=min(mn[j],D+(j&1?-a[i]:a[i])+(j&2?-b[i]:b[i])+(j&4?-c[i]:c[i]));
	u[3]=mn[0];d[3]=-mn[7];
	for(i=1;i<7;++i){
		if(aa[i]!=-1)u[aa[i]]=mn[i];
		if(bb[i]!=-1)d[bb[i]]=-mn[i];
	}
	for(i=0;i<4;++i)if(u[i]<d[i])return 0;
	for(i=0;i<16;++i){
		ll p,q,r,s;
		p=i&1?u[0]:d[0];
		q=i&2?u[1]:d[1];
		r=i&4?u[2]:d[2];
		s=i&8?u[3]:d[3];
		s=p+q+r;
		if(d[3]<=s && s<=u[3] && ckk(p,q,r))return 1;
		
		p=i&1?u[0]:d[0];
		q=i&2?u[1]:d[1];
		r=i&4?u[2]:d[2];
		s=i&8?u[3]:d[3];
		r=s-p-q;
		if(d[2]<=r && r<=u[2] && ckk(p,q,r))return 1;		
		p=i&1?u[0]:d[0];
		q=i&2?u[1]:d[1];
		r=i&4?u[2]:d[2];
		s=i&8?u[3]:d[3];
		q=s-p-r;
		if(d[1]<=q && q<=u[1] && ckk(p,q,r))return 1;

		p=i&1?u[0]:d[0];
		q=i&2?u[1]:d[1];
		r=i&4?u[2]:d[2];
		s=i&8?u[3]:d[3];
		p=s-q-r;
		if(d[0]<=p && p<=u[0] && ckk(p,q,r))return 1;
	}
	return 0;
}
int main(){
	scanf("%d",&T);
	for(;T--;){
		l=r=0;
		scanf("%d",&n);for(i=1;i<=n;++i)scanf("%lld%lld%lld",a+i,b+i,c+i),r=max(r,abs(a[i])+abs(b[i])+abs(c[i]));
		for(;l<r;){
			m=l+r>>1;
			if(ck(m))r=m;else l=m+1;
		}
		ck(l);
		printf("%lld %lld %lld\n",x,y,z);
	}
	return 0;
}