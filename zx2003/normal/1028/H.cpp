#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,U=51e5;
int mn[U];
int n,q,a[N],x,y,i,j,k,l,r,lb[199],cnt[199],buc[19],lst[U][9],ans[N*6];
vector<pair<int,int>>qu[N];
inline void upi(int&a,const int&b){a>b?a=b:0;}
int main(){
	for(i=1;i<199;++i)lb[i]=i&1?0:lb[i>>1]+1,cnt[i]=cnt[i>>1]+(i&1);
	for(i=2;i<U;++i)if(!mn[i])for(j=i;j<U;j+=i)if(!mn[j])mn[j]=i;
	memset(buc,1,sizeof buc);memset(lst,1,sizeof lst);
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<=q;++i)scanf("%d%d",&l,&r),qu[l].push_back({r,i});
	for(i=n;i;--i){
		static int pr[19],pi[199];int xb=0;
		for(x=a[i];x>1;){
			int z=mn[x],c=0;
			for(;x%z==0;x/=z,++c);
			if(c&1)pr[xb++]=z;
		}
		*pi=1;for(j=1;j<1<<xb;++j)pi[j]=pi[j^(1<<lb[j])]*pr[lb[j]];
		for(j=0;j<1<<xb;++j)for(k=cnt[j];k<=7;++k)upi(buc[xb+k-cnt[j]*2],lst[pi[j]][k]);
		for(j=0;j<1<<xb;++j)lst[pi[j]][xb]=i;
		for(auto u:qu[i]){
			tie(y,x)=u;
			for(k=0;buc[k]>y;++k);
			ans[x]=k;
		}
	}
	for(i=1;i<=q;++i)printf("%d\n",ans[i]);
}