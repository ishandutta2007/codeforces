#include<iostream>
#include<vector>

using namespace std;

int n, k;
int p[1234567];

vector<int> v;

long long m = 998244353;

long long sum = 0, ans = 1;

int main(int argc, char const *argv[]) {
  cin>>n>>k;
  for(int i = 0; i < n; i++)
  {
    cin>>p[i];
    if(p[i] > n-k)
    {
      v.push_back(i);
      sum += p[i];
    }
  }
  for(int j = 1; j < v.size(); j++)
    ans = (ans*(v[j]-v[j-1]))%m;
  cout<<sum<<" "<<ans<<endl;
  return 0;
}