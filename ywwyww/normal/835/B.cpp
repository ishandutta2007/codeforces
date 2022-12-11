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
char s[1000010];
int c[20];
int main()
{
	int k;
	scanf("%d",&k);
	scanf("%s",s+1);
	int n=strlen(s+1);
	int sum=0;
	int i;
	memset(c,0,sizeof c);
	int ans=0;
	for(i=1;i<=n;i++)
	{
		c[s[i]-'0']++;
		sum+=s[i]-'0';
	}
	sum=k-sum;
	for(i=0;i<=9;i++)
		while(sum>0&&c[i])
		{
			sum-=9-i;
			ans++;
			c[i]--;
		}
	printf("%d\n",ans);
	return 0;
}