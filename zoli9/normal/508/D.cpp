#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> G[200009];
vector<int> P[200009];
vector<int> H[200009];
bool bejar[200009];
int kezdo=0;
int paratlan=0;
int mutato[200009];
vector<int> v;
vector<int> seta;
vector<bool> volt[200009];
string s[200009];
int befok[200009];
int ert(char z)
{
  if('a'<=z && z<='z') return z-'a';
  else if('A'<=z && z<='Z') return 26+z-'A';
  else return 52+z-'0';
}
char karakter(int w)
{
  if(w<26) return 'a'+w;
  if(w<52) return 'A'+w-26;
  return '0'+w-52;
}
void dfs(int x)
{
  bejar[x]=true;
  for(int sz: P[x]) if(!bejar[sz]) dfs(sz);
}
void dfs2(int x)
{
  while(mutato[x]<G[x].size() && volt[x][mutato[x]]) mutato[x]++;
  if(mutato[x]!=G[x].size())
  {
    int sz=G[x][mutato[x]];
    v.push_back(sz);
    volt[x][mutato[x]]=true;
    //volt[sz][H[x][mutato[x]]]=true;
    dfs2(sz);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin>>n;
  for(int i=1; i<=n; i++)
  {
    cin>>s[i];
    int a=62*ert(s[i][0])+ert(s[i][1]);
    int b=62*ert(s[i][1])+ert(s[i][2]);
    G[a].push_back(b);
    befok[b]++;
    volt[a].push_back(false);
    P[a].push_back(b);
    P[b].push_back(a);
  }
  
  /*for(int i=1; i<=m; i++)
  {
    int a, b;
    cin>>a>>b;
    G[a].push_back(b);
    G[b].push_back(a);
    H[a].push_back(G[b].size()-1);
    H[b].push_back(G[a].size()-1);
    volt[a].push_back(false);
    volt[b].push_back(false);
  }*/
  for(int i=0; i<62*62; i++)
  {
    if(G[i].size()>0)
    {
      kezdo=i;
      dfs(i);
      break;
    }
  }
  for(int i=0; i<62*62; i++)
  {
    if(abs((int)G[i].size()-befok[i])>1)
    {
      cout<<"NO"<<endl;
      return 0;
    }
    if(!bejar[i] && G[i].size()>0)
    {
      cout<<"NO"<<endl;
      return 0;
    }
    if(G[i].size()>befok[i])
    {
      paratlan++;
      kezdo=i;
    }
  }
  if(paratlan>1)
  {
    cout<<"NO"<<endl;
    return 0;
  }
  cout<<"YES"<<endl;
  v.push_back(kezdo);
  while(v.size()>0)
  {
    int akt=v.back();
    while(mutato[akt]<G[akt].size() && volt[akt][mutato[akt]]) mutato[akt]++;
    if(mutato[akt]==G[akt].size())
    {
      seta.push_back(akt);
      v.pop_back();
      continue;
    }
    dfs2(akt);
  }
  for(int i=seta.size()-1; i>=0; i--) cout<<karakter(seta[i]/62);
  cout<<karakter(seta[0]%62)<<endl;
  return 0;
}