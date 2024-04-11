#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define int long long
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
#include<bitset>
const int N=200005;
int n,f[N],ans;
signed main(){
	cin>>n;
	if(n<1000){
		for(int i=1;i<=50000;i++){
			f[i]=1e9;
			if(i>=4)f[i]=f[i-4]+1; 
			if(i>=9)f[i]=min(f[i],f[i-9]+1);
			if(i>=49)f[i]=min(f[i],f[i-49]+1);
			ans+=f[i]<=n; 
		}
		cout<<ans+1<<endl;
	}else{
		for(int i=1;i<=50000;i++){
			f[i]=1e9;
			if(i>=4)f[i]=f[i-4]+1; 
			if(i>=9)f[i]=min(f[i],f[i-9]+1);
			if(i>=49)f[i]=min(f[i],f[i-49]+1);
			ans+=f[i]<=1000; 
		}
		cout<<ans+(n-1000)*49+1<<endl;
	}
}