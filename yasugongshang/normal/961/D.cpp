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
inline int read(){
	int x=0; char ch=gc(); bool positive=1;
	for (;!isdigit(ch);ch=gc())if(ch=='-')positive=0;
	for (;isdigit(ch);ch=gc())x=x*10+ch-'0';
	return positive?x:-x;
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
#define ll long long
#define PI pair<int,int>
#define x first
#define y second
ll Cross(PI a,PI b,PI c){
	return 1ll * (a.x-c.x) * (b.y-c.y) - 1ll * (b.x-c.x) * (a.y-c.y);
}
const int maxn = 1e5+233;
bool mark[maxn];
vector<PI> B;
int n;
PI a[maxn];
bool check(PI x,PI y){
	B.clear();
	memset(mark,0,sizeof(mark));
	for(int i=1;i<=n;i++)
		if(Cross(x,y,a[i]) == 0) mark[i] = true; else
		B.push_back(a[i]);
	if(B.size() <= 2) return true;
	for(int i=2;i<B.size();i++){
		if(Cross(B[0],B[1],B[i]) != 0) return false;
	}
	return true;
}
int main(){
	n =read();
	for(int i=1;i<=n;i++){
		a[i] . x = read(); a[i].y =read();
	}
	if(check(a[1],a[2]) || check(a[1],a[3]) || check(a[2],a[3])){
		puts("YES");
	} else
		puts("NO");
	return 0;
}