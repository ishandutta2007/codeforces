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
int first[30];
int last[30];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	int i;
	memset(first,0,sizeof first);
	memset(last,0,sizeof last);
	for(i=1;i<=n;i++)
		last[s[i]-'A'+1]=i;
	for(i=n;i>=1;i--)
		first[s[i]-'A'+1]=i;
	int ans=0;
	for(i=1;i<=n;i++)
	{
		int c=s[i]-'A'+1;
		if(first[c]==i)
			ans++;
		if(ans>k)
		{
			printf("YES\n");
			return 0;
		}
		if(last[c]==i)
			ans--;
	}
	printf("NO\n");
	return 0;
}