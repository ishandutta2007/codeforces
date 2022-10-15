#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
const int N=2e5+7;
int n,a[N],id[N],cnt[N],ans[N];
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)cnt[i]=0;
	for(int i=1;i<=n;i++)cnt[a[i]=read()]++,id[i]=i;
	sort(id+1,id+n+1,[](int x,int y){return a[x]<a[y];});
	int z=*max_element(cnt+1,cnt+n+1);
	for(int i=1;i<=n;i++)ans[id[(i+z-1)%n+1]]=a[id[i]];
	for(int i=1;i<=n;i++)printf("%d%c",ans[i]," \n"[i==n]);
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}