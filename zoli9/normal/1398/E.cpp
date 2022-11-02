#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    set<int> s, s0, s1;
    auto it=s.end();
    ll sum=0;
    ll simplesum=0;
    for(int tt=0; tt<n; tt++)
    {
      int tp;
      int x;
      cin>>tp>>x;
      if(x>0)
      {
        simplesum+=x;
        s.insert(x);
        if(tp==0)
        {
          s0.insert(x);
          if(it!=s.end() && (*it)<x)
          {
            sum+=x;
            sum-=(*it);
            it++;
          }
        }
        else
        {
          s1.insert(x);
          if(it==s.end() || (*it)>x)
          {
            it--;
            sum+=(*it);
          }
          else
          {
            sum+=x;
          }
        }
      }
      else
      {
        x=-x;
        simplesum-=x;
        if(tp==0)
        {
          s0.erase(x);
          if(it!=s.end() && (*it)<=x)
          {
            sum-=x;
            it--;
            sum+=(*it);
          }
        }
        else
        {
          s1.erase(x);
          if((*it)==x)
          {
            it++;
            sum-=x;
          }
          else if(x<(*it))
          {
            sum-=(*it);
            it++;
          }
          else
          {
            sum-=x;
          }
        }
        s.erase(x);
      }
      if(s0.size()==0)
      {
        if(s1.size()==0)
        {
          cout<<0<<'\n';
        }
        else
        {
          auto its1=s1.begin();
          cout<<simplesum+sum-(*its1)<<'\n';
        }
      }
      else
      {
        if(s1.size()==0)
        {
          cout<<simplesum<<'\n';
        }
        else
        {
          auto its0=s0.end();
          its0--;
          auto its1=s1.begin();
          if((*its0)<(*its1))
          {
            cout<<simplesum+sum-(*its1)+(*its0)<<'\n';
          }
          else
          {
            cout<<simplesum+sum<<'\n';
          }
        }
      }
    }


    return 0;
}