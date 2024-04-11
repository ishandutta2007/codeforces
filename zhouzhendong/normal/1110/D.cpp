#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f|=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=1000005;
int n,m;
int t[N],ans=0;
int dp[N][8][8];
void ckmax(int &x,int y){
	x=x>y?x:y;
}
int main(){
	n=read(),m=read();
	for (int i=1;i<=n;i++)
		t[read()]++;
	for (int i=1;i<=m;i++)
		while (t[i]>7)
			t[i]-=3,ans++;
	for (int i=0;i<=m;i++)
		for (int a=0;a<=7;a++)
			for (int b=0;b<=7;b++)
				dp[i][a][b]=-N*2;
	dp[0][0][0]=0;
	for (int i=0;i<m;i++)
		for (int a=0;a<=7;a++)
			for (int b=0;b<=7;b++){
				if (dp[i][a][b]<-N||a>t[i]||b>t[i+1])
					continue;
				int v=dp[i][a][b];
				for (int x=0;x<=2;x++)
					for (int y=0;y<=2;y++)
						if (a+x*3+y<=t[i]&&b+y<=t[i+1])
							ckmax(dp[i+1][b+y][y],v+x+y);
			}
	int k=0;
	for (int i=0;i<=t[m];i++)
		ckmax(k,dp[m][i][0]+(t[m]-i)/3);
	cout<<ans+k;
	return 0;
}
/*
100 10
7 4 5 5 10 10 5 8 5 7 4 5 4 6 8 8 2 6 3 3 10 7 10 
8 6 2 7 3 9 7 7 2 4 5 2 4 9 5 10 1 10 5 10 4 1 3 4
 2 6 9 9 9 10 6 2 5 6 1 8 10 4 10 3 4 10 5 5 4 10 4 
 5 3 7 10 2 7 3 6 9 6 1 6 5 5 4 6 6 4 4 1 5 1 6 6 6 8 8 6 2 6
 
 
 t : 6 8 7 14 15 16 8 7 6 13
*/
/*
6 8 7 14 15 16 8 7 6 13
6 6 5 12 15 16 8 7 6 13
6 6 3 10 13 16 8 7 6 13
6 6 3 9 12 15 8 7 6 13
6 6 3 9 12 15 6 5 4 13
6 6 3 9 12 15 6 4 3 12

6 5 7 5 6 7 5 7 6 7
6 3 5 3 6 7 5 7 6 7 
6 3 3 1 4 7 5 7 6 7 
6 3 3 0 3 6 5 7 6 7
6 3 3 0 3 6 3 5 4 7
6 3 3 0 3 6 3 4 3 6
*/