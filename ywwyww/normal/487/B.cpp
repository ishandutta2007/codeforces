#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<set>
using namespace std;
typedef long long ll;
int f[100010];
int c[100010];
multiset<int> a,b;
int main()
{
	int n,s,l;
	scanf("%d%d%d",&n,&s,&l);
	int i;
	for(i=1;i<=n;i++)
		scanf("%d",&c[i]);
	int last=1;
	memset(f,0x7f,sizeof f);
	f[0]=0;
	for(i=1;i<=n;i++)
	{
		a.insert(c[i]);
		if(i-last+1>=l)
			b.insert(f[i-l]);
		while(!a.empty()&&*a.rbegin()-*a.begin()>s)
		{
			a.erase(a.find(c[last]));
			if(i-last+1>=l)
				b.erase(b.find(f[last-1]));
			last++;
		}
		if(!b.empty())
			f[i]=*b.begin()+1;
	}
	printf("%d\n",f[n]>=0x7f7f7f7f?-1:f[n]);
	return 0;
}