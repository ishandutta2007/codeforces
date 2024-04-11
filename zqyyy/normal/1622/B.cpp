#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=((r<<1)+(r<<3)+(c&15)),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int n,p[N],q[N],id[N];
char s[N];
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)p[i]=read(),id[i]=i;
	scanf("%s",s+1);
	sort(id+1,id+n+1,[](int x,int y){return s[x]^s[y]?s[x]<s[y]:p[x]<p[y];});
	for(int i=1;i<=n;i++)q[id[i]]=i;
	for(int i=1;i<=n;i++)printf("%d ",q[i]);puts("");
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int test=read();
	while(test--)work();
    return 0;
}