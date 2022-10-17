#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1e3+10;
int w[M],n;
int a[26]={0,0,1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};
int main(){
	
//	freopen("1.out","w",stdout);
//	a[25]=1082401;
////	for (int k=1;k<=24;k++){
////		int p=(1<<k)-1;
////		for (int i=1;i<p;i++) 
////		a[k]=max(a[k],__gcd(i&p,i^p));
////	}
////	for (int i=1;i<=25;i++) cout<<a[i]<<",";
	n=read();
//	cout<<a[1]<<"\n";
	for (int i=1;i<=n;i++){
		int x=read(),y=0,w=0;
		for (int j=0;j<25;j++){
			if ((1<<j)<x) w++; 
			if ( (x&(1<<j) )==0 && (1<<j)<x) y+=(1<<j);
		}
		if (!y) cout<<a[w]<<"\n";
//		cout<<y<<"   y\n";
		else cout<<(x^y)<<"\n";
//		for (int j=1;j<=25;j++){
//			if (x==(1<<j)-1){
//				
//			}
//		}
	}
	return 0;
}