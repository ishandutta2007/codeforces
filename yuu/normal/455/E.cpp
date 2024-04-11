#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100001];
int s[100001];
template <typename num, num def=0> class line{//y=ax+b
public:
  num a, b;
  line(num a=0, num b=def): a(a), b(b){}
  num at(num x){
    return a*x+b;
  }
  num firstBetter(line <num, def> &l){//a<l.a, 
    //a*x+b<l.a*x+l.b
    num res=(b-l.b)/(l.a-a);//if n-l.b is negative, this can be really dumb
    while(at(res)<l.at(res)) res--;
    while(at(res)>=l.at(res)) res++;
    return res;
  }
  friend bool operator < (const line &A, const line &B){
    return A.a>B.a;
  }
};
template <typename num, num low, num high> class convexHullTrick{
public:
  using line=line<num, (int)1e9>;
  vector <line> s;
  vector <num> p;
  convexHullTrick(){}
  void make(const vector <line> &v){
    s.clear();
    p.clear();
    for(line l: v){
      while((!s.empty())&&(s.back().at(p.back())>=l.at(p.back()))){
        s.pop_back();
        p.pop_back();
      }
      if(s.empty()){
        s.push_back(l);
        p.push_back(low);
      }
      else{
        if(s.back().at(high)<=l.at(high)) continue;
        else{//find first x in [s.back().second, high] such that l.at(x)<s.back().at(x))
          p.push_back(l.firstBetter(s.back()));
          s.push_back(l);
        }
      }
    }
  }
  convexHullTrick(const vector <line> &v){//lines should be sorted by **decreasing** slope
    make(v);
  }
  convexHullTrick(const convexHullTrick &A, const convexHullTrick &B){//can potentially merge using A.p and B.p (?)
    vector <line> v;    
    v.resize(A.s.size()+B.s.size());
    merge(A.s.begin(), A.s.end(), B.s.begin(), B.s.end(), v.begin());
    make(v);
  }
  num get(num x){
    return s[upper_bound(p.begin(), p.end(), x)-p.begin()-1].at(x);
  }
};
line <int, (int)(1e9)> L[100001];
template <typename CHT> class segmentTree{
public:
  using pointer=segmentTree<CHT>*;
  using line=line<int, (int)(1e9)>;
  int l, r, m;
  pointer left, right;
  CHT cht;
  segmentTree(int l, int r): l(l), r(r), m((l+r)/2){
    if(l==r) cht=CHT(vector <line>({L[l]}));
    else{
      left=new segmentTree<CHT>(l, m);
      right=new segmentTree<CHT>(m+1, r);
      cht=CHT(left->cht, right->cht);
    }
  }
  int get(int u, int v, int key){
    if((l>v)||(r<u)) return 1e9;
    if((u<=l)&&(v>=r)) return cht.get(key);
    else return min(left->get(u, v, key), right->get(u, v, key));
  }
};
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin>>n;
  for(int i=1; i<=n; i++){
    cin>>a[i];
    s[i]=s[i-1]+a[i];
    L[i]=line<int, (int)1e9>(a[i], a[i]*i-s[i]);
  }
  auto tree=new segmentTree<convexHullTrick<int, -100000, 0>>(1, n);
  cin>>m;
  for(int c=1, i, j; c<=m; c++){
    cin>>i>>j;
    cout<<s[j]+tree->get(j-i+1, j, i-j)<<'\n';
  }
}