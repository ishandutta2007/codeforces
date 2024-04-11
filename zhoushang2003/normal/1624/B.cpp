#import<bits/stdc++.h>
using namespace std;
int n,a,b,c;
main()
{
	for(cin>>n;cin>>a>>b>>c;)
		puts(2*b-a>0&&(2*b-a)%c==0||(a+c)%2==0&&(a+c)/2%b==0||2*b-c>0&&(2*b-c)%a==0?"YES":"NO");
}