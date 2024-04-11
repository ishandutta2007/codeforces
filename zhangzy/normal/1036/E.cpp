#include<bits/stdc++.h>
using namespace std;

#define ll long long
struct P{ int x, y; };
P operator + (const P &a,const P &b){ return (P){a.x+b.x,a.y+b.y}; }
P operator - (const P &a,const P &b){ return (P){a.x-b.x,a.y-b.y}; }
ll ddd(const P &a,const P &b){ return (ll)a.x*b.x+(ll)a.y*b.y; }
ll xxx(const P &a,const P &b){ return (ll)a.x*b.y-(ll)b.x*a.y; }

#define db double
db pi=atan2(0,-1);
struct Po{ db x,y; };
Po itod(P a){ return (Po){(db)a.x,(db)a.y}; }
P dtoi(Po a){ return (P){(int)round(a.x),(int)round(a.y)}; } 
Po operator + (const Po &a,const Po &b){ return (Po){a.x+b.x,a.y+b.y}; }
Po operator - (const Po &a,const Po &b){ return (Po){a.x-b.x,a.y-b.y}; }
Po operator * (const Po &a,const db &b){ return (Po){a.x*b,a.y*b}; }
Po operator / (const Po &a,const db &b){ return (Po){a.x/b,a.y/b}; }
db ddd(const Po &a,const Po &b){ return a.x*b.x+a.y*b.y; }
db xxx(const Po &a,const Po &b){ return a.x*b.y-a.y*b.x; }
db len(const Po &v){ return sqrt(v.x*v.x+v.y*v.y); }
Po uni(const Po &v){ return v/len(v); }
Po rot(Po a,Po b=(Po){0,1}){return(Po){a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x};}
Po rot(Po a,db ang){ return rot(a,(Po){cos(ang),sin(ang)}); }

struct Li{ Po p,v; };
Po vtcfot(Po p,Li l){
  db d=ddd(l.v=uni(l.v),p-l.p);
  return l.p+(l.v*d);
}
db dis(Po p,Li l){ return len(p-vtcfot(p,l)); }
Po cro(Li c,Li d){
  db e=xxx((d.p-c.p),d.v)/xxx(c.v,d.v);
  return c.p+(c.v*e);
}

int n, ans;
P p1[1010], p2[1010];
Li l[1010];

struct cmp{
  bool operator ()(const P &a,const P &b){
    return a.x!=b.x? a.x<b.x: a.y<b.y;
  }
};
map<P,int,cmp>mp;

int gcd(int x,int y){
  return !x||!y? x+y: __gcd(x,y);
}

bool in(int a,int b,int c){
  return a<=b&&b<=c||a>=b&&b>=c;
}
bool in(P a,P b,P c){
  if (!in(a.x,b.x,c.x)) return 0;
  if (!in(a.y,b.y,c.y)) return 0;
  return xxx(b-a,c-a)==0;
}

int main(){
  cin>>n;
  for (int i=1;i<=n;++i){
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    p1[i]=(P){a,b}; p2[i]=(P){c,d};
    ans+=gcd(abs(a-c),abs(b-d))+1;
    l[i]=(Li){itod(p1[i]),itod(p2[i]-p1[i])};
  }
  for (int i=1;i<=n;++i)
    for (int j=i+1;j<=n;++j){
      P p=dtoi(cro(l[i],l[j]));
      if (in(p1[i],p,p2[i])&&in(p1[j],p,p2[j])) ++mp[p];
    }
  cerr<<ans<<endl;
  for (auto &it:mp){
    for (int i=1;;++i)
      if (i*(i+1)/2==it.second){
	ans-=i; break;
      }
  }
  cout<<ans<<endl;
}