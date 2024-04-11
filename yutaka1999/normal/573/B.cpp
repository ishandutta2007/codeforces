#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#define SIZE 100005

using namespace std;

int A[SIZE],B[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		A[i]=B[i]=a;
	}
	int mn=0;
	for(int i=0;i<n;i++)
	{
		mn=min(mn+1,A[i]);
		B[i]=min(B[i],mn);
	}
	mn=0;
	for(int i=n-1;i>=0;i--)
	{
		mn=min(mn+1,A[i]);
		B[i]=min(B[i],mn);
	}
	int mx=0;
	for(int i=0;i<n;i++) mx=max(mx,B[i]);
	printf("%d\n",mx);
	return 0;
}