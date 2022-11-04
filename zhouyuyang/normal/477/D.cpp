#include<bits/stdc++.h>
#define For(i,j,k) for (int i=j;i<=k;i++)
#define Rep(i,j,k) for (int i=j;i>=k;i--)
using namespace std;
const int mo=1000000007;
const int N=5005;
char s[N];
int f[N][N],g[N][N],lcp[N][N];
int n,ans;
bool cmp(int x,int y,int ln){
	if (!ln||y+ln-1>n) return 1;
	int df=lcp[x][y];
	if (df>=ln) return 0;
	return s[x+df]>s[y+df];
}
void upd(int &x,int y){
	(x+=y)>=mo?x-=mo:233;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	Rep(i,n,1) Rep(j,n,1)
		if (s[i]==s[j]) lcp[i][j]=lcp[i+1][j+1]+1;
	g[1][0]=1;
	For(i,1,n) For(j,0,i-1){
		upd(f[i][j],g[i][j]);
		upd(g[i+1][j],g[i][j]);
		if (!f[i][j]||s[i+1]=='0') continue;
		int ii=i+(i-j);
		if (cmp(j+1,i+1,i-j)) ii++;
			if (ii<=n) upd(g[ii][i],f[i][j]);
	}
	For(i,0,n-1)
		upd(ans,f[n][i]);
	printf("%d\n",ans);
	For(i,0,n) For(j,0,n)
		f[i][j]=g[i][j]=1e9;
	For(i,1,n){
		int szb=s[i]-'0';
		For(k,i,n){
			g[i][k]=szb;
			szb=(szb*2+s[k+1]-'0')%mo;
		}
	}
	For(i,1,n) f[i][0]=1;
	For(i,1,n) For(j,0,i-1)
		if (f[i][j]<1e9){
			f[i+1][j]=min(f[i+1][j],f[i][j]);
			if (s[i+1]=='0') continue;
			int ii=i+(i-j);
			if (cmp(j+1,i+1,i-j)) ii++;
			if (ii<=n) f[ii][i]=min(f[ii][i],f[i][j]+1);
		}
	ans=1e9;
	For(i,1,min(n,25)) if (f[n][n-i]<1e9)
		ans=min(ans,f[n][n-i]+g[n-i+1][n]);
	if (ans==1e9){
		Rep(i,n-1,0) if (f[n][i]<1e9){
			ans=(f[n][i]+g[i+1][n])%mo;
			break;
		}
	}
	printf("%d\n",ans);
}