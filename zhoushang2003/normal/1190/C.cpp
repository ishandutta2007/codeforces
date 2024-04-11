#include<bits/stdc++.h>
using namespace std;
int n,k;
string s;
vector<int>a,b;
int main()
{
	cin>>n>>k>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='0')
			a.push_back(i+1);
		else
			b.push_back(i+1);
	if(a.size()==0||b.size()==0)
	{
		cout<<"tokitsukaze";
		return 0;
	}
	if(a[a.size()-1]-a[0]<k||b[b.size()-1]-b[0]<k)
	{
		cout<<"tokitsukaze";
		return 0;
	}
	if(a[a.size()-1]-a[0]>k||b[b.size()-1]-b[0]>k)
	{
		cout<<"once again";
		return 0;
	}
	for(int i=0;i<a.size();i++)
		if(a[i]>k&&a[a.size()-1]-a[i]>=k)
		{
			cout<<"once again";
			return 0;
		}
	for(int i=a.size()-1;i>=0;i--)
		if(a[i]<=n-k&&a[i]-a[0]>=k)
		{
			cout<<"once again";
			return 0;
		}
	for(int i=0;i<b.size();i++)
		if(b[i]>k&&b[b.size()-1]-b[i]>=k)
		{
			cout<<"once again";
			return 0;
		}
	for(int i=b.size()-1;i>=0;i--)
		if(b[i]<n-k&&b[i]-b[0]>=k)
		{
			cout<<"once again";
			return 0;
		}
	cout<<"quailty";
	return 0;
}