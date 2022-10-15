#include <cstdio>
#include <cmath>
const double eps=1e-2;
double p,a,b,c,r,s,da,db,dc,deg,x[3],y[3];
double dis(int i,int j){
	return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
double gcd(double x,double y){
	if(fabs(x)<eps)return y;
	if(fabs(y)<eps)return x;
	return gcd(y,fmod(x,y));
}
int main(){
	scanf("%lf %lf %lf %lf %lf %lf",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2]);
	a=dis(0,1),b=dis(0,2),c=dis(1,2),p=(a+b+c)/2.0;
	s=sqrt(p*(p-a)*(p-b)*(p-c)),r=a*b*c/(s*4.0);
	da=acos(1.0-a*a/(2.0*r*r)),db=acos(1.0-b*b/(2.0*r*r)),dc=acos(1.0-c*c/(2.0*r*r));
	deg=gcd(gcd(da,db),2*acos(-1)-da-db);
	printf("%.6lf",acos(-1)*r*r*sin(deg)/deg);
	return 0;
}