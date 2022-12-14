#include<bits/stdc++.h>
using namespace std;
long long int a[300000];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   long long int ans;
   int n,m,k;
   cin>>n>>m>>k;
   for(int i=0;i<n;i++)
      cin>>a[i];
   sort(a,a+n);
   ans=a[n-1]*(m-m/(k+1))+a[n-2]*(m/(k+1));
   cout<<ans<<endl;
}