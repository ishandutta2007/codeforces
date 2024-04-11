#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
inline char getc(){
	char c;
	while(!isdigit(c=getchar()));
	return c;	
}
const int N=44;
int n,test,A,B,a[N];
int f[N][N][N][N<<1];
int mn;
bool ans[N],p[N];
int dfs(int x,int r,int b,int c){
	if(x==n+1){
		if(!r && !b && c>0 && c<2*n){
			if(mn>abs(c-n)){
				mn=abs(c-n);
				for(int i=1;i<=n;i++)ans[i]=p[i];	
			}
			return 1;
		}
		return 0;
	}
	if(~f[x][r][b][c])return f[x][r][b][c];
	f[x][r][b][c]=0;
	p[x]=0,f[x][r][b][c]|=dfs(x+1,(r*10+a[x])%A,b,c+1);
	p[x]=1,f[x][r][b][c]|=dfs(x+1,r,(b*10+a[x])%B,c-1);
	return f[x][r][b][c];
}
inline void work(){
	n=read(),A=read(),B=read();
	for(int i=1;i<=n;i++)a[i]=getc()&15,ans[i]=0;
	memset(f,-1,sizeof(f)),mn=1e9;
	if(!dfs(1,0,0,n)){puts("-1");return;}
	for(int i=1;i<=n;i++)putchar(ans[i]?'B':'R');
	putchar('\n');
}
int main(){
	test=read();
	while(test--)work();
	return 0;
}