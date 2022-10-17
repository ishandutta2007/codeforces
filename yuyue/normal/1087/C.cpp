#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
	return w*c;
}
int g[2000][2000],cnt;
struct node{
	int x,y;
}a,b,c,ans[201010];
int dis(node x,node y){
	return abs(x.x-y.x)+abs(x.y-y.y);
}
void f(node p){
	if (!g[p.x][p.y]) 
	ans[++cnt]=p;
	g[p.x][p.y]=1;
}

void print(){
	cout<<"A   ("<<a.x<<" , "<<a.y<<")\n";
	cout<<"B   ("<<b.x<<" , "<<b.y<<")\n";
	cout<<"C   ("<<c.x<<" , "<<c.y<<")\n";
}
void out(node p){
	cout<<"out:  ("<<p.x<<" , "<<p.y<<")\n";
}
void walk(node &H,node x,node y,node z){
	f(x);
	node t; int v;
	t=x; t.x--;
	v=dis(x,y)+dis(x,z)-dis(t,y)-dis(t,z);
//	cout<<v<<"\n";
//	out(x); out(t); out(y); out(z);
//	cout<<dis(x,y)<<"    dis\n";
	while (v==2){
		x=t;
		t.x--;
		f(x);
		v=dis(x,y)+dis(x,z)-dis(t,y)-dis(t,z);
	}
	t=x; t.x++;
	v=dis(x,y)+dis(x,z)-dis(t,y)-dis(t,z);
	while (v==2){
		x=t;
		t.x++;
		f(x);
		v=dis(x,y)+dis(x,z)-dis(t,y)-dis(t,z);
	}
	t=x; t.y--;
	v=dis(x,y)+dis(x,z)-dis(t,y)-dis(t,z);
	while (v==2){
		x=t;
		t.y--;
		f(x);
		v=dis(x,y)+dis(x,z)-dis(t,y)-dis(t,z);
	}
	t=x; t.y++;
	v=dis(x,y)+dis(x,z)-dis(t,y)-dis(t,z);
	while (v==2){
		x=t;
		t.y++;
		f(x);
		v=dis(x,y)+dis(x,z)-dis(t,y)-dis(t,z);
	}
	H=x;
}
int main(){
	a=(node){read(),read()};
	b=(node){read(),read()};
	c=(node){read(),read()};
	int T=100;
	while (T--){
		walk(a,a,b,c);
		walk(b,b,a,c);
		walk(c,c,a,b);
	}
//	print();
	cout<<cnt<<"\n";
	for (int i=1;i<=cnt;i++){
		cout<<ans[i].x<<" "<<ans[i].y<<"\n";
	}
	return 0;
}