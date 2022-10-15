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
int n,a[N],cnt[N];
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),cnt[i]=cnt[i-1]+(a[i]!=0);
	if(!cnt[n]){puts("0");return;}
	int x=cnt[n];
	for(int i=x;i<=n;i++)
		if(cnt[i]-cnt[i-x]==x){puts("1");return;}
	puts("2");
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	int test=read();
	while(test--)work();
	return 0;
}