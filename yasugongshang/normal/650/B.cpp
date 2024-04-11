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
long long n,a,b,T,TT,ans;
char s[500005];
int main(){
    n=read(); a=read(); b=read(); TT=T=read();
    cin>>s;
    long long sum=0,j=-2;
    for(long long i=0;i<n;i++){
    	if(s[i]=='w')T-=b;
    	if(i)T-=a; T--;
    	if(T<0){
    		j=i-1; if(s[i]=='w')T+=b; T+=a;T++; break;
		}
	}
	if(j==-1){
		puts("0"); return 0;
	}
	if(j==-2){
		writeln(n);
		return 0;
	}ans=j+1;
	for(long long i=n-1;i;i--){
		T-=a*2+(s[i]=='w'?b:0)+1;
		while(T<0&&j){
			T+=a+(s[j--]=='w'?b:0)+1;
		}
		if(T>=0)ans=max(ans,n-i+j+1); else if(!j)break;
	}
	for(long long i=1;i<(n+1)/2;i++)swap(s[i],s[n-i]); T=TT;
	j=-1;
    for(long long i=0;i<n;i++){
    	if(s[i]=='w')T-=b;
    	if(i)T-=a; T--;
    	if(T<0){
    		j=i-1; if(s[i]=='w')T+=b; T+=a; T++;break;
		}
	}
	ans=max(ans,j+1);
	for(long long i=n-1;i;i--){
		T-=a*2+(s[i]=='w'?b:0)+1;
		while(T<0&&j){
			T+=a+(s[j--]=='w'?b:0)+1;
		}
		if(T>=0)ans=max(ans,n-i+j+1); else if(!j)break;
	}
	writeln(ans);
}