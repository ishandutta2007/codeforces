#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))r=(r<<1)+(r<<3)+(ch^48),ch=getchar();
	return f?r:-r;
}
const int N=5007;
int n,lcp[N][N],f[N];
char s[N];
inline void work(){
	n=read(),scanf("%s",s+1);
	for(int i=n;i;i--)
		for(int j=n;j;j--)
			lcp[i][j]=s[i]==s[j]?lcp[i+1][j+1]+1:0;
	int ans=0;
	for(int i=1;i<=n;i++){
		f[i]=n-i+1;
		for(int j=1;j<i;j++){
			int x=lcp[i][j];
			if(i+x<=n && s[i+x]>s[j+x])
				f[i]=max(f[i],f[j]+n-i-x+1);
		}
		ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)lcp[i][j]=0;
}
int main(){
	int T=read();
	while(T--)work();
	return 0;	
}