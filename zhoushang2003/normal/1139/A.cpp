#include<iostream>
using namespace std;
int n;
long long A;
string s;
int main()
{
	cin>>n>>s;
	for(int i=0;i<s.size();i++)
		if((s[i]-'0')%2==0)
			A+=i+1;
	cout<<A;
	return 0;
}