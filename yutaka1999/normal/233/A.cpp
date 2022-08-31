#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
	int n;
	cin>>n;
	if(n%2!=0) cout<<-1<<endl;
	else
	{
		cout<<2<<" "<<1;
		
		int a;
		for(a=4;a<=n;a+=2) cout<<" "<<a<<" "<<a-1;
		
		cout<<endl;
	}
	
	return 0;
}