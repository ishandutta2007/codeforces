#include<bits/stdc++.h>
using namespace std;
int t,n;
string s;
int main()
{
	cin>>t;
	while(t--&&cin>>n>>s)
		if(n==2&&s[0]>=s[1])
			cout<<"NO"<<endl;
		else
		{
			cout<<"YES"<<endl<<2<<endl<<s[0]-'0'<<" ";
			for(int i=1;i<n;i++)
				cout<<s[i]-'0';
			cout<<endl;
		}
	return 0;
}