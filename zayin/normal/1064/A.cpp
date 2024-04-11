#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[3];
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	if (a[0]+a[1]>a[2])
		printf("%d\n",0);
	else
		printf("%d\n",a[2]+1-a[0]-a[1]); 
	return 0;
}