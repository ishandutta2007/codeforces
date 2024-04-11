#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main()
{
	int n;
	int s=0;
	int i,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x&1)
			s=1;
	}
	if(s)
		printf("First\n");
	else
		printf("Second\n");
	return 0;
}