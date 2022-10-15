#include <cstdio>
#include <cmath>
#include <cstdlib>
const double pi=acos(-1),eps=1e-6;
double parg,x[3],y[3],r[3];
namespace basic{
	int res;char cdc;bool ng;
	template<typename T>T sq(T x){return x*x;}
	template<typename T>T rv(T x){return x>T()?x:(-x);}
	template<typename T>void swp(T &x,T &y){T z=x;x=y;y=z;}
	inline int read(){
		res=0,ng=false;
		for(;cdc<'0'||cdc>'9';cdc=getchar())ng|=cdc=='-';
		for(;!(cdc<'0'||cdc>'9');cdc=getchar())res=(res<<1)+(res<<3)+(cdc^48);
		return ng?~res+1:res;
	}
}using basic::sq;using basic::rv;using basic::swp;using basic::read;
struct cpx{
	double x,y;
	cpx():x(0),y(0){};
	cpx(double x,double y):x(x),y(y){};
	cpx(double arg):x(cos(arg)),y(sin(arg)){};
	inline cpx operator*(double w)const{return cpx(x*w,y*w);}
	inline cpx operator/(double w)const{return cpx(x/w,y/w);}
	inline cpx operator+(const cpx &nxt)const{return cpx(x+nxt.x,y+nxt.y);}
	inline cpx operator-(const cpx &nxt)const{return cpx(x-nxt.x,y-nxt.y);}
	inline cpx operator*(const cpx &nxt)const{return cpx(x*nxt.x-y*nxt.y,x*nxt.y+y*nxt.x);}
	inline cpx operator/(const cpx &nxt)const{return cpx(x*nxt.x+y*nxt.y,y*nxt.x-x*nxt.y)/(sq(nxt.x)+sq(nxt.y));}
	inline double operator&(const cpx &nxt)const{return x*nxt.y-y*nxt.x;}
	inline double len()const{return sqrt(sq(x)+sq(y));}
	inline cpx back()const{return *this/len();}
}ans;
struct line{
	cpx u,v;
	line(){};
	line(cpx u,cpx v):u(u),v(v){};
	inline cpx t()const{return v-u;}
};
struct circle{
	cpx p;double r;
	circle(){};
	circle(cpx p,double r):p(p),r(r){};
};
inline double area(const cpx &a,const cpx &b,const cpx &c){return ((b-a)&(c-a))/2;}
inline double dist(const cpx &a,const line &b){return rv(area(a,b.u,b.v))*2/b.t().len();}
inline cpx depart(const cpx &a,const cpx &b,double pa,double pb){return (a*pb+b*pa)/(pa+pb);}
inline cpx inter(const line &a,const line &b){return depart(a.u,a.v,area(a.u,b.u,b.v),area(a.v,b.v,b.u));}
inline line vertical(const cpx &a,const cpx &b){return line((a+b)/2,(a+b)/2+(b-a)*cpx(pi/2));}
inline line vertical(int i,int j){return vertical(cpx(x[i],y[i]),cpx(x[j],y[j]));}
inline circle equation(double A,double B,double C,double D){
	double s=-(D/A)+(sq(B)+sq(C))/(sq(A)*4);if(s<0)exit(0);
	return circle(cpx(-B/(2*A),-C/(2*A)),sqrt(s));
}
inline circle equation(int i,int j){
	double A,B,C,D;D=sq(r[i])*(sq(x[j])+sq(y[j]))-sq(r[j])*(sq(x[i])+sq(y[i]));
	A=sq(r[i])-sq(r[j]),B=2*(x[i]*sq(r[j])-x[j]*sq(r[i])),C=2*(y[i]*sq(r[j])-y[j]*sq(r[i]));
	return equation(A,B,C,D);
}
void check(const cpx &a){
	double arg=r[0]/(cpx(x[0],y[0])-a).len();
	if(parg<arg)parg=arg,ans=a;
}
void check(const line &a,const line &b){
	if((a.t()&b.t())<eps)exit(0);
	check(inter(a,b));
}
void check(const line &a,const circle &b){
	double d=dist(b.p,a);if(d>b.r-eps)exit(0);
	cpx p=inter(a,line(b.p,b.p+a.t()*cpx(pi/2))),q=a.t().back()*sqrt(sq(b.r)-sq(d));
	check(p+q),check(p-q);
}
void check(const circle &a,const circle &b){
	double d=(a.p-b.p).len();if(d>a.r+b.r-eps||d<rv(a.r-b.r)+eps)exit(0);
	double arg=acos((sq(a.r)+sq(d)-sq(b.r))/(2*d*a.r));cpx p=(b.p-a.p).back()*a.r,q=cpx(arg);
	check(a.p+p*q),check(a.p+p/q);
}
int main(){
	for(int i=0;i<3;++i)x[i]=read(),y[i]=read(),r[i]=read();
	if(r[0]==r[1]&&r[0]==r[2])check(vertical(0,1),vertical(0,2));
	else if(r[0]!=r[1]&&r[0]!=r[2]&&r[1]!=r[2])check(equation(0,1),equation(0,2));
	else{
		if(r[0]==r[2])swp(x[1],x[2]),swp(y[1],y[2]),swp(r[1],r[2]);
		if(r[1]==r[2])swp(x[0],x[2]),swp(y[0],y[2]),swp(r[0],r[2]);
		check(vertical(0,1),equation(0,2));
	}
	printf("%.5lf %.5lf",ans.x,ans.y);return 0;
}