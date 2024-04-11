#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7,M=2000;

int n,m;

struct Query{
	int l,r,x,k,id;
	Query(int _l=0,int _r=0,int _x=0,int _k=0,int _id=0){l=_l,r=_r,x=_x,k=_k,id=_id;}
};

struct OP{
	int x,y,last;
	OP(int _x=0,int _y=0,int _last=0){x=_x,y=_y,last=_last;}
};

vector<Query>q;

vector<OP>s;

int a[N],cnt[N],last[N],ans[N];

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

pii cr[N];

vector<pii>ord;

bool cmp(Query a,Query b)
{
	int la=a.l/M,lb=b.l/M;
	int ra=a.r/M,rb=b.r/M;
	if(la==lb&&ra==rb)
		return a.x<b.x;
	if(la==lb)
		return ra<rb;
	return la<lb;
}

int l,r,x;

int val[N];

pii ran[N];

void del(int w)
{
	cnt[w]--;
	ran[cnt[w]+1].fs++;
	if(ran[cnt[w]].fs==0||ran[cnt[w]].fs>ran[cnt[w]].sd)
		ran[cnt[w]].fs=ran[cnt[w]].sd=ran[cnt[w]+1].fs-1;
	else
		ran[cnt[w]].sd++;
	val[ran[cnt[w]].sd]=cnt[w];
}

void ins(int w)
{
	cnt[w]++;
	ran[cnt[w]-1].sd--;
	if(ran[cnt[w]].fs==0||ran[cnt[w]].fs>ran[cnt[w]].sd)
		ran[cnt[w]].fs=ran[cnt[w]].sd=ran[cnt[w]-1].sd+1;
	else
		ran[cnt[w]].fs--;
	val[ran[cnt[w]].fs]=cnt[w];
}

void change(int x,int y)
{
	if(x>=l&&x<=r)
		del(a[x]);
	a[x]=y;
	if(x>=l&&x<=r)
		ins(a[x]);
}

int isq[N];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),last[i]=a[i];
	for(int i=1;i<=m;i++)
	{
		int op;
		scanf("%d",&op);
		if(op==1)
		{
			int l,r,k;
			isq[i]=1;
			scanf("%d%d%d",&l,&r,&k);
			q.push_back(Query(l,r,(int)s.size()-1,k,i));
		}
		else
		{
			int x,y;
			scanf("%d%d",&x,&y);
			s.push_back(OP(x,y,last[x]));
			last[x]=y;
		}
	}
	sort(q.begin(),q.end(),cmp);
	l=1,r=0,x=-1;
	ran[0].fs=1,ran[0].sd=n;
	for(auto qi:q)
	{	
		while(x<qi.x)
			x++,change(s[x].x,s[x].y);
		while(x>qi.x)
			change(s[x].x,s[x].last),x--;
		while(l>qi.l)
			l--,ins(a[l]);
		while(r<qi.r)
			r++,ins(a[r]);
		while(l<qi.l)
			del(a[l]),l++;
		while(r>qi.r)
			del(a[r]),r--;
		ord.clear();
		for(int i=n;val[i];i=ran[val[i]].fs-1)
			ord.push_back(mp(val[i],ran[val[i]].sd-ran[val[i]].fs+1));
		reverse(ord.begin(),ord.end());
		int know=0,res=1e9,last=0;
		for(auto [a,b]:ord)
		{
			know+=b;
			while(know-ord[last].sd>=qi.k)
				know-=ord[last].sd,last++;
			if(know>=qi.k)
				res=min(res,a-ord[last].fs);
		}
		ans[qi.id]=res;
	}
	for(int i=1;i<=m;i++)
		if(isq[i])
			printf("%d\n",ans[i]==1e9?-1:ans[i]);
}