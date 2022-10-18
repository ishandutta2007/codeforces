#include<iostream>
using namespace std;
int t,x;
int main()
{
	cin>>t;
	while(t--&&cin>>x)
		cout<<(x-1)/7+1<<endl;
	return 0;
}