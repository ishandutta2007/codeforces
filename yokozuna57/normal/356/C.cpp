#include<iostream>
using namespace std;
int n,a[6]={0},b[4]={0},c[3],d[3]={0,3,4},ret,in,peo=0,ans=1000000000;

int z(int x){
	if(x<0)return -x;
	return x;
}

int f(int x){
	if(x<0)return 0;
	return a[x];
}

int g(int x){
	if(x<0)return 0;
	return c[x];
}

int com(int a,int b,int c,int d){
	return max(0,min(b,d)-max(a,c)+1);
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&in);
		a[in]++;
		peo+=in;
	}
	for(int i=1;i<=4;i++)a[i]+=a[i-1];
	b[0]=n-(peo/3); b[1]=peo/3-peo%3; b[2]=peo%3;
	for(int i=0;i<=n;i++){
		if(b[1]<0)break;
		ret=0; 
		c[0]=b[0];
		c[1]=b[0]+b[1];
		c[2]=b[0]+b[1]+b[2];
		//cout<<a[0]<<a[1]<<a[2]<<a[3]<<a[4]<<endl<<c[0]<<c[1]<<c[2]<<endl;
		for(int j=0;j<5;j++){
			for(int k=0;k<3;k++){
				ret+=com(f(j-1)+1,f(j),g(k-1)+1,g(k))*(z(j-d[k]));
			}
		}
		ret/=2;
		if(ans>ret)ans=ret;
		b[0]++;
		b[1]-=4;
		b[2]+=3;
		//cout<<ret<<endl;
	}
	if(ans==1000000000)printf("-1\n");
	else printf("%d\n",ans);
}