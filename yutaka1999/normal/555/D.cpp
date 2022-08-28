#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <map>
#include <set>
#include <cmath>
#define SIZE 200005

using namespace std;
typedef long long int ll;
typedef pair <ll,int> P;

P ppp[SIZE];
ll pos[SIZE];
int id[SIZE],ch[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		ll p;
		scanf("%I64d",&p);
		ppp[i]=P(p,i);
	}
	sort(ppp,ppp+n);
	for(int i=0;i<n;i++)
	{
		id[i]=ppp[i].second;
		pos[i]=ppp[i].first;
		ch[id[i]]=i;
	}
	for(int i=0;i<m;i++)
	{
		int p;
		ll L;
		scanf("%d %I64d",&p,&L);p--;
		p=ch[p];
		while(1)
		{
			int to=upper_bound(pos,pos+n,pos[p]+L)-pos-1;
			L-=pos[to]-pos[p];
			int left=lower_bound(pos,pos+n,pos[to]-L)-pos;
			if(to==left)
			{
				printf("%d\n",id[to]+1);
				break;
			}
			ll d=pos[to]-pos[left];
			L%=2*d;
			if(L<d) p=to;
			else
			{
				p=left;
				L-=d;
			}
		}
	}
	return 0;
}