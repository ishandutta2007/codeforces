#include<iostream>
#include<vector>

using namespace std;

int n;
int mi[1234];

vector<int> v;

int main(int argc, char const *argv[]) {
  cin>>n;
  for(int i = 0; i <= n; i++)
    mi[i] = 1e9;
  for(int i = 0; i < 10; i++)
  {
    v.clear();
    for(int j = 1; j <= n; j++)
      if(j&(1<<i))
        v.push_back(j);
    if(v.size())
    {
      cout<<v.size()<<endl;
      for(int j = 0; j < v.size(); j++)
        cout<<v[j]<<" ";
      cout<<endl;

      int x;
      for(int j = 1; j <= n; j++)
      {
        cin>>x;
        if(!(j&(1<<i)))
          mi[j] = min(mi[j], x);
      }
    }
  }
  for(int i = 0; i < 10; i++)
  {
    v.clear();
    for(int j = 1; j <= n; j++)
      if(!(j&(1<<i)))
        v.push_back(j);
    if(v.size())
    {
      cout<<v.size()<<endl;
      for(int j = 0; j < v.size(); j++)
        cout<<v[j]<<" ";
      cout<<endl;
      int x;
      for(int j = 1; j <= n; j++)
      {
        cin>>x;
        if(j&(1<<i))
          mi[j] = min(mi[j], x);
      }
    }
  }
  cout<<-1<<endl;
  for(int i = 1; i <= n; i++)
    cout<<mi[i]<<" ";
  cout<<endl;
  return 0;
}