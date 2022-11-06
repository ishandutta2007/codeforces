#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, s;
int t;

bool l[1234];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n;
  while((s+1)*(s+1) <= n)
    s++;
  int spa = n/s;
  if(s*spa < n)
    spa++;
  while(t < n-spa-(s-1))
  {
    cout<<s<<" ";
    t += s;
    int done = 0;
    for(int i = 0; i < s; i++)
    {
      for(int j = 0; j <= n/s+1; j++)
      {
        if(j*s+i < n-1 && !l[j*s+i])
        {
          cout<<j*s+i+1<<" ";
          l[j*s+i] = true;
          done++;
        }
        if(done == s)
          break;
      }
      if(done == s)
        break;
    }
    cout<<endl;
    int x;
    cin>>x;
    x--;
    for(int i = 0; i < s; i++)
    {
      if(l[(x+i)%n])
      {
        l[(x+i)%n] = 0;
        t--;
      }
    }
  }
  cout<<0<<endl;
  return 0;
}