#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
inline int read(){
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    cout<<a<<endl;
}
int n,a[20005];
int main(){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=3;i<=n;i++){
    	if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
    		writeln(a[n]); return 0;
		}
	}
	writeln(a[n]*2-a[n-1]);
}