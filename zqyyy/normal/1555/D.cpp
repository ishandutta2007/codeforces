#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int n,m,sum[N][7];
char s[N],t[7];
inline void work(int x){
	for(int i=1;i<=n;i++)sum[i][x]=sum[i-1][x]+(s[i]!=t[(i-1)%3+1]);	
}
int main(){
	n=read(),m=read(),scanf("%s",s+1);
	t[1]='a',t[2]='b',t[3]='c';int now=0;
	do{
		work(++now);
	}while(next_permutation(t+1,t+4));
	while(m--){
		int l=read(),r=read(),ans=1e9;
		for(int i=1;i<7;i++)ans=min(ans,sum[r][i]-sum[l-1][i]);
		printf("%d\n",ans);
	}
	return 0;
}