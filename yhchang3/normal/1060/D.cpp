#include<bits/stdc++.h>
using namespace std;
priority_queue<int> pq1,pq2;
int main(){
   ios_base::sync_with_stdio(0);
	cin.tie(0);
   int n,a,b;
   long long int ans=0;
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>a>>b;
      pq1.push(a);
      pq2.push(b);
   }
   for(int i=1;i<=n;i++){
      ans+=max(pq1.top(),pq2.top());
      pq1.pop();pq2.pop();
   }
   cout<<ans+n<<endl;
}