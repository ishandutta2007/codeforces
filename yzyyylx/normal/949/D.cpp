#include<bits/stdc++.h>
#define N 100100
using namespace std;

int n,d,b,num[N],A,B,sum;

int main()
{
    int i,j;
    cin>>n>>d>>b;
    for(i=1;i<=n;i++) scanf("%d",&num[i]);
    for(i=j=1;i<=(n+1)/2;i++)
    {
	for(;j<=min(i*(d+1),n);j++) sum+=num[j];
	if(sum<b) A++;
	else sum-=b;
    }
    reverse(num+1,num+n+1);
    sum=0;
    for(i=j=1;i<=n/2;i++)
    {
	for(;j<=min(i*(d+1),n);j++) sum+=num[j];
	if(sum<b) B++;
	else sum-=b;
    }
    cout<<max(A,B);
}