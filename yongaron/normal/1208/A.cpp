#include<iostream>

using namespace std;

int a, b, n, t;

int main()
{
	cin>>t;
	for(int i = 0; i < t; i++)
	{
		cin>>a>>b>>n;
		if(n%3 == 0)
			cout<<a<<endl;
		else if(n%3 == 1)
			cout<<b<<endl;
		else
			cout<<(a^b)<<endl;

	}
	return 0;
}