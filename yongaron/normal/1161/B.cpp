#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector<int> v[123456];
vector<int> vz;
vector<int> x;

vector<int> najdi_vyskyty(vector<int> text, vector<int> vzor)
{
    vector<int> vysledok;
    for(int zaciatok = 0; zaciatok + vzor.size() <= text.size(); zaciatok++)
    {
        bool sedi = true;
        for(int i=0; i<vzor.size(); i++)
        {
            if(vzor[i] != text[zaciatok + i])
            {
                sedi = false;
                break;
            }
        }
        if(sedi)
        {
            vysledok.push_back(zaciatok);
        }
    }
    return vysledok;
}

int main(int argc, char const *argv[]) {
  cin>>n>>m;
  int a, b;
  for(int i = 0; i < m; i++)
  {
    cin>>a>>b;
    if(a > b)
      swap(a, b);
    if(a+n-b < b-a)
    {
      v[a].push_back(a+n-b);
      v[b].push_back(a+n-b);
    }
    else
    {
      v[a].push_back(b-a);
      v[b].push_back(b-a);
    }
  }
  for(int i = 1; i <= n; i++)
    sort(v[i].begin(), v[i].end());
  for(int i = 1; i <= n; i++)
  {
    vz.push_back(0);
    for(int j = 0; j < v[i].size(); j++)
      vz.push_back(v[i][j]);
  }
  for(int i = 1; i < 2*n-1; i++)
  {
    x.push_back(0);
    for(int j = 0; j < v[i%n+1].size(); j++)
      x.push_back(v[i%n+1][j]);
  }
  // for(int i = 1; i <= n; i++)
  //   cout<<v[i].size()<<endl;
  // for(int i = 0; i < vz.size(); i++)
  //   cout<<vz[i]<<" ";
  // cout<<endl;
  // for(int i = 0; i < x.size(); i++)
  //   cout<<x[i]<<" ";
  // cout<<endl;
  if(najdi_vyskyty(x, vz).size())
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
  return 0;
}