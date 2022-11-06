#include<iostream>
#include<algorithm>

using namespace std;

int n, q;
int a[1234567], f[1234567], l[1234567];
int fen[1234567];

void upd(int k, int x)
{
  while(k <= n)
  {
    fen[k] += x;
    k += k&-k;
  }
}

int sum(int k)
{
  int ans = 0;
  while(k > 0)
  {
    ans += fen[k];
    k -= k&-k;
  }
  return ans;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin>>q;
  for(int u = 0; u < q; u++)
  {
    cin>>n;
    for(int i = 0; i <= n; i++)
    {
      f[i+1] = n;
      l[i+1] = 0;
      fen[i+1] = 0;
    }
    for(int i = 0; i < n; i++)
    {
      cin>>a[i];
      f[a[i]] = min(f[a[i]], i+1);
      l[a[i]] = max(l[a[i]], i+1);
    }
    long long ans = 0;
    int ma = 0;
    int la = 0;
    int str = 0;
    int d = 0;
    for(int i = 0; i < n; i++)
    {
      if(l[i+1])
      {
        d++;
        if(la > 0 && l[la] > f[i+1])
          str = 1;
        else
          str++;
        la = i+1;
        // ans += sum(n)-sum(f[i+1]);
        // cout<<i+1<<" "<<ans<<endl;
        // upd(l[i+1], 1);
      }
      ma = max(str, ma);
    }
    cout<<d-ma<<endl;
  }
  return 0;
}