#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
int zl[MAXN],zr[MAXN];
const int mod = 998244353;
void Zvalue(string s,int z[]){
   z[0]=s.size();
   int l=0,r=0,x;
   for(int i=1;i<s.size();i++){
      if(r<i||z[i-l]>=r-i+1){
         r<i?x=i:x=r+1;
         while(x<s.size()&&s[x]==s[x-i])  x++;
         z[i]=x-i;if(i<x){l=i;r=x-1;};
      }
      else
         z[i]=z[i-l];
   }
}
string n,l,r;
long long int dp[MAXN],sum[MAXN];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n>>l>>r;
   Zvalue(l+'#'+n,zl);
   Zvalue(r+'#'+n,zr);
   dp[n.size()]=sum[n.size()]=1;
   for(int i=n.size()-1;i>=0;i--){
      if(n[i]=='0'){
         if(l=="0")  dp[i]=dp[i+1];
         else  dp[i]=0;
         sum[i]=(sum[i+1]+dp[i])%mod;
         continue;
      }
      int L=l.size()+i;
      if(n.size()-i<l.size()) L++;
      else if(zl[l.size()+1+i]==l.size());
      else if(n[i+zl[l.size()+1+i]]<l[zl[l.size()+1+i]]) L++;
      int R=r.size()+i;
      if(n.size()-i<r.size());
      else if(zr[r.size()+1+i]==r.size());
      else if(n[i+zr[r.size()+1+i]]<r[zr[r.size()+1+i]]);
      else R--;
      int tmp=0;
      if(L<=R&&L<=n.size()){
         R=min(R,(int) n.size());
         tmp=sum[L];
         if(R!=n.size()) tmp=(tmp+mod-sum[R+1])%mod;
      }
      dp[i]=tmp;
      sum[i]=(sum[i+1]+dp[i])%mod;
   }
   cout<<dp[0]<<endl;
}