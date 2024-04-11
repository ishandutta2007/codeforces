#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main()
{	
	cin>>a>>b>>c>>d;
	int t1=max(3*a/10,a-a/250*c), t2=max(3*b/10,b-b/250*d);
	cout<<(t1>t2 ? "Misha" : t1==t2 ? "Tie" : "Vasya")<<endl;
	return 0;
}