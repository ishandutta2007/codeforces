#include<iostream>
using namespace std;

const long long M=1000000009;

long long n,m,a[300010];

long long F1[1500000];
long long F2[1500000];
long long sum_F1[1500000];
long long sum_F2[1500000];

long long siz;
long long sum[1500000];
long long area[1500000];
long long add1[1500000];
long long add2[1500000];

void init(){
	siz=1;
	while(siz<n)siz*=2;

	for(long long i=0;i<n;i++){
		area[siz-1+i]=a[i];
		sum[siz-1+i]=a[i];
	}
	for(long long i=siz-2;i>=0;i--){
		sum[i]=sum[2*i+1]+sum[2*i+2];
	}
}

void updata(long long a,long long b,long long a1,long long a2,long long k,long long l,long long r){
	if(a<=l&&r<=b){
		add1[k]+=a1*F1[l-a+1]+a2*F2[l-a+1]; add1[k]%=M;
		add2[k]+=a1*F1[l-a+2]+a2*F2[l-a+2]; add2[k]%=M;
		area[k]+=a1*(sum_F1[r-1-a+1]-sum_F1[l-a]+M); area[k]%=M;
		area[k]+=a2*(sum_F2[r-1-a+1]-sum_F2[l-a]+M); area[k]%=M;
		sum[k]+=a1*(sum_F1[r-1-a+1]-sum_F1[l-a]+M); sum[k]%=M;
		sum[k]+=a2*(sum_F2[r-1-a+1]-sum_F2[l-a]+M); sum[k]%=M;
		return;
	}

	if(b<=l||r<=a)return;
	
	
	updata(a,b,a1,a2,2*k+1,l,(l+r)/2);
	updata(a,b,a1,a2,2*k+2,(l+r)/2,r);
	sum[k]=sum[2*k+1]+sum[2*k+2]+area[k]; sum[k]%=M;
}

long long query(long long a,long long b,long long k,long long l,long long r){
	if(a<=l&&r<=b)return sum[k];
	if(b<=l||r<=a)return 0;

	updata(l,r,add1[k],add2[k],2*k+1,l,(l+r)/2);
	updata(l,r,add1[k],add2[k],2*k+2,(l+r)/2,r);

	area[k]=0;
	add1[k]=0;
	add2[k]=0;

	long long vl=query(a,b,2*k+1,l,(l+r)/2);
	long long vr=query(a,b,2*k+2,(l+r)/2,r);
	return (vl+vr)%M;
}

int main(){
	F1[1]=1; F1[2]=0;
	F2[1]=0; F2[2]=1;
	for(long long i=3;i<1500000;i++){
		F1[i]=F1[i-2]+F1[i-1]; F1[i]%=M;
		F2[i]=F2[i-2]+F2[i-1]; F2[i]%=M;
	}

	sum_F1[1]=1; sum_F2[1]=0;
	for(long long i=2;i<1500000;i++){
		sum_F1[i]=sum_F1[i-1]+F1[i]; sum_F1[i]%=M;
		sum_F2[i]=sum_F2[i-1]+F2[i]; sum_F2[i]%=M;
	}

	scanf("%I64d%I64d",&n,&m);
	for(long long i=0;i<n;i++){
		scanf("%I64d",&a[i]);
	}

	init();

	for(long long i=0;i<m;i++){
/*printf("%I64d:",i);
for(long long j=0;j<n;j++){
	printf("%I64d ",query(j,j+1,0,0,siz));
}
printf("\n");*/
		long long k,l,r;
		scanf("%I64d%I64d%I64d",&k,&l,&r);

		if(k==1)updata(l-1,r,1,1,0,0,siz);
		else printf("%I64d\n",query(l-1,r,0,0,siz));

/*if(i==0){
prlong longf("%I64d %I64d %I64d %I64d\n",add1[0],add2[0],area[0],sum[0]);
}*/
	}
}