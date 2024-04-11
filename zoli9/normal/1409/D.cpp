#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

ll infi=1e18;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
      ll n, s;
      cin>>n>>s;
      vector<ll> digs;
      ll m=n;
      ll originalSum=0;
      while(m>0)
      {
        digs.push_back(m%10);
        originalSum+=(m%10);
        m/=10;
      }
      if(originalSum<=s)
      {
        cout<<0<<'\n';
        continue;
      }
      ll si=digs.size();
      reverse(digs.begin(), digs.end());
      int fi=0;
      ll sum=digs[0];
      while(sum<s)
      {
        fi++;
        sum+=digs[fi];
      }
      ll rest=0;
      //cout<<fi<<endl;
      for(int i=fi; i<si; i++)
      {
        rest*=10;
        rest+=digs[i];
      }
      ll w=1;
      while(w<=rest) w*=10;
      cout<<w-rest<<'\n';
      
    }


    return 0;
}