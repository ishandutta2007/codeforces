#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <string>
#include <set>
#include <map>
#include <cassert>
#include <cmath>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

ll A[SIZE],B[SIZE];
ll C[SIZE],D[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&A[i]);
		if(i>0) B[i-1]=A[i]-A[i-1];
	}
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&C[i]);
		if(i>0) D[i-1]=C[i]-C[i-1];
	}
	if(A[0]!=C[0])
	{
		puts("No");
		return 0;
	}
	sort(B,B+n-1);
	sort(D,D+n-1);
	for(int i=0;i+1<n;i++)
	{
		if(B[i]!=D[i])
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}