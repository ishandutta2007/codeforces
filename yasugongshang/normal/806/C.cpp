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
inline long long read(){
	long long x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(long long a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(long long a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const long long N=100005;
map<long long,long long> M,ycl;
map<long long,long long>::iterator it;
long long tot,n,ans[N];
long long a[N],bin[60],b[N],mx,mi,tong[60],zs[60];
int main(){
	n=read(); bin[0]=1; ycl[1]=0;
	for(long long i=1;i<60;i++){ycl[bin[i]=bin[i-1]<<1]=i;}
	for(long long i=1;i<=n;i++)if(ycl.find(a[i]=read())!=ycl.end())tong[ycl[a[i]]]++; else b[++tot]=a[i]; mx=tong[0];
	sort(&b[1],&b[tot+1]);
	for(long long i=tot;i;i--){
		int j=59;
		for(;!tong[j]&&j;j--);  
		if(bin[j]*2<b[i]){
			puts("-1"); return 0;
		}
	    for(int i=j;i>=0;i--)if(!tong[i]){
	    	puts("-1"); return 0;
		}else tong[i]--;
	    ans[++mi]=j; 
	}
	for(int i=0;i<60;i++)zs[i]=tong[i];
	int l=0,r=n+1;
	while(l<r){
		for(int i=0;i<60;i++)tong[i]=zs[i];
		//for(int i=0;i<60;i++)if(tong[i])cout<<i<<" "<<tong[i]<<endl;
		int mid=(l+r)>>1,flag=0;
		for(int i=1;i<=mid;i++){
			ans[i]=0;
			for(int j=0;tong[j];j++)tong[ans[i]=j]--;
		}
		for(int i=1;i<=mid;i++){
			for(int j=ans[i]+1;j>=0;j--)if(tong[j]){
				tong[j]--; break;
			}
		}
		for(int i=0;i<60;i++)if(tong[i]){
			flag=1; break;
		}
		if(!flag)r=mid; else l=mid+1;
	}
	if(l+mi>mx)puts("-1"); else
	for(long long i=l+mi;i<=mx;i++){
		write(i); putchar(' ');
	}
}