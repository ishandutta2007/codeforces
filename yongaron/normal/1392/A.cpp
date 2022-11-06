#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    int l = -1;
    int a;
    cin>>n;
    bool dif = false;
    cin>>l;
    for(int i = 1; i < n; i++)
    {
      cin>>a;
      if(a != l)
        dif = true;
      l = a;
    }
    if(dif)
      cout<<1<<endl;
    else
      cout<<n<<endl;
  }
  return 0;
}