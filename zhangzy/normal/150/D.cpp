#include<bits/stdc++.h>
#define N [155]
#define U(x,y) x=max(x,y)
using namespace std;
int n,c N,f N N,h N N N;
char s N;

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]); c[0]=-1;
	scanf("%s",s);
	for (int sz=1;sz<=n;sz++)
		for (int i=0;i<=n-sz;i++){ int j=i+sz;
			for (int len=2;len<=sz;len++){
				h[i][j][len]=-1;
				if (s[i]==s[j-1]) U(h[i][j][len],h[i+1][j-1][len-2]);
				for (int k=1;k<=sz-len;k++){
					if (~h[i+k][j][len]&&~h[i][i+k][0]) U(h[i][j][len], h[i+k][j][len]+h[i][i+k][0]);
					if (~h[i][j-k][len]&&~h[j-k][j][0]) U(h[i][j][len], h[i][j-k][len]+h[j-k][j][0]);
				}
			}
			
			h[i][j][1]=-1;
			for (int k=0;k<sz;k++)
				if (~h[i][i+k][0]&&~h[i+k+1][j][0])
					U(h[i][j][1],h[i][i+k][0]+h[i+k+1][j][0]);
			h[i][j][0]=-1;
			for (int k=1;k<sz;k++)
				if (~h[i][i+k][0]&&~h[i+k][j][0])
					U(h[i][j][0],h[i][i+k][0]+h[i+k][j][0]);
			for (int k=1;k<=sz;k++)
				if (~h[i][j][k]&&~c[k])
					U(h[i][j][0],c[k]+h[i][j][k]);
			
			U(f[i][j],h[i][j][0]);
			for (int k=i+1;k<j;k++)
				U(f[i][j],f[i][k]+f[k][j]);
		}
	cout<<f[0][n];
}