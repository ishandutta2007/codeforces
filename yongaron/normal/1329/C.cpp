#include<iostream>
#include<vector>
#include<algorithm>

#pragma GCC optimize("Ofast")

using namespace std;

int h, g, t;
int a[2234567], b[2234567];
int dept[2234567];
int d[2234567];
int mp[2234567];
pair<int, int> c[2234567];
int real[2234567];

void proce(int i)
{
  // cout<<i<<endl;
  int l = 2*i;
  int r = 2*i+1;
  if(a[l] == 0 && a[r] == 0)
  {
    a[i] = 0;
    return;
  }
  if(a[l] < a[r])
    swap(l, r);
  a[i] = a[l];
  mp[a[i]] = i;
  proce(l);
  if(a[l] == 0 && a[r] == 0)
  {
    dept[i] = d[i]-1;
    return;
  }
  if(a[l] < a[r])
    swap(l, r);
  dept[i] = dept[l];
}

void printd()
{
  for(int i = 1; i < 1<<h; i++)
    cout<<dept[i]<<" ";
  cout<<endl;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>h>>g;
    vector<int> v;
    long long sum = 0;
    d[0] = 0;
    for(int i = 1; i < (1<<h); i++)
    {
      cin>>c[i].first;
      c[i].second = i;
      a[i] = c[i].first;
    }
    sort(c+1, c+(1<<h));
    for(int i = 1; i < (1<<h); i++)
    {
      real[i] = c[i].first;
      a[c[i].second] = i;
      // cout<<c[i].second<<" "<<i<<endl;
      // cout<<a[c[i].second]<<endl;
      // cout<<a[i]<<endl;
    }
    for(int i = 1; i < (1<<h); i++)
    {
      // cout<<i<<" "<<a[i]<<endl;
      d[i] = d[i/2]+1;
      b[i] = a[i];
      mp[b[i]] = i;
      sum += real[a[i]];
      dept[i] = h;
      if(2*i >= (1<<h))
        a[2*i] = a[2*i+1] = dept[2*i] = dept[2*i+1] = 0;
    }
    sort(b+1, b+(1<<h));
    int ind = (1<<h)-1;
    while(ind)
    {
      int x = mp[b[ind]];
      // cout<<b[ind]<<endl;
      if(dept[x] >= g)
      {
        sum -= real[b[ind]];
        proce(x);
        v.push_back(x);
      }
      ind--;
    }
    cout<<sum<<endl;
    for(int i = 0; i < v.size(); i++)
      cout<<v[i]<<" ";
    cout<<endl;
  }
}