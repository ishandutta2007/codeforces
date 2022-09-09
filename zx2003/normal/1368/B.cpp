#include<bits/stdc++.h>
typedef long long ll;
inline ll poww(int x,int y){return y?poww(x,y-1)*x:1;}
char c[19]="codeforces";
int i,j,k,x;
ll K;
int main(){
	scanf("%lld",&K);
	for(x=1;poww(x,10)<K;++x);
	for(i=0;poww(x,i)*poww(x-1,10-i)<K;++i);
	for(j=0;j<i;++j)for(k=0;k<x;++k)putchar(c[j]);
	for(;j<10;++j)for(k=0;k<x-1;++k)putchar(c[j]);putchar('\n');
}