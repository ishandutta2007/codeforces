#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int t;
int n, k;
int a[123456];

int main() {
  ios::sync_with_stdio(false);
  cin.tie();
  cin>>t;
  while(t--)
  {
    bool found = false;
    cin>>n>>k;
    bool is = false;
    for(int i = 0; i < n; i++)
    {
      cin>>a[i];
      if(i >= 1 && a[i] >= k && a[i-1] >= k)
        found = true;
      if(i >= 2 && a[i] >= k && a[i-2] >= k)
        found = true;
      if(a[i] == k)
        is = true;
    }
    if(n == 1 && a[0] == k)
      found = true;
    if(found && is)
      cout<<"yes"<<endl;
    else
      cout<<"no"<<endl;
  }
  return 0;
}