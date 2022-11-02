#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
inline long long read(){
	long long x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(long long a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(long long a){
    write(a); puts("");
}
const long long N=600006;
struct data{
	long long val,pos;
}a[N];
inline bool cmp(data a,data b){
	return a.val>b.val;
}
long long k,kk,n,tong[N],ans,an[N];
int main(){
    n=read(); kk=k=read(); ++k;
    for(long long i=1;i<=n;i++){a[i].val=read(); a[i].pos=i;}
    sort(&a[1],&a[n+1],cmp);
    for(long long i=1;i<=n;i++){
    	if(a[i].pos>k){
    		tong[a[i].pos]=i; an[a[i].pos]=a[i].pos; 
		}else{
			while(tong[k])++k;
			tong[k]=i; an[a[i].pos]=k; ans+=a[i].val*(k-a[i].pos);
		}
	}
	cout<<ans<<endl;
	for(long long i=1;i<=n;i++){
		write(an[i]); putchar(' ');
	}
}