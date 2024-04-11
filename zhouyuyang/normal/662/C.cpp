#include<bits/stdc++.h>
#define For(i,j,k) for (int i=j;i<=k;i++)
using namespace std;
int n,m,ans;
char a[22][100002];
int f[21][(1<<20)+1];
int main(){
	scanf("%d%d",&n,&m);
	ans=1e9;
	For(i,1,n) scanf("%s",a[i]+1);
	For(i,1,m){
		int tmp=0;
		For(j,1,n)
			tmp=tmp*2+a[j][i]-'0';
		f[0][tmp]++;
	}
	For(i,0,n-1)
		for (int j=n;j;j--)
			For(k,0,(1<<n)-1)
				f[j][k]+=f[j-1][k^(1<<i)];
	For(k,0,(1<<n)-1){
		int tmp=0;
		For(i,0,n) tmp+=min(i,n-i)*f[i][k];
		ans=min(ans,tmp);
	}
	printf("%d",ans);
}