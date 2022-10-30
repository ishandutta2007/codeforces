#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int> > G[100009];
bool bejart[100009];
int legrovidebb[100009];
int apa[100009];

struct csucs {
  int azonosito;
  int tav;
  bool operator<(const csucs & cs) const {
    return tav>cs.tav;
  }
};
csucs cs1, cs2;


int main() {
	cin>>n>>m;
  for(int i=1; i<=m; i++) {
    int a, b, suly;
    cin>>a>>b>>suly;
    G[a].push_back({b, suly});
    G[b].push_back({a, suly});
  }
  for(int i=1; i<=n; i++) {
    bejart[i]=false;
    legrovidebb[i]=-1;
  }
  priority_queue<csucs> Q;
  apa[1]=0;
  cs1.azonosito=1;
  cs1.tav=0;
  legrovidebb[1]=0;
  Q.push(cs1);
  while(Q.size()>0) {
    cs1=Q.top();
    Q.pop();
    if(!bejart[cs1.azonosito]) {
      bejart[cs1.azonosito]=true;
      for(pair<int, int> szomszed: G[cs1.azonosito]) {
        if(!bejart[szomszed.first]) {
          if(legrovidebb[szomszed.first]==-1 || (cs1.tav+szomszed.second<legrovidebb[szomszed.first])) {
            cs2.azonosito=szomszed.first;
            cs2.tav=cs1.tav+szomszed.second;
            legrovidebb[szomszed.first]=cs1.tav+szomszed.second;
            apa[szomszed.first]=cs1.azonosito;
            Q.push(cs2);
          }
        }
      }
    }
  }
  
  if(!bejart[n]) {
    cout<<-1<<endl;
    return 0;
  }
  
  vector<int> valasz;
  int aktualis=n;
  while(aktualis!=0) {
    valasz.push_back(aktualis);
    aktualis=apa[aktualis];
  }
  reverse(valasz.begin(), valasz.end());
  for(int x: valasz) {
    cout<<x<<" ";
  }
  cout<<endl;
	return 0;
}
//https://codeforces.com/problemset/problem/20/C