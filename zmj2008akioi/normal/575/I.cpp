#include <cstdio>
#include <cstring>
const int N=5e3+10,M=1e5+10;
int n,q,c,qn1,qn2,qn3,qn4,ans[M];
template<typename T>T lb(T x){return x&(-x);}
template<typename T>T md(T x,T y){return (x+y)/2;}
namespace IO{
	int lt,nw,res,dig[30];char c;
	int read(){
		res=0;for(;c<'0'||c>'9';c=getchar());
		for(;!(c<'0'||c>'9');c=getchar())res=(res<<1)+(res<<3)+(c^48);
		return res;
	}
	void write(int x){
		if(!x)putchar('0');
		for(;x;x=nw)nw=x/10,dig[++lt]=x-(nw<<1)-(nw<<3);
		for(;lt;--lt)putchar(dig[lt]^48);putchar('\n');
	}
}using IO::read;using IO::write;
struct opt{
	int id,tp,a,b,c;opt(){};
	opt(int id,int tp,int a,int b,int c):id(id),tp(tp),a(a),b(b),c(c){};
}nq[M],q1[M],q2[M],q3[M],q4[M];
int R(int x){return n+1-x;}
namespace BIT{
	int a[N][N];
	void gm(int i,int x,int d){while(x<=n)a[i][x]+=d,x+=lb(x);}
	int gq(int i,int x){int res=0;while(x)res+=a[i][x],x-=lb(x);return res;}
	void fm(int x,int y,int d){while(x<=n)gm(x,y,d),x+=lb(x);}
	int fq(int x,int y){int res=0;while(x)res+=gq(x,y),x-=lb(x);return res;}
};
void megcalc(int l,int r,opt* qs){
	if(l==r)return;int mid=md(l,r);
	megcalc(l,mid,qs),megcalc(mid+1,r,qs);
	for(int p=l,q=mid+1,i=l;i<=r;++i){
		if(p<=mid&&(q>r||qs[p].c<=qs[q].c)){
			int x=qs[p].a,y=qs[p].b;
			if(qs[p].tp==0)BIT::fm(x,y,1);
			nq[i]=qs[p++];
		}
		else{
			int x=qs[q].a,y=qs[q].b,id=qs[q].id;
			if(qs[q].tp==1)ans[id]+=BIT::fq(x,y);
			nq[i]=qs[q++];
		}
	}
	for(int i=l;i<=mid;++i)if(qs[i].tp==0)BIT::fm(qs[i].a,qs[i].b,-1);
	for(int i=l;i<=r;++i)qs[i]=nq[i];
}
int main(){
	n=read(),q=read();
	for(int d,x,y,t,i=1;i<=q;++i){
		switch(read()){
			case 1:{
				d=read(),x=read(),y=read(),t=read();
				switch(d){
					case 1:q1[++qn1]=opt(0,0,x,y,R(x+y+t));break;
					case 2:q2[++qn2]=opt(0,0,x,R(y),R(x-y+t));break;
					case 3:q3[++qn3]=opt(0,0,R(x),y,x-y-t);break;
					case 4:q4[++qn4]=opt(0,0,R(x),R(y),x+y-t);break;
					default:puts("I AK IOI!");break;
				}
			}break;
			case 2:{
				x=read(),y=read(),++c;
				q1[++qn1]=opt(c,1,x,y,R(x+y));
				q2[++qn2]=opt(c,1,x,R(y),R(x-y));
				q3[++qn3]=opt(c,1,R(x),y,x-y);
				q4[++qn4]=opt(c,1,R(x),R(y),x+y);
			}break;
			default:puts("I AK IOI!");break;
		}
	}
	megcalc(1,qn1,q1),megcalc(1,qn2,q2);
	megcalc(1,qn3,q3),megcalc(1,qn4,q4);
	for(int i=1;i<=c;++i)write(ans[i]);return 0;
}