#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <set>
#include <functional>
#include <queue>
#include <map>
#define M1 1000000007LL
#define M2 1000000009LL
#define S1 37LL
#define S2 11451499LL
#define SIZE 1000005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

ll hash1[SIZE],hash2[SIZE];
ll r1[SIZE],r2[SIZE];
char str[SIZE];
bool ok[SIZE];
int imos[SIZE];

ll get1(int s,int t)
{
	return (hash1[t]-(s==0?0:hash1[s-1]*r1[t-s+1]%M1)+M1)%M1;
}
ll get2(int s,int t)
{
	return (hash2[t]-(s==0?0:hash2[s-1]*r2[t-s+1]%M2)+M2)%M2;
}
bool good(int s1,int t1,int s2,int t2)
{
	return get1(s1,t1)==get1(s2,t2);//&&get2(s1,t1)==get2(s2,t2);
}
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<SIZE;i++)
	{
		if(i==0) r1[i]=r2[i]=1;
		else
		{
			r1[i]=r1[i-1]*S1%M1;
			r2[i]=r2[i-1]*S2%M2;
		}
	}
	scanf("%s",&str);
	for(int i=0;i<n;i++)
	{
		hash1[i]=hash2[i]=str[i]-'a'+1;
		if(i>0)
		{
			hash1[i]+=hash1[i-1]*S1%M1;
			hash2[i]+=hash2[i-1]*S2%M2;
			hash1[i]%=M1;
			hash2[i]%=M2;
		}
	}
	memset(imos,0,sizeof(imos));
	for(int i=n-1;i>=0;i--)
	{
		if((i+1)%k==0)
		{
			int L=(i+1)/k;
			ok[i]=true;
			for(int j=L;j+L-1<=i;j+=L)
			{
				if(!good(0,L-1,j,j+L-1))
				{
					ok[i]=false;
					break;
				}
			}
			if(ok[i])
			{
				int s=0,e=L+1;
				while(e-s>1)
				{
					int m=(s+e)/2;
					if(i+m<n&&good(0,m-1,i+1,i+m)) s=m;
					else e=m;
				}
				//printf("%d [%d %d]\n",i,s,e);
				imos[i]++;
				imos[i+e]--;
			}
		}
	}
	for(int i=1;i<n;i++) imos[i]+=imos[i-1];
	for(int i=0;i<n;i++)
	{
		if(imos[i]>0) printf("1");
		else printf("0");
	}
	puts("");
	return 0;
}