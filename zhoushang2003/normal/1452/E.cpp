#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
using namespace std;
const int N=2001;
int n,m,k,l[N],r[N],A;
int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<m;l[i++]--)
		cin>>l[i]>>r[i];
	for(int i=0,t=0;i+k<=n;i++)
		for(int j=i;j+k<=n;j++,A=max(A,t),t=0)
			for(int x=0;x<m;x++)
				t+=max(max(min(r[x],i+k)-max(l[x],i),min(r[x],j+k)-max(l[x],j)),0);
    cout<<A;
	return 0;
}