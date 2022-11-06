#include<iostream>

using namespace std;

int n;
long long s[223456];
int p[223456];
long long f[223456];

long long get(int k)
{
  long long ans = 0;
  while(k >= 1)
  {
    ans += f[k];
    k -= k&-k;
  }
  return ans;
}

void update(int k, int x)
{
  while(k <= n)
  {
    f[k] += x;
    k += k&-k;
  }
}


int main(int argc, char const *argv[]) {
  cin>>n;
  for(int i = 0; i < n; i++)
    cin>>s[i];
  for(int i = 0; i < n; i++)
    update(i+2, i+1);

  for(int i = n; i > 0; i--)
  {
    int l = 1, r = n, m;
    while(l < r)
    {
      m = (l+r+1)/2;
      long long g = get(m);
      // cout<<l<<" "<<r<<" "<<m<<" "<<g<<endl;
      if(g == s[i-1])
        l = m;
      else if(g < s[i-1])
        l = m+1;
      else
        r = m-1;
    }
    // cout<<l<<endl;
    if(l > n)
      l = n;
    p[i] = l;
    update(l+1, -l);
    // for(int j = 1; j <= n; j++)
    //   cout<<get(j)<<" ";
    // cout<<endl;
  }
  for(int i = 0; i < n; i++)
    cout<<p[i+1]<<" ";
  cout<<endl;
  return 0;
}