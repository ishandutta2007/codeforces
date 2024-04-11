#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<set>
#include<vector>
using namespace std;
const int N=200020,Inf=1<<30;
class BIT
{
	vector<int> t;
	int presum(int pos)
	{
		int s=0;
		for(int i=pos;i;i-=i&(-i))
			s+=t[i];
		return s;
	}
	public:
	BIT(int n=0): t(n) {}
	void resize(int n)
	{
		t.resize(n+1);
		fill(t.begin(),t.end(),0);
	}
	void add(int pos,int c)
	{
		for(int i=pos;i<=(int)t.size();i+=i&(-i))
			t[i]+=c;
	}
	int sum(int l,int r)
	{
		return presum(r)-presum(l-1);
	}
}T;
struct event
{
	int type,pos,x,y,num;
}e[N+N]={};
bool cmp(const event &e1,const event &e2)
{
	return e1.pos<e2.pos || (e1.pos==e2.pos && e1.type<e2.type);
}
int n,m,root[N]={},num[N+N]={};
long long s[N]={};
int get_root(int r)
{
	if(r!=root[r])
		root[r]=get_root(root[r]);
	return root[r];
}
inline void merge(int u,int v,long long delta=0)
{
	int ur=get_root(u) , vr=get_root(v);
	if(ur==vr)
		return;
	root[ur]=vr;
	s[vr]+=s[ur]+delta;
	s[ur]=0;
}
void init()
{
	scanf("%d",&n);
	vector<int> v;
	for(int i=1,x1,y1,x2,y2;i<=n;++i)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1==x2)
		{
			e[++m]=(event){1,x1,y1,y2,i};
			root[i]=i;
			s[i]=y2-y1;
			v.push_back(y1);
			v.push_back(y2);
		}
		else
		{
			e[++m]=(event){0,x1,y1,0,i};
			e[++m]=(event){2,x2,y1,0,i};
			root[i]=i;
			s[i]=x2-x1;
			v.push_back(y1);
		}
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()) , v.end());
	T.resize(v.size());
	for(int i=1;i<=m;++i)
		if(e[i].type==1)
		{
			e[i].x=lower_bound(v.begin(),v.end(),e[i].x)-v.begin()+1;
			e[i].y=lower_bound(v.begin(),v.end(),e[i].y)-v.begin()+1;
		}
		else
			e[i].x=lower_bound(v.begin(),v.end(),e[i].x)-v.begin()+1;
	sort(e+1,e+m+1,cmp);
	// "No two horizontal segments share common points."
	// "No two vertical segments share common points."
}
void work()
{
	set<int> beg,end,point,calc;
	beg.insert(-Inf);
	end.insert(-Inf);
	beg.insert(Inf);
	end.insert(Inf);
	point.insert(-Inf);
	point.insert(Inf);
	for(int i=1;i<=m;++i)
	{
		if(e[i].type==0)
		{
			int pos=e[i].x;
			point.insert(pos);
			num[pos]=e[i].num;
			T.add(pos,1);
			int tmp=*--beg.upper_bound(*end.lower_bound(pos));
			beg.insert(pos);
			end.insert(pos);
			if(tmp<=pos)
			{
				beg.insert(*point.upper_bound(pos));
				end.insert(*(--point.lower_bound(pos)));
			}
		}
		if(e[i].type==2)
		{
			int pos=e[i].x;
			point.erase(pos);
			num[pos]=0;
			T.add(pos,-1);
			int r=*end.lower_bound(pos);
			int l=*(--beg.upper_bound(pos));
			if(l==pos)
			{
				if(r==pos)
				{
					beg.erase(pos);
					end.erase(pos);
				}
				else
				{
					beg.insert(*point.upper_bound(pos));
					beg.erase(pos);
				}
			}
			else
				if(r==pos)
				{
					end.insert(*(--point.lower_bound(pos)));
					end.erase(pos);
				}
		}
		if(e[i].type==1)
		{
			calc.clear();
			int lpos=e[i].x , rpos=e[i].y;
			if(point.lower_bound(lpos)==point.upper_bound(rpos))
				continue;
			set<int>::iterator L=end.lower_bound(lpos);
			set<int>::iterator R=end.lower_bound(rpos);
			if(*(--beg.upper_bound(*R))>rpos)
				--R;
			int r=*R,now=get_root(num[r]),tmp1=0,tmp2=0;
			calc.insert(now);
			for(set<int>::iterator it=L;*it!=r;it=end.upper_bound(tmp1))
			{
				tmp1=*it;
				tmp2=get_root(num[tmp1]); // Notice "get_root()" function.
				calc.insert(tmp2);
				merge(tmp2,now);
				end.erase(tmp1);
				beg.erase(beg.upper_bound(tmp1));
			}
			merge(e[i].num,now,(int)calc.size()-T.sum(lpos,rpos));
		}
	}
	long long ans=0;
	for(int i=1;i<=n;++i)
		ans=max(ans,s[get_root(i)]);
	cout<<ans<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}