#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 1005

using namespace std;
typedef pair <int,int> P;

P in[SIZE];

int main()
{
	int n,m,k,t;
	scanf("%d %d %d %d",&n,&m,&k,&t);
	for(int i=0;i<k;i++) scanf("%d %d",&in[i].first,&in[i].second);
	for(int i=0;i<t;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		P p=P(x,y);
		int cnt=0;
		for(int j=0;j<k;j++)
		{
			if(p==in[j])
			{
				cnt=-1;
				break;
			}
			else if(p>in[j]) cnt++;
		}
		if(cnt==-1) puts("Waste");
		else
		{
			int zan=(x-1)*m+y-cnt;
			if(zan%3==1) puts("Carrots");
			else if(zan%3==2) puts("Kiwis");
			else puts("Grapes");
		}
	}
	return 0;
}