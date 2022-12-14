#include<bits/stdc++.h>
using namespace std;
int a[300000];
int L[300000],X[300000];
char b;
int c;
int cnt=0;
int main(){
   int q;
   cin>>q;
   for(int i=1;i<=q;i++){
      cin>>b>>c;
      L[i]=L[i-1];
      //R[i]=R[i-1];
      if(b=='L'){
         L[i]++;
         a[c]=i;
         X[c]=0;
         cnt++;
      }
      else if(b=='R'){
         a[c]=i;
         X[c]=cnt;
         cnt++;
      }
      else{
         int ans=X[c]+L[i]-L[a[c]];
         cout<<min(ans,cnt-1-ans)<<endl;
      }
   }
}