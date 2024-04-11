#include<iostream>
#include<cstring>
using namespace std;
string s;
bool c[120];
int a[120],b,i;
void fx(char k,int t)
{
	if(k=='a'||k=='e'||k=='i'||k=='o'||k=='u'||k=='y') a[t]=1;
}
int main()
{
	cin>>b>>s;
	fx(s[b-1],b-1);
	for(i=b-2;i>=0;--i)
	{
		fx(s[i],i);
		if(a[i]==1&&a[i+1]==1) c[i+2]=true;
	}
	for(i=0;i<=b-1;++i)
	{
		if(c[i+1]==false) cout<<s[i];
	}
	return 0;
}