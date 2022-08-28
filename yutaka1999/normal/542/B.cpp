#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#define SIZE 200005
#define BT 256*1024*2

using namespace std;
typedef pair <int,int> P;

struct segtree
{
	int seg[BT],add[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=add[i]=0;
	}
	void update(int a,int b,int k,int l,int r,int v)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b)
		{
			seg[k]+=v;
			add[k]+=v;
		}
		else
		{
			update(a,b,k*2+1,l,(l+r)/2,v);
			update(a,b,k*2+2,(l+r)/2,r,v);
			seg[k]=max(seg[k*2+1],seg[k*2+2])+add[k];
		}
	}
	void update(int a,int b,int v)
	{
		update(a,b,0,0,mum,v);
	}
	void ins(int k,int x)
	{
		update(k,k+1,x);
	}
	int get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return 0;
		if(a<=l&&r<=b) return seg[k];
		else
		{
			int vl=get(a,b,k*2+1,l,(l+r)/2);
			int vr=get(a,b,k*2+2,(l+r)/2,r);
			return max(vl,vr)+add[k];
		}
	}
	int get(int a,int b)
	{
		return get(a,b,0,0,mum);
	}
};
segtree seg;
vector <int> vec[SIZE];
int left[SIZE],right[SIZE];

int main()
{
	int n,r;
	scanf("%d %d",&n,&r);
	vector <int> vx;
	vx.push_back(0);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&left[i],&right[i]);
		left[i]=max(left[i],0);
		if(right[i]>=0) vx.push_back(left[i]);
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	for(int i=0;i<n;i++)
	{
		if(right[i]>=0)
		{
			int L=lower_bound(vx.begin(),vx.end(),left[i])-vx.begin();
			vec[L].push_back(right[i]);
		}
	}
	set <int> st;
	for(int i=0;i<vx.size();i++) st.insert(vx[i]);
	seg.init(n+2);
	priority_queue <P,vector <P>,greater <P> > que;//pending
	vector <int> now;
	int mx=-1;
	while(!st.empty())
	{
		int v=*st.begin();
		st.erase(v);
		int pos=lower_bound(vx.begin(),vx.end(),v)-vx.begin();
		if(pos<vx.size()&&vx[pos]==v)
		{
			for(int i=0;i<vec[pos].size();i++) que.push(P(vec[pos][i],v));
		}
		while(!que.empty()&&que.top().first<v)
		{
			P p=que.top();que.pop();
			int s=p.second,t=p.first;
			s=lower_bound(now.begin(),now.end(),s)-now.begin();
			if(s<now.size()) seg.update(s,now.size(),1);
		}
		//vscoremxok
		int back=upper_bound(now.begin(),now.end(),v-r)-now.begin()-1;
		int vl=que.size();
		if(back>=0) vl+=seg.get(0,back+1);
		//printf("%d : %d %d\n",v,que.size(),back);
		//for(int i=0;i<3;i++) printf("%d ",seg.get(i,i+1));puts("");
		if(vl>mx)
		{
			mx=vl;
			//printf("add %d %d\n",now.size(),vl-que.size());
			seg.ins(now.size(),vl-que.size());
			now.push_back(v);
			st.insert(v+r);
		}
	}
	printf("%d\n",mx);
	return 0;
}