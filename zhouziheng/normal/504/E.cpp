#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> PI;

const PI BASE=make_pair(133,137),MOD=make_pair(998244353,1e9+7);
long long add(long long x,long long y,long long MOD){return x+y>=MOD?x+y-MOD:x+y;}
long long sub(long long x,long long y,long long MOD){return x>=y?x-y:x+MOD-y;}
PI add(PI x,PI y){return make_pair(add(x.first,y.first,MOD.first),add(x.second,y.second,MOD.second));}
PI sub(PI x,PI y){return make_pair(sub(x.first,y.first,MOD.first),sub(x.second,y.second,MOD.second));}
PI operator*(PI x,PI y){return make_pair(x.first*y.first,x.second*y.second);}
PI operator%(PI x,PI MOD){return make_pair(x.first%MOD.first,x.second%MOD.second);}

long long fast_pow(long long b,long long p,long long MOD)
{
	long long ans=1;while(p){if(p&1)ans=ans*b%MOD;b=b*b%MOD;p>>=1;}
	return ans;
}
long long INV(long long x,long long MOD){return fast_pow(x,MOD-2,MOD);}
PI INV(PI x,PI MOD){return make_pair(INV(x.first,MOD.first),INV(x.second,MOD.second));}

PI E[400000],IV[400000];
void init_hsh(int n)
{
	E[0]=IV[0]=make_pair(1,1);PI I=INV(BASE,MOD);for(int i=1;i<=n;i++)E[i]=E[i-1]*BASE%MOD,IV[i]=IV[i-1]*I%MOD;
}

char s[400000];
vector<int> ed[400000];
int dep[400000],fa[400000];
PI hsh[400000][2];// 0: UP, 1: DOWN
int sz[400000],son[400000];

void dfs_bas(int u,int f)
{
	dep[u]=dep[f]+1;
	hsh[u][0]=add(hsh[f][0]*BASE%MOD,make_pair(s[u],s[u]));
	hsh[u][1]=add(hsh[f][1],make_pair(s[u],s[u])*E[dep[u]-1]%MOD);
	fa[u]=f;sz[u]=1;
	
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];if(v==f)continue;
		dfs_bas(v,u);sz[u]+=sz[v];if(sz[son[u]]<sz[v])son[u]=v;
	}
}
int dfn[400000],rev[400000],top[400000];
struct pth
{
	int x,y,sta;pth(int _x=0,int _y=0,int _sta=0):x(_x),y(_y),sta(_sta){}
	int len(){return dep[x]-dep[y]+1;}
};
void dfs_sec(int u,int f)
{
	dfn[u]=++dfn[0];rev[dfn[u]]=u;top[u]=son[fa[u]]==u?top[fa[u]]:u;
	if(son[u])dfs_sec(son[u],u);
	for(int i=0;i<ed[u].size();i++)if(ed[u][i]!=fa[u]&&ed[u][i]!=son[u])dfs_sec(ed[u][i],u);
}

int LCA(int x,int y)
{
	int fx=top[x],fy=top[y];
	while(fx!=fy)
	{
		if(dep[fx]<dep[fy])swap(fx,fy),swap(x,y);
		x=fa[fx];fx=top[x];
	}
	return dep[x]<dep[y]?x:y;
}

vector<pth> split_road(int x,int y)
{
	int l=LCA(x,y);
	vector<pth> A,B;
	while(top[x]!=top[l])
	{
		A.push_back(pth(x,top[x],0));x=fa[top[x]];
	}
	A.push_back(pth(x,l,0));
	while(top[y]!=top[l])
	{
		B.push_back(pth(y,top[y],1));y=fa[top[y]];
	}
	if(y!=l)B.push_back(pth(y,rev[dfn[l]+1],1));
	for(int i=B.size()-1;i>=0;i--)A.push_back(B[i]);return A;
}

PI hsh_path(pth P)
{
	int x=P.x,y=P.y,sta=P.sta;
	y=fa[y];
	if(sta==0)
	{
		return sub(hsh[x][0],hsh[y][0]*E[dep[x]-dep[y]]%MOD);
	}
	return sub(hsh[x][1],hsh[y][1])*IV[dep[y]]%MOD;
}

pth pre(pth X,int len)
{
	if(X.sta==0){X.y=rev[dfn[X.x]-len+1];}
	else{X.x=rev[dfn[X.x]-X.len()+len];}return X;
}
pth suf(pth X,int len)
{
	if(X.sta==1){X.y=rev[dfn[X.x]-len+1];}
	else{X.x=rev[dfn[X.x]-X.len()+len];}return X;
}

int LCP(pth X,pth Y)
{
	int len=X.len();
	if(len==1)return s[X.x]==s[Y.x];
	int mid=len>>1;
	//printf("LCP: (%d, %d, %d) (%d, %d, %d)\n",X.x,X.y,X.sta,Y.x,Y.y,Y.sta);
	if(hsh_path(pre(X,mid))==hsh_path(pre(Y,mid)))return mid+LCP(suf(X,len-mid),suf(Y,len-mid));return LCP(pre(X,mid),pre(Y,mid));
}



int main()
{
	int n=0;scanf("%d%s",&n,s+1);
	init_hsh(n);
	for(int i=1,u=0,v=0;i<n;i++){scanf("%d%d",&u,&v);ed[u].push_back(v),ed[v].push_back(u);}
	dfs_bas(1,0);
	dfs_sec(1,0);
	//for(int i=1;i<=n;i++)printf("%d ",top[i]);puts("");
	int q=0;scanf("%d",&q);
	while(q--)
	{
		int a=0,b=0,c=0,d=0;scanf("%d%d%d%d",&a,&b,&c,&d);
		vector<pth> X=split_road(a,b),Y=split_road(c,d);
		int ans=0;
		//for(int i=0;i<X.size();i++)printf("%d %d %d\n",X[i].x,X[i].y,X[i].sta);puts("");
		//for(int i=0;i<Y.size();i++)printf("%d %d %d\n",Y[i].x,Y[i].y,Y[i].sta);
		//puts("");
		for(int i=0,j=0;i<X.size()&&j<Y.size();)
		{
			//printf("%d %d\n",X[i].len(),Y[j].len());
			if(X[i].len()==Y[j].len())
			{
				if(hsh_path(X[i])==hsh_path(Y[j]))
				{
					ans+=X[i].len();
					i++,j++;
				}
				else
				{
					ans+=LCP(X[i],Y[j]);break;
				}
			}
			else if(X[i].len()<Y[j].len())
			{
				pth Z=pre(Y[j],X[i].len());
				if(hsh_path(X[i])==hsh_path(Z))
				{
					//puts("A");
					ans+=X[i].len();Y[j]=suf(Y[j],Y[j].len()-X[i].len());i++;
				}
				else
				{
					//puts("B");
					ans+=LCP(X[i],Z);break;
				}
			}
			else
			{
				pth Z=pre(X[i],Y[j].len());
				if(hsh_path(Y[j])==hsh_path(Z))
				{
					ans+=Y[j].len();X[i]=suf(X[i],X[i].len()-Y[j].len());j++;
				}
				else
				{
					ans+=LCP(Y[j],Z);break;
				}
			}
		}
		printf("%d\n",ans);
	}
}