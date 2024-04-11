#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#define SIZE 100005

using namespace std;

int A[SIZE];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	sort(A,A+n);
	int ret=0;
	for(int i=0;i<k;i++) ret+=A[i];
	printf("%d\n",ret);
	return 0;
}