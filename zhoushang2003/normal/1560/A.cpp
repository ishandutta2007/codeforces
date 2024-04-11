#import<bits/stdc++.h>
using namespace std;
const int N=2e6;
int v,t,A[N],c,n;
main()
{
	for(int i=1;i<N;i++)
		if(i%3!=0&&i%10!=3)
			A[++c]=i;
	for(cin>>n;cin>>n;)
		cout<<A[n]<<'\n';
}