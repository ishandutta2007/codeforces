#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[9]={};
	cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]>>a[7]>>a[8];
	int s=accumulate(a,a+9,0)/2;
	cout<<s-a[1]-a[2]<<' '<<a[1]<<' '<<a[2]<<endl;
	cout<<a[3]<<' '<<s-a[3]-a[5]<<' '<<a[5]<<endl;
	cout<<a[6]<<' '<<a[7]<<' '<<s-a[6]-a[7]<<endl;
	return 0;
}