#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#define SIZE 1000005
#define M1 1000000007LL
#define B1 89793LL

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

char str[SIZE];
ll h1[SIZE],rt[SIZE];

ll get1(int s,int t)
{
	return (h1[t]-(s==0?0:h1[s-1]*rt[t-s+1]%M1)+M1)%M1;
}
int main()
{
	scanf("%s",&str);
	string S=str;
	scanf("%s",&str);
	string T=str;
	rt[0]=1;
	for(int i=1;i<=T.size();i++) rt[i]=rt[i-1]*B1%M1;
	for(int i=0;i<T.size();i++)
	{
		h1[i]=T[i]-'a'+1;
		if(i>0)
		{
			h1[i]+=h1[i-1]*B1%M1;
			if(h1[i]>=M1) h1[i]-=M1;
		}
	}
	int a=0,b=0;
	for(int i=0;i<S.size();i++)
	{
		if(S[i]=='0') a++;
		else b++;
	}
	int ret=0;
	for(int i=0;i<T.size();i++)
	{
		int lz=i+1;
		if(a*lz>=T.size()) break;
		if(((int) T.size()-a*lz)%b==0)
		{
			int lo=((int) T.size()-a*lz)/b;
			ll h0=-1,h1=-1;
			bool up=true;
			int now=0;
			for(int j=0;j<S.size();j++)
			{
				if(S[j]=='0')
				{
					ll h=get1(now,now+lz-1);
					now+=lz;
					if(h0==-1) h0=h;
					else if(h0!=h)
					{
						up=false;
						break;
					}
				}
				else
				{
					ll h=get1(now,now+lo-1);
					now+=lo;
					if(h1==-1) h1=h;
					else if(h1!=h)
					{
						up=false;
						break;
					}
				}
			}
			if(up&&h0!=h1)
			{
				ret++;
			}
		}
	}
	printf("%d\n",ret);
	return 0;
}