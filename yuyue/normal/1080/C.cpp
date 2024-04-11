#include<bits/stdc++.h>
#define LL long long

using namespace std;

inline int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
	return w*c;
}
struct node{
	LL l,down,r,up;
}a,b,c,o;
LL T,n,m;
bool y(LL x,LL y){
	return (x+y)&1;
}
LL j(node x){
	LL ans=0,l=0,tot=0;
	LL s=(x.up-x.down+1)*(x.r-x.l+1);
	if (y(x.l,x.down)&&y(x.l,x.up)&&y(x.r,x.up)&&y(x.r,x.down)) return 1;
	if (y(x.l,x.down)+y(x.l,x.up)+y(x.r,x.up)+y(x.r,x.down)==0) return -1;
	return 0;
}
LL s(node x){
	return (x.up-x.down+1)*(x.r-x.l+1);
}
int main(){
	T=read();
	while (T--){
		n=read(); m=read(); 
		o=(node){1,n,m,1};
		LL black,white,s2w,s1b,d1w,d2b,s3b;
		black=white=n*m/2;
		if (j(o)==-1) white++;
		if (j(o)==1) black++;
		a=(node){read(),read(),read(),read()};
		b=(node){read(),read(),read(),read()}; 
		s1b=s(a)/2; s2w=s(b)/2;
		if (j(a)==1) s1b++;
		if (j(b)==-1) s2w++;
		c.l=max(a.l,b.l);
		c.r=min(b.r,a.r);
		c.up=min(a.up,b.up);
		c.down=max(a.down,b.down);	
		//cout<<c.l<<" "<<c.r<<" "<<c.up<<" "<<c.down<<"    -\n";
		//cout<<white<<" "<<black<<" "<<s1b<<" "<<s2w<<"\n";
		if (c.l>c.r||c.up<c.down){
			cout<<white+s1b-s2w<<" "<<black+s2w-s1b<<"\n";
		}
		else {
		
			s3b=s(c)/2;
			if (j(c)==1) s3b++;
			//cout<<s3b<<"  -\n";
			cout<<white+s1b-s2w-s3b<<" "<<black+s2w-s1b+s3b<<"\n";
		}
	}
	return 0;
}