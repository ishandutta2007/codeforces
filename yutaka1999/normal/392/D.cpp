#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#define SIZE 300005
#define INF 100000000

using namespace std;
typedef pair <int,int> P;

int a[SIZE],b[SIZE],c[SIZE];
int fa[SIZE],fb[SIZE],fc[SIZE];
vector <int> vx;
set <P> st;
set <P>::iterator it,its;
multiset <int> score;
multiset <int>::iterator I;
int n;

void add(int id,int val)
{
	bool up=false;
	it=st.lower_bound(P(id+1,-1));
	if(it!=st.end()&&(*it).first==id+1) up=true;
	it--;
	if((*it).second>=val) return;
	int hi=(*it).second;
	int l;
	while(1)
	{
		if((*it).second>val) break;
		l=(*it).first;
		I=score.lower_bound((*it).first+(*it).second);
		score.erase(I);
		if(it==st.begin())
		{
			st.erase(it);
			break;
		}
		else
		{
			its=it;its--;
			st.erase(it);
			it=its;
		}
	}
	st.insert(P(l,val));
	score.insert(l+val);
	if(id+1<=n&&!up)
	{
		st.insert(P(id+1,hi));
		score.insert(id+1+hi);
	}
}/*
void see()
{
	puts("");
	for(it=st.begin();it!=st.end();it++) printf("%d %d\n",(*it).first,(*it).second);
	for(I=score.begin();I!=score.end();I++) printf("%d ",*I);puts("");
}*/
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++) scanf("%d",&b[i]);
	for(int i=0;i<n;i++) scanf("%d",&c[i]);
	for(int i=0;i<n;i++)
	{
		vx.push_back(a[i]);
		vx.push_back(b[i]);
		vx.push_back(c[i]);
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	for(int i=0;i<vx.size();i++) fa[i]=fb[i]=fc[i]=INF;
	for(int i=0;i<n;i++)
	{
		a[i]=lower_bound(vx.begin(),vx.end(),a[i])-vx.begin();
		b[i]=lower_bound(vx.begin(),vx.end(),b[i])-vx.begin();
		c[i]=lower_bound(vx.begin(),vx.end(),c[i])-vx.begin();
		if(fa[a[i]]==INF) fa[a[i]]=i;
		if(fb[b[i]]==INF) fb[b[i]]=i;
		if(fc[c[i]]==INF) fc[c[i]]=i;
	}
	st.insert(P(0,0));
	score.insert(0);
	for(int i=0;i<vx.size();i++)
	{
		if(fa[i]==INF)
		{
			add(fb[i],fc[i]+1);
		}
		//see();
	}
	int ret=n+(*score.begin());
	for(int i=n-1;i>=0;i--)
	{
		if(fa[a[i]]==i) add(fb[a[i]],fc[a[i]]+1);
		ret=min(ret,i+(*score.begin()));
		//see();
	}
	printf("%d\n",ret);
	return 0;
}