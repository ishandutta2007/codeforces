#include<iostream>
#include<queue>

using namespace std;

int t, n;

int a[1234567], b[1234567];

int tree[1234567];
queue<int> q[312345];

void update(int k, int x)
{
  k += n;
  tree[k] = x;
  k /= 2;
  while(k)
  {
    tree[k] = min(tree[2*k], tree[2*k+1]);
    k /= 2;
  }
}

int query(int l, int r)
{
  l += n;
  r += n;
  int ans = 1e9;
  while(l < r)
  {
    if(l%2)
      ans = min(ans, tree[l++]);
    if(r%2)
      ans = min(ans, tree[--r]);
    l /= 2;
    r /= 2;
  }
  return ans;
}

int main(int argc, char const *argv[]) {
  cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i = 0; i < 4*n; i++)
      tree[i] = 1e9;
    for(int i = 0; i <= n; i++)  
    {
      while(!q[i].empty())
        q[i].pop();
    }
    for(int i = 0; i < n; i++)
    {
      cin>>a[i];
      q[a[i]].push(i);
      update(i, a[i]);
    }
    for(int i = 0; i < n; i++)
      cin>>b[i];
    for(int i = 0; i < n; i++)
    {
      if(q[b[i]].empty())
      {
        cout<<"NO"<<endl;
        goto endd;
      }
      int s = q[b[i]].front();
      q[b[i]].pop();
      if(query(0, s) < b[i])
      {
        cout<<"NO"<<endl;
        goto endd;
      }
      update(s, 1e9);
    }
    cout<<"YES"<<endl;
    endd:
      ;
  }
  return 0;
}