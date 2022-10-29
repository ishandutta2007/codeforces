#include<bits/stdc++.h>
#define inf 1000000007
#define maxn 200100
using namespace std;
void upd(int& x,int y){
	if(x==-1)x=y;
	else if(x>y)x=y;
}
struct data{
	int a[5][5];
	data(){
		for(int i=0;i<=4;++i)
			for(int j=0;j<=4;++j)
				a[i][j]=inf;
	}
	void init(int d){
		a[0][0]=a[1][1]=a[2][2]=a[3][3]=a[4][4]=0;
		if(d==2)a[0][1]=0,a[0][0]=1;
		else if(d==0)a[1][2]=0,a[1][1]=1;
		else if(d==1)a[2][3]=0,a[2][2]=1;
		else if(d==6)a[3][3]=1,a[4][4]=1;
		else if(d==7)a[3][4]=0,a[4][4]=0;
	}
	data operator+(const data& d)const{
		data ret;
		for(int i=0;i<=4;++i)
			for(int j=0;j<=4;++j)
				for(int k=0;k<=4;++k)
					ret.a[i][j]=min(ret.a[i][j],a[i][k]+d.a[k][j]);
		return ret;
	}
	void print(){
		for(int i=0;i<=4;++i,puts(""))
			for(int j=0;j<=4;++j)
				printf("[%d]",a[i][j]);
	}
}s[maxn<<2];
char str[maxn];
void build(int o,int l,int r){
	if(l==r){
		s[o].init(str[l]-'0');
//		printf("[%d,%d]\n",l,r);
//		s[o].print();
		return ;
	}
	int mid=l+r>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	s[o]=s[o<<1]+s[o<<1|1];
//	printf("[%d,%d]\n",l,r);
//	s[o].print();
}
data query(int o,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)return s[o];
	int mid=l+r>>1;
	if(qr<=mid)return query(o<<1,l,mid,ql,qr);
	else if(ql>mid)return query(o<<1|1,mid+1,r,ql,qr);
	else return query(o<<1,l,mid,ql,qr)+query(o<<1|1,mid+1,r,ql,qr);
}
int main(){
	int n,Q;
	scanf("%d%d%s",&n,&Q,str+1);
	build(1,1,n);
	for(int i=1,x,y,z;i<=Q;++i)
		scanf("%d%d",&x,&y),z=query(1,1,n,x,y).a[0][4],
		printf("%d\n",z>=inf?-1:z);
}