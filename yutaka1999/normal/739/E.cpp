#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#define SIZE 2005
#define INF 100000000000LL

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;

struct getBotKsum
{
	multiset <ll> now,zan;
	multiset <ll>::iterator it;
	ll sum;
	
	void init()
	{
		now.clear();
		zan.clear();
		sum=0;
	}
	void ins(ll k)
	{
		if(now.empty()) zan.insert(k);
		else
		{
			it=now.end();it--;
			if(*it<=k) zan.insert(k);
			else
			{
				ll v=*it;
				sum-=v;
				zan.insert(v);
				now.erase(it);
				sum+=k;
				now.insert(k);
			}
		}
	}
	void rem(ll k)
	{
		//puts("O");
		//prllf("%d\n",k);
		//for(it=now.begin();it!=now.end();it++) prllf("%d ",*it);puts("");
		//for(it=zan.begin();it!=zan.end();it++) prllf("%d ",*it);puts("");
		if(now.empty())
		{
			it=zan.lower_bound(k);
			zan.erase(it);
		}
		else
		{
			it=now.end();it--;
			if(*it<k)
			{
				it=zan.lower_bound(k);
				zan.erase(it);
			}
			else
			{
				it=now.lower_bound(k);
				now.erase(it);
				sum-=k;
				if(!zan.empty())
				{
					it=zan.begin();
					ll v=*it;
					sum+=v;
					now.insert(v);
					zan.erase(it);
				}
			}
		}
		//puts("K");
	}
	void change_size(ll k)
	{
		if(now.size()+zan.size()<k) return;
		while(now.size()>k)
		{
			it=now.end();it--;
			ll v=*it;
			sum-=v;
			zan.insert(v);
			now.erase(it);
		}
		while(now.size()<k)
		{
			it=zan.begin();
			ll v=*it;
			sum+=v;
			now.insert(v);
			zan.erase(it);
		}
	}
	ll get(ll k)//ka
	{
		change_size(k);
		return sum;
	}
};
getBotKsum gt;
P A[SIZE],B[SIZE];
ll diff[SIZE];
bool use[SIZE];
bool use2[SIZE];

ll solve(vector <P> query,int a,int b)
{
	int n=query.size();
	if(a+b>n||a<0||b<0) return -INF;
	/*
	prllf("%d %d\n",a,b);
	for(int i=0;i<n;i++) prllf("[%d %d] ",query[i].first,query[i].second);puts("");*/
	for(int i=0;i<n;i++)
	{
		A[i]=P(query[i].first,i);
		B[i]=P(query[i].second,i);
		diff[i]=query[i].first-query[i].second;
	}
	sort(A,A+n,greater <P>());
	sort(B,B+n,greater <P>());
	memset(use,false,sizeof(use));
	memset(use2,false,sizeof(use2));
	gt.init();
	int s=0,t=n-1,nm=0;
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		use2[B[i].second]=true;
		sum+=B[i].first;
		nm++;
	}
	ll ret=-INF;
	for(int i=a;i<=n;i++)
	{
		while(s<i)
		{
			use[A[s].second]=true;
			if(use2[A[s].second])
			{
				sum+=diff[A[s].second];
				gt.ins(diff[A[s].second]);
			}
			else
			{
				sum+=A[s].first;
				nm++;
			}
			s++;
		}
		while(t>=0&&nm>a+b)
		{
			use2[B[t].second]=false;
			if(use[B[t].second])
			{
				gt.rem(diff[B[t].second]);
			}
			else
			{
				sum-=B[t].first;
				nm--;
			}
			t--;
		}
		if(nm>a+b||t+1<b) break;
		ret=max(ret,sum-gt.get(i-a));
	}
	return ret;
}
int U[SIZE],V[SIZE];
char str[10];
int main()
{
	int n,a,b;
	scanf("%d %d %d",&n,&a,&b);
	for(int i=0;i<n;i++)
	{
		int dm,st;
		scanf("%d.%d",&dm,&st);
		U[i]=1000*dm+st;
	}
	for(ll i=0;i<n;i++)
	{
		ll dm,st;
		scanf("%d.%d",&dm,&st);
		V[i]=1000*dm+st;
	}
	vector <P> ord;
	for(ll i=0;i<n;i++) ord.push_back(P(U[i],V[i]));
	sort(ord.begin(),ord.end());
	ll ret=0;
	for(int i=a;i<=n;i++)
	{
		vector <P> query;
		ll sum=0;
		for(int j=0;j<n-i;j++)
		{
			P p=ord[j];
			query.push_back(P(1000*p.second,-INF));
		}
		for(int j=n-i;j<n;j++)
		{
			P p=ord[j];
			query.push_back(P((1000-p.first)*p.second,(p.second-p.first)*1000));
			sum+=1000*p.first;
		}
		sum+=solve(query,b-(i-a),i-a);
		ret=max(ret,sum);
	}
	printf("%.10f\n",(double) ret/1e6);
	return 0;
}