#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int n,k;
string s;
bool C()
{
	for(int i=0;i<n;i++)
		if(s[i]!=s[i%k])
			return s[i]<s[i%k];
	return true;
}
int main()
{
	cin>>n>>k>>s;
	if(!C())
	{
		s[k-1]++;
		for(int i=k-1;i>0;i--)
			s[i-1]+=(s[i]-'0')/10,s[i]=(s[i]-'0')%10+'0';
	}
	cout<<n<<'\n';
	for(int i=0;i<n;i++)
		cout<<s[i%k];
	return 0;
}