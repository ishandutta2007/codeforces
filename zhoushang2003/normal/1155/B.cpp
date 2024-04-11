#include<bits/stdc++.h>
using namespace std;
int n,a,b;
string s;
int main()
{
	cin>>n>>s;
	for(int i=0;i<n-10;i++)
		if(s[i]=='8')
			a++;
		else
			b++;
	if(a<b)
		cout<<"NO";
	else
		cout<<"YES";
	return 0;
}