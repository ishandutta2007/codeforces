#include<bits/stdc++.h>
#define maxn 300100
using namespace std;
const int inf=1<<30;
int n,a[maxn],col[maxn],lst;
long long ans=0;
char s[4];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%s",&a[i],s),col[i]=(s[0]=='G'?1:(s[0]=='B'?2:3));
		if(col[i]==1){
			if(!lst){
				int r=0,b=0;
				for(int j=1;j<i&&!r;++j)if(col[j]==2)r=a[j];
				for(int j=1;j<i&&!b;++j)if(col[j]==3)b=a[j];
				if(r)ans+=a[i]-r;
				if(b)ans+=a[i]-b;
			} else {
				int mxr=-inf,mxb=-inf,r=0,b=0;
				for(int j=lst+1;j<i;++j){
					if(col[j]==2){
						if(r)mxr=max(mxr,a[j]-r);
						else mxr=max(mxr,a[j]-a[lst]);
						r=a[j];
					} else if(col[j]==3){
						if(b)mxb=max(mxb,a[j]-b);
						else mxb=max(mxb,a[j]-a[lst]);
						b=a[j];
					}
				}
				if(r)mxr=max(mxr,a[i]-r);
				if(b)mxb=max(mxb,a[i]-b);
				long long dong=0;
//				printf("<%d,%d(%d,%d)>",mxr,mxb,r,b);
				if(r&&b)dong=min(2ll*(a[i]-a[lst]),3ll*(a[i]-a[lst])-mxr-mxb);
				else if(r)dong=2ll*(a[i]-a[lst])-mxr;
				else if(b)dong=2ll*(a[i]-a[lst])-mxb;
				else dong=a[i]-a[lst];
				ans+=dong;
//				printf("{%d,%d}",ans,dong);
			}
			lst=i;
		}
	}
	int r=0,b=0,nr=0,nb=0;
	for(int j=n;j>=lst+1&&!r;--j)if(col[j]==2)r=a[j];
	for(int j=n;j>=lst+1&&!b;--j)if(col[j]==3)b=a[j];
	if(!lst){
		for(int j=1;j<=n&&!nr;++j)if(col[j]==2)nr=a[j];
		for(int j=1;j<=n&&!nb;++j)if(col[j]==3)nb=a[j];
		ans+=r-nr+b-nb;
	} else {
		if(r)ans+=r-a[lst];
		if(b)ans+=b-a[lst];
	}
	printf("%lld",ans);
}