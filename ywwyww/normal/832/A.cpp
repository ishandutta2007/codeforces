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
	ll n,k;
	scanf("%I64d%I64d",&n,&k);
	if((n/k)%2==0)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}