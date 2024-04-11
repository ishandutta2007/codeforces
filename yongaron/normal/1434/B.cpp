#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>

#define ll long long

using namespace std;

int n;

ll p[223456];

vector<int> v;
char c[222222];
int x[222222];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n;
  for(int i = 0; i < 2*n; i++)
  {
    cin>>c[i];
    if(c[i] == '-')
    {
      cin>>x[i];
      if(!v.size())
      {
        cout<<"NO"<<endl;
        return 0;
      }
      p[v.back()] = x[i];
      v.pop_back();
    }
    else
    {
      v.push_back(i);
    }
  }
  set<int> st;
  for(int i = 0; i < 2*n; i++)
  {
    if(c[i] == '+')
    {
      st.insert(p[i]);
    }
    else
    {
      if(*st.begin() != x[i])
      {
        cout<<"NO"<<endl;
        return 0;
      }
      st.erase(st.begin());
    }
  }
  cout<<"YES"<<endl;
  for(int i = 0; i < 2*n; i++)
  {
    if(c[i] == '+')
      cout<<p[i]<<" ";
  }
  cout<<endl;
  return 0;
}