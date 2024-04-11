#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define MN 10000005
#define PRN 670000
#define MAX_S 1000000000000000000LL

using namespace std;
typedef pair <int,int> P;
typedef long long int ll;

bool ok[MN];
ll cnt[PRN];
ll imos[MN];
vector <int> prm;
vector <int> vec;

void make()
{
	memset(ok,false,sizeof(ok));
	for(int i=2;i<MN;i++)
	{
		if(!ok[i])
		{
			prm.push_back(i);
			for(int j=i*2;j<MN;j+=i) ok[j]=true;
		}
	}
}
void decom()
{
	for(int i=MN-1;i>1;i--)
	{
		//if(imos[i]==0) continue;
		if(!ok[i])
		{
			int w=lower_bound(prm.begin(),prm.end(),i)-prm.begin();
			cnt[w]=imos[i];
		}
		else
		{
			for(int j=0;j<prm.size();j++)
			{
				int p=prm[j];
				if(i%p==0)
				{
					imos[i/p]+=imos[i];
					imos[p]+=imos[i];
					break;
				}
			}
		}
	}
}
bool qok(ll x)
{
	for(int i=0;i<prm.size();i++)
	{
		int p=prm[i];
		ll sum=0;
		ll y=x;
		while(y>=p)
		{
			y/=p;
			sum+=y;
		}
		if(sum<cnt[i]) return false;
	}
	return true;
}
int main()
{
	make();
	int k;
	scanf("%d",&k);
	memset(imos,0,sizeof(imos));
	for(int i=0;i<k;i++)
	{
		int a;
		scanf("%d",&a);
		imos[2]++;
		imos[a+1]--;
	}
	for(int i=1;i<MN;i++) imos[i]+=imos[i-1];
	decom();
	ll s=0,e=MAX_S;
	while(e-s>1)
	{
		ll med=(s+e)/2;
		if(qok(med)) e=med;
		else s=med;
	}
	printf("%I64d\n",e);
	return 0;
}