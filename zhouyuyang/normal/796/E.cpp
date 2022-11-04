#include<bits/stdc++.h>
#define f(I,J,K,L) f[(I)*(p+1)*k*k+(J)*k*k+(K)*k+(L)]
using namespace std;
int n,p,k,x,c,ans;
int a[1005];
int b[1005];
int f[233333];
void upd(int &x,int y){
	x<y?x=y:233;
}
int main(){
	scanf("%d%d%d",&n,&p,&k);
	scanf("%d",&x);
	for (int i=1;i<=x;i++){
		int y;
		scanf("%d",&y);
		a[y]=1;
	}
	scanf("%d",&x);
	for (int i=1;i<=x;i++){
		int y;
		scanf("%d",&y);
		b[y]=1;
	}
	x=(n-1)/k+1;
	if (2*x<=p){
		for (int i=1;i<=n;i++)
			ans+=(a[i]|b[i]);
		printf("%d",ans);
		return 0;
	}
	for (int j=0;j<=p;j++)
		for (int x=0;x<k;x++)
			for (int y=0;y<k;y++)
				f(c,j,x,y)=-1e9;
	f(c,0,0,0)=0;
	for (int i=1;i<=n;i++){
		c^=1;
		for (int j=0;j<=p;j++)
			for (int x=0;x<k;x++)
				for (int y=0;y<k;y++)
					f(c,j,x,y)=-1e9;
		for (int j=0;j<=p;j++)
			for (int x=0;x<k;x++)
				for (int y=0;y<k;y++){
					int tmp=f(c^1,j,x,y);
					int v=((x&&a[i])||(y&&b[i])?1:0);
					upd(f(c,j,max(x-1,0),max(y-1,0)),tmp+v);
					if (j+1<=p){
						upd(f(c,j+1,k-1,max(y-1,0)),tmp+(v|a[i]));
						upd(f(c,j+1,max(x-1,0),k-1),tmp+(v|b[i]));
					}
					if (j+2<=p)
						upd(f(c,j+2,k-1,k-1),tmp+(v|a[i]|b[i]));
				}
	}
	for (int x=0;x<k;x++)
		for (int y=0;y<k;y++)
			upd(ans,f(c,p,x,y));
	printf("%d",ans);
}