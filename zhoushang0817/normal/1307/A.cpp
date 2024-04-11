#include<bits/stdc++.h>
using namespace std;
const int N=101;
int t,n,d,a[N],A;
int main()
{
 cin>>t;
 while(t--&&cin>>n>>d)
 {
  for(int i=1;i<=n;i++)
   cin>>a[i];
  A=0;
  for(int i=1;i<=n;i++)
   for(int j=1;j<=a[i];j++)
    if(d>=i-1)
     d-=i-1,A++;
  cout<<A<<'\n';
 }
 return 0;
}