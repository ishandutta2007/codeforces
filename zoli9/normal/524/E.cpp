#include <bits/stdc++.h>
using namespace std;

int vegtelen=100000009;
int ertek[1000009];
void modosit(int cs, int k, int v, int mit, int mire)
{
  if(mit<k || v<mit) return;
  if(k==v)
  {
    ertek[cs]=mire;
    return;
  }
  modosit(2*cs, k, (k+v)/2, mit, mire);
  modosit(2*cs+1, (k+v)/2+1, v, mit, mire);
  ertek[cs]=min(ertek[2*cs], ertek[2*cs+1]);
}
int minimum(int cs, int k, int v, int x, int y)
{
  if(x<=k && v<=y) return ertek[cs];
  if(v<x || y<k) return vegtelen;
  return min(minimum(2*cs, k, (k+v)/2, x, y), minimum(2*cs+1, (k+v)/2+1, v, x, y));
}


int n, m, k, q;
vector <int> obastya[100009];
vector <int> sbastya[100009];
struct query
{
  int x1, y1, x2, y2;
  int az;
};
vector<query> qu;
vector<query> xveg[100009];
vector<query> yveg[100009];
bool sorokjok[200009];
bool oszlopokjok[200009];
int main() {
  ios::sync_with_stdio(false);
  cin>>n>>m>>k>>q;
  qu.resize(q);
  for(int i=1; i<=k; i++)
  {
    int bx, by;
    cin>>bx>>by;
    obastya[bx].push_back(by);
    sbastya[by].push_back(bx);
  }
  for(int i=0; i<q; i++)
  {
    cin>>qu[i].x1>>qu[i].y1>>qu[i].x2>>qu[i].y2;
    qu[i].az=i+1;
    xveg[qu[i].x2].push_back(qu[i]);
    yveg[qu[i].y2].push_back(qu[i]);
  }
  for(int xx=1; xx<=n; xx++)
  {
    for(auto index: obastya[xx])
    {
      modosit(1, 0, m-1, index-1, xx);
      //cout<<index-1<<"*"<<xx<<endl;
    }
    for(query aktq: xveg[xx])
    {
      //for (int s = 1; s<=10; s++) cout << ertek[s] << " ";
      //cout << endl;
      int mm=minimum(1, 0, m-1, aktq.y1-1, aktq.y2-1);
      if(aktq.x1<=mm) sorokjok[aktq.az]=true;
      //cout << aktq.y1-1 << " " << aktq.y2-1 << " " << mm << endl;
    }
  }
  for(int i=0; i<=1000000; i++) ertek[i]=0;
  for(int yy=1; yy<=m; yy++)
  {
    for(auto index: sbastya[yy])
    {
      modosit(1, 0, n-1, index-1, yy);
    }
    for(query aktq: yveg[yy])
    {
      int mm=minimum(1, 0, n-1, aktq.x1-1, aktq.x2-1);
      if(aktq.y1<=mm) oszlopokjok[aktq.az]=true;
      //cout << aktq.az << " " << mm << endl;
    }
  }
  for(int i=1; i<=q; i++)
  {
    if(sorokjok[i] || oszlopokjok[i]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    //cout<<sorokjok[i]<<" "<<oszlopokjok[i]<<endl;
  }
  return 0;
}