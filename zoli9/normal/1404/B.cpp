#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int n, a, b, da, db;
vi G[100009];
bool was[100009];
int dist[100009];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
      cin>>n>>a>>b>>da>>db;
      for(int i=1; i<=n; i++)
      {
        G[i].clear();
        was[i]=false;
      }
      for(int i=1; i<n; i++)
      {
        int aa, bb;
        cin>>aa>>bb;
        G[aa].push_back(bb);
        G[bb].push_back(aa);
      }
      if(db<=2*da)
      {
        cout<<"Alice"<<'\n';
        continue;
      }
      queue<int> Q;
      Q.push(a);
      was[a]=true;
      dist[a]=0;
      while(Q.size()>0)
      {
        int cur=Q.front();
        Q.pop();
        for(int nb: G[cur])
        {
          if(!was[nb])
          {
            Q.push(nb);
            was[nb]=true;
            dist[nb]=dist[cur]+1;
          }
        }
      }
      if(dist[b]<=da)
      {
        cout<<"Alice"<<'\n';
        continue;
      }
      int st=1;
      for(int i=1; i<=n; i++)
      {
        was[i]=false;
        if(dist[i]>dist[st]) st=i;
      }
      Q.push(st);
      was[st]=true;
      dist[st]=0;
      while(Q.size()>0)
      {
        int cur=Q.front();
        Q.pop();
        for(int nb: G[cur])
        {
          if(!was[nb])
          {
            Q.push(nb);
            was[nb]=true;
            dist[nb]=dist[cur]+1;
          }
        }
      }
      int diam=0;
      for(int i=1; i<=n; i++)
      {
        diam=max(diam, dist[i]);
      }
      if(diam<=2*da)
      {
        cout<<"Alice"<<'\n';
      }
      else
      {
        cout<<"Bob"<<'\n';
      }
    }


    return 0;
}