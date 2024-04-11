#include<iostream>
#include<string>

using namespace std;

int t;
string s;
int n, a, b;

int main(int argc, char const *argv[]) {
  cin>>t;
  while(t--)
  {
    cin>>n>>a>>b;
    s = "";
    for(int i = 0; i < a-b; i++)
      s += 'a';
    for(int i = a-b; i < a; i++)
      s += 'a'+(i-(a-b));
    for(int i = a; i < n; i++)
      s += s[s.size()-a];
    cout<<s<<endl;
  }
  return 0;
}