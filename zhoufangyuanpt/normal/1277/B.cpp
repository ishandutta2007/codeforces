//luogu
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
set<int,greater<int> > S;
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		S.clear();
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int x;scanf("%d",&x);
			if(x%2==0)S.insert(x);
		}
		int ss=0;
		while(!S.empty())
		{
			set<int>::iterator it=S.begin();
			if(*it/2%2==0)S.insert(*it/2);
			S.erase(it);
			ss++;
		}
		printf("%d\n",ss);
	}
	return 0;
}