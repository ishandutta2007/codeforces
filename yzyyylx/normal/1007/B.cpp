#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
#define N 100100
using namespace std;

ll T,a,b,c,cnt[N],zs[N],zz,A,B,C,AB,AC,ABC,BC,ab,ac,bc,abc;
bool P[N];

inline void get()
{
	ll i,j,t,mx=0;
	cnt[1]=1;
	for(i=2; i<=100000; i++)
	{
		if(!P[i])
		{
			cnt[i]=2,zs[++zz]=i;
			for(j=i+i; j<=100000; j+=i)
			{
				P[j]=1;
			}
		}
	}
	for(i=2; i<=100000; i++)
	{
		if(!P[i]) continue;
		ll res=1;
		t=i;
		for(j=1; t>1; j++)
		{
			ll tmp=1;
			for(; t%zs[j]==0; t/=zs[j]) tmp++;
			res*=tmp;
		}
		cnt[i]=res;
		mx=max(mx,cnt[i]);
	}
}

inline ll gcd(ll u,ll v)
{
	for(; u&&v&&u!=v;)
	{
		swap(u,v);
		u%=v;
	}
	return max(u,v);
}

int main()
{
	ll i,j,p,q;
	get();
	cin>>T;
	while(T--)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		ab=gcd(a,b);
		ac=gcd(a,c);
		bc=gcd(b,c);
		abc=gcd(ab,c);
		ABC=cnt[abc];
		AB=cnt[ab]-cnt[abc];
		AC=cnt[ac]-cnt[abc];
		BC=cnt[bc]-cnt[abc];
		A=cnt[a]-cnt[ab]-cnt[ac]+cnt[abc];
		B=cnt[b]-cnt[ab]-cnt[bc]+cnt[abc];
		C=cnt[c]-cnt[ac]-cnt[bc]+cnt[abc];
//		cout<<A<<" "<<B<<" "<<C<<" "<<AB<<" "<<AC<<" "<<BC<<" "<<ABC<<endl;
		printf("%lld\n",A*B*C+A*B*AC+A*B*BC+A*B*ABC+A*AB*C+A*AB*AC+A*AB*BC+A*AB*ABC+A*BC*C+A*BC*AC+(BC+BC*(BC-1)/2)*A+A*BC*ABC+A*ABC*C+A*ABC*AC+(ABC+ABC*(ABC-1)/2)*A+AB*B*C+AB*B*AC+AB*B*BC+AB*B*ABC+(AB+AB*(AB-1)/2)*C+(AB+AB*(AB-1)/2)*AC+(AB+AB*(AB-1)/2)*BC+(AB+AB*(AB-1)/2)*ABC+AB*BC*C+AB*BC*AC+(BC+BC*(BC-1)/2)*AB+AB*BC*ABC+AB*ABC*C+AB*ABC*AC+(ABC+ABC*(ABC-1)/2)*AB+AC*B*C+(AC+AC*(AC-1)/2)*B+AC*B*BC+AC*B*ABC+AC*AB*C+(AC+AC*(AC-1)/2)*AB+AC*BC*C+(AC+AC*(AC-1)/2)*BC+(BC+BC*(BC-1)/2)*AC+AC*BC*ABC+AC*ABC*C+(AC+AC*(AC-1)/2)*ABC+(ABC+ABC*(ABC-1)/2)*AC+ABC*B*C+ABC*B*BC+(ABC+ABC*(ABC-1)/2)*B+ABC*BC*C+(BC+BC*(BC-1)/2)*ABC+(ABC+ABC*(ABC-1)/2)*BC+(ABC+ABC*(ABC-1)/2)*C+ABC+(ABC-1)*ABC+ABC*(ABC-1)*(ABC-2)/6);
	}
}