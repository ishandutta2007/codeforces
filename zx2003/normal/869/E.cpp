namespace GenHelper
{
    unsigned z1,z2,z3,z4,b;
    unsigned rand_()
    {
    b=((z1<<6)^z1)>>13;
    z1=((z1&4294967294U)<<18)^b;
    b=((z2<<2)^z2)>>27;
    z2=((z2&4294967288U)<<2)^b;
    b=((z3<<13)^z3)>>21;
    z3=((z3&4294967280U)<<7)^b;
    b=((z4<<3)^z4)>>12;
    z4=((z4&4294967168U)<<13)^b;
    return (z1^z2^z3^z4);
    }
}
void srand(unsigned x)
{using namespace GenHelper;
z1=x; z2=(~x)^0x233333333U; z3=x^0x1234598766U; z4=(~x)+51;}
int read()
{
    using namespace GenHelper;
    int a=rand_()&32767;
    int b=rand_()&32767;
    return a*32768+b;
}
#include<cstdio>
#include<ctime>
#include<map>
#include<utility>
using namespace std;
const int N=2505;
int n,m,q,i,a,b,c,d,o,xb;
map<pair<int,int>,int> s;
map<pair<int,int>,int>::iterator it;
struct node{
	int l,r,v;
}t[35000000];
void ins(int&i,int l,int r,int x,int y,int v){
	if(!i)i=++xb;
	if(l==x && r==y){t[i].v^=v;return;}
	int m=(l+r)>>1;
	if(x>m)ins(t[i].r,m+1,r,x,y,v);
		else if(y<=m)ins(t[i].l,l,m,x,y,v);
				else ins(t[i].l,l,m,x,m,v),ins(t[i].r,m+1,r,m+1,y,v);
}
int sum(int i,int l,int r,int x){
	if(!i)return 0;
	if(l==r)return t[i].v;
	int m=(l+r)>>1;
	if(x>m)return sum(t[i].r,m+1,r,x)^t[i].v;
		else return sum(t[i].l,l,m,x)^t[i].v;
}
struct segtree1{
	int rt[N*5];
	void add(int i,int l,int r,int r1,int r2,int c1,int c2,int v){
		if(l==r1 && r==r2){
			ins(rt[i],1,m,c1,c2,v);
			return;
		}
		int m=(l+r)>>1;
		if(r1>m)add(i<<1|1,m+1,r,r1,r2,c1,c2,v);
			else if(r2<=m)add(i<<1,l,m,r1,r2,c1,c2,v);
					else add(i<<1,l,m,r1,m,c1,c2,v),add(i<<1|1,m+1,r,m+1,r2,c1,c2,v);
	}
	int query(int i,int l,int r,int x,int y){
		int z=sum(rt[i],1,m,y),m=(l+r)>>1;
		if(l==r)return z;
		if(x>m)return query(i<<1|1,m+1,r,x,y)^z;
			else return query(i<<1,l,m,x,y)^z;
	}
}tt;
int main(){
	scanf("%d%d%d",&n,&m,&q);srand(time(0));
	while(q--){
		scanf("%d%d%d%d%d",&o,&a,&b,&c,&d);
		if(o==1){
			i=read();
			tt.add(1,1,n,a,c,b,d,i);
			s.insert(make_pair(make_pair(a,b),i));
		}
		if(o==2){
			it=s.find(make_pair(a,b));
			tt.add(1,1,n,a,c,b,d,it->second);
			s.erase(it);
		}
		if(o==3){
			puts(tt.query(1,1,n,a,b)==tt.query(1,1,n,c,d)?"Yes":"No");
		}
	}
	return 0;
}