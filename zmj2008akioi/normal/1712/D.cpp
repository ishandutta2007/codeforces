#include <cstdio>
#include <algorithm>
const int inf=1e9,N=1e5+10;
int T,n,k,a[N],b[N];
int min(int x,int y){return x<y?x:y;}
void cmax(int &x,int y){if(x<y)x=y;}
void swp(int &x,int &y){x^=y^=x^=y;}
int md(int x,int y){return (x+y)>>1;}
int bsc(int x){
	int mid,l=0,r=n;
	while(l!=r){
		mid=md(l,r+1);
		if(b[mid]>x)r=mid-1;
		else l=mid;
	}
	return l;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),b[i]=a[i]<<1;
		if(k==n){printf("%d\n",inf);continue;}
		int ans=0;std::sort(b+1,b+n+1);
		for(int i=1;i<n;++i){
			int np,nq,gp,gq,p=a[i],q=a[i+1];
			if(p>q)swp(p,q);np=bsc(p),nq=bsc(q),gp=bsc(p<<1),gq=bsc(q<<1);
			if(k<np)cmax(ans,b[k+1]);
			else if(k==np)cmax(ans,p);
			else if(gp<=nq){
				if(k<gp)cmax(ans,b[k]);
				else if(k<nq)cmax(ans,b[k+1]);
				else if(k==nq)cmax(ans,q);
				else if(k<gq)cmax(ans,b[k]);
				else cmax(ans,b[k+1]);
			}
			else{
				++nq;
				if(k<nq)cmax(ans,b[k]);
				else if(k==nq)cmax(ans,q);
				else if(k<gp)cmax(ans,b[k-1]);
				else if(k<gq)cmax(ans,b[k]);
				else cmax(ans,b[k+1]);
			}
		}
		printf("%d\n",min(ans,inf));
	}
	return 0;
}