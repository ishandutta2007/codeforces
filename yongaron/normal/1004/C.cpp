#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n;

int a[123456];
bool used[123456];
bool used2[123456];
int leftt[123456];
int rightt[123456];
long long prel[123456];
long long prer[123456];

int main(int argc, char const *argv[]) {
  cin>>n;
  for(int i = 0; i < n; i++)
    cin>>a[i];
  prel[0] = 0;
  for(int i = 0; i < n; i++)
  {
    if(!used[a[i]])
    {
      used[a[i]] = true;
      leftt[i]++;
    }
    prel[i+1] = prel[i]+leftt[i];
  }
  prer[n+1] = 0;
  for(int i = n-1; i >= 0; i--)
  {
    if(!used2[a[i]])
    {
      used2[a[i]] = true;
      rightt[i]++;
    }
    //prer[i+1] = prel[i+2]+rightt[i];
  }
  long long ans = 0;
  /*for(int i = 0; i < n; i++)
    cout<<prel[i]<<" ";
  cout<<endl;
  for(int i = 0; i < n; i++)
    cout<<rightt[i]<<" ";
  cout<<endl;*/
  for(int i = 1; i < n; i++)
  {
    ans += prel[i]*rightt[i];
  }
  cout<<ans<<endl;
  return 0;
}