#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 1000005
#define MX 30
#define MOD 1000000007

using namespace std;
typedef pair <int,int> P;

char A[SIZE];
int dp[MX],last[MX];
P pos[MX];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	scanf("%s",&A);
	int m=strlen(A);
	int ans=1;
	memset(last,-1,sizeof(last));
	for(int i=0;i<m;i++)
	{
		int c=A[i]-'a';
		last[c]=i;
		int nxt=ans*2-dp[c];
		if(nxt>=MOD) nxt-=MOD;
		else if(nxt<0) nxt+=MOD;
		dp[c]=ans;
		ans=nxt;
	}
	for(int i=0;i<k;i++) pos[i]=P(last[i],i);
	sort(pos,pos+k);
	queue <int> que;
	for(int i=0;i<k;i++) que.push(pos[i].second);
	for(int i=0;i<n;i++)
	{
		int c=que.front();que.pop();
		int nxt=ans*2-dp[c];
		if(nxt>=MOD) nxt-=MOD;
		else if(nxt<0) nxt+=MOD;
		dp[c]=ans;
		ans=nxt;
		que.push(c);
	}
	printf("%d\n",ans);
	return 0;
}