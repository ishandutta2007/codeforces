#include<iostream>
using namespace std;
string s;
int l,x,y,p[5],t;
int main()
{
	cin>>s;
	l=s.size();
	x=(l-1)/20+1,y=(l-1)/x+1;
	cout<<x<<" "<<y<<endl;
	for(int i=0;i<x;i++)
		p[i]=y;
	if(y>1&&x>1)
		for(int i=l%(y-1);i<x;i++)
			p[i]--;
	for(int i=0;i<x;i++)
	{
		for(int j=t;j<t+p[i];j++)
			cout<<s[j];
		t+=p[i];
		if(p[i]<y)
			cout<<"*";
		cout<<endl;
	}
	return 0;
}