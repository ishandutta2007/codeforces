#include<iostream>
typedef long long ll;
using namespace std;
int a[5010],b,i;
int main()
{
	cin>>b;
	for(i=1;i<=b;++i)
	{
		cin>>a[i];
	}
	for(i=1;i<=b;++i)
	{
		if(i==a[a[a[i]]])
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}