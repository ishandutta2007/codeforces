#include <bits/stdc++.h>
using namespace std;
int n, m;
char c[2002][2002];
int r[2002][2002];
int d[2002][2002];
int f[2002][2002];
int g[2002][2002];
const int base=1000000007;
void add_rect(int f[2002][2002], int lowc, int highc, int lowr, int highr, int val){
	if(lowc>highc) return;
	if(lowr>highr) return;
	f[lowr][lowc]+=val;
	if(f[lowr][lowc]>=base) f[lowr][lowc]-=base;
	f[lowr][highc+1]-=val;
	if(f[lowr][highc+1]<0) f[lowr][highc+1]+=base;
	f[highr+1][lowc]-=val;
	if(f[highr+1][lowc]<0) f[highr+1][lowc]+=base;
	f[highr+1][highc+1]+=val;
	if(f[highr+1][highc+1]>=base) f[highr+1][highc+1]-=base;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>c[i][j];
	for(int i=1; i<=n; i++)	for(int j=m; j>=1; j--) r[i][j]=r[i][j+1]+(c[i][j]=='R');
	for(int i=n; i>=1; i--)	for(int j=1; j<=m; j++) d[i][j]=d[i+1][j]+(c[i][j]=='R');
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) r[i][j]-=(c[i][j]=='R');
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) d[i][j]-=(c[i][j]=='R');
	if(n==1&&m==1){
		cout<<1<<'\n';
		return 0;
	}
	add_rect(f, 1, 1, 1, 1, 1);
	add_rect(g, 1, 1, 1, 1, 1);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			f[i][j]+=f[i-1][j];
			if(f[i][j]>=base) f[i][j]-=base;
			f[i][j]+=f[i][j-1];
			if(f[i][j]>=base) f[i][j]-=base;
			f[i][j]-=f[i-1][j-1];
			if(f[i][j]<0) f[i][j]+=base;
			
			g[i][j]+=g[i-1][j];
			if(g[i][j]>=base) g[i][j]-=base;
			g[i][j]+=g[i][j-1];
			if(g[i][j]>=base) g[i][j]-=base;
			g[i][j]-=g[i-1][j-1];
			if(g[i][j]<0) g[i][j]+=base;
			//f mean will now go down
			add_rect(g, j, j, i+1, n-d[i][j], f[i][j]);
			add_rect(f, j+1, m-r[i][j], i, i, g[i][j]);
		}
	}
	int ans=f[n][m]+g[n][m];
	if(ans>=base) ans-=base;
	cout<<ans<<'\n';
}