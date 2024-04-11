#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#define SIZE 200005

using namespace std;

struct Heavy_Light
{
	struct segtree
	{
		vector < vector <int> > seg;
		int mum;
		
		void init(int n)
		{
			mum=1;
			while(mum<n) mum<<=1;
			seg.resize(mum*2);
		}
		void update(int a,int b,int k,int l,int r,int v)
		{
			if(b<=l||r<=a) return;
			if(a<=l&&r<=b) seg[k].push_back(v);
			else
			{
				update(a,b,k*2+1,l,(l+r)/2,v);
				update(a,b,k*2+2,(l+r)/2,r,v);
			}
		}
		void update(int a,int b,int v)
		{
			update(a,b,0,0,mum,v);
		}
		vector <int> get(int k)
		{
			k+=mum-1;
			vector <int> vx;
			for(int i=0;i<seg[k].size();i++) vx.push_back(seg[k][i]);
			seg[k].clear();
			while(k>0)
			{
				k=(k-1)/2;
				for(int i=0;i<seg[k].size();i++) vx.push_back(seg[k][i]);
				seg[k].clear();
			}
			return vx;
		}
	};
	vector <int> vec[SIZE];
	vector <segtree> seg;
	int nd[SIZE],dep[SIZE];
	int id[SIZE],back[SIZE];
	int cmb[SIZE],len[SIZE];
	int now_sz;
	int n;
	
	void init(int N)
	{
		n=N;
	}
	void add_edge(int a,int b)
	{
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	void dfs(int v=0,int p=-1,int d=0)
	{
		dep[v]=d;
		nd[v]=1;
		for(int i=0;i<vec[v].size();i++)
		{
			int to=vec[v][i];
			if(to!=p)
			{
				dfs(to,v,d+1);
				nd[v]+=nd[to];
			}
		}
	}
	void make(int v=0,int p=-1,int b=-1)
	{
		back[v]=b;
		id[v]=len[now_sz]++;
		cmb[v]=now_sz;
		bool up=false;
		for(int i=0;i<vec[v].size();i++)
		{
			int to=vec[v][i];
			if(to!=p&&nd[to]*2>=nd[v])
			{
				up=true;
				make(to,v,b);
				break;
			}
		}
		if(!up)
		{
			segtree S;
			S.init(len[now_sz]+2);
			seg.push_back(S);
			now_sz++;
		}
		for(int i=0;i<vec[v].size();i++)
		{
			int to=vec[v][i];
			if(to!=p&&nd[to]*2<nd[v])
			{
				make(to,v,v);
			}
		}
	}
	void build()
	{
		dfs();
		make();
	}
	int LCA(int a,int b)
	{
		while(1)
		{
			if(dep[a]>dep[b]) swap(a,b);//dep[a]<=dep[b]
			if(cmb[a]==cmb[b]) return a;
			if(back[a]==-1) b=back[b];
			else if(back[b]==-1) a=back[a];
			else if(dep[back[a]]<=dep[back[b]]) b=back[b];
			else a=back[a];
		}
	}
	void ins2(int v,int p,int x)
	{
		while(cmb[v]!=cmb[p])
		{
			seg[cmb[v]].update(0,id[v]+1,x);
			v=back[v];
		}
		if(id[p]<id[v]) seg[cmb[v]].update(id[p]+1,id[v]+1,x);
	}
	void ins(int a,int b,int x)
	{
		int p=LCA(a,b);
		ins2(a,p,x);
		ins2(b,p,x);
	}
	vector <int> get(int a,int b)
	{
		if(dep[a]>dep[b]) swap(a,b);//dep[a]<=dep[b]
		return seg[cmb[b]].get(id[b]);
	}
};
Heavy_Light T[2];
int left[2][SIZE],right[2][SIZE];
bool use[2][SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int t=0;t<2;t++)
	{
		T[t].init(n+2);
		for(int i=1;i<n;i++)
		{
			int p;
			scanf("%d",&p);p--;
			left[t][i-1]=i,right[t][i-1]=p;
			T[t].add_edge(i,p);
		}
		T[t].build();
	}
	for(int t=0;t<2;t++)
	{
		for(int i=0;i<n-1;i++)
		{
			T[1-t].ins(left[t][i],right[t][i],i);
			use[t][i]=false;
		}
	}
	int idx;
	scanf("%d",&idx);idx--;
	vector <int> vx;
	vx.push_back(idx);
	string now="Blue",nxt="Red";
	int t=0;
	use[t][idx]=true;
	while(!vx.empty())
	{
		printf("%s\n",now.c_str());swap(now,nxt);
		vector <int> vy;
		sort(vx.begin(),vx.end());
		for(int i=0;i<vx.size();i++)
		{
			if(i!=0) printf(" ");
			printf("%d",vx[i]+1);
			vector <int> gt=T[t].get(left[t][vx[i]],right[t][vx[i]]);
			for(int j=0;j<gt.size();j++)
			{
				if(!use[1-t][gt[j]])
				{
					use[1-t][gt[j]]=true;
					vy.push_back(gt[j]);
				}
			}
		}puts("");
		vx=vy;
		t=1-t;
	}
	return 0;
}