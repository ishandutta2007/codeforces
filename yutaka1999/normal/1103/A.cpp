#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 1005

using namespace std;
typedef pair <int,int> P;

char str[SIZE];
P pos[SIZE];

int main()
{
	scanf("%s",&str);
	int n=strlen(str);
	bool zero=false,one=false;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='0')
		{
			if(!zero)
			{
				zero=true;
				pos[i]=P(3,1);
			}
			else
			{
				zero=false;
				pos[i]=P(1,1);
			}
		}
		else
		{
			if(!one)
			{
				one=true;
				pos[i]=P(1,3);
			}
			else
			{
				one=false;
				pos[i]=P(1,1);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		P p=pos[i];
		printf("%d %d\n",p.first,p.second);
	}
	return 0;
}