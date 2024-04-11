
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=1e5+7;
int n,a[3][N];
inline void work(){
	n=read();
	for(int i=1;i<3;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=read()+a[i][j-1];
	int ans=1e9;
	for(int i=1;i<=n;i++)
		ans=min(ans,max(a[1][n]-a[1][i],a[2][i-1]));
	printf("%d\n",ans);
}
int main(){
	int T=read();
	while(T--)work();
	return 0;	
}