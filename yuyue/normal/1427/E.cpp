#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
struct node{
	LL x,y,op;
	void out(){
		if (op==0) cout<<x<<" + "<<y<<'\n';
		else cout<<x<<" ^ "<<y<<"\n";
	}
};
vector<node> ans;
void add(LL x,LL y,int op){
	ans.pb((node){x,y,op});
}
void init(LL x,LL y){
	LL lst=0;
	for (;y;y>>=1,add(x,x,0),x=x+x)
	if (y&1){
		add(lst,x,0);
		lst+=x;
	}
}
void exgcd(LL a,LL b,LL &x,LL &y){
	if (!b){
		x=1; y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=(a/b)*x;
}
LL n;
int main(){
	n=read();
	add(n,n,1);
	LL k=0;
	DF(i,20,0) if (n>>i&1) {k=i; break;}
	init(n,(1<<k));
	add((n<<k),n,1);
	LL m=(n<<k)^n; 
	LL x,y;
	exgcd(n,m,x,y);
	//cout<<n<<" "<<m<<" "<<x<<" "<<y<<'\n';
	if ((x&1)^(x>0)){
		if (x>0) x+=m,y-=n;
		else x-=m,y+=n;
		//cout<<x<<"   ggg\n";
	}
	if (x<0) x=-x;
	if (y<0) y=-y;
	LL xx=n*x,yy=m*y;
	init(n,x);
	init(m,y);
	add(xx,yy,1);
	cout<<SZ(ans)+1<<"\n";
	F(i,0,SZ(ans)) ans[i].out();
	return 0;
}