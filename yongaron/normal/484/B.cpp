#include<iostream>

using namespace std;

const int N = 1000005;

int n;

bool was[2*N];
int maxpre[2*N];

int main(int argc, char const *argv[]) {
  cin>>n;
  int a;
  for(int i = 0; i < n; i++)
  {
    cin>>a;
    was[a] = true;
  }
  maxpre[0] = 0;
  for(int i = 1; i < 2*N; i++)
  {
    if(was[i])
      maxpre[i] = i;
    else
      maxpre[i] = maxpre[i-1];
  }
  int ans = 0;
  for(int i = 0; i < 2*N; i++)
    if(was[i])
      for(int j = 2; j*i < 2*N; j++)
        if(maxpre[j*i] >= i)
          ans = max(ans, maxpre[j*i-1]%i);
  cout<<ans<<endl;
  return 0;
}