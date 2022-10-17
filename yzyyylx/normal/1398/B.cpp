#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define N 500100
#define M 998244353
using namespace std;

int T,n,ans,num[N];
char str[N];
priority_queue<int>pq;

int main()
{
	int i,j,t;
	cin>>T;
	while(T--)
	{
		ans=t=0;
		for(;!pq.empty();pq.pop());
		scanf("%s",str+1);
		n=strlen(str+1);
		for(i=1;i<=n;i++)
		{
			if(str[i]=='1') t++;
			else if(t)
			{
				pq.push(t);
				t=0;
			}
		}
		if(t) pq.push(t);
		for(i=1;!pq.empty();i^=1)
		{
			if(i) ans+=pq.top();
			pq.pop();
		}
		printf("%d\n",ans);
	}
}