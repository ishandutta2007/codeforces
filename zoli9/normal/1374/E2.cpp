#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int n, m, k;
vector<pair<ll, pii> > w;
vector<pair<int, pii> > like;
vector<pair<ll, int> > AB, AA, BB;
vll Apref, Bpref, ABpref, wPref;

int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin>>n>>m>>k;
  for(int i=1; i<=n; i++)
  {
    ll t;
    int a, b;
    cin>>t>>a>>b;
    if(a==1 && b==1)
    {
      w.push_back({t, {0, i}});
      AB.push_back({t, i});
    }
    else if(a==1)
    {
      w.push_back({t, {1, i}});
      AA.push_back({t, i});
    }
    else if(b==1)
    {
      w.push_back({t, {2, i}});
      BB.push_back({t, i});
    }
    else
    {
      w.push_back({t, {3, i}});
    }
  }
  sort(w.begin(), w.end());
  sort(AB.begin(), AB.end());
  sort(AA.begin(), AA.end());
  sort(BB.begin(), BB.end());
  Apref.push_back(0);
  for(int i=0; i<AA.size(); i++)
  {
    Apref.push_back(Apref.back()+AA[i].F);
  }
  Bpref.push_back(0);
  for(int i=0; i<BB.size(); i++)
  {
    Bpref.push_back(Bpref.back()+BB[i].F);
  }
  ABpref.push_back(0);
  for(int i=0; i<AB.size(); i++)
  {
    ABpref.push_back(ABpref.back()+AB[i].F);
  }
  wPref.push_back(0);
  for(int i=0; i<w.size(); i++)
  {
    wPref.push_back(wPref.back()+w[i].F);
  }
  like.push_back({0, {0, 0}});
  for(int i=0; i<w.size(); i++)
  {
    pair<int, pii> L=like.back();
    if(w[i].S.F==0) like.push_back({L.F+1, {L.S.F, L.S.S}});
    if(w[i].S.F==1) like.push_back({L.F, {L.S.F+1, L.S.S}});
    if(w[i].S.F==2) like.push_back({L.F, {L.S.F, L.S.S+1}});
    if(w[i].S.F==3) like.push_back({L.F, {L.S.F, L.S.S}});
  }
  ll bestans=-1;
  ll bestdb=-1;
  ll sumsame=0;
  for(int dbsame=0; dbsame<=min(k, (int)(AB.size())); dbsame++)
  {
    if(dbsame>0) sumsame+=AB[dbsame-1].F;
    int morelikes=k-dbsame;
    if(morelikes>AA.size() || morelikes>BB.size()) continue;
    ll curans=sumsame+Apref[morelikes]+Bpref[morelikes];
    int kell=m-dbsame-2*morelikes;
    if(kell<0) continue;
    if(kell==0)
    {
      if(bestans==-1 || curans<bestans)
      {
        bestans=curans;
        bestdb=dbsame;
      }
    }
    int elso=0;
    int utolso=n-1;
    while(elso<=utolso)
    {
      int koz=(elso+utolso)/2;
      int unused=koz+1-min(dbsame, like[koz+1].F)-min(morelikes, like[koz+1].S.F)-min(morelikes, like[koz+1].S.S);
      if(unused<kell)
      {
        elso=koz+1;
      }
      else
      {
        utolso=koz-1;
      }
    }
    curans+=wPref[elso+1];
    curans-=ABpref[min(dbsame, like[elso+1].F)];
    curans-=Apref[min(morelikes, like[elso+1].S.F)];
    curans-=Bpref[min(morelikes, like[elso+1].S.S)];
    if(bestans==-1 || curans<bestans)
    {
      bestans=curans;
      bestdb=dbsame;
    }
  }
  if(bestans==-1)
  {
    cout<<bestans<<endl;
    return 0;
  }
  cout<<bestans<<endl;
  vi answer;
  vi was(n+1, false);
  for(int i=0; i<bestdb; i++)
  {
    answer.push_back(AB[i].S);
    was[AB[i].S]=true;
  }
  for(int i=0; i<k-bestdb; i++)
  {
    answer.push_back(AA[i].S);
    was[AA[i].S]=true;
    answer.push_back(BB[i].S);
    was[BB[i].S]=true;
  }
  int extra=m-bestdb-(2*(k-bestdb));
  int i=0;
  for(int j=1; j<=extra; j++)
  {
    while(i<n && was[w[i].S.S])
    {
      i++;
    }
    answer.push_back(w[i].S.S);
    was[w[i].S.S]=true;
  }
  for(int x: answer) cout<<x<<" ";
  cout<<endl;
  
	return 0;
}