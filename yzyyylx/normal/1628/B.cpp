#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define N 200100
#define M 
using namespace std;

ll T,n,m,num[N],len[N];
char str[N][5];
map<ll,bool>mm,san;

ll gcd(ll u,ll v){return v?gcd(v,u%v):u;}
inline void Min(ll &u,ll v){if(v<u) u=v;}
inline void Max(ll &u,ll v){if(v>u) u=v;}
inline ll cg(char u){return u-'a'+1;}
int main()
{
	ll i,j,p,q,pp,qq;
	cin>>T;
	while(T--)
	{
		mm.clear(),san.clear();
		scanf("%lld",&n);
		for(i=1;i<=n;i++) scanf("%s",str[i]+1);
		for(i=1;i<=n;i++)
		{
			len[i]=strlen(str[i]+1);
			if(len[i]==1) break;
			if(len[i]==2)
			{
				p=cg(str[i][1])*100+cg(str[i][2]);
				q=cg(str[i][2])*100+cg(str[i][1]);
				mm[q]=1;
				if(mm.count(p) || san.count(p)) break;
				if(str[i][1]==str[i][2]) break;
			}
			if(len[i]==3)
			{
				p=cg(str[i][2])*100+cg(str[i][1]);
				q=cg(str[i][2])*100+cg(str[i][3]);
				pp=cg(str[i][1])*10000+cg(str[i][2])*100+cg(str[i][3]);
				qq=cg(str[i][3])*10000+cg(str[i][2])*100+cg(str[i][1]);
				san[p]=1,mm[qq]=1;
				if(mm.count(pp) || mm.count(q)) break;
				if(str[i][1]==str[i][3]) break;
			}
		}
		if(i<=n)
		{
			puts("YES");
			continue;
		}
		puts("NO");
	}
}