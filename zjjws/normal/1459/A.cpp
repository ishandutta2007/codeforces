#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e3+3;
LL rin()
{
	LL s=0;
	bool bj=0;
	char c=getchar();
	while((c>'9'||c<'0')&&c!='-')c=getchar();
	if(c=='-')bj=1,c=getchar();
	while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^'0'),c=getchar();
	if(bj)return -s;
	return s;
}


inline int gc(){char c=getchar();for(;c<'0'||c>'9';c=getchar());return c-'0';}
int a[N];
int b[N];
inline void work()
{
	int n=rin();
	int s_1=0,s_2=0;
	for(int i=1;i<=n;i++)a[i]=gc();
	for(int i=1;i<=n;i++)b[i]=gc();
	for(int i=1;i<=n;i++)
	{
		if(a[i]>b[i])s_1++;
		if(a[i]<b[i])s_2++;
	}
	if(s_1>s_2){puts("RED");return;}
	if(s_1<s_2)puts("BLUE");
	else puts("EQUAL");
	return;
}
int main()
{
	int i,j;
	for(int T=rin();T;T--)work();
	return 0;
}