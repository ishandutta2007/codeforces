#include<iostream>
using namespace std;
const int N=2e5+1;
int n,a[N],x,y;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		if(a[i]==1)
			x++;
		else
			y++;
	if(y)
		cout<<2<<" ",y--;
	if(x)
		cout<<1<<" ",x--;
	while(y--)
		cout<<2<<" ";
	while(x--)
		cout<<1<<" ";
	return 0;
}