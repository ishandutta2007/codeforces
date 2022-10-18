#import<bits/stdc++.h>
using namespace std;
int a,b,A; 
main()
{
	for(cin>>a;cin>>a>>b;)
	{
		A=1e9;
		for(int i=b;i<=b+b;i++)
			A=min(A,(i|a)-b+1);
		for(int i=a;i<=b;i++)
			A=min(A,(i|b)-b+i-a+1);
		cout<<min(A,b-a)<<'\n';
	}
}