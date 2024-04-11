#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
typedef long double Ldb;
const int maxn = 10;
const Ldb eps = 1e-12;
struct Point{
    Ldb x,y;
    Point() {}
    Point(Ldb _x,Ldb _y):x(_x),y(_y) {}
    Point operator + (const Point &t)const{
        return Point(x+t.x,y+t.y);
    }
    Point operator - (const Point &t)const{
        return Point(x-t.x,y-t.y);
    }
    Point operator * (const Ldb &t)const{
        return Point(x*t,y*t);
    }
    Point operator / (const Ldb &t)const{
        return Point(x/t,y/t);
    }
    bool operator < (const Point &t)const{
    	if(fabs(x-t.x)<eps && fabs(y-t.y)<eps)return 0;
        return fabs(x-t.x) < eps ? y<t.y : x<t.x;
    }
    bool operator == (const Point &t)const{
        return fabs(x-t.x)<eps && fabs(y-t.y)<eps;
    }
    Ldb len()const{
        return sqrt(x*x+y*y);
    }
    Point rot90()const{
        return Point(-y,x);
    }
};

struct Circle{
    Point o;
    Ldb r;
    Circle(){}
    Circle(Point _o,Ldb _r):o(_o),r(_r) {}
    friend vector<Point> operator & (const Circle &c1,const Circle &c2){
        Ldb d=(c1.o-c2.o).len();
        if(d>c1.r+c2.r+eps || d<fabs(c1.r-c2.r)-eps)
            return vector<Point>();
        Ldb dt=(c1.r*c1.r-c2.r*c2.r)/d,d1=(d+dt)/2;
        Point dir=(c2.o-c1.o)/d,pcrs=c1.o+dir*d1;
        dt=sqrt(max(0.0L,c1.r*c1.r-d1*d1)),dir=dir.rot90();
        return vector<Point> {pcrs+dir*dt,pcrs-dir*dt};
    }
};
Circle a[4];
const int N=4;
int n,x[N],y[N],r[N],ans,father[N];
inline int get(int x){
	return father[x]==x?x:father[x]=get(father[x]);
}
set<Point> s[4],ss;
set<Point>::iterator it;
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		x[i]=read(); y[i]=read(); r[i]=read(); father[i]=i;
		a[i]=(Circle){Point(x[i],y[i]),r[i]};
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			vector<Point> zs=a[i]&a[j];
			if(!zs.size())continue;
			for(unsigned k=0;k<zs.size();k++){
				s[i].insert(zs[k]); s[j].insert(zs[k]); ss.insert(zs[k]);
			}
			//cout<<i<<" "<<j<<" "<<ans<<endl;
			int t1=get(i),t2=get(j); father[t1]=t2;
		}
	}
	for(int i=1;i<=n;i++)ans+=s[i].size(); ans-=ss.size();
	for(int i=1;i<=n;i++)if(get(i)==i)ans++;
	cout<<ans+1<<endl;
}