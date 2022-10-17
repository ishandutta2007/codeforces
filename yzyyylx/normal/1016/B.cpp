 #include<bits/stdc++.h>
#define ll long long
#define db double
#define N 1010
using namespace std;

int n,m,Q,p[N],sz[N];
bool ok[N];
string s,t;

inline int lb(int u){return u&(-u);}
inline void add(int u){for(;u<=1000;u+=lb(u)) sz[u]++;}
inline int ask(int u)
{
	if(u<=0) return 0;
	int res=0;
	for(;u;u-=lb(u))
	{
		res+=sz[u];
	}
	return res;
}

int main()
{
	int i,j,p,q;
	cin>>n>>m>>Q;
	cin>>s>>t;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m&&i<n;j++)
		{
			if(s[i+j]!=t[j]) break;
		}
		if(j==m)
		{
//			cout<<i+1<<endl;
			add(i+1);
		}
	}
//	return 0;
	for(i=1;i<=Q;i++)
	{
		scanf("%d%d",&p,&q);
		if(q-p+1<m)
		{
			printf("0\n");
			continue;
		}
		printf("%d\n",ask(q-m+1)-ask(p-1));
	}
}