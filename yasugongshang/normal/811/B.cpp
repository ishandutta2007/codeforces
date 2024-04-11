#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=10005;
int a[N],sorted[N],n,m,sum[20][N],tree[20][N];
inline void build(int deep,int l,int r){
    int i,mid=(l+r)>>1,lm=mid-l+1,lp=l,rp=mid+1;
    for(i=l;i<=mid;i++)if(sorted[i]>sorted[mid])lm--;
    for(i=l;i<=r;i++){
        if(i==l)sum[deep][i]=0;else sum[deep][i]=sum[deep][i-1];
        if(tree[deep][i]==sorted[mid]){
            if(lm){lm--;sum[deep][i]++;tree[deep+1][lp++]=tree[deep][i];}else tree[deep+1][rp++]=tree[deep][i];
        }else if(tree[deep][i]>sorted[mid]){sum[deep][i]++;tree[deep+1][lp++]=tree[deep][i];}else tree[deep+1][rp++]=tree[deep][i];
    }
	if(l!=r){build(deep+1,l,mid); build(deep+1,mid+1,r);}
}
int ask(int deep,int l,int r,int ql,int qr,int k){
    int s,ss,mid=(l+r)>>1;
    if(l==r)return tree[deep][l];
    if(l==ql){s=0; ss=sum[deep][qr];}else{s=sum[deep][ql-1]; ss=sum[deep][qr]-s;}
    if(k<=ss)return ask(deep+1,l,mid,l+s,l+s+ss-1,k);
    else return ask(deep+1,mid+1,r,mid-l+1+ql-s,mid-l+1+qr-s-ss,k-ss);
}
inline bool cmp(int a,int b){
	return a>b;
}
inline int	read()// 
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a)
{
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
int main(){
    n=read(); m=read();
    for(int i=1;i<=n;i++)a[i]=tree[0][i]=sorted[i]=read();
    sort(sorted+1,sorted+1+n,cmp);
    build(0,1,n);
    while(m--){
    	int s1=read(),s2=read(),s3=read();
        if(ask(0,1,n,s1,s2,s2-s3+1)==a[s3])puts("Yes");else puts("No");
    }
}