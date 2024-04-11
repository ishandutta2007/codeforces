#include<bits/stdc++.h>
using namespace std;

int main()
{
	int i,j,n,a[1005],k=0,l=0;
	cin>>n;
	for(i=1;i<=2*n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+2*n+1);
	if(a[n+1]>a[n])
	{
		cout<<"YES";
	}
	else cout<<"NO";
}