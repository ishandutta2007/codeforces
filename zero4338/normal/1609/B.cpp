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
int n,q;
int ans;
char s[maxn];
bool check(int i)
{
	if(i<1)return false;
	if(i>n-2)return false;
	return s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c';
}
int main()
{
	n=read();q=read();scanf("%s",s+1);
	for(int i=1;i<=n-2;i++)if(check(i))ans++;
	while(q--)
	{
		int i=read();char c;scanf(" %c",&c);
		if(check(i-2)||check(i-1)||check(i))ans--;
		s[i]=c;
		if(check(i-2)||check(i-1)||check(i))ans++;
		printf("%d\n",ans);
	}
	return 0;
}