#include<bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for(int i=a;i<=b;++i)
long long query(long long);
struct node
{
	int t,x,z;
	node(int tt=0,int xx=0,int zz=0){t=tt,x=xx,z=zz;}
	inline bool operator <(const node &b)const
	{
		if(t<b.t)return true;
		if(t>b.t)return false;
		return x>b.x;
	}
}b[10005];
std::priority_queue<node>pq;
bool prime[10005];
long long query(long long x)
{
	printf("? %lld\n",x);
	fflush(stdout);
	scanf("%lld",&x);
	return x;
}
void init()
{
	for(int i=1;i<=10000;++i)prime[i]=1;
	prime[1]=0;
	for(int i=2;i<=10000;++i)
	{
		if(prime[i])
		{
			for(int j=i;1LL*i*j<=1000;++j)prime[i*j]=0;
		}
	}
}
void report(int x)
{
	printf("! %d\n",x);
	fflush(stdout);
}
int guess(int M)
{
	while(!pq.empty())pq.pop();
	for(int i=2;i<=10000;++i)if(prime[i])pq.push(node(1,i,i));
	int ans=1;
	FOR(i,1,22)
	{
		ll x=1,cnt=0;
		while(!pq.empty())
		{
			node temp=pq.top();
			pq.pop();
			if(1.0*x*temp.x>1e18){pq.push(temp);break;}
			b[++cnt]=temp,x*=temp.x;
		}
		int ss=query(x);
		FOR(i,1,cnt)
		{
			if(ss%b[i].x==0)
			{
				ans/=b[i].t;
				ans*=(++b[i].t);
				b[i].x*=b[i].z;
				pq.push(b[i]);
			}
		}
	}
	return ans*2;
}
int main()
{
	int T;scanf("%d",&T);
	init();
	while(T--)report(guess(22));
}//