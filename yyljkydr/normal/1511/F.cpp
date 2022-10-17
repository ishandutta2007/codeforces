#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e3+1e1+7,P=998244353;

void inc(int &a,int b)
{
	a+=b;
	a>=P?a-=P:0;
}

int k;

struct Matrix{
	int a[N][N];

	void init()
	{
		for(int i=0;i<=k;i++)
			a[i][i]=1;
	}

	void clear()
	{
		for(int i=0;i<=k;i++)
			for(int j=0;j<=k;j++)
				a[i][j]=0;
	}
}A,B;

Matrix operator *(const Matrix &a,const Matrix &b)
{
	Matrix ret;
	ret.clear();
	for(int i=0;i<=k;i++)
		for(int j=0;j<=k;j++)
			for(int t=0;t<=k;t++)
				inc(ret.a[i][j],a.a[i][t]*b.a[t][j]%P);
	return ret;
}

Matrix qpow(Matrix &a,int b)
{
	Matrix ret;
	ret.clear();
	ret.init();
	while(b)
	{
		if(b&1)
			ret=ret*a;
		b>>=1;
		a=a*a;
	}
	return ret;
}

int trie[N][26],tot,tag[N];

void insert(char *s)
{
	int x=0,len=strlen(s);
	for(int i=0;i<len;i++)
	{
		if(trie[x][s[i]-'a']==-1)
		{
			trie[x][s[i]-'a']=++tot;
			for(int j=0;j<26;j++)
				trie[tot][j]=-1;
		}
		x=trie[x][s[i]-'a'];
	}
	tag[x]=1;
}

char s[11];

int n,m;

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

map<pii,int>id;

pii pos[N];

int getid(int x,int y)
{
	if(x>y)
		swap(x,y);
	if(id.find(mp(x,y))==id.end())
		id[mp(x,y)]=++k,pos[k]=mp(x,y);
	return id[mp(x,y)];
}

queue<int>q;

map<int,int>vis;

signed main()
{
	for(int i=0;i<26;i++)
		trie[0][i]=-1;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s),insert(s);
	id[mp(0,0)]=0;
	q.push(0);
	A.a[0][0]=1;
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		if(vis[p])
			continue;
		vis[p]=1;
		int x=pos[p].fs,y=pos[p].sd;
		for(int i=0;i<26;i++)
		{
			int tx=trie[x][i],ty=trie[y][i];
			if(tx==-1||ty==-1)
				continue;
			int tp=getid(tx,ty);
			q.push(tp);
			B.a[p][tp]++;
			if(tag[tx])
				B.a[p][getid(0,ty)]++,q.push(getid(0,ty));
			if(tag[ty])
				B.a[p][getid(tx,0)]++,q.push(getid(tx,0));
			if(tag[tx]&&tag[ty])
				B.a[p][getid(0,0)]++;
		}
	}
	A=A*qpow(B,m);
	printf("%lld\n",A.a[0][0]);
}