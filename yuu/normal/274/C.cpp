#include <bits/stdc++.h>
using namespace std;
#define love long
#define live double
#define sqr(x) ((x)*(x))
class point{
public:
  love live x, y;
  void input(){
    cin>>x>>y;
  }
  love live dist(point P){
    return sqrtl(sqr(x-P.x)+sqr(y-P.y));
  }
  love live dist2(point P){
      return sqr(x-P.x)+sqr(y-P.y);
  }
  point(){x=y=0;}
  point(love live x, love live y): x(x), y(y){}
  friend ostream& operator <<(ostream &cout, point X){
    cout<<"("<<X.x<<", "<<X.y<<")";
    return cout;
  }
};
int n;
vector <point> p;
class line{
public:
  love live a, b, c;
  point A, B;
  line(love live a, love live b, love live c): a(a), b(b), c(c){}
  line(point A, point B): A(A), B(B){
    a=A.y-B.y;
    b=B.x-A.x;
    c=-(a*A.x+b*A.y);
  }
  point intersect(line B){///no exception handler for parallel
    if(abs(a)<1e-9) return B.intersect((*this));
    B.b-=(B.a/a)*b;
    B.c-=(B.a/a)*c;
    love live y=-B.c/B.b;
    love live x=(-c-b*y)/a;
    return point(x, y);
  }
  line perpendicular_bisector(){
    line res(b, -a, 0);
    point mid((A.x+B.x)/2, (A.y+B.y)/2);
    res.c=-(mid.x*res.a+mid.y*res.b);
    return res;
  }
};
point circumcenter(point A, point B, point C){
  {
    love live AB=A.dist(B);
    love live AC=A.dist(C);
    love live BC=B.dist(C);
    if(min(min(sqr(AB)+sqr(AC)-sqr(BC), sqr(AB)+sqr(BC)-sqr(AC)), sqr(AC)+sqr(BC)-sqr(AB))<=-1e-9) return point(-1e8, -1e8);///obtuse triangle
    if(min(min(abs(sqr(AB)+sqr(AC)-sqr(BC)), abs(sqr(AB)+sqr(BC)-sqr(AC))), abs(sqr(AC)+sqr(BC)-sqr(AB)))<=1e-9){///right triangle
      return point(-1e9, -1e9);
    }
  }
  line AB(A, B), BC(B, C);
  AB=AB.perpendicular_bisector();
  BC=BC.perpendicular_bisector();
  return AB.intersect(BC);
}
love live ans=0;
void check_rect(point A, point B, point C, point D){
  if(A.dist(B)>A.dist(C)) swap(B, C);
  if(A.dist(C)>A.dist(D)) swap(C, D);
  if(abs(A.dist2(B)+A.dist2(C)-B.dist2(C))>1e-9) return;
  if(abs(D.dist2(B)+D.dist2(C)-B.dist2(C))>1e-9) return;
  if(abs(B.dist2(A)+B.dist2(D)-A.dist2(D))>1e-9) return;
  if(abs(B.dist2(C)-A.dist2(D))>1e-9) return;
  ///ABDC is a rectangle
  point X((A.x+D.x)/2, (A.y+D.y)/2);
  love live min_time=1e9;
  for(auto B: p) min_time=min(min_time, X.dist(B));
  if(min_time-A.dist(X)<-1e-9) return;
  ans=max(ans, min_time);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin>>n;
  p.resize(n);
  for(auto &x: p) x.input();
  for(int i=0; i<n; i++) for(int j=i+1; j<n; j++) for(int k=j+1; k<n; k++){
    point A=circumcenter(p[i], p[j], p[k]);
    if(A.x==-1e9){
      for(int l=k+1; l<n; l++) check_rect(p[i], p[j], p[k], p[l]);
      continue;
    }
    else if(A.x==-1e8) continue;
    love live min_time=1e9;
    for(auto B: p) min_time=min(min_time, A.dist(B));
    if(min_time-p[i].dist(A)<-1e-9) continue;
    ans=max(ans, min_time);
  }
  if(abs(ans)<1e-9) cout<<"-1\n";
  else cout<<setprecision(10)<<fixed<<ans<<'\n';
}