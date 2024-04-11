#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 105

using namespace std;

bool use[6][6];
bool aru[6];
char str[6];

int ctoi(char c)
{
	if(c=='G') return 0;
	if(c=='R') return 1;
	if(c=='B') return 2;
	if(c=='Y') return 3;
	return 4;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",&str);
		use[ctoi(str[0])][str[1]-'1']=true;
	}
	int ret=10;
	for(int S=0;S<1<<5;S++)
	{
		for(int T=0;T<1<<5;T++)
		{
			int cnt=0;
			for(int i=0;i<5;i++)
			{
				if(S>>i&1) cnt++;
				if(T>>i&1) cnt++;
			}
			memset(aru,false,sizeof(aru));
			bool up=true;
			int un=0;
			for(int i=0;i<5;i++)
			{
				if(S>>i&1)
				{
					int pos=0;
					for(int j=0;j<5;j++)
					{
						if(!use[i][j]) continue;
						if(!(T>>j&1))
						{
							pos++;
						}
					}
					if(pos>=2)
					{
						up=false;
						break;
					}
				}
				else
				{
					for(int j=0;j<5;j++)
					{
						if(!use[i][j]) continue;
						if(!(T>>j&1))
						{
							un++;
						}
						else if(aru[j])
						{
							up=false;
						}
						else aru[j]=true;
					}
				}
			}
			if(un>=2||!up) continue;
			ret=min(ret,cnt);
		}
	}
	printf("%d\n",ret);
	return 0;
}