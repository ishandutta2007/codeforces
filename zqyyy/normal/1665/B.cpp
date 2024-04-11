#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
int n;
inline void work(){
	n=read();
	int mx=0;
	map<int,int>cnt;
	for(int i=1;i<=n;i++)
		mx=max(mx,++cnt[read()]);
	int ans=0;
	while(mx<n)ans+=1+min(n-mx,mx),mx<<=1;
	printf("%d\n",ans);
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}