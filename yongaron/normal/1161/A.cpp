#include<iostream>

using namespace std;

int n, k;
int a[123456];
bool was[123456];
int last[123456];
int dist[123456];
int fir[123456];

int d = 0;

int main(int argc, char const *argv[]) {
  cin>>n>>k;
  for(int i = 0; i < k; i++)
  {
    cin>>a[i];
    last[a[i]] = i+1;
  }
  for(int i = k-1; i >= 0; i--)
  {
    fir[a[i]] = i+1;
  }
  dist[n-1] = 0;
  for(int i = k-1; i >= 0; i--)
  {
    if(!was[a[i]])
    {
      was[a[i]] = true;
      d++;
    }
    dist[i] = d;
  }
  long long ans = 0;
  for(int i = 1; i <= n; i++)
  {
    if(i < n && (fir[i+1] > last[i] || !last[i+1] || !last[i]))
    {
      ans++;
      // cout<<i<<" "<<i+1<<endl;
    }
    if(i > 1 && (fir[i-1] > last[i] || !last[i-1] || !last[i]))
    {
      ans++;
      // cout<<i<<" "<<i-1<<endl;
    }
    if(!last[i])
    {
      ans++;
      // cout<<i<<" "<<i<<endl;
    }

  }
  cout<<ans<<endl;
  return 0;
}