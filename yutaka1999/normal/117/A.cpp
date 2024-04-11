#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef long long int ll;

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);m--;
	for(int i=0;i<n;i++)
	{
		int s,f,t;
		scanf("%d %d %d",&s,&f,&t);s--;f--;
		if(s>f)
		{
			s=2*m-s;
			f=2*m-f;
		}
		if(s==f) printf("%d\n",t);
		else
		{
			int w=t%(2*m);
			if(w<=s) printf("%d\n",t+(f-w));
			else
			{
				t=(t/(2*m)+1)*2*m;
				printf("%d\n",t+f);
			}
		}
	}
	return 0;
}