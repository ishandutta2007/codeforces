#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
char s[100010];
int nxt[100010];
int cnt[100010];
int c[100010];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	int i;
	nxt[1]=n;
	int j,k,p;
	for(i=2,j=-1;i<=n;i++,j--)
		if(j<0||i+nxt[i-k+1]-1>=p)
		{
			if(j<0)
			{
				j=0;
				p=i-1;
			}
			while(p<n&&s[j+1]==s[p+1])
			{
				j++;
				p++;
			}
			nxt[i]=j;
			k=i;
		}
		else
			nxt[i]=nxt[i-k+1];
	memset(cnt,0,sizeof(cnt));
	for(i=1;i<=n;i++)
	{
		if(i+nxt[i]-1==n)
			c[nxt[i]]++;
		cnt[nxt[i]]++;
	}
	int ans=0;
	for(i=1;i<=n;i++)
		if(c[i])
			ans++;
	printf("%d\n",ans);
	for(i=n-1;i>=1;i--)
		cnt[i]+=cnt[i+1];
	for(i=1;i<=n;i++)
		if(c[i])
			printf("%d %d\n",i,cnt[i]);
	return 0;
}