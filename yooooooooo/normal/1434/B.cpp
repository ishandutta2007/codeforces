#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
int n,p[200005],x,pos[100005];
char s[5];
set<int>st1,st2;
set<int>::iterator it,it2;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)
	{
		scanf("%s",s);
		if(s[0]=='+')st1.insert(i);
		else
		{
			scanf("%d",&x);
			pos[x]=i;
			st2.insert(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		it=st1.lower_bound(pos[i]);
		it2=st2.lower_bound(pos[i]);
		if(it==st1.begin())
		{
			printf("NO\n");
			return 0;
		}
		it--;
		if(it2!=st2.begin())
		{
			it2--;
			if(*it2>*it)
			{
				printf("NO\n");
				return 0;
			}
		}
		p[*it]=i;
		st1.erase(it);
		st2.erase(pos[i]);
	}
	printf("YES\n");
	int tt=0;
	for(int i=1;i<=2*n;i++)
	{
		if(p[i])printf("%d",p[i]),tt++;
		else continue;
		if(tt<n)printf(" ");
		else printf("\n");
	}
	return 0;
}