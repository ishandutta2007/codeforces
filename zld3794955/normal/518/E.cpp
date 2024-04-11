#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=100010,L=20,Inf=1<<30;
const long long Inf2=1ll<<60;
int n,k,u[N+N+N]={},*a=&u[N];
bool b[N+N]={};
void init()
{
	char ch[L]={};
	scanf("%d %d\n",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%s\n",ch+1);
		if(ch[1]!='?')
			sscanf(ch+1,"%d",&a[i]);
		else
			b[i]=true;
	}
	for(int i=-n;i<=0;++i)
		a[i]=-Inf;
	for(int i=n+1;i<=n+n;++i)
		a[i]=Inf;
}
long long fill(int l,int r,int d,int sv)
{
	for(int i=l;i<=r;i+=d)
		a[i]=sv++;
	if(a[l-d]>=a[l] || a[r]>=a[r+d])
		return Inf2;
	else
	{
		long long s=0;
		for(int i=l;i<=r;i+=d)
			s+=abs(a[i]);
		return s;
	}
}
void work()
{
	for(int i=1;i<=k;++i)
	{
		int j=i,r=i;
		while(j<=n)
		{
			r=j;
			if(b[r])
			{
				while(b[r+k])
					r+=k;
				int lv=a[j-k]+1,rv=a[r+k]-1;
				long long s[4]={Inf2,Inf2,Inf2,Inf2};
				int v[4]={lv,rv-(r-j)/k,-(r-j)/k/2,-(r-j)/k/2-1};
				for(int t=0;t<=3;++t)
					s[t]=fill(j,r,k,v[t]);
				int p=min_element(s,s+4)-s;
				if(s[p]==Inf2)
				{
					puts("Incorrect sequence");
					return;
				}
				fill(j,r,k,v[p]);
				j=r+k;
			}
			else
			{
				if(!b[r+k] && a[r]>=a[r+k])
				{
					puts("Incorrect sequence");
					return;
				}
				j+=k;
			}
		}
	}
	for(int i=1;i<=n;++i)
		printf("%d%c",a[i]," \n"[i==n]);
}
int main()
{
	init();
	work();
	return 0;
}