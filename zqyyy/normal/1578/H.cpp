#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1007;
int n,H,a[N];
inline void work(){
	n=read(),H=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	int ans=H/(a[n-1]+a[n])*2;H%=a[n-1]+a[n];
	if(H)ans++;
	if(H>a[n])ans++;
	printf("%d\n",ans);	
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}