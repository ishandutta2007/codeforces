#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int t, q;

long long a, b, l, r, nsd;

int x[40004];
ll pre[40004];

int main(int argc, char const *argv[]) {
  cin>>t;
  while(t--)
  {
    ll tot = 0;
    cin>>a>>b>>q;
    if(a > b)
      swap(a, b);
    pre[0] = 0;
    for(int i = 0; i < a*b; i++)
    {
      x[i] = 0;
      if((i%a)%b != (i%b)%a)
        x[i] = 1;
      pre[i+1] = pre[i]+x[i];
    }
    for(int i = 0; i < q; i++)
    {
      cin>>l>>r;
      ll f = l%(a*b);
      ll ff = r%(a*b);
      l -= f;
      cout<<pre[a*b]*((r-l)/(a*b))-pre[f]+pre[ff+1]<<" ";
    }
    cout<<endl;
  }
  return 0;
}