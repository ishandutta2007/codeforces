#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t;

vector<int> s, b;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>n;
    char c;
    s.clear();
    b.clear();
    if(n%2)
    {
      s.push_back(n);
      b.push_back(n);
    }
    for(int i = 0; i < n/2; i++)
    {
      cout<<"? "<<2*i+1<<" "<<2*i+2<<endl;
      cin>>c;
      if(c == '>')
      {
        b.push_back(2*i+1);
        s.push_back(2*i+2);
      }
      else
      {
        s.push_back(2*i+1);
        b.push_back(2*i+2);
      }
    }
    int bi = b[0];
    for(int i = 1; i < b.size(); i++)
    {
      cout<<"? "<<bi<<" "<<b[i]<<endl;
      cin>>c;
      if(c == '<')
        bi = b[i];
    }
    int si = s[0];
    for(int i = 1; i < s.size(); i++)
    {
      cout<<"? "<<si<<" "<<s[i]<<endl;
      cin>>c;
      if(c == '>')
        si = s[i];
    }
    cout<<"! "<<si<<" "<<bi<<endl;
  }
  return 0;
}