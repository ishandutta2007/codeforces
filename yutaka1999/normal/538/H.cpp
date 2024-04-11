#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 200005
#define BT 256*1024*2

using namespace std;
typedef pair <int,int> P;

P merge(P p,P q)
{
	return P(max(p.first,q.first),min(p.second,q.second));
}
struct segtree
{
	P seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=P(0,BT);
	}
	void update(int a,int b,int k,int l,int r,P p)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b) seg[k]=merge(seg[k],p);
		else
		{
			update(a,b,k*2+1,l,(l+r)/2,p);
			update(a,b,k*2+2,(l+r)/2,r,p);
		}
	}
	void update(int a,int b,P p)
	{
		update(a,b,0,0,mum,p);
	}
	P get(int k)
	{
		k+=mum-1;
		P ret=seg[k];
		while(k>0)
		{
			k=(k-1)/2;
			ret=merge(ret,seg[k]);
		}
		return ret;
	}
};
segtree sl,sr;
vector <int> vec[SIZE];
int bg[SIZE],col[SIZE];
int L[SIZE],R[SIZE];
P left[SIZE],right[SIZE];
P l1[SIZE],r1[SIZE];
P l2[SIZE],r2[SIZE];
P pos[SIZE];
int ans[SIZE];

int main()
{
	int t,T;
	scanf("%d %d",&t,&T);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		r=min(r,T);
		if(l>r)
		{
			puts("IMPOSSIBLE");
			return 0;
		}
		pos[i]=P(l,r);
	}
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	memset(col,-1,sizeof(col));
	int sz=0;
	for(int i=0;i<n;i++)
	{
		if(col[i]==-1)
		{
			int zero=-1,one=-1;
			queue <int> que;
			col[i]=0;
			que.push(i);
			while(!que.empty())
			{
				int v=que.front();que.pop();
				if(col[v]==0)
				{
					if(zero==-1) zero=v;
					pos[zero]=merge(pos[zero],pos[v]);
					bg[v]=zero;
				}
				else
				{
					if(one==-1) one=v;
					pos[one]=merge(pos[one],pos[v]);
					bg[v]=one;
				}
				for(int j=0;j<vec[v].size();j++)
				{
					int to=vec[v][j];
					if(col[to]==-1)
					{
						col[to]=col[v]^1;
						que.push(to);
					}
					else if(col[to]==col[v])
					{
						puts("IMPOSSIBLE");
						return 0;
					}
				}
			}
			L[sz]=zero,R[sz]=one;
			left[sz]=pos[zero];
			if(one==-1) right[sz]=P(0,T);
			else right[sz]=pos[one];
			if(left[sz].first>left[sz].second||right[sz].first>right[sz].second)
			{
				puts("IMPOSSIBLE");
				return 0;
			}
			if(left[sz].second>right[sz].second)
			{
				swap(L[sz],R[sz]);
				swap(left[sz],right[sz]);
			}
			//printf("[%d %d] [%d %d]\n",left[sz].first,left[sz].second,right[sz].first,right[sz].second);
			sz++;
		}
	}
	//l
	//LDILAR
	//WkAlleft,rightmergeOvZ
	vector <int> vx;
	vx.push_back(0);
	vx.push_back(T+1);//vx.size()>=2
	for(int i=0;i<sz;i++)
	{
		left[i].second++,right[i].second++;//J
		vx.push_back(left[i].first);
		vx.push_back(left[i].second);
		vx.push_back(right[i].first);
		vx.push_back(right[i].second);
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	for(int i=0;i<vx.size();i++) l1[i]=r1[i]=l2[i]=r2[i]=P(0,vx.size());
	sl.init(vx.size()+2);
	sr.init(vx.size()+2);
	for(int i=0;i<sz;i++)
	{
		int a=lower_bound(vx.begin(),vx.end(),left[i].first)-vx.begin();
		int b=lower_bound(vx.begin(),vx.end(),left[i].second)-vx.begin();
		int c=lower_bound(vx.begin(),vx.end(),right[i].first)-vx.begin();
		int d=lower_bound(vx.begin(),vx.end(),right[i].second)-vx.begin();
		//printf("[%d %d] [%d %d]\n",a,b,c,d);
		l1[a]=merge(l1[a],P(a,b));
		r1[a]=merge(r1[a],P(c,d));
		l2[b]=merge(l2[b],P(a,b));
		r2[b]=merge(r2[b],P(c,d));
		sl.update(a,b,P(a,b));
		sr.update(a,b,P(c,d));
	}
	for(int i=((int) vx.size())-2;i>=0;i--) l1[i]=merge(l1[i],l1[i+1]),r1[i]=merge(r1[i],r1[i+1]);
	for(int i=1;i<vx.size();i++) l2[i]=merge(l2[i],l2[i-1]),r2[i]=merge(r2[i],r2[i-1]);
	int A=-1,B=-1;
	for(int i=0;i+1<vx.size();i++)
	{
		//vx[i]`vx[i+1]-1zu
		//A
		P f,s;//fAs
		f=merge(r1[i+1],r2[i]);
		f=merge(f,sl.get(i));
		s=merge(l1[i+1],l2[i]);
		s=merge(s,sr.get(i));
		s=merge(s,P(i,vx.size()));
		//printf("%d : [%d %d] [%d %d]\n",i,f.first,f.second,s.first,s.second);
		if(f.first<=i&&i<f.second&&s.first<s.second)
		{
			int a=vx[i],b=vx[i+1]-1;
			int c=vx[s.first],d=vx[s.second]-1;
			if(b+d<t||a+c>T) continue;
			int tg=min(b+d,T);
			int diff=tg-(a+c);
			A=a,B=c;
			if(diff<=b-a) A+=diff;
			else
			{
				A+=b-a;
				B=tg-A;
			}
			break;
		}
	}
	if(A==-1)
	{
		puts("IMPOSSIBLE");
		return 0;
	}
	puts("POSSIBLE");
	printf("%d %d\n",A,B);
	for(int i=0;i<sz;i++)
	{
		if(left[i].first<=A&&A<=left[i].second)
		{
			ans[L[i]]=1;
			ans[R[i]]=2;
		}
		else
		{
			ans[L[i]]=2;
			ans[R[i]]=1;
		}
	}
	for(int i=0;i<n;i++) printf("%d",ans[bg[i]]);puts("");
	return 0;
}