#include<bits/stdc++.h>
#define N 100100
using namespace std;

int n,m;

int main()
{
    int i,j,t;
    cin>>n>>m;
    t=(n-m)/2+1;
    if(m==1)
    {
	printf("1");
	for(i=2;i<=n;i++) printf("0");
	return 0;
    }
    for(i=1;i<=n;i++)
    {
	if(i%t==1) printf("1");
	else printf("0");
    }
}