#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <string>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int A[SIZE];
char str[SIZE];
int tp[SIZE],X[SIZE];
int sgn[SIZE];

int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	for(int i=0;i<q;i++)
	{
		scanf("%s %d",&str,&X[i]);
		if(str[0]=='>') tp[i]=0;
		else tp[i]=1;
	}
	int to=SIZE-1;
	int prod=1;
	for(int i=q-1;i>=0;i--)
	{
		if(X[i]>=0)
		{
			if(tp[i]==0)
			{
				while(to>abs(X[i]))
				{
					sgn[to]=-1*prod;
					to--;
				}
			}
			else
			{
				while(to>=abs(X[i]))
				{
					sgn[to]=prod;
					to--;
				}
				prod*=-1;
			}
		}
		else
		{
			if(tp[i]==0)
			{
				while(to>=abs(X[i]))
				{
					sgn[to]=-1*prod;
					to--;
				}
				prod*=-1;
			}
			else
			{
				while(to>abs(X[i]))
				{
					sgn[to]=prod;
					to--;
				}
			}
		}
	}
	//printf("%d\n",to);
	for(int i=0;i<n;i++)
	{
		if(abs(A[i])>to)
		{
			int a=abs(A[i]);
			printf("%d ",a*sgn[a]);
		}
		else
		{
			printf("%d ",A[i]*prod);
		}
	}puts("");
	return 0;
}