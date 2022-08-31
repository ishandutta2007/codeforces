#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#define SIZE 100005
#define M1 1000000007LL
#define M2 1000000009LL
#define B1 896532
#define B2 7983

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;

ll h1[SIZE],h2[SIZE];
ll r1[SIZE],r2[SIZE];
char str[SIZE];
vector <P> vec[2];
int n;

ll get1(int s,int t)
{
	return (h1[t]-(s==0?0:h1[s-1]*r1[t-s+1]%M1)+M1)%M1;
}
ll get2(int s,int t)
{
	return (h2[t]-(s==0?0:h2[s-1]*r2[t-s+1]%M2)+M2)%M2;
}
void make(int tp)
{
	scanf("%s",&str);
	r1[0]=r2[0]=1;
	for(int i=1;i<=n;i++)
	{
		r1[i]=r1[i-1]*B1%M1;
		r2[i]=r2[i-1]*B2%M2;
	}
	for(int i=0;i<n;i++)
	{
		h1[i]=h2[i]=str[i]-'a'+1;
		if(i>0)
		{
			h1[i]+=h1[i-1]*B1%M1;
			h2[i]+=h2[i-1]*B2%M2;
			if(h1[i]>=M1) h1[i]-=M1;
			if(h2[i]>=M2) h2[i]-=M2;
		}
	}
	for(int i=0;i<=n;i++)
	{
		ll f1=0,s1=0;
		ll f2=0,s2=0;
		if(i>0)
		{
			f1=get1(0,i-1);
			f2=get2(0,i-1);
		}
		if(i<n)
		{
			s1=get1(i,n-1);
			s2=get2(i,n-1);
		}
		for(int j=0;j<26;j++)
		{
			ll g1=(f1*r1[n-i+1]+(ll) (j+1)*r1[n-i]+s1)%M1;
			ll g2=(f2*r2[n-i+1]+(ll) (j+1)*r2[n-i]+s2)%M2;
			vec[tp].push_back(P(g1,g2));
		}
	}
	sort(vec[tp].begin(),vec[tp].end());
	vec[tp].erase(unique(vec[tp].begin(),vec[tp].end()),vec[tp].end());
}
int main()
{
	scanf("%d",&n);
	make(0);
	make(1);
	int to=0;
	int ret=0;
	for(int i=0;i<vec[0].size();i++)
	{
		P v=vec[0][i];
		while(to<vec[1].size()&&vec[1][to]<v) to++;
		if(to<vec[1].size()&&vec[1][to]==v) ret++;
	}
	printf("%d\n",ret);
	return 0;
}