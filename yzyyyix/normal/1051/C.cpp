#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define N 110
#define M 
using namespace std;

ll n,cnt[N],num[N],ans[N];
vector<int>use,one,pos[N],all;

int main()
{
	ll i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
		cnt[num[i]]++;
		pos[num[i]].push_back(i);
	}
	for(i=1;i<=100;i++)
	{
		if(!cnt[i] || cnt[i]==2) continue;
		if(cnt[i]==1) one.push_back(pos[i][0]);
		else all.push_back(i);
	}
	if(one.size()%2&&!all.size())
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	for(i=0;i<one.size()/2;i++) ans[one[i]]=1;
	if(one.size()%2) ans[pos[all[0]][0]]=1;
	for(i=1;i<=n;i++)
	{
		ans[i]?printf("A"):printf("B");
	}
}