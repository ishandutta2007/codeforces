#include <bits/stdc++.h>
using namespace std;
const int eps = 1e-10;
const int maxn = 1e5+10;
inline int sgn(double x){return (x>eps) - (x<-eps);}
struct P{
	double x, y;
	P(){}
	P(double _x,double _y){x=_x;y=_y;}
    P operator+(const P &t)const {return P(x+t.x,y+t.y);}
    P operator-(const P &t)const {return P(x-t.x,y-t.y);}
    P operator*(const double &t)const {return P(x*t,y*t);}
    P operator/(const double &t)const {return P(x/t,y/t);}
    bool operator<(const P &t)const {return (x==t.x)?y<t.y:x<t.x;}
    bool operator==(const P &t)const {return sgn(x-t.x) == 0 && sgn(y-t.y) == 0;}
    double operator^(const P &t)const {return x*t.y-y*t.x;}
    double operator*(const P &t)const {return x*t.x+y*t.y;}
    double len(){return sqrt(x*x+y*y);}
    void in(){scanf("%lf%lf",&x,&y);}
    void out(){cout<<"("<<x<<" , "<<y<<")"<<endl;}
}A[maxn],B[maxn];
double dist(P a,P b){ return sqrt((b-a)*(b-a));}
double cnt_dist(P o, P a, P b){
	if(a == b) return dist(o,a);
	P v1 = b - a, v2 = o - a, v3 = o - b;
	if(sgn(v1 * v2) < 0) return v2.len();
	if(sgn(v1 * v3) > 0) return v3.len();
	return fabs(v1 ^ v2) / v1.len();
}
int n;
double d1,d2;
void work(){
    scanf("%d%lf%lf",&n,&d1,&d2);
    bool close = false;
    int times = 0;
    A[0].in();B[0].in();
    if (sgn (dist(A[0],B[0]) - d1) <= 0) {times++;close = true;}

    double tost, toed, mid;
    P va, vb, v;
    for (int i=1;i<n;i++){
//        cout<<"--------------------------i = "<<i<<endl;
        A[i].in();B[i].in();
        va = (A[i] - A[i-1]);
        vb = (B[i] - B[i-1]);
        v = ((B[i-1] + vb) - va);

//        va.out();
//        vb.out();
//        v.out();

        tost = dist(A[i-1], B[i-1]);
        toed = dist(A[i-1], v);
        mid = cnt_dist(A[i-1], B[i-1], v);
//        cout<<"tost = "<<tost<<"\ttoed = "<<toed<<"\tmid = "<<mid<<endl;

        if (sgn(mid - tost) != 0 && sgn(mid - toed) != 0){
//            cout<<"zhexian"<<endl;
            if (!close && sgn(mid - d1) <= 0) {close = true; times++;}
            if (close && sgn(toed - d2) > 0) close = false;
        }else if (sgn(tost - toed) <= 0){//far
//            cout<<"far"<<endl;
            if (close && sgn(toed - d2) > 0) close = false;
        }else{//close
//            cout<<"close"<<endl;
            if (!close && sgn(toed - d1) <= 0) {close = true; times++;}
        }
//        cout<<"times = "<<times<<endl;
    }
    printf("%d\n",times);
}
int main(){
//    freopen("in.txt","r",stdin);
    work();
}