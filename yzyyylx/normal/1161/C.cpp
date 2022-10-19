#include<bits/stdc++.h>
#define N 100100
using namespace std;

int n,mn,cnt,num[N];

int main()
{
    int i,j,k,p,q;
    cin>>n;
    mn=60;
    for(i=1;i<=n;i++)
    {
	scanf("%d",&num[i]);
	mn=min(mn,num[i]);
    }
    for(i=1;i<=n;i++)
    {
	if(num[i]==mn)
	{
	    cnt++;
	}
    }
    if(cnt>n/2) puts("Bob");
    else puts("Alice");
}
//