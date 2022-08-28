#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 100005

using namespace std;
typedef long long int ll;

ll mpow(int x,int t,int p)
{
	if(t==0) return 1;
	ll ret=mpow(x,t/2,p);
	ret=ret*ret%p;
	if(t%2==1) ret=ret*(ll) x%p;
	return ret;
}
int gcd(int a,int b)
{
	if(a>b) swap(a,b);
	if(a==0) return b;
	return gcd(b%a,a);
}
int A[SIZE];
int cnt[SIZE];
bool ok[SIZE];
int main()
{
	int n,m,p;
	scanf("%d %d %d",&n,&m,&p);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	int g=p-1;
	for(int i=0;i<m;i++)
	{
		int b;
		scanf("%d",&b);
		g=gcd(g,b);
	}
	vector <int> pr;
	int now=p-1;
	for(int i=2;i*i<=now;i++)
	{
		if(now%i==0)
		{
			pr.push_back(i);
			while(now%i==0) now/=i;
		}
	}
	if(now!=1) pr.push_back(now);
	vector <int> yk;
	for(int i=1;i*i<=p-1;i++)
	{
		if((p-1)%i==0)
		{
			yk.push_back(i);
			if(i!=(p-1)/i) yk.push_back((p-1)/i);
		}
	}
	sort(yk.begin(),yk.end());
	for(int i=0;i<n;i++)
	{
		A[i]=(int) mpow(A[i],g,p);
		int s=p-1;
		for(int j=0;j<pr.size();j++)
		{
			int q=pr[j];
			while(s%q==0&&mpow(A[i],s/q,p)==1) s/=q;
		}
		int pos=lower_bound(yk.begin(),yk.end(),s)-yk.begin();
		ok[pos]=1;
	}
	ll ret=0;
	for(int i=((int) yk.size())-1;i>=0;i--)
	{
		if(ok[i])
		{
			int d=1-cnt[i];
			ret+=(ll) d*(ll) yk[i];
			for(int j=0;j<i;j++)
			{
				if(yk[i]%yk[j]==0)
				{
					ok[j]=true;
					cnt[j]+=d;
				}
			}
		}
	}
	printf("%d\n",(int) ret);
	return 0;
}