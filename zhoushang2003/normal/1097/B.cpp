#include<iostream>
using namespace std;
const int N=15;
bool t;
int n,a[N],s;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<(1<<n);i++)
	{
		s=0;
		for(int j=0;j<n;j++)
			if(i&(1<<j))
				s+=a[j];
			else
				s-=a[j];
		if(s%360==0)
			t=true;
	}
	if(t)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}