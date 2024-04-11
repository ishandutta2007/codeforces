#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
#define I inline void
#define IN inline int
#define C(x,y) memset(x,y,sizeof(x))
#define STS system("pause")
template<class D>I read(D &res){
	res=0;register D g=1;register char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')g=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	res*=g;
}
ll ans;
int n,m,k,p,a[40400],b[40400],r[40400],sa,sb;
struct MST{
	int t[40400],lim;
	IN lbt(int x){
		return x&(-x);
	}
	I modi(int x){
		while(x<=lim)t[x]++,x+=lbt(x);
	}
	IN ques(int x){
		static int res;res=0;
		while(x)res+=t[x],x-=lbt(x);
		return res;
	}
}A,B;
I solve(int x,int y){
	re w[2];
	//cout<<x<<" "<<n<<" "<<y<<" "<<m<<endl;
	if(x>n||y>m)return;
	w[0]=sa-A.ques(x-1);w[1]=sb-B.ques(y-1);
	//cout<<w[0]<<" "<<w[1]<<endl;
	ans+=(ll)w[0]*w[1];
}
int main(){
	read(n);read(m);read(k);
	F(i,1,n)read(a[i]);
	F(i,1,m)read(b[i]);
	p=-1;A.lim=n;B.lim=m;
	F(i,1,n+1){
		if(!a[i]){
			if(p!=-1){
				F(j,p,i-1)r[j]=i-1;
			}
			r[i]=p=-1;
		}
		else if(p==-1)p=i;
	}
	F(i,1,n)if(r[i]!=-1)sa++,A.modi(r[i]-i+1);
	p=-1;
	F(i,1,m+1){
		if(!b[i]){
			if(p!=-1){
				F(j,p,i-1)r[j]=i-1;
			}
			r[i]=p=-1;
		}
		else if(p==-1)p=i;
	}
	F(i,1,m)if(r[i]!=-1)sb++,B.modi(r[i]-i+1);
	//cout<<sa<<" "<<sb<<endl;
	F(i,1,sqrt(k)){
		if((k%i)==0){
			solve(i,k/i);
			if(i*i<k)solve(k/i,i);
		}
	}
	cout<<ans;
	return 0;
}