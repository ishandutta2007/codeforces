#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=100005;
int sorted[N],n,m,sum[22][N],tree[22][N],a[N],k,last[N],first[N],nextt[N],tong[N],to[N],lastt;
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
inline void write(int a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
int main(){
    n=read(); k=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=n;i;i--){nextt[i]=first[a[i]]; first[a[i]]=i;}
    for(int i=1;i<=n;i++){
    	if(tong[a[i]]>=k){
    		if(tong[a[i]]==k)last[i]=first[a[i]]; else last[i]=nextt[to[a[i]]];
    		to[a[i]]=last[i];
		}
		tong[a[i]]++;
	}
	//for(int i=1;i<=n;i++)writeln(last[i]);
    for(int i=1;i<=n;i++)tree[0][i]=sorted[i]=last[i];
    sort(sorted+1,sorted+1+n,cmp);
    build(0,1,n); m=read();
    while(m--){
    	int s1=(read()+lastt)%n+1,s2=(read()+lastt)%n+1; if(s1>s2)swap(s1,s2);
        int l=0,r=s2-s1+1;
        while(l<r){
        	int mid=(l+r)>>1; mid++;
        	if(ask(0,1,n,s1,s2,mid)<s1)r=mid-1; else l=mid;
        	//cout<<l<<" "<<r<<" "<<mid<<endl;
		}
		writeln(s2-s1+1-l); lastt=s2-s1+1-l;
    }
}