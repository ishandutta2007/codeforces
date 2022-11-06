#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n;
string collors[50], s;
int l, r, m, cl, cr, cm;

int main(int argc, char const *argv[]) {
  cin>>n;
  l = 1;
  r = 1e9-1;
  for(int i = 0; i < n; i++)
  {
    if(i == 0)
    {
      cout<<1<<" "<<10<<endl;
      cin>>s;
      if(s[0] == 'w')
      {
        cl = 0;
        cr = 1;
      }
      else
      {
        cl = 1;
        cr = 0;
      }
      continue;
    }
    m = (l+r+1)/2;
    cout<<m<<" "<<10<<endl;
    fflush(stdout);
    cin>>s;
    if(s[0] == 'w')
      cm = 0;
    else
      cm = 1;
    if(cm != cl)
      r = m;
    else
      l = m;
  }
  cout<<l<<" "<<9<<" "<<l+1<<" "<<11<<endl;
  fflush(stdout);
  return 0;
}