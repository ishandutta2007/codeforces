#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=17;
int n=10,f[N][N][N];
char s[N];
inline void work(){
	scanf("%s",s+1);
	memset(f,0,sizeof(f)),f[0][0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<i;j++)
			for(int k=0;k<i;k++)
				if(i&1){
					if(s[i]=='1')f[i][j+1][k]|=f[i-1][j][k];
					else if(s[i]=='0')f[i][j][k]|=f[i-1][j][k];
					else f[i][j+1][k]|=f[i-1][j][k],f[i][j][k]|=f[i-1][j][k];
				}else{
					if(s[i]=='1')f[i][j][k+1]|=f[i-1][j][k];
					else if(s[i]=='0')f[i][j][k]|=f[i-1][j][k];
					else f[i][j][k+1]|=f[i-1][j][k],f[i][j][k]|=f[i-1][j][k];
				}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++)
			for(int k=0;k<=i;k++)
				if(f[i][j][k])
					if(j>k+(n-i+1)/2 || k>j+(n-i)/2){printf("%d\n",i);return;}
	puts("10");
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}