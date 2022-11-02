#include<bits/stdc++.h>
using namespace std;
int a,b,s;
int main()
{	
	cin>>a>>b>>s;
	cout<<(s>=abs(a)+abs(b) && (s-abs(a)-abs(b))%2==0 ? "Yes" : "No")<<endl;
	return 0;
}