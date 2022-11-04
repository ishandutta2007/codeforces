#include<bits/stdc++.h>
#define db long double
#define ll long long
#define pi acos(-1)
#define eps 1e-13
#define N 400005
using namespace std;
int sgn(db x){
	if (fabs(x)<=eps) return 0;
	return x<0?-1:1;
}
int Plane[2][2]={{2,1},
				 {3,4}};
struct P{
	db x,y,deg;
	int p;
	P(){}
	P(db _x,db _y){
		x=_x; y=_y;
		p=Plane[y<0][x>0];
	}
	P operator +(const P &b)const{
		return P(x+b.x,y+b.y);
	}
	P operator -(const P &b)const{
		return P(x-b.x,y-b.y);
	}
	P operator *(const db &b)const{
		return P(x*b,y*b);
	}
	db operator *(const P &b)const{
		return x*b.y-y*b.x;
	}
	bool operator <(const P &a)const{
		if (p!=a.p)
			return p<a.p;
		return sgn(*this*a)>0;
	}
	bool operator ==(const P &a)const{
		return !sgn(x-a.x)&&!sgn(y-a.y);
	}
	bool jdb(const P &a)const{
		return !sgn(*this*a)&&sgn(x)==sgn(a.x)&&sgn(y)==sgn(a.y);
	}
};
struct Hp{
	P a,b;
	Hp(){}
	Hp(P x,P y){
		a=x; b=y-x;
	}
	bool contain(P x)const{
		return sgn((x-a)*b)>=0;
	}
};
P getsec(Hp a,Hp b){
	db s1=(b.a-a.a)*a.b;
	db s2=a.b*(b.a+b.b-a.a);
	db k=s1/(s1+s2);
	return b.a+b.b*k;
}
bool cmp(P a,P b){
	return a.deg<b.deg;
}
bool cmpL(Hp a,Hp b){
	if (a.b.jdb(b.b))
		return sgn(a.b*(b.a-a.a))>0;
	return a.b<b.b;
}
P p[N];
Hp l[N*2];
Hp q[N*2];
P tmp[N*2];
db calcS(int cnt){
	db inf=1e6,ans=0;
	l[++cnt]=Hp(P(-inf,-inf),P(-inf,inf));
	l[++cnt]=Hp(P(-inf,inf),P(inf,inf));
	l[++cnt]=Hp(P(inf,inf),P(inf,-inf));
	l[++cnt]=Hp(P(inf,-inf),P(-inf,-inf));
	sort(l+1,l+cnt+1,cmpL);
	int Cnt=1;
	for (int i=2;i<=cnt;i++)
		if (!l[i].b.jdb(l[i-1].b))
			l[++Cnt]=l[i];
	if (Cnt<2) return 0;
	cnt=Cnt;
	int h=1,t=0;
	q[++t]=l[1];
	q[++t]=l[2];
	for (int i=3;i<=cnt;i++){
		for (;h<t&&!l[i].contain(getsec(q[t],q[t-1]));t--);
		for (;h<t&&!l[i].contain(getsec(q[h],q[h+1]));h++);
		q[++t]=l[i];
	} 
	for (;h<t&&!q[h].contain(getsec(q[t],q[t-1]));t--);
	for (;h<t&&!q[t].contain(getsec(q[h],q[h+1]));h++);
	if (t-h<=1) return 0;
	Cnt=0;
	for (int i=h;i<t;i++)
		tmp[++Cnt]=getsec(q[i],q[i+1]);
	tmp[++Cnt]=getsec(q[t],q[h]);
	for (int i=1;i<Cnt;i++)
		ans+=tmp[i]*tmp[i+1];
	ans+=tmp[Cnt]*tmp[1];
	return ans/2; 
}
void solve(){
	int n,m,cnt=0;
	scanf("%d",&n);
	m=2*n-1;
	for (int i=0;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		p[i].x=x; p[i].y=y;
		if (!i) continue;
		p[i].deg=atan2(p[i].y-p[0].y,p[i].x-p[0].x);
	}
	sort(p+1,p+n,cmp);
	for (int i=1;i<n;i++)
		p[i+n-1]=p[i],p[i+n-1].deg+=2*pi;
	for (int i=1,j=1;i<n;i++){
		for (;j+1<m&&sgn(p[i].deg+pi-p[j+1].deg)>=0;j++);
		if (!sgn(p[i+1].deg-p[i].deg))
			return puts("0"),void(0);
		if (i!=j&&!sgn(p[j].deg-p[i].deg-pi))
			return puts("0"),void(0);
		if (i!=j){
			l[++cnt]=Hp(P(p[i+1].x,p[i+1].y),P(p[i].x,p[i].y));
			l[++cnt]=Hp(P(p[j].x,p[j].y),P(p[i].x,p[i].y));
		}
	}
	printf("%.15lf\n",(double)calcS(cnt));
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}