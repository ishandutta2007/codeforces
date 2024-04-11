#include<bits/stdc++.h>
using namespace std;
int n;
void W(int x,int y)
{
	cout<<x<<' '<<y<<'\n';
}
int main()
{
	cin>>n;
	if(n%4>1)
	{
		cout<<"NO";
		return 0;
	}
	cout<<"YES"<<'\n';
	for(int i=1;i<n;i+=2)
	{
		for(int j=i+2;j<n;j+=2)
			W(i,j),W(i+1,j+1),W(i,j+1),W(i+1,j);
		if(n%4)
			W(i,n),W(i,i+1),W(i+1,n);
		else
			W(i,i+1);
	}
	return 0;
}