#include<iostream>
using namespace std;
const int M=123;
char p;
int n,k,c=1,t[M],A;
string s;
int main()
{
	cin>>n>>k>>s;
	p=s[0];
	for(int i=1;i<n;i++)
		if(s[i]==p)
			c++;
		else
			t[p]+=c/k,p=s[i],c=1;
	t[p]+=c/k;
	for(int i=0;i<M;i++)
		A=max(A,t[i]);
	cout<<A;
	return 0;
}