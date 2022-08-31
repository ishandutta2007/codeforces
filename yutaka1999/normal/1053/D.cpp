#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 2000005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

int mx[SIZE];
int A[SIZE],tp[SIZE];
bool use[SIZE];
/*
 0->1->1->... 
A LCM B +1 B
\Kv
*/

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int p;
		scanf("%d",&p);
		A[i]=p;
	}
	sort(A,A+n);
	bool up=false;
	for(int i=n-1;i>=0;i--)
	{
		int p=A[i];
		if(mx[p]==0) mx[p]=1,tp[i]=0;
		else
		{
			tp[i]=1;
			p--;
			bool ok=false;
			for(int j=2;j*j<=p;j++)
			{
				if(p%j==0)
				{
					int c=0;
					while(p%j==0) p/=j,c++;
					if(mx[j]<c)
					{
						mx[j]=c;
						ok=true;
					}
				}
			}
			if(p!=1&&mx[p]==0)
			{
				mx[p]=1;
				ok=true;
			}
			if(!ok) up=true;
		}
	}
	ll ret=1;
	for(int i=2;i<SIZE;i++) for(int j=0;j<mx[i];j++) ret=ret*(ll) i%MOD;
	if(!up)
	{
		for(int i=0;i<n;i++)
		{
			int p=A[i];
			if(tp[i]==0) use[p]=true;
			else
			{
				p--;
				bool ok=false;
				for(int j=2;j*j<=p;j++)
				{
					if(p%j==0)
					{
						int c=0;
						while(p%j==0) p/=j,c++;
						if(mx[j]==c&&!use[j])
						{
							use[j]=true;
							ok=true;
						}
					}
				}
				if(p!=1&&mx[p]==1&&!use[p])
				{
					use[p]=true;
					ok=true;
				}
				if(!ok) up=true;
			}
		}
	}
	printf("%lld\n",(ret+up)%MOD);
	return 0;
}