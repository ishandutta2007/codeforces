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
    write(a); puts("");
}
int f[10005],n,sum;
inline int erfen(int x){
    int l=1,r=448;
    while(l<r){
    	int mid=(l+r)>>1; mid++; 
    	if(f[mid]>x)r=mid-1; else l=mid;
	}
	return l;
}
int main(){
    n=read(); if(n==0){putchar('a'); return 0;}
    for(int i=2;i<=448;i++){f[i]=f[i-1]+i-1; }
	while(n){
		int t=erfen(n);
    	n-=f[t]; 
    	while(t--){
    		putchar(sum+'a');
		}sum++; 
	}
}