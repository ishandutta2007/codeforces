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
int k;
string s;
bool exi[10];int cnt[1<<10];
bool judge(int x)
{
	for(int i=2;i<=x/i;i++)if(x%i==0)return 0;
	return 1;
}
int main()
{
	T=read();
	while(T--)
	{
		k=read();cin>>s;memset(exi,0,sizeof exi);
		bool flag1=0,flag2=0;int chose2=0;
		for(int i=0;i<s.size();i++)
		{
			int now=s[i]-'0';
			if(now==1||now==4||now==6||now==8||now==9)
			{
				printf("%d\n%d\n",1,now);flag1=1;flag2=1;break;
			}
			else
			{
				if(exi[now]){flag2=1;chose2=now;}
				exi[now]=1;
			}
		}
		if(flag1)continue;
		if(flag2)
		{
			printf("%d\n%d%d\n",2,chose2,chose2);
			continue;
		}
		int ans=0,ap=0;
		for(int i=1;i<(1<<s.size());i++)
		{
			cnt[i]=cnt[i>>1]+(i&1);
			int now=0;
			for(int j=0;j<s.size();j++)
				if((i>>j)&1)now=now*10+s[j]-'0';
			if(s.size()-cnt[i]>=ans&&!judge(now))
			{
				ans=s.size()-cnt[i];
				ap=i;
			}
		}
		printf("%d\n",s.size()-ans);
		for(int i=0;i<s.size();i++)if((ap>>i)&1)printf("%d",s[i]-'0');printf("\n");
	}
	return 0;
}