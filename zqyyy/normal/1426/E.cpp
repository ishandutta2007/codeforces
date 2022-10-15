#include <bits/stdc++.h>
using namespace std;int n,a,b,c,d,e,f;int main(){cin>>n>>a>>b>>c>>d>>e>>f;return cout<<n-min(a,n-e)-min(b,n-f)-min(c,n-d)<<" "<<min(a,e)+min(b,f)+min(c,d),0;}