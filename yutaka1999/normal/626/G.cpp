#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#define SIZE 200005
#define MX 100000000

using namespace std;
typedef long long int ll;
typedef long double ld;

struct Q
{
	ll a,b;// , @normalize
	Q(ll a=0,ll b=1):a(a),b(b){}
	bool operator<(const Q&l) const
	{
		//a/b<l.a/l.b
		return a*l.b<l.a*b;
	}
	bool operator>(const Q&l) const
	{
		//a/b>l.a/l.b
		return a*l.b>l.a*b;
	}
	Q operator-(const Q&l) const
	{
		//a/b-l.a/l.b;
		return Q(a*l.b-l.a*b,b*l.b);
	}
	ld val()
	{
		return (ld) a/(ld) b;
	}
};
typedef pair <Q,int> P;
int pr[SIZE],L[SIZE];
int now[SIZE];
set <P> st,nxt;
set <P>::iterator it;
ld sum;
int cnt;
int n,T,q;

Q get(int v,int k)
{
	if(k>L[v]) return Q(0,1);
	if(k==0) return Q(MX,1);
	return Q(pr[v]*L[v],(ll) (L[v]+k)*(ll) (L[v]+k-1));
}
void add()
{
	while(cnt<T)
	{
		it=nxt.end();it--;
		P p=*it;
		//printf("%d : %lld %lld\n",p.second,p.first.a,p.first.b);
		if(p.first.a==0) break;
		cnt++;
		sum+=p.first.val();
		int v=p.second;
		st.erase(P(get(v,now[v]),v));
		nxt.erase(P(get(v,now[v]+1),v));
		now[v]++;
		st.insert(P(get(v,now[v]),v));
		nxt.insert(P(get(v,now[v]+1),v));
	}
}
void change()
{
	while(1)
	{
		it=st.begin();
		P p=*it;
		it=nxt.end();it--;
		P q=*it;
		//puts("OK");
		if(p.first<q.first)
		{
			sum+=q.first.val()-p.first.val();
			int a=p.second,b=q.second;
			//printf("%d : %lld %lld : %lld %lld\n",a,get(a,now[a]).a,get(a,now[a]).b,p.first.a,p.first.b);
			//printf("%d : %lld %lld : %lld %lld\n",b,get(b,now[b]+1).a,get(b,now[b]+1).b,q.first.a,q.first.b);
			st.erase(P(get(a,now[a]),a));
			nxt.erase(P(get(a,now[a]+1),a));
			st.erase(P(get(b,now[b]),b));
			nxt.erase(P(get(b,now[b]+1),b));
			now[a]--;now[b]++;
			st.insert(P(get(a,now[a]),a));
			nxt.insert(P(get(a,now[a]+1),a));
			st.insert(P(get(b,now[b]),b));
			nxt.insert(P(get(b,now[b]+1),b));
		}
		else break;
	}
}
int main()
{
	scanf("%d %d %d",&n,&T,&q);
	for(int i=0;i<n;i++) scanf("%d",&pr[i]);
	for(int i=0;i<n;i++) scanf("%d",&L[i]);
	for(int i=0;i<n;i++)
	{
		now[i]=0;
		st.insert(P(get(i,now[i]),i));
		nxt.insert(P(get(i,now[i]+1),i));
	}
	cnt=0;
	sum=0.0;
	add();
	//printf("%.10f\n",(double) sum);
	for(int i=0;i<q;i++)
	{
		//printf("%d\n",i);
		int tp,v;
		scanf("%d %d",&tp,&v);v--;
		st.erase(P(get(v,now[v]),v));
		nxt.erase(P(get(v,now[v]+1),v));
		sum-=(ld) (pr[v]*now[v])/(ld) (L[v]+now[v]);
		bool up=false;
		if(now[v]>0)
		{
			now[v]--;
			cnt--;
			up=true;
		}
		if(tp==1) L[v]++;
		else L[v]--;
		st.insert(P(get(v,now[v]),v));
		nxt.insert(P(get(v,now[v]+1),v));
		sum+=(ld) (pr[v]*now[v])/(ld) (L[v]+now[v]);
		add();
		//puts("YES");
		change();
		printf("%.10f\n",(double) sum);
	}
	return 0;
}