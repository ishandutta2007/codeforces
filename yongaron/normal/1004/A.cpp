#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n, d;
int a[123];

int main(int argc, char const *argv[]) {
  cin>>n>>d;
  for(int i = 0; i < n; i++)
    cin>>a[i];
  int ans = 2;
  for(int i = 0; i < n-1; i++)
  {
    if(a[i+1]-a[i] == 2*d)
      ans++;
    else if(a[i+1]-a[i] > 2*d)
      ans += 2;
  }
  cout<<ans<<endl;
  return 0;
}