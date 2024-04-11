#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, x, ans;
priority_queue<ll>q;

int main(){
  for (cin>>n;n--;){
    cin>>x; x+=n;
    q.push(x);
    if (q.top()>x){
      ans+=q.top()-x;
      q.pop(); q.push(x);
    }
  }
  cout<<ans<<endl;
}