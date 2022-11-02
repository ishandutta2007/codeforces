#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cassert>
using namespace std;
const int N=404000,Q=404000,Inf=1<<28;
class segment_tree
{
	vector<int> minv;
	int size;
	void change(int pos,int v,int l,int r,int k)
	{
		minv[k]=min(v,minv[k]);
		if(l==r)
			return;
		int mid=(l+r)>>1;
		if(pos<=mid)
			change(pos,v,l,mid,k<<1);
		else
			change(pos,v,mid+1,r,(k<<1)+1);
	}
	int get_min(int l_,int r_,int l,int r,int k)
	{
		if(l>=l_ && r<=r_)
			return minv[k];
		int ans=Inf,mid=(l+r)>>1;
		if(l_<=mid)
			ans=min(get_min(l_,r_,l,mid,k<<1),ans);
		if(r_>mid)
			ans=min(get_min(l_,r_,mid+1,r,(k<<1)+1),ans);
		return ans;
	}
	public:
	void resize(int s)
	{
		size=s;
		minv.clear();
		minv.resize(s*4+1,Inf);
	}
	void insert(int pos,int c)
	{
		change(pos,c,1,size,1);
	}
	int get_min(int l,int r)
	{
		return get_min(l,r,1,size,1);
	}
}T;
struct query
{
	int r1,c1,r2,c2,num;
}t[Q]={};
bool query_cmp(const query &q1,const query &q2)
{
	return q1.r2<q2.r2;
}
bool query_cmp2(const query &q1,const query &q2)
{
	return q1.r1<q2.r1;
}
inline int delta(int a,int b)
{
	return a>b ? a-b : b-a;
}
int n,q,a[N]={},ans[Q]={},c[Q]={};
vector<query> qlist;
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	scanf("%d",&q);
	for(int i=1;i<=q;++i)
	{
		scanf("%d%d%d%d",&t[i].r1,&t[i].c1,&t[i].r2,&t[i].c2);
		t[i].num=i;
		ans[i]=1+t[i].c2+delta(t[i].r1,t[i].r2); // Situation 1
	}
}
void cross_directly()
{
	vector<int> s(1,0),sv(1,-Inf);
	sort(qlist.begin(),qlist.end(),query_cmp);
	vector<query>::iterator it=qlist.begin();
	for(int i=1;i<=n;++i)
	{
		while(a[i]<sv.back())
			s.pop_back() , sv.pop_back();
		s.push_back(i) , sv.push_back(a[i]);
		while(it!=qlist.end() && it->r2==i)
		{
			int now=it->num,r1=it->r1,r2=it->r2,c1=it->c1,c2=it->c2;
			vector<int>::iterator l=lower_bound(s.begin(),s.end(),r1);
			vector<int>::iterator lv=sv.begin()+(l-s.begin());
			c[now]=*lv;
			ans[now]=min(ans[now],delta(r1,r2)+delta(min(c[now],c1),c2));
			int tmp1=delta(*lower_bound(lv,sv.end(),c2),c2);
			vector<int>::iterator tmp=upper_bound(lv,sv.end(),c2);
			int tmp2=tmp!=lv ? delta(*(--tmp),c2) : Inf;
			ans[now]=min(ans[now],delta(r1,r2)+1+min(tmp1,tmp2));
			++it;
		}
	}
} //Situation 2
void beyond_end()
{
	sort(qlist.rbegin(),qlist.rend(),query_cmp);
	T.resize(n);
	vector<int> s(1,n+1),sv(1,-Inf);
	vector<query>::iterator it=qlist.begin();
	for(int i=n;i>=1;--i)
	{
		while(a[i]<sv.back())
			s.pop_back() , sv.pop_back();
		s.push_back(i) , sv.push_back(a[i]);
		T.insert(i,a[i]+i+i);
		while(it!=qlist.end() && it->r2==i)
		{
			int now=it->num,r1=it->r1,r2=it->r2,c1=min(c[now],it->c1),c2=it->c2;
			vector<int>::iterator lv=upper_bound(sv.begin(),sv.end(),c2);
			vector<int>::iterator l=s.begin()+(lv-sv.begin());
			--lv,--l;
			ans[now]=min(ans[now],delta(r1,r2)+c2-*lv+2*(*l-i)+(*lv>c1));
			++lv,++l;
			vector<int>::iterator dv=--upper_bound(sv.begin(),sv.end(),c1);
			vector<int>::iterator d=s.begin()+(dv-sv.begin());
			if(l<=d)
				ans[now]=min(ans[now],delta(r1,r2)+T.get_min(*d,*l)-i-i-c2);
			++dv,++d;
			if(l!=s.end() && d!=s.end())
				ans[now]=min(ans[now],delta(r1,r2)+T.get_min(i,*max(l,d))-i-i-c2+1);
			++it;
		}
	}
} //Situation 3
void beyond_start()
{
	sort(qlist.begin(),qlist.end(),query_cmp2);
	T.resize(n);
	vector<int> s(1,0),sv(1,-Inf);
	vector<query>::iterator it=qlist.begin();
	for(int i=1;i<=n;++i)
	{
		while(a[i]<sv.back())
			s.pop_back() , sv.pop_back();
		s.push_back(i) , sv.push_back(a[i]);
		T.insert(i,a[i]-i-i);
		while(it!=qlist.end() && it->r1==i)
		{
			int now=it->num,r1=it->r1,r2=it->r2,c1=it->c1,c2=it->c2;
			vector<int>::iterator ev=--upper_bound(sv.begin(),sv.end(),c[now]);
			vector<int>::iterator e=s.begin()+(ev-sv.begin());
			vector<int>::iterator lv=upper_bound(sv.begin(),sv.end(),c2);
			vector<int>::iterator l=s.begin()+(lv-sv.begin());
			--lv,--l;
			if(l<=e)
				ans[now]=min(ans[now],delta(r1,r2)+c2-*lv+2*(i-*l)+(*lv>c1));
			++lv,++l;
			vector<int>::iterator dv=--upper_bound(sv.begin(),sv.end(),c1);
			vector<int>::iterator d=s.begin()+(dv-sv.begin());
			if(l<=min(d,e))
				ans[now]=min(ans[now],delta(r1,r2)+T.get_min(*l,*min(d,e))+i+i-c2);
			++d,++dv;
			if(max(l,d)<=e)
				ans[now]=min(ans[now],delta(r1,r2)+T.get_min(*max(l,d),*e)+i+i-c2+1);
			++it;
		}
	}
} //Situation 4
void calc_ans()
{
	qlist.clear();
	for(int i=1;i<=q;++i)
		if(t[i].r2>=t[i].r1)
			qlist.push_back(t[i]);
	cross_directly();
	beyond_end();
	beyond_start();
}
void reverse()
{
	reverse(a+1,a+n+1);
	for(int i=1;i<=q;++i)
	{
		t[i].r1=n+1-t[i].r1;
		t[i].r2=n+1-t[i].r2;
	}
}
void work()
{
	calc_ans();
	reverse();
	calc_ans();
	for(int i=1;i<=q;++i)
		printf("%d\n",ans[i]);
			
}
int main()
{
	init();
	work();
	return 0;
}