#include <bits/stdc++.h> 
using namespace std;
 
int n;
long long a[1000000];
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
long long ans=1;
bool np[1000001];
vector <int> primes;
vector <long long> f;
vector <int> c;
vector <int> g;
map <long long, pair <int, vector <int>>> d;
void divgen(int u, int v, long long s){
  if(u==f.size()){
    d[s]={0, g};
  }
  else{
    g[u]=v;
    divgen(u+1, 0, s);
    if(v<c[u]) divgen(u, v+1, s*f[u]);
  }
}
int total=0;
int goal;
void mulcount(int u, int v, long long s){
  // if(total>=goal) return;
  if(u==f.size()){
    total+=d[s].first;
  }
  else{
    mulcount(u+1, g[u+1], s);
    if(v<c[u]) mulcount(u, v+1, s*f[u]);
  }
}
void solve(){
  // long long rnd=rand();
  // (rnd<<=15)^=rand();
  long long dump=rng();
  dump=rng();
  dump=rng();
  dump=rng();
  dump=rng();
  long long x=a[rng()%n];
  // if(tested.find(x)!=tested.end()) return;
  // tested.insert(x);
  f.clear();
  c.clear();
  d.clear();
  g.clear();
  {
    long long u=x;
    for(long long p: primes) if(u%p==0){
      if(p*p>u) break;
      f.push_back(p);
      c.push_back(0);
      g.push_back(0);
      while(u%p==0){
        c.back()++;
        u/=p;
      }
    }
    if(u>1){
      f.push_back(u);
      c.push_back(1);
      g.push_back(0);
    }
  } 
  divgen(0, 0, 1);
  {
    for(int i=0; i<n; i++){
      int j=i;
      while((j+1<n)&&(a[j+1]==a[j])) j++;
      d[__gcd(x, a[j])].first+=j-i+1;
      i=j;
    }
  }
  for(auto it=d.rbegin(); it!=d.rend(); it++){
    if(it->first<=ans) break;
    g=it->second.second;
    g.push_back(0);
    total=0;
    mulcount(0, g[0], it->first);
    if(total>=goal){
      ans=it->first;
      break;
    }
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  for(int i=2; i<=1000000; i++) if(!np[i]){
    primes.push_back(i);
    for(int j=i+i; j<=1000000; j+=i) np[j]=1;
  }
  
  cin>>n;
  goal=(n+1)/2;
  for(int i=0; i<n; i++) cin>>a[i];
  sort(a, a+n);
  for(int cnt=0; cnt<7; cnt++) solve();
  cout<<ans<<'\n';
}