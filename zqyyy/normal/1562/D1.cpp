#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=3e5+7;
int n,Q,a[N];
char s[N];
inline void work(){
	n=read(),Q=read(),scanf("%s",s+1);
	for(int i=1;i<=n;i++)a[i]=a[i-1]+(s[i]=='+'?1:-1)*(i&1?1:-1);
	while(Q--){
		int l=read(),r=read();
		if((r-l+1)&1)puts("1");
		else printf("%d\n",abs(a[r]-a[l-1])?2:0);
	}
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}