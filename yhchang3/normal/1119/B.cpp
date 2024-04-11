#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,h;
   cin>>n>>h;
   for(int i=0;i<n;i++)
      cin>>a[i];
   for(int i=0;i<n;i++){
      sort(a,a+i+1);
      long long int tmp=0;
      for(int j=i;j>=0;j-=2)
         tmp+=a[j];
      if(tmp>h){
         cout<<i<<endl;
         return 0;
      }
   }
   cout<<n<<endl;

}