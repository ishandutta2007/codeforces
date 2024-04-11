#include <bits/stdc++.h>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int deg[SIZE];

int main()
{
	int n,S;
	scanf("%d %d",&n,&S);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--,b--;
		deg[a]++,deg[b]++;
	}
	if(n==2)
	{
		printf("%d\n",S);
		return 0;
	}
	int cnt=0;
	for(int i=0;i<n;i++) if(deg[i]==1) cnt++;
	printf("%.10f\n",2.0*(double) S/(double) cnt);
	return 0;
}