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
char s[100010];
int a[100010];
int main()
{
	memset(a,0,sizeof a);
	int n,k;
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	int i;
	for(i=1;i<=n;i++)
		a[s[i]-'a'+1]++;
	for(i=1;i<=26;i++)
		if(a[i]>k)
		{
			printf("NO\n");
			return 0;
		}
	printf("YES\n");
	return 0;
}