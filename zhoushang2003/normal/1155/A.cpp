#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main()
{
	cin>>n>>s;
	for(int i=1;i<n;i++)
		if(s[i-1]>s[i])
		{
			cout<<"YES"<<endl<<i<<" "<<i+1;
			return 0;
		}
	cout<<"NO";
	return 0;
}