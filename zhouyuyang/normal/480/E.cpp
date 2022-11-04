#include<bits/stdc++.h>
using namespace std;
const int N=2005;
bool a[N][N];
int f[N][N],l[N],r[N];
int L[N][N],R[N][N];
int n,m,k,ans[N];
int x[N],y[N];
char s[N];
#define For(i,j,k) for (int i=j;i<=k;i++)
int getl(int i,int j){
	return L[i][j]==j?j:L[i][j]=getl(i,L[i][j]);
}
int getr(int i,int j){
	return R[i][j]==j?j:R[i][j]=getr(i,R[i][j]);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	For(j,0,m+1) a[0][j]=a[n+1][j]=1;
	For(i,1,n){
		scanf("%s",s+1);
		For(j,0,m+1)
			a[i][j]=(s[j]=='.'?0:1);
	}
	For(i,1,k){
		scanf("%d%d",&x[i],&y[i]);
		a[x[i]][y[i]]=1;
	}
	For(i,1,n) For(j,1,m){
		f[i][j]=(a[i][j]?0:min(min(f[i-1][j],f[i][j-1]),f[i-1][j-1])+1);
		ans[k]=max(ans[k],f[i][j]);
	}
	For(i,0,n+1) For(j,0,m+1)
		if (a[i][j]) L[i][j]=R[i][j]=j;
		else L[i][j]=j-1,R[i][j]=j+1;
	for (int p=k;p>=2;p--){
		ans[p-1]=ans[p];
		a[x[p]][y[p]]=0;
		L[x[p]][y[p]]=y[p]-1;
		R[x[p]][y[p]]=y[p]+1;
		l[x[p]]=getl(x[p],y[p]);
		r[x[p]]=getr(x[p],y[p]);
		for (int i=x[p]-1;i>=1;i--){
			l[i]=max(l[i+1],getl(i,y[p]));
			r[i]=min(r[i+1],getr(i,y[p]));
		}
		For(i,x[p]+1,n){
			l[i]=max(l[i-1],getl(i,y[p]));
			r[i]=min(r[i-1],getr(i,y[p]));
		}
		for (int i=min(x[p],n-ans[p-1]);i&&i+ans[p-1]>=x[p];i--)
			for (;min(r[i],r[i+ans[p-1]])-max(l[i],l[i+ans[p-1]])-1>=ans[p-1]+1;)
				ans[p-1]++;
	}
	for (int i=1;i<=k;i++)
		printf("%d\n",ans[i]);
}