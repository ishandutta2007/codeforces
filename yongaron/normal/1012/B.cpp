#include<iostream>
#include<string>
#include<vector>

using namespace std;

int n, m, q;

vector<int> sl[223456];
vector<int> ra[232456];
vector<int> grafsl[423456];

int slcomp[423456], slcom = 0;

df1(int v)
{
  //cout<<v<<endl;
  slcomp[v] = slcom;
  for(int i = 0; i < grafsl[v].size(); i++)
  {
    if(!slcomp[grafsl[v][i]])
      df1(grafsl[v][i]);
  }
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin>>n>>m>>q;
  int a, b;
  for(int i = 0; i < q; i++)
  {
    cin>>a>>b;
    if(sl[a].size())
    {
      grafsl[sl[a].back()].push_back(b);
      grafsl[b].push_back(sl[a].back());
    }
    grafsl[m+a].push_back(b);
    grafsl[b].push_back(m+a);
    sl[a].push_back(b);
    if(ra[b].size())
    {
      grafsl[m+ra[b].back()].push_back(m+a);
      grafsl[m+a].push_back(m+ra[b].back());
    }
    ra[b].push_back(a);
  }
  /*for(int i = 1; i <= m+n; i++)
  {
    for(int j = 0; j < grafsl[i].size(); j++)
      cout<<grafsl[i][j]<<" ";
    cout<<endl;
  }*/
  for(int i = 1; i <= m+n; i++)
  {
    if(!slcomp[i]/* && grafsl[i].size()*/)
    {
      //cout<<"I"<<i<<endl;
      slcom++;
      df1(i);
    }
  }
  /*int ans = 0;
  ans += n+m;
  for(int i = 1; i <= m; i++)
  {
    if(ra[i].size())
      ans--;
  }
  for(int i = 1; i <= n; i++)
  {
    if(sl[i].size())
      ans--;
  }*/
  //cout<<slcom<<endl;
  /*cout<<ans<<endl;
  for(int i = 1; i <= n; i++)
    cout<<slcomp[i]<<" s";
  cout<<endl;*/
  cout<<slcom-1/*+ans*/<<endl;
  /*for(int i = 1; i <= m; i++)
    cout<<racomp[i]<<" ";
  cout<<endl;*/
  return 0;
}