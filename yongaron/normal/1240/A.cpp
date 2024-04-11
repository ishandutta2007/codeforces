#include<iostream>
#include<algorithm>

using namespace std;

int n, q;
long long p[1234567];
long long pr[1234567];
long long k;
long long x, a, y, b;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin>>q;
  for(int u = 0; u < q; u++)
  {
    cin>>n;
    for(int i = 0; i < n; i++)
      cin>>p[i];
    cin>>x>>a>>y>>b;
    cin>>k;
    sort(p, p+n);
    pr[0] = 0;
    for(int i = 0; i < n; i++)
      pr[i+1] = pr[i]+p[i];
    int l = 0, r = n, m;
    if(y > x)
    {
      swap(a, b);
      swap(x, y);
    }
    long long g = a*b/__gcd(a, b);
    bool ok = false;
    for(int m = 1; m <= n; m++)
    {
      long long sum = (x+y)*(pr[n]-pr[n-m/g])
                      +x*(pr[n-m/g]-pr[n-m/a])
                      +y*(pr[n-m/a]-pr[n-m/a-m/b+m/g]);
      sum /= 100;
      if(sum >= k)
      {
        cout<<m<<endl;
        break;
      }
    }
    long long sum = (x+y)*(pr[n]-pr[n-n/g])
                    +x*(pr[n-n/g]-pr[n-n/a])
                    +y*(pr[n-n/a]-pr[n-n/a-n/b+n/g]);
    sum /= 100;
    if(sum < k)
      cout<<-1<<endl;
  }
  return 0;
}