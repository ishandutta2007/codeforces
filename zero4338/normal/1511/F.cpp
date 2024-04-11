#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=160;
const int mod=998244353;
int n,m;
map<pair<int,int>,int>id;
struct matrix
{
	int num[maxn][maxn];
	matrix(){memset(num,0,sizeof num);}
	matrix operator *(const matrix &x)
	{
		matrix ret;
		for(int i=0;i<id.size();i++)
			for(int j=0;j<id.size();j++)
				for(int k=0;k<id.size();k++)
					(ret.num[i][j]+=(ll)num[i][k]*x.num[k][j]%mod)%=mod;
		return ret;
	}
	friend matrix qpow(matrix a,int b)
	{
		matrix ret;for(int i=0;i<id.size();i++)ret.num[i][i]=1;
		for(;b;b>>=1,a=a*a)if(b&1)ret=ret*a;
		return ret;
	}
}tran,ans;
struct trie
{
	#define S(u,i) t[u].ch[i]
	struct node{int ch[26];bool ed;}t[maxn];int cnt;
	void insert(string &s)
	{
		int p=0;
		for(char &c:s)
		{
			if(!S(p,c-'a'))S(p,c-'a')=++cnt;
			p=S(p,c-'a');
		}
		t[p].ed=1;
	}
	void dfs(int u1,int u2)
	{
		if(u1>u2)swap(u1,u2);
		if(id.count({u1,u2}))return;
		if(u1&&u2){int tmp=id.size();id[{u1,u2}]=tmp;}
		for(int i=0;i<26;i++)
			if(S(u1,i)&&S(u2,i))dfs(S(u1,i),S(u2,i));
	}
	void getid(){for(int i=0;i<=cnt;i++)dfs(0,i);}
	void getmat()
	{
		for(auto &i:id)
		{
			int x=i.first.first,y=i.first.second;
			for(int j=0;j<26;j++)
				if(S(x,j)&&S(y,j))
				{
					int tox=S(x,j),toy=S(y,j);
					if(tox<=toy)tran.num[i.second][id[{tox,toy}]]++;
				}
			if(t[x].ed)
				for(int j=0;j<26;j++)
					if(S(0,j)&&S(y,j))
					{
						int tox=S(0,j),toy=S(y,j);
						if(tox<=toy)tran.num[i.second][id[{tox,toy}]]++;
					}
			if(t[y].ed)
				for(int j=0;j<26;j++)
					if(S(x,j)&&S(0,j))
					{
						int tox=S(x,j),toy=S(0,j);
						if(tox<=toy)tran.num[i.second][id[{tox,toy}]]++;
					}
			if(t[x].ed&&t[y].ed)
				for(int j=0;j<26;j++)
					if(S(0,j)&&S(0,j))
					{
						int tox=S(0,j),toy=S(0,j);
						if(tox<=toy)tran.num[i.second][id[{tox,toy}]]++;
					}
			if(x!=y)
			{
				swap(x,y);
				for(int j=0;j<26;j++)
				if(S(x,j)&&S(y,j))
				{
					int tox=S(x,j),toy=S(y,j);
					if(tox<=toy)tran.num[i.second][id[{tox,toy}]]++;
				}
				if(t[x].ed)
					for(int j=0;j<26;j++)
						if(S(0,j)&&S(y,j))
						{
							int tox=S(0,j),toy=S(y,j);
							if(tox<=toy)tran.num[i.second][id[{tox,toy}]]++;
						}
				if(t[y].ed)
					for(int j=0;j<26;j++)
						if(S(x,j)&&S(0,j))
						{
							int tox=S(x,j),toy=S(0,j);
							if(tox<=toy)tran.num[i.second][id[{tox,toy}]]++;
						}
				if(t[x].ed&&t[y].ed)
					for(int j=0;j<26;j++)
						if(S(0,j)&&S(0,j))
						{
							int tox=S(0,j),toy=S(0,j);
							if(tox<=toy)tran.num[i.second][id[{tox,toy}]]++;
						}	
			}
		}
		for(int i=0;i<26;i++)
			if(S(0,i))ans.num[0][id[{S(0,i),S(0,i)}]]++;
	}
	#undef S
}tr;
int f[maxn];
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++){string s;cin>>s;tr.insert(s);}
	tr.getid();tr.getmat();
	ans=ans*qpow(tran,m-1);
	int sum=0;
	for(auto &i:id)
		if(tr.t[i.first.first].ed&&tr.t[i.first.second].ed)
			sum=((ll)sum+(1+(i.first.first!=i.first.second))*ans.num[0][i.second])%mod;
	printf("%d\n",sum);
	return 0;
}