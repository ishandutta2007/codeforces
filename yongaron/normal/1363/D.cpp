#include<iostream>
#include<vector>
#include<string>

using namespace std;

int t, n, k;

vector<int> v[1234];

int ma;

int query(int l, int r)
{
  cout<<"? "<<r-l+1<<" ";
  for(int i = l; i <= r; i++)
    cout<<i<<" ";
  cout<<endl;
  int x;
  cin>>x;
  return x;
}

int main(int argc, char const *argv[]) {
  cin>>t;
  while(t--)
  {
    cin>>n>>k;
    int a, x;
    for(int i = 0; i < k; i++)
    {
      cin>>x;
      v[i].clear();
      for(int j = 0; j < x; j++)
      {
        cin>>a;
        v[i].push_back(a);
      }
    }
    int l = 1, r = n, m;
    ma = query(l, r);
    while(l < r)
    {
      m = (l+r)/2;
      int q = query(l, m);
      if(q == -1)
        return 0;
      else if(q == ma)
        r = m;
      else
        l = m+1;
    }
    int sma;
    int index = -1;
    for(int i = 0; i < k; i++)
    {
      for(int j = 0; j < v[i].size(); j++)
        if(v[i][j] == r)
          index = i;
    }
    if(index != -1 && v[index].size() != n)
    {
      cout<<"? "<<n-(v[index].size())<<" ";

      for(int j = 1; j <= n; j++)
      {
        bool inbad = false;
        for(int i = 0; i < v[index].size(); i++)
        {
          if(j == v[index][i])
            inbad = true;
        }
        if(!inbad)
          cout<<j<<" ";
      }
      cout<<endl;
      cin>>sma;
    }
    cout<<"! ";
    for(int i = 0; i < k; i++)
    {
      bool maxin = false;
      for(int j = 0; j < v[i].size(); j++)
        if(v[i][j] == r)
          maxin = true;
      cout<<(maxin ? sma : ma) << " ";
    }
    cout<<endl;
    string s;
    cin>>s;
  }
  return 0;
}