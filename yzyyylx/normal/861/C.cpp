#include<bits/stdc++.h>
using namespace std;

bool pd(char n)
{
	if(n=='a'||n=='o'||n=='e'||n=='i'||n=='u') return true;
	else return false;
}

int main()
{
	string a;
	int len,i,j,l2,l1;
	cin>>a;
	len=a.size();
	if(len<=2)
	{
		cout<<a;
		return 0;
	}
	l2=pd(a[0]);
	l1=pd(a[1]);
//	cout<<l2<<l1;
	cout<<a[0]<<a[1];
	for(i=2;i<len;i++)
	{
		if(l2==false&&l1==false&&pd(a[i])==false&&a[i]!=a[i-1]
		||a[i-1]!=a[i-2]&&l2==false&&l1==false&&pd(a[i])==false
		||a[i]!=a[i-2]&&l2==false&&l1==false&&pd(a[i])==false)
		{
			cout<<" ";
			l2=true;
			l1=false;
		}
		else
		{
			l2=l1;
			l1=pd(a[i]);
		}
		cout<<a[i];
	}
}