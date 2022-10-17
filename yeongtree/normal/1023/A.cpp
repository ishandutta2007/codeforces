#include <iostream>

using namespace std;

int main()
{
   int n,m; cin>>n>>m;
   char s[n]; char t[m];
   for(int i=0;i<n;i++) cin>>s[i];
   for(int i=0;i<m;i++) cin>>t[i];
   if(m+1<n) {cout<<"NO"; return 0;}
   int x; int y=0;
   for(x=0;x<n;x++)
   {
       if(s[x]=='*') {y=m-n; continue;}
       if(s[x]!=t[x+y]) {cout<<"NO"; return 0;}
   }
   if(x+y!=m) {cout<<"NO"; return 0;}
   cout<<"YES";
   return 0;
}