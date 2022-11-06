#include<iostream>
#include<map>

using namespace std;

int t, n;

map<int, int> mp;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin>>t;
  while(t--)
  {
    mp.clear();
    int a;
    cin>>n;
    int ma = 0;
    int uni = 0;
    for(int i = 0; i < n; i++)
    {
      cin>>a;
      if(!mp.count(a))
      {
        uni++;
        mp[a] = 1;
        ma = max(ma, 1);
      }
      else
      {
        mp[a]++;
        ma = max(ma, mp[a]);
      }
    }
    if(uni == ma)
      cout<<max(0, ma-1)<<endl;
    else
      cout<<min(ma, uni)<<endl;
  }
  return 0;
}