#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 200005

using namespace std;

vector <int> A,B;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		if(a!=0) A.push_back(a);
	}
	for(int i=0;i<n;i++)
	{
		int b;
		scanf("%d",&b);
		if(b!=0) B.push_back(b);
	}
	int pos=-1;
	for(int i=0;i<n-1;i++)
	{
		if(B[i]==A[0])
		{
			pos=i;
			break;
		}
	}
	for(int i=0;i<n-1;i++)
	{
		int to=(pos+i)%(n-1);
		if(A[i]!=B[to])
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}