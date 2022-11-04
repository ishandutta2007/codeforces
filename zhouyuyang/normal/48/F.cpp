#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#define N 510000
#define int64 long long
using namespace std;
int i,j,n,m,W,v,l,r,mid,w[N],c[N],a[N],id[N];
int64 ans,tmp,fv;
long double fans,price[N];
bool cmp(const int&a,const int&b){
	return price[a]<price[b];
}
int main(){
	scanf("%d%d%d",&n,&m,&W);
	for(i=1;i<=m;++i)scanf("%d",&w[i]);
	for(i=1;i<=m;++i)scanf("%d",&c[i]);
	for(i=1;i<=m;++i)scanf("%d",&a[i]);
	for(i=0;i<n;++i){
		for(j=1;j<=m;++j){
			price[j]=1.0*(c[j]-i*a[j])/w[j];
			id[j]=j;
		}
		v=W; l=1; r=m;
		while(l+1<=r){
			mid=(l+r)/2;
			nth_element(id+l,id+mid,id+r+1,cmp);
			tmp=0;
			fv=0;
			for(j=l;j<=mid;++j){
				tmp+=c[id[j]]-i*a[id[j]];
				fv+=w[id[j]];
			}
			if(v>=fv){
				v-=fv;
				ans+=tmp;
				l=mid+1;
			}else r=mid;
		}
		fans+=v*price[id[l]];
		int64 p=(int64)fans;
		ans+=p; fans-=p;
	}
	printf("%I64d.",ans);
	for(i=1;i<=14;++i){
		fans*=10;
		printf("%d",(int64)fans%10);
	}
}