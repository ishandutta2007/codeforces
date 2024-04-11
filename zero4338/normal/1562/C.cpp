#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int read()
{
	int ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
int T;
const int maxn=2e4+5;
int n;
char s[maxn];
int main()
{
	T=read();
    while(T--)
    {
    	n=read();scanf("%s",s+1);
    	bool flag=0;
    	for(int i=1;i<=n;i++)
    	{
    		int now=s[i]-'0';if(now)continue;
    		if(i<=n/2){printf("%d %d %d %d\n",i,n,i+1,n);flag=1;break;}
    		else {printf("%d %d %d %d\n",1,i,1,i-1);flag=1;break;}
    	}
    	if(!flag){if(n&1)n--;printf("%d %d %d %d\n",1,n,1,n/2);}
    }
    return 0;
}