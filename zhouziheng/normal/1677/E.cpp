#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct line
{
	long long k,b;line(long long _k=0,long long _b=0):k(_k),b(_b){}
};
line operator+(line X,line Y){return line(X.k+Y.k,X.b+Y.b);}
line operator*(long long x,line Y){return line(x*Y.k,x*Y.b);}

struct SegmentTree
{
	struct nd
	{
		int l,r;line sum,tag;
	}t[800000];
	void build(int l,int r,int k=1)
	{
		t[k].l=l,t[k].r=r;if(l==r)return;
		int mid=(l+r)>>1;build(l,mid,k<<1),build(mid+1,r,k<<1|1);
	}
	void add_tag(int k,line tag){t[k].sum=t[k].sum+(t[k].r-t[k].l+1)*tag,t[k].tag=t[k].tag+tag;}
	void spread(int k)
	{
		if(t[k].tag.k!=0||t[k].tag.b!=0)
		{
			add_tag(k<<1,t[k].tag),add_tag(k<<1|1,t[k].tag);t[k].tag=line(0,0);
		}
	}
	void update(int k){t[k].sum=t[k<<1].sum+t[k<<1|1].sum;}
	void add(int l,int r,line val,int k=1)
	{
		if(l>t[k].r||r<t[k].l)return;
		if(l<=t[k].l&&t[k].r<=r){add_tag(k,val);return;}
		spread(k);add(l,r,val,k<<1),add(l,r,val,k<<1|1);update(k);
	}
	line query(int l,int r,int k=1)
	{
		if(l>t[k].r||r<t[k].l)return line(0,0);
		if(l<=t[k].l&&t[k].r<=r)return t[k].sum;
		spread(k);return query(l,r,k<<1)+query(l,r,k<<1|1);
	}
}T;

vector<pair<pair<int,int>,line> > E[1100000];vector<pair<int,int> > Q[1100000];
void add_rec(int small_L,int big_L,int small_R,int big_R)
{
	E[small_R].push_back(make_pair(make_pair(small_L,big_L),line(1,-(small_R-1))));
	E[big_R+1].push_back(make_pair(make_pair(small_L,big_L),line(-1,big_R)));
}

long long ans[1100000];int p[1100000],pos[1100000];
vector<int> st;int l[1100000],r[1100000];
vector<pair<int,int> > POS[1100000];

int main()
{
	int n=0,q=0;scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]),pos[p[i]]=i;
	
	p[0]=p[n+1]=n+1;
	st.push_back(0);
	for(int i=1;i<=n;i++)
	{
		while(p[i]>p[st.back()])st.pop_back();
		l[i]=st.back()+1;st.push_back(i);
	}
	st.clear();st.push_back(n+1);
	for(int i=n;i>=1;i--)
	{
		while(p[i]>p[st.back()])st.pop_back();
		r[i]=st.back()-1;st.push_back(i);
	}
	for(int i=1;i*(i+1)<=n;i++)
	{
		for(int j=i+1;i*j<=n;j++)
		{
			int x=pos[i],y=pos[j],z=pos[i*j];if(x>y)swap(x,y);
			if(x>=l[z]&&y<=r[z]){POS[z].push_back(make_pair(min(x,z),max(y,z)));}
		}
	}
	//for(int i=1;i<=n;i++)printf("%d %d\n",l[i],r[i]);
	T.build(1,n);
	for(int i=1;i<=n;i++)
	{
		if(!POS[i].size())continue;
		sort(POS[i].begin(),POS[i].end());
		//printf("%d: \n",i);for(int j=0;j<POS[i].size();j++)printf("%d %d\n",POS[i][j].first,POS[i][j].second);
		vector<pair<int,int> > P;
		for(int j=0;j<POS[i].size();j++)
		{
			while(!P.empty()&&P.back().second>=POS[i][j].second)P.pop_back();P.push_back(POS[i][j]);
		}
		int cur=l[i];
		for(int j=0;j<P.size();j++)
		{
			add_rec(cur,P[j].first,P[j].second,r[i]);
			cur=P[j].first+1;
		}
	}
	
	for(int i=1,l=0,r=0;i<=q;i++)
	{
		scanf("%d%d",&l,&r);Q[r].push_back(make_pair(l,i));
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<E[i].size();j++){T.add(E[i][j].first.first,E[i][j].first.second,E[i][j].second);}
		for(int j=0;j<Q[i].size();j++)
		{
			line L=T.query(Q[i][j].first,i);ans[Q[i][j].second]=i*L.k+L.b;
		}
	}
	for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
}