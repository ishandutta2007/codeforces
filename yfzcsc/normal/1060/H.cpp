#include<bits/stdc++.h>
using namespace std;
struct data{
	int op,x,y,z;
	data(){}
	data(int op,int x,int y,int z):
		op(op),x(x),y(y),z(z){}
};
vector<data>G;
int d,p,ptr=4,a[20][20];
int val[20],C[20][20];
int ax[20],ay[20],az[20];

int mem[5100];
int qpow(int a,int b,int p){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%p)
		if(b&1)ans=1ll*ans*a%p;
	return ans;
}
void init(int x,int y){
	for(int i=1;i<=5000;++i)mem[i]=1;
	mem[1]=x,mem[2]=y;
}
void pb(data A){
//	if(A.op==0)mem[A.z]=(mem[A.x]+mem[A.y])%p;
//	else if(A.op==1)mem[A.y]=qpow(mem[A.x],d,p);
//	else printf("[%d]",mem[A.x]);
	G.push_back(A);
}
void print(){
	for(auto c:G){
		if(c.op==0)printf("+ %d %d %d\n",c.x,c.y,c.z);
		else if(c.op==1)printf("^ %d %d\n",c.x,c.y);
		else printf("f %d\n",c.x);
	}
}
int mulcons(int x,int y){
	if(y<=0)y+=p;
	++ptr;
	for(int i=0;i<30;++i){
		if(i==0)pb(data(0,x,x,i+ptr));
		if(i>0)pb(data(0,i+ptr-1,i+ptr-1,i+ptr));
	}
	int ret=-1;
	for(int i=30;i>=0;--i)if(y>>i&1){
		if(ret==-1)ret=(i==0?x:i+ptr-1);
		else pb(data(0,(i==0?x:i+ptr-1),ret,ret));
	}
	ptr+=31;
	return ret;
}
int add(int x,int y){
	pb(data(0,x,y,++ptr));
	return ptr;
}
int main(){
//	d=10,p=10007;
//	init(7,8);
	scanf("%d%d",&d,&p);
	for(int i=0;i<=d;++i)
		for(int j=*C[i]=1;j<=i;++j)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%p;
	for(int j=0;j<=d;++j){
		for(int i=0;i<=d;++i)
			a[j][i]=(a[j][i]+1ll*C[d][j]*qpow(i,d-j,p)%p)%p;
		a[j][d+1]=j==2?1:0;
	}
	for(int i=0,j=0;i<=d;++i){
		for(j=i;j<=d&&!a[j][i];j++);
		for(int k=0;k<=d+1;++k)swap(a[i][k],a[j][k]);
		int t=qpow(a[i][i],p-2,p);
		for(int k=0;k<=d;++k)if(a[k][i]&&k!=i){
			int nt=1ll*a[k][i]*t%p;
			for(int l=0;l<=d+1;++l)
				a[k][l]=(a[k][l]-1ll*a[i][l]*nt%p+p)%p;
		}
	}
//	int A=5,sum=0;
	for(int i=0;i<=d;++i)val[i]=1ll*a[i][d+1]*qpow(a[i][i],p-2,p)%p;
//	for(int i=0;i<=d;++i)sum=(sum+1ll*val[i]*qpow(i+A,d,p))%p;
//	printf("[%d]",sum);
	
	ax[0]=1,ay[0]=2,az[0]=3;
	pb(data(0,1,2,3));
	
	for(int i=1;i<=d;++i){
		ax[i]=++ptr,ay[i]=++ptr,az[i]=++ptr;
		pb(data(0,ax[i],ax[i-1],ax[i]));
		pb(data(0,ay[i],ay[i-1],ay[i]));
		pb(data(0,az[i],az[i-1],az[i]));
	}
//	ptr++;
//	for(int i=0;i<=d;++i)ax[i]=(i==0?1:++ptr);
//	for(int i=0;i<=d;++i)ay[i]=(i==0?2:++ptr);
//	for(int i=0;i<=d;++i);
	for(int i=0;i<=d;++i){
//		printf("[%d]",mem[ax[i]]);
		pb(data(1,ax[i],ax[i],0));
		pb(data(1,ay[i],ay[i],0));
		pb(data(1,az[i],az[i],0));
	}
	
	for(int i=0;i<=d;++i){
		ax[i]=mulcons(ax[i],val[i]);
		ay[i]=mulcons(ay[i],val[i]);
		az[i]=mulcons(az[i],val[i]);
//		printf("[%d(%d)]",mem[az[i]],1ll*qpow(i+5,d,p)*val[i]%p);
	}
	for(int i=1;i<=d;++i){
//		printf("[%d,%d]",mem[ax[0]],mem[ax[i]]);
		ax[0]=add(ax[0],ax[i]);
		ay[0]=add(ay[0],ay[i]);
		az[0]=add(az[0],az[i]);
	}
	ax[0]=mulcons(ax[0],p-1);
	ay[0]=mulcons(ay[0],p-1);
	
	az[0]=add(az[0],ax[0]);
//	printf("[%d]",mem[az[0]]);
	az[0]=add(az[0],ay[0]);
	az[0]=mulcons(az[0],(p+1)/2);
	pb(data(2,az[0],0,0));
//	return 0;
	print();
}