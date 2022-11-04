#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int LEN=80;
const int YW=8;
const int BAS=100000000;
struct big{
	int a[LEN];
	//delete .a[]
	int& operator [](int x){
		return a[x];
	}
	const int& operator [](int x)const{
		return a[x];
	}
	
	//getnum
	big(){
		CLR(a,0);
	}
	big operator =(const big &x){
		For(i,x[0]+1,a[0]) a[i]=0;
		For(i,0,x[0]) a[i]=x[i];
		return *this;
	}
	big operator =(int x){
		Rep(i,a[0],0) a[i]=0;
		for (;x;x/=BAS)
			a[++a[0]]=x%BAS;
		return *this;
	}
	big(int x){
		CLR(a,0);
		*this=x;
	}
	
	//compare
	bool operator <(const big &b)const{
		if (a[0]!=b[0]) return a[0]<b[0];
		Rep(i,a[0],1) if (a[i]!=b[i]) return a[i]<b[i];
		return 0;
	}
	bool operator >(const big &b)const{
		if (a[0]!=b[0]) return a[0]>b[0];
		Rep(i,a[0],1) if (a[i]!=b[i]) return a[i]>b[i];
		return 0;
	}
	bool operator <=(const big &b)const{
		return !(*this>b);
	}
	bool operator >=(const big &b)const{
		return !(*this<b);
	}
	bool operator ==(const big &b)const{
		return !(*this>b)&&!(*this<b);
	}
	bool operator !=(const big &b)const{
		return !(*this==b);
	}
	
	//cheng
	big operator *(const big &b)const{
		big c; c[0]=a[0]+b[0];
		For(i,1,a[0]) For(j,1,b[0]){
			ll x=c[i+j-1]+1ll*a[i]*b[j];
			c[i+j]+=x/BAS; c[i+j-1]=x%BAS;
		}
		for (;c[0]>0&&!c[c[0]];c[0]--);
		return c;
	}
	big operator *(int x)const{
		big c; ll v=0;
		For(i,1,a[0]+3){
			v=1ll*x*a[i]+v;
			c[i]=v%BAS; v/=BAS;
		}
		c[0]=a[0]+3;
		for (;c[0]>0&&!c[c[0]];c[0]--);
		return c;
	}
	
	//chu
	big operator /(int x)const{
		big c; ll v=0;
		Rep(i,a[0],1){
			v=v*BAS+a[i];
			c[i]=v/x; v%=x;
		}
		c[0]=a[0];
		for (;c[0]>0&&!c[c[0]];c[0]--);
		return c;
	}
	big operator /(const big &b)const{
		if (b[0]==1&&!b[1]){
			puts("error! divide by 0");
			exit(0);
		}
		if (*this<b) return big(0);
		int l1=max(0,(a[0]-1))*YW;
		int l2=max(0,(b[0]-1))*YW;
		int v1=a[a[0]],v2=b[b[0]];
		for (;v1;v1/=10,l1++);
		for (;v2;v2/=10,l2++);
		big c,chu=*this,B=b;
		For(i,1,(l1-l2)/YW) B*=BAS;
		For(i,1,(l1-l2)%YW) B*=10;
		Rep(i,l1-l2,0){
			int x=0;
			for (;chu>=B;chu-=B,x++);
			c[i/YW+1]=c[i/YW+1]*10+x;
			B/=10;
		}
		c[0]=(l1-l2)/YW+1;
		for (;c[0]>0&&!c[c[0]];c[0]--);
		return c;
	}
	
	//jia
	big operator +(const big &b)const{
		big c; c[0]=max(a[0],b[0]);
		For(i,1,c[0]) c[i]=a[i]+b[i];
		For(i,1,c[0]) c[i+1]+=c[i]/BAS,c[i]%=BAS;
		if (c[c[0]+1]) c[0]++;
		return c;
	} 
	big operator +(int x)const{
		big c=*this; c[1]+=x;
		For(i,1,c[0]+1)
			if (c[i]>=BAS){
				c[i+1]+=c[i]/BAS;
				c[i]%=BAS;
			}
			else break;
		if (c[c[0]+1]) c[0]++;
		return c;
	}
	
	//jian
	big operator -(const big &b)const{
		big c; c[0]=a[0];
		For(i,1,c[0]) c[i]=a[i]-b[i];
		For(i,1,c[0]) if (c[i]<0)
			c[i]+=BAS,c[i+1]--;
		for (;c[0]>1&&!c[c[0]];c[0]--);
		return c;
	}
	big operator -(int x)const{
		big c=*this; c[1]-=x;
		For(i,1,c[0]+1)
			if (c[i]<0){
				c[i+1]+=(c[i]+1)/BAS-1;
				c[i]=(c[i]+1)%BAS+BAS-1;
			}
			else break;
		for (;c[0]>1&&!c[c[0]];c[0]--);
		return c;
	}
	
	//mod
	int operator %(int x)const{
		ll ans=0;
		Rep(i,a[0],1)
			ans=(ans*BAS+a[i])%x;
		return ans;
	}
	big operator %(const big &b)const{
		if (b[0]==1&&!b[1]){
			puts("error! mod by 0");
			exit(0);
		}
		if (*this<b) return *this; 
		int l1=max(0,(a[0]-1))*YW;
		int l2=max(0,(b[0]-1))*YW;
		int v1=a[a[0]],v2=b[b[0]];
		for (;v1;v1/=10,l1++);
		for (;v2;v2/=10,l2++);
		big chu=*this,B=b;
		For(i,1,(l1-l2)/YW) B*=BAS;
		For(i,1,(l1-l2)%YW) B*=10;
		Rep(i,l1-l2,0){
			for (;chu>=B;chu-=B);
			B/=10;
		}
		return chu;
	}
	
	//suoxie
	big operator +=(const big &b){
		return *this=(*this+b);
	}
	big operator -=(const big &b){
		return *this=(*this-b);
	}
	big operator *=(const big &b){
		return *this=(*this*b);
	}
	big operator /=(const big &b){
		return *this=(*this/b);
	}
	big operator %=(const big &b){
		return *this=(*this%b);
	}
	big operator +=(int x){
		return *this=(*this+x);
	}
	big operator -=(int x){
		return *this=(*this-x);
	}
	big operator *=(int x){
		return *this=(*this*x);
	}
	big operator /=(int x){
		return *this=(*this/x);
	}
	
	//IO
	void read(){
		char c[LEN*YW+10];
		scanf("%s",c);
		int len=strlen(c);
		CLR((*this).a,0);
		reverse(c,c+len);
		a[0]=(len-1)/YW+1;
		Rep(i,len-1,0)
			a[i/YW+1]=a[i/YW+1]*10+c[i]-'0';
	}
	void write()const{
		printf("%d",a[a[0]]);
		Rep(i,a[0]-1,1) printf("%08d",a[i]);
	}
	void writeln()const{
		write(); puts("");
	}
};
big gcd(const big &a,const big &b){
	big A=a,B=b,ans=1;
	for (;!(A[1]&1)&&!(B[1]&1);A/=2,B/=2,ans*=2);
	for (;;){
		if (A[0]==1&&A[1]==0) return B*ans;
		if (B[0]==1&&B[1]==0) return A*ans;
		for (;!(A[1]&1);A/=2);
		for (;!(B[1]&1);B/=2);
		A>B?A-=B:B-=A;
	}
}
big q[233];
big ans[233];
int tp,tot;
int rnd(int md){
	int x=0;
	For(i,1,100) x=(x*10ll+rand()%10)%md;
	return x;
}
big make(big n){
	big x; x=n;
	x[x[0]]=rnd(x[x[0]]);
	For(j,1,x[0]-1) x[j]=rnd(BAS);
	for (;x[0]>1&&!x[x[0]];x[0]--);
	if (x[0]==1&&!x[1]) x[1]++;
	return x;
}
void insert(const big &a){
	//printf("insert "); a.writeln();
	int pos=++tp; q[tp]=a;
	Rep(i,pos-1,1){
		big G=gcd(q[i],q[pos]);
		if (G==1) continue;
		q[i]/=G; q[pos]/=G; q[++tp]=G;
	}
	pos=0;
	For(i,1,tp)
		if (q[i]!=1)
			q[++pos]=q[i];
	tp=pos;
	//printf("%d\n",pos);
	//For(i,1,tp)
	//	q[i].writeln();
}
int main(){
	srand(time(NULL)); 
	big n; n.read();
	q[++tp]=n;
	For(i,1,10){
		big x=make(n);
		for (;gcd(x,n)!=1;){
			insert(gcd(x,n));
			x=make(n);
		} 
		big y=x*x%n;
		printf("sqrt ");
		y.writeln();
		fflush(stdout);
		big z; z.read();
		if (z!=x&&z!=n-x){
			big v1=(x+z)%n;
			insert(gcd(n,v1));
		}
	}
	printf("! %d ",tp);
	for (int i=1;i<=tp;i++)
		q[i].write(),putchar(' ');
}
/*
1:1,20,8,13
4:2,19,5,16
7:7,14
9:3,18
15:6,15
16:4,17,10,11
18:9,12
if (gcd(i,v[i])==1) continue;
else{
	erase(v[i]);
	push(v[i]/G,i/G,G)
}
*/