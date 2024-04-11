#include<bits/stdc++.h>
using namespace std;
int maxn,n;
 
int main()
{
   cin>>n;
   for(int i=1;i<=n;i++)
   {
       int x;cin>>x;
       if(x>maxn) { cout<<i<<endl; return 0;}
       if(x>=maxn) maxn=x+1;
   }
   cout<<"-1"<<endl;
   return 0;
}