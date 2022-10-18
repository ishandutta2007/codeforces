#include<iostream>
using namespace std;
const int P=1e9+7;
long long c,A=1;
string s;
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='a')
			c++;
		else if(s[i]=='b')
			(A*=c+1)%=P,c=0;
	cout<<A*(c+1)%P-1;
	return 0;
}