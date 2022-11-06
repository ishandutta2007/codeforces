#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, m, t;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>n>>m;
    bool ok = true;
    int a;
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < m; j++)
      {
        cin>>a;
        if(i == 0 || i == n-1)
        {
          if(j == 0 || j == m-1)
          {
            if(a > 2)
              ok = false;
          }
          else if(a > 3)
            ok = false;
        }
        else
        {
          if(j == 0 || j == m-1)
          {
            if(a > 3)
              ok = false;
          }
          else if(a > 4)
            ok = false;
        }
      }
    }
    if(!ok)
      cout<<"NO"<<endl;
    else
    {
      cout<<"YES"<<endl;
      for(int i = 0; i < n; i++)
      {
        for(int j = 0; j < m; j++)
        {
          if(i == 0 || i == n-1)
          {
            if(j == 0 || j == m-1)
              cout<<2<<" ";
            else
              cout<<3<<" ";
          }
          else
          {
            if(j == 0 || j == m-1)
              cout<<3<<" ";
            else
              cout<<4<<" ";
          }
        }
        cout<<endl;
      }
    }
  }
  return 0;
}