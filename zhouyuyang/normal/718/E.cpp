#include<bits/stdc++.h>
#define For(i,j,k) for (int i=j;i<=k;i++)
#define N 100005
using namespace std;
char s[N];
long long sum;
int ans,n,f[9][260];
int d[9][9],dis[N][9];
int add[N];
int Mn(int &x,int y){
	(x>y?x=y:233);
}
int main(){
	scanf("%d%s",&n,s+1);
	For(i,1,n) s[i]-='a';
	For(i,0,7) For(j,0,7)
		d[i][j]=(i==j?0:n);
	For(i,1,n) For(j,0,7)
		dis[i][j]=(s[i]==j?0:n);
	For(k,0,7){
		For(i,1,n) For(j,0,7){
			if (i>1) Mn(dis[i][j],dis[i-1][j]+1);
			if (i<n) Mn(dis[i][j],dis[i+1][j]+1);
		}
		For(i,1,n) For(j,0,7)
			Mn(d[s[i]][j],dis[i][j]);
		For(i,1,n) For(j,0,7)
			Mn(dis[i][j],d[s[i]][j]+1);
	}
	For(i,1,n) For(j,0,7)
		if (d[s[i]][j]<dis[i][j])
			add[i]+=(1<<j);
	For(i,1,n){
		For(j,max(1,i-15),i-1){
			int mn=i-j;
			For(k,0,7)
				Mn(mn,dis[i][k]+dis[j][k]+1);
			if (ans<mn) ans=mn,sum=0;
			sum+=(ans==mn?1:0);
		}
		if (i-16<=0) continue;
		f[s[i-16]][add[i-16]]++;
		For(c,0,7) For(j,0,(1<<8)-1)
			if (f[c][j]){
				int mn=n;
				For(k,0,7)
					Mn(mn,dis[i][k]+d[c][k]+1+((j>>k)&1));
				if (ans<mn) ans=mn,sum=0;
				sum+=(ans==mn)*f[c][j];
			}
	}
	printf("%d %lld",ans,sum);
}