#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1e5+7;
int n,m,a[N];
inline void work(){
	n=read(),m=read();
	for(int i=1;i<=n*m;i++)a[i]=read();
	int ans=0;
	for(int i=1;i<=m;i++)
		for(int j=i+1;j<=m;j++)
			if(a[i]<a[j])ans++;
	printf("%d\n",ans);
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}