#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

typedef unsigned long long ull;

struct itv
{
	ull l,r;itv(ull _l=0,ull _r=0):l(_l),r(_r){}
};
bool operator<(itv A,itv B){return A.l<B.l;}

char op[10];bool type[100000],ans[100000];itv Q[100000];
vector<itv> E[2];itv F[6000000];

int vcnt;

vector<int> ed[6000000];
bool ban[6000000];

void build(ull L,ull R,vector<itv> E)
{
	if(E.size()==1){++vcnt;F[vcnt]=itv(L,R);return;}
	ull mid=(L+R)>>1;
	int pos=0;while(pos+1<E.size()&&E[pos+1].l<=mid)pos++;
	
	int x=vcnt;
	vector<itv> G;for(int i=0;i<pos;i++)G.push_back(E[i]);G.push_back(itv(E[pos].l,mid));
	build(L,mid,G);
	int y=vcnt;
	G.clear();if(E[pos].r>mid)G.push_back(itv(mid+1,E[pos].r));for(int i=pos+1;i<E.size();i++)G.push_back(E[i]);
	build(mid+1,R,G);
	int z=vcnt;ull C=R-mid;
	
	for(int i=x+1,j=y+1;i<=y&&j<=z;)
	{
		ed[i].push_back(j),ed[j].push_back(i);
		if(F[i].r+C==F[j].r)i++,j++;
		else if(F[i].r+C<F[j].r)i++;else j++;
	}
}

struct BCJ
{
	int fa[6000000];
	void init(int n){for(int i=1;i<=n;i++)fa[i]=i;}
	int fnd(int x){return x==fa[x]?x:fa[x]=fnd(fa[x]);}
	void conn(int x,int y){fa[fnd(x)]=fnd(y);}
}B;

int main()
{
	int n=0,m=0;scanf("%d%d",&n,&m);ull U=(1ull<<n)-1;
	for(int i=1;i<=m;i++)
	{
		scanf("%s%llu%llu",op,&Q[i].l,&Q[i].r);
		if(op[0]=='b')
		{
			type[i]=0;E[0].push_back(Q[i]);
		}
		else type[i]=1;
	}
	
	if(E[0].size()==0)
	{
		for(int i=1;i<=m;i++)if(type[i])puts("1");return 0;
	}
	sort(E[0].begin(),E[0].end());
	if(E[0][0].l>0)E[1].push_back(itv(0,E[0][0].l-1));
	for(int i=0;i<E[0].size()-1;i++)
	{
		E[1].push_back(E[0][i]);if(E[0][i+1].l>E[0][i].r+1)E[1].push_back(itv(E[0][i].r+1,E[0][i+1].l-1));
	}
	E[1].push_back(E[0].back());if(E[0].back().r<U)E[1].push_back(itv(E[0].back().r+1,U));
	build(0,U,E[1]);
	
	for(int i=0,j=1;i<E[0].size();i++)
	{
		while(j<=vcnt&&F[j].r<E[0][i].l)j++;
		while(j<=vcnt&&F[j].r<=E[0][i].r){ban[j]=1;j++;}
	}
	B.init(vcnt);
	for(int j=1;j<=vcnt;j++)if(!ban[j]){for(int k=0;k<ed[j].size();k++)if(!ban[ed[j][k]])B.conn(j,ed[j][k]);}
	
	for(int i=m;i>=1;i--)
	{
		if(type[i])
		{
			int posx=upper_bound(F+1,F+vcnt+1,itv(Q[i].l,0))-F-1,posy=upper_bound(F+1,F+vcnt+1,itv(Q[i].r,0))-F-1;
			ans[i]=B.fnd(posx)==B.fnd(posy);
		}
		else
		{
			int posx=upper_bound(F+1,F+vcnt+1,itv(Q[i].l,0))-F-1;
			while(posx<=vcnt&&F[posx].r<=Q[i].r)
			{
				ban[posx]=0;for(int j=0;j<ed[posx].size();j++)if(!ban[ed[posx][j]])B.conn(ed[posx][j],posx);
				posx++;
			}
		}
	}
	for(int i=1;i<=m;i++)if(type[i])printf("%d\n",(int)ans[i]);
}