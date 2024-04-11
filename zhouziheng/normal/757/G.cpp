#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

int n=0,q=0;

int p[250000];
struct e
{
	int to,val;e(int t=0,int v=0):to(t),val(v){} 
};
vector<e> ed[250000];

int fa[250000],sz[250000],son[250000];long long dep[250000],val[250000];
void dfs_bas(int u,int f)
{
	fa[u]=f,sz[u]=1,son[u]=0;
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i].to;
		if(v!=f)
		{
			dep[v]=dep[u]+ed[u][i].val,val[v]=ed[u][i].val;
			dfs_bas(v,u);
			sz[u]+=sz[v];
			if(sz[v]>sz[son[u]])son[u]=v;
		}
	}
}

int seg[250000],rev[250000],top[250000];
void dfs_sec(int pos=1,int f=0)
{
    if(son[pos])
    {
        seg[0]++;seg[son[pos]]=seg[0];
        top[son[pos]]=top[pos];
        rev[seg[0]]=son[pos];
        dfs_sec(son[pos],pos);
    }
    for(int i=0,v=0;i<ed[pos].size();i++)
    {
        v=ed[pos][i].to;
        if(v!=son[pos]&&v!=f)
        {
            seg[0]++;seg[v]=seg[0];
            rev[seg[0]]=v;
            top[v]=v;
            dfs_sec(v,pos);
        }
    }
}
long long s[250000];

struct nd
{
    int lch,rch;int sum;long long sum_s;
};
nd t[30000001];

int used=0,lim=0;
void change(int &now,int l,int r,int x,int y)
{
	if(now<=lim)
	{
		++used;t[used]=t[now];now=used;
	}
    int mid=(l+r)>>1;
    if(x<=l&&r<=y)
    {
    	t[now].sum++;t[now].sum_s+=s[r]-s[l-1];return;
	}
	if(x<=mid)change(t[now].lch,l,mid,x,y);
	if(y>mid)change(t[now].rch,mid+1,r,x,y);
    t[now].sum_s=t[t[now].lch].sum_s+t[t[now].rch].sum_s+(s[r]-s[l-1])*t[now].sum;
}
long long query(int now,int l,int r,int x,int y,int cnt)
{
    if(now==0)return cnt*(s[min(r,y)]-s[max(l,x)-1]);
    if(x<=l&&r<=y)return t[now].sum_s+cnt*(s[r]-s[l-1]);
    int mid=(l+r)>>1;
    long long ans=0;
    if(x<=mid)ans+=query(t[now].lch,l,mid,x,y,cnt+t[now].sum);
    if(y>mid)ans+=query(t[now].rch,mid+1,r,x,y,cnt+t[now].sum);
    return ans;
}

int rt[250000];
void add_road(int tree_id,int pos)
{
	lim=used;
	int fpos=0;
	while(pos)
	{
		fpos=top[pos];
		change(rt[tree_id],1,n,seg[fpos],seg[pos]);
		pos=fa[fpos];
	}
}


long long sum_dep[250000];

long long sum_dist(int tree_id,int v)
{
	int pos=v,fpos=0;long long sum=0;
	while(pos)
	{
		fpos=top[pos];
		sum+=query(rt[tree_id],1,n,seg[fpos],seg[pos],0);
		pos=fa[fpos];
	}
	return sum_dep[tree_id]+dep[v]*tree_id-2*sum;
}

int main()
{
	scanf("%d%d",&n,&q);for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1,x=0,y=0,w=0;i<n;i++){scanf("%d%d%d",&x,&y,&w);ed[x].push_back(e(y,w)),ed[y].push_back(e(x,w));}
	
	dfs_bas(1,0);
	seg[0]=seg[1]=top[1]=rev[1]=1;dfs_sec(1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+val[rev[i]];
	//for(int i=1;i<=n;i++)printf("%lld ",s[i]);puts("");
	for(int i=1;i<=n;i++)rt[i]=rt[i-1],add_road(i,p[i]);
	for(int i=1;i<=n;i++)sum_dep[i]=sum_dep[i-1]+dep[p[i]];
	
	int type=0,l=0,r=0,v=0,x=0;
	long long last_ans=0;
	int cnt=0;
	while(q--)
	{
		scanf("%d",&type);
		if(type==1)
		{
			scanf("%d%d%d",&l,&r,&v);
			l=last_ans^l,r=last_ans^r,v=last_ans^v;
			last_ans=sum_dist(r,v)-sum_dist(l-1,v);
			//printf("%lld %lld\n",sum_dist(r,v),sum_dist(l-1,v));
			printf("%lld\n",last_ans);
			last_ans%=1<<30;
		}
		else
		{
			cnt++;
			scanf("%d",&x);
			x=last_ans^x;
			sum_dep[x]=sum_dep[x-1]+dep[p[x+1]];
			if(used>2.99e7)
			{
				swap(p[x],p[x+1]);
				used=0;
				for(int i=1;i<=n;i++)rt[i]=rt[i-1],add_road(i,p[i]);
				cnt=0;
			}
			else
			{
				rt[x]=rt[x-1];add_road(x,p[x+1]);
				swap(p[x],p[x+1]);
			}
		}
	}
}