#include<iostream>
#include<string>
using namespace std;

long long int gcd(long long int x,long long int y){
	if(y==0)return x;
	return gcd(y,x%y);
}

int main(){
	long long int n,m,k,g,sx,sy,ans=0;
	string x,y;
	scanf("%I64d%I64d",&n,&m);
	cin>>x>>y;
	sx=x.size();
	sy=y.size();
	g=gcd(n,m);
	n/=g; m/=g;
	k=x.size()/m;
	for(int i=0;i<k;i++){
		long long int ret,a[26]={0},b[26]={0};
		for(int j=i;j<sx;j+=k)a[x[j]-'a']++;
		for(int j=i;j<sy;j+=k)b[y[j]-'a']++;
		ret=(sx/k)*(sy/k);
		for(int j=0;j<26;j++)ret-=a[j]*b[j];
		ans+=ret;
	}
	ans*=g;
	printf("%I64d\n",ans);
}