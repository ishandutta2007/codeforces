#include <cstdio>
const int inf=2e9,N=2e5+10;
int T,n,ans,a[N],b[N],a1[N],a2[N],b1[N],b2[N];
int min(int x,int y){return x<y?x:y;}
int max(int x,int y){return x>y?x:y;}
void cmin(int &x,int y){if(x>y)x=y;}
void cmax(int &x,int y){if(x<y)x=y;}
int g(int y,int x){return y?b[x]:a[x];}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),a1[n+1]=a2[n+1]=b1[n+1]=b2[n+1]=-inf,ans=inf;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=1;i<=n;++i)scanf("%d",&b[i]);
		a[1]=-1;int nt=0;
		for(int i=n;i;--i)a1[i]=max(a1[i+1],a[i]-i);
		for(int i=n;i;--i)a2[i]=max(a2[i+1],a[i]+i);
		for(int i=n;i;--i)b1[i]=max(b1[i+1],b[i]-i);
		for(int i=n;i;--i)b2[i]=max(b2[i+1],b[i]+i);
		for(int y=0,i=1;i<=n;){
			int rn=n-i+1,p=i-1;
			if(!y)cmin(ans,max(nt+(rn<<1)-1,max(b2[i]-p,a1[i]+(rn<<1)+1+p)));
			else cmin(ans,max(nt+(rn<<1)-1,max(a2[i]-p,b1[i]+(rn<<1)+1+p)));
			y^=1,cmax(nt,g(y,i)),++nt;
			++i;if(i<=n)cmax(nt,g(y,i)),++nt;
		}
		printf("%d\n",min(nt,ans));
	}
}