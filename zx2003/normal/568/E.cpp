#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int N=1e5+5;
int n,m,a[N],b[N],pre1[N],i,j,k;
int w,l,r,mid,pre2[N];pii q[N];bool usd[N];
inline int F(int l){return a[q[l].second]==-1?pre2[l]:q[l].second;}
int main(){
	scanf("%d",&n);for(i=1;i<=n;++i)scanf("%d",a+i);
	scanf("%d",&m);for(i=1;i<=m;++i)scanf("%d",b+i);sort(b+1,b+m+1);
	for(i=1;i<=n;++i)if(a[i]!=-1){
		for(l=1,r=w+1;l<r;){
			mid=l+r>>1;
			if(q[mid].first<a[i])l=mid+1;else r=mid;
		}
		q[l]=pii(a[i],i);pre2[l]=pre1[i]=F(l-1);w+=w<l;
	}else{
		w+=b[m]>q[w].first;
		for(j=m,k=w;j;--j){
			for(;k>1 && q[k-1].first>=b[j];--k);
			q[k]=pii(b[j],i);pre2[k]=F(k-1);
		}
	}
	int lst=1<<30;
	for(i=F(w),j=n,k=m;;i=pre1[i]){
		for(;j>i;--j)if(a[j]==-1){for(;b[k]>=lst;--k);if(k && b[k]>a[i])lst=a[j]=b[k],usd[k--]=1;}
		if(!i)break;lst=a[i];
	}
	for(i=k=1;i<=n;++i)if(a[i]==-1){for(;k<=m && usd[k];++k);a[i]=b[k++];}
	for(i=1;i<=n;++i)printf("%d ",a[i]);puts("");
	return 0;
}