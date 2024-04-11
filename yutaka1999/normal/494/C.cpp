#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#define SIZE 5005
#define MX 100005
#define BT 1024*128*2

using namespace std;
typedef pair <int,int> P;
typedef long double ld;

struct segtree
{
	int seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=0;
	}
	void add(int k,int x)
	{
		k+=mum-1;
		seg[k]=x;
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=max(seg[k*2+1],seg[k*2+2]);
		}
	}
	int get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return 0;
		if(a<=l&&r<=b) return seg[k];
		else
		{
			int vl=get(a,b,k*2+1,l,(l+r)/2);
			int vr=get(a,b,k*2+2,(l+r)/2,r);
			return max(vl,vr);
		}
	}
	int get(int a,int b)
	{
		return get(a,b,0,0,mum);
	}
};
segtree seg;
int left[SIZE],right[SIZE],mx[SIZE];
double prob[SIZE];
ld dp[SIZE][SIZE];
set <P> st;
set <P>::iterator it,its;
P pos[SIZE];

int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	seg.init(n+2);
	mx[q]=0;
	for(int i=0;i<n;i++) 
	{
		int a;
		scanf("%d",&a);
		seg.add(i,a);
		mx[q]=max(mx[q],a);
	}
	for(int i=0;i<q;i++)
	{
		scanf("%d %d %lf",&left[i],&right[i],&prob[i]);
		left[i]--;right[i]--;
		mx[i]=seg.get(left[i],right[i]+1);
		pos[i]=P(right[i]-left[i],i);
	}
	left[q]=0;
	right[q]=n-1;
	prob[q]=0.0;
	pos[q]=P(n,q);
	q++;
	sort(pos,pos+q);
	for(int i=0;i<q;i++)
	{
		int v=pos[i].second;
		for(int j=0;j<=q;j++) dp[v][j]=1.0;//dp[v][i]:=(max)<=mx[v]+i  probability
		it=st.lower_bound(P(left[v],-1));
		while(it!=st.end()&&(*it).first<=right[v])
		{
			int u=(*it).second;
			for(int j=0;j<=q;j++)
			{
				int to=j+mx[v]-mx[u];
				if(to<=q) dp[v][j]*=dp[u][to];
			}
			its=it;
			its++;
			st.erase(it);
			it=its;
		}
		st.insert(P(left[v],v));
		for(int j=q;j>=0;j--)
		{
			dp[v][j]*=1.0-prob[v];
			if(j>=1) dp[v][j]+=dp[v][j-1]*prob[v];
		}
	}
	ld pl=0.0;
	for(int j=0;j<=q;j++)
	{
		ld per=dp[q-1][j];
		if(j>=1) per-=dp[q-1][j-1];
		pl+=per*j;
	}
	printf("%.8f\n",(double) mx[q-1]+(double) pl);
	return 0;
}