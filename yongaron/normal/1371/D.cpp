#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t, k;

int a[333][333];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>n>>k;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        a[i][j] = 0;

    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < n && k > 0; j++, k--)
        a[(i+j)%n][j] = 1;
    }

    int mi = n, ma = 0;

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
      int s = 0;
      for(int j = 0; j < n; j++)
        s += a[i][j];
      mi = min(mi, s);
      ma = max(ma, s);
    }

    ans += (ma-mi)*(ma-mi);

    mi = n;
    ma = 0;


    for(int i = 0; i < n; i++)
    {
      int s = 0;
      for(int j = 0; j < n; j++)
        s += a[j][i];
      mi = min(mi, s);
      ma = max(ma, s);
    }



    ans += (ma-mi)*(ma-mi);


    cout<<ans<<endl;

    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < n; j++)
        cout<<a[i][j];
      cout<<endl;
    }
  }
  return 0;
}