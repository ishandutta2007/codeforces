#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
using namespace std;
int a[2005],n,x;
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) a[i]-=a[i+1];
	For(i,1,n) a[i]-=a[i+1];
	For(i,1,n) For(j,1,a[i]){
		For(k,1,i) putchar('a'+x);
		x=(x+1)%26;
	} 
}