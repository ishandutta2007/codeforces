#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define int long long
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
	write(a); puts("");
}
const int N=200005;
struct data{
	int hp,dmg;
}arr[N];
int n,a,b,ans,sum;
inline bool cmp(data a,data b){
	return max(a.hp,a.dmg)-a.dmg>max(b.hp,b.dmg)-b.dmg;
}
signed main(){
	n=read(); a=read(); b=read(); b=min(b,n);
	for(int i=1;i<=n;i++){
		arr[i].hp=read(); arr[i].dmg=read();
	}
	sort(&arr[1],&arr[n+1],cmp);
	if(b==0){
		for(int i=1;i<=n;i++)ans+=arr[i].dmg;
		cout<<ans<<endl; return 0;
	}
	for(int i=1;i<=b;i++)ans+=max(arr[i].hp,arr[i].dmg);
	for(int i=b+1;i<=n;i++)ans+=arr[i].dmg;
	sum=ans;
	ll t=(ll)1<<a;
	for(int i=1;i<=b;i++){
		//if(sum+arr[i].hp*t-max(arr[b].hp,arr[b].dmg)==3575)cout<<arr[i].hp<<endl;
		ans=max(ans,sum+arr[i].hp*t-max(arr[i].hp,arr[i].dmg));
	}
	for(int i=b+1;i<=n;i++){
		ans=max(ans,sum+arr[i].hp*t-arr[i].dmg+(arr[b].dmg-max(arr[b].hp,arr[b].dmg)));
	}
	cout<<ans<<endl;
}