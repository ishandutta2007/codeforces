#include <bits/stdc++.h>
using namespace std;
long long n;
long long h[1000001];
// long long g[1000001];
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int main(){
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  cin>>n;
  // n=rng()%20+5;
  // for(int i=1; i<=n; i++) h[i]=h[i-1]+rng()%100+1;
  for(int i=1; i<=n; i++) cin>>h[i];
  long long sum=0;
  for(int i=1; i<=n; i++) sum+=h[i];
    // for(int i=1; i<=n; i++) cout<<h[i]<<" \n"[i==n];
    // while(true){
      // for(int i=1; i<=n; i++) g[i]=h[i];
      // bool good=0;
      // for(int i=2; i<=n; i++) if(h[i]-h[i-1]>1){
        // good=1;
        // g[i-1]++;
        // g[i]--;
      // }
      // if(!good) break;
      // for(int i=1; i<=n; i++) h[i]=g[i];
    // }
    // for(int i=1; i<=n; i++) cout<<h[i]<<" \n"[i==n];
    // int cnt=0;
    // for(int i=2; i<=n; i++) cnt+=h[i]==h[i-1];
    // if(cnt>1){
      // cerr<<"FAIL\n";
      // exit(-1);
    // }
  //I don't know why but experimental results show that there's alway at most one place in the end where 2 consecutive numbers are equal.
 
  //all +1
  //x*n+n(n-1)/2==sum
  for(long long pos=1; pos<=n; pos++){
    if((sum-n*(n-1)/2+(n-pos))%n==0){
      long long x=(sum-n*(n-1)/2+(n-pos))/n;
      for(long long i=0; i<n; i++) cout<<x+i-(i>=pos)<<" \n"[i==n];
      return 0;
    }
  }
}