#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <map>

using namespace std;

int n;
int a[123456];

int main(int argc, char const *argv[]) {
  cin>>n;
  for(int i = 0; i < n; i++)
    cin>>a[i];
  sort(a, &a[n]);
  int ans = -1;
  int li = 0;
  for(int i = 0; i < n; i++)
  {
    ans++;
    while(i+1 < n && a[i] == a[i+1])
    {
      if(ans < li)
        ans++;
      i++;
    }
    li = i+1;
  }
  cout<<ans<<endl;
  return 0;
}