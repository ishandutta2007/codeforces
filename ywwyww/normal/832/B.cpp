#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int b[100010];
char s[100010];
char t[100010];
int match(int l1,int r1,int l2,int r2)
{
	if(r1<l1)
		return 0;
	if(r1-l1!=r2-l2)
		return 0;
	int i;
	for(i=1;i<=r1-l1+1;i++)
	{
		if(s[l1+i-1]==t[l2+i-1])
			continue;
		else if(s[l1+i-1]=='?'&&b[t[l2+i-1]])
			continue;
		return 0;
	}
	return 1;
}
int main()
{
	scanf("%s",s+1);
	int i;
	int len=strlen(s+1);
	memset(b,0,sizeof b);
	for(i=1;i<=len;i++)
		b[s[i]]=1;
	scanf("%s",s+1);
	len=strlen(s+1);
	int ss=0;
	for(i=1;i<=len;i++)
		if(s[i]=='*')
		{
			ss=i;
			break;
		}
	int j;
	int n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",t+1);
		int m=strlen(t+1);
		int ans=1;
		if(!ss)
			ans=match(1,len,1,m);
		else
		{
			if(m<len-1)
				ans=0;
			else
			{
				if(ss>1)
					ans=ans&&match(1,ss-1,1,ss-1);
				if(ss<len)
					ans=ans&&match(ss+1,len,m-len+ss+1,m);
				for(j=ss;j<=m-len+ss;j++)
					ans=ans&&!b[t[j]];
			}
		}
		if(ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}