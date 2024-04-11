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

ll n,cnt[5],num[N],tmp[5],T;
char str[N];
vector<char>need;

inline int zh(char u)
{
	if(u>='A'&&u<='Z') return 1;
	if(u<='z'&&u>='a') return 2;
	return 3;
}

inline bool ask(ll u,ll v)
{
	memcpy(tmp,cnt,sizeof(cnt));
	ll i,j;
	for(i=u; i<=v; i++)
	{
		tmp[num[i]]--;
	}
	need.clear();
	if(!tmp[1]) need.push_back('A');
	if(!tmp[2]) need.push_back('a');
	if(!tmp[3]) need.push_back('1');
	if(need.size()>v-u+1) return 0;
	for(i=u,j=0; i<=v&&j<need.size(); i++,j++)
	{
		str[i]=need[j];
	}
	printf("%s\n",str+1);
	return 1;
}

int main()
{
	ll i,j;
	cin>>T;
	while(T--)
	{
		memset(cnt,0,sizeof(cnt));
		scanf("%s",str+1);
		n=strlen(str+1);
		for(i=1; i<=n; i++)
		{
			num[i]=zh(str[i]);
			cnt[num[i]]++;
		}
		if(cnt[1]&&cnt[2]&&cnt[3])
		{
			printf("%s\n",str+1);
			continue;
		}
		bool ok=0;
		for(i=1; i<=n&&!ok; i++)
		{
			for(j=1; j+i-1<=n&&!ok; j++)
			{
				ok=ask(j,j+i-1);
			}
		}
	}
}