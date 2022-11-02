#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long LL;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
int n,a[100005],sum;
int main(){
	n=read()+1;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=2;i<=n;i++)if(a[i-1]>1&&a[i]>1){
		puts("ambiguous");
		for(int j=1;j<=n;j++){
			for(int k=sum+1;k<=sum+a[j];k++){
				write(sum); putchar(' ');
			}
			sum+=a[j];
		}sum=0; puts("");
		for(int j=1;j<=n;j++){
			for(int k=sum+1;k<=sum+a[j];k++){
				if(i==j&&k==sum+1){
					write(sum-1);
				}else write(sum); putchar(' ');
			}
			sum+=a[j];
		}
		return 0;
	}
	puts("perfect");
}