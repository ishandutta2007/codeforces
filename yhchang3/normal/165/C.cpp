#include<bits/stdc++.h>
using namespace std;
string s;
int pre[1000001];
int cnt[1000001];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int k;
   cin>>k;
   cin>>s;
   int n=(int) s.size();
   s.insert(0," ");
   for(int i=1;i<=n;i++){
      if(s[i]=='1')
         pre[i]=pre[i-1]+1;
      else
         pre[i]=pre[i-1];
   }
   cnt[0]++;
   long long int ans=0;
   for(int i=1;i<=n;i++){
      if(pre[i]>=k)
         ans+=cnt[pre[i]-k];
      cnt[pre[i]]++;
   }
   cout<<ans<<endl;
}