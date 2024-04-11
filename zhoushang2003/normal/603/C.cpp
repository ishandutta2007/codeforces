#include<iostream>
using namespace std;
const int X[5]={0,0,2,2,1};
int n,k,x,A; 
int main()
{
	cin>>n>>k;
	if(k%2==0)
	{
		while(n--&&cin>>x)
			if(x==1)
				A^=1;
			else if(x==2)
				A^=2;
			else if(x%2==0)
				A^=1;
		if(A)
			cout<<"Kevin";
		else
			cout<<"Nicky";
		return 0;
	}
	while(n--&&cin>>x)
	{
		if(x&1)
		{
			if(x<4)
				A^=1;
			continue;
		}
		x/=2;
		while(x%4==0&&x>4)
			x/=4;
		if(x<5)
		{
			A^=X[x];
			continue;
		}
		if(x%4==2)
			A^=2;
		else
			A^=1;
	}
	if(A)
		cout<<"Kevin";
	else
		cout<<"Nicky";
	return 0;
}