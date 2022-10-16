#include<cstdio>

using namespace std;

struct SegmentTree
{
	struct nd
	{
		int l,r,sum;
	}t[1200000];
	void build(int l,int r,int k=1)
	{
		int mid=(l+r)>>1;t[k].l=l,t[k].r=r,t[k].sum=0;if(l==r)return;
		build(l,mid,k<<1),build(mid+1,r,k<<1|1);
	}
	void update(int k){t[k].sum=t[k<<1].sum+t[k<<1|1].sum;}
	void add(int pos,int val,int k=1)
	{
		t[k].sum+=val;if(t[k].l==t[k].r)return;
		int mid=(t[k].l+t[k].r)>>1;if(pos<=mid)add(pos,val,k<<1);else add(pos,val,k<<1|1);
	}
	int query(int l,int r,int k=1)
	{
		if(l>t[k].r||r<t[k].l)return 0;
		if(l<=t[k].l&&t[k].r<=r){return t[k].sum;}
		return query(l,r,k<<1)+query(l,r,k<<1|1);
	}
}T;

int n;
int query(int l,int r)
{
	if(l<r)return T.query(l,r);return T.query(l,n)+T.query(1,r);
}

int p[300000],f[300000];

int main()
{
	int TT=0;scanf("%d",&TT);
	while(TT--)
	{
		scanf("%d",&n);for(int i=1;i<=n;i++){scanf("%d",&p[i]);f[p[i]]=i;}
		T.build(1,n);
		/*for(int i=n;i>=1;i--)
		{
			while(!st.empty()&&p[st.back()]>p[i])st.pop_back();
			if(!st.empty())pos[i]=st.back();
			st.push_back(i);
		}
		minnp[1]=p[1];for(int i=2;i<=n;i++)minnp[i]=min(minnp[i-1],p[i]);
		for(int i=1,lst=n;i<=n;i++)
		{
			for(int j=minnp[i];j<=lst;j++)tmp[j]=i;
			j=minnp[i]-1;
		}
		for(int i=1;i<=n;i++)if(!pos[i])pos[i]=tmp[p[i]];*/
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			//for(int j=1;j<=n;j++)printf("%d ",T.query(j,j));puts("");
			if(i>=3)ans+=(long long)(query(f[i-1],f[i])-1)*(n-i+1);
			//if(i>=2)printf("%d %d %lld\n",f[i-1],f[i],query(f[i-1],f[i]));
			T.add(f[i],1);
			
		}
		printf("%lld\n",ans);
	}
}