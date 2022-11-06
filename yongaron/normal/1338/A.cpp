#include<iostream>

using namespace std;

int n, t;
long long a[123456];

int main(int argc, char const *argv[]) {
  cin>>t;
  while(t--)
  {
    cin>>n;
    long long ma = -1e9;
    long long maxdif = 0;
    for(int i = 0; i < n; i++)
    {
      cin>>a[i];
      maxdif = max(maxdif, ma-a[i]);
      ma = max(a[i], ma);
    }
    long long moc = 1;
    int ans = 0;
    while(moc <= maxdif)
    {
      moc *= 2;
      ans++;
    }
    cout<<ans<<endl;
  }
  return 0;
}