#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define ull long long
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
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
	write(a); putchar(' ');
}
const int N=1000005,mod=998244353;
ull hash[N],ycl[N];
char ch[N];
int ans[N],n,tong[26];
inline ull get(int l,int r){
	return ((hash[r]-hash[l-1]*ycl[r-l+1])%mod+mod)%mod;
}
inline bool check(int l,int r,int len){
	//cout<<get(l-len+1,l+len-1)<<" "<<get(r-len+1,r+len-1)<<endl;
	return get(l-len+1,l+len-1)==get(r-len+1,r+len-1);
}
int main(){
	srand(19260817);
	n=read();
	scanf("%s",ch+1);
	for(int i=0;i<26;i++)tong[i]=i;
	random_shuffle(&tong[0],&tong[26]); ycl[0]=1;
	for(int i=1;i<=n;i++){
		hash[i]=(hash[i-1]*233+tong[ch[i]-'a'])%mod;
		ycl[i]=ycl[i-1]*233%mod;
	}
	//cout<<check(7,9,7)<<endl; return 0;
	for(int i=1;i<=n/2;i++){
		int pos1=i,pos2=n-i+1;
		int l=0,r=i;
		while(l<r){
			int mid=(l+r)>>1; mid++;
			if(check(pos1,pos2,mid))l=mid; else r=mid-1;
		}
		//cout<<i<<" "<<l<<endl;
		ans[i-l+1]=max(ans[i-l+1],l*2-1);
	}
	for(int i=1;i<=(n+1)/2;i++){ans[i]=max(ans[i],ans[i-1]-2); writeln(ans[i]?ans[i]:-1);}
}