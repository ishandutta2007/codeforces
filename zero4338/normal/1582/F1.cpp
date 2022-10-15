#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e5+5;
const int maxm=1e3+5;
int n,a[maxn];
int ans;
int pos[maxn];
int main()
{
	generate_n(a+1,n=read(),read);
	memset(pos,0x3f,sizeof pos);
	pos[0]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=512;j++)
			if(pos[j]<a[i])
				pos[a[i]^j]=min(pos[a[i]^j],a[i]);
	for(int i=0;i<=512;i++)if(pos[i]!=0x3f3f3f3f)ans++;
	printf("%d\n",ans);
	for(int i=0;i<=512;i++)if(pos[i]!=0x3f3f3f3f)printf("%d ",i);putchar('\n');
	return 0;
}