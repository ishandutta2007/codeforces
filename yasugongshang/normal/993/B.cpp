#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define PI pair<int,int>
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
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
inline int rnd(int x){
	return (rand()<<16|rand())%x;
}
int n,m;
PI a[100],b[100];
set<int> s1[100],s2[100],ss;
int main(){
	n=read(); m=read();
	for(int i=1;i<=n;i++){
		a[i].first=read(); a[i].second=read();
		if(a[i].first>a[i].second)swap(a[i].first,a[i].second);
	}
	for(int i=1;i<=m;i++){
		b[i].first=read(); b[i].second=read();
		if(b[i].first>b[i].second)swap(b[i].first,b[i].second);
	}
	ss.clear();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i].first==b[j].first&&a[i].second==b[j].second)continue;
			if(a[i].first==b[j].first||a[i].second==b[j].first||a[i].first==b[j].second||a[i].second==b[j].second){
				if(a[i].first==b[j].first||a[i].first==b[j].second){s1[i].insert(a[i].first); s2[j].insert(a[i].first); ss.insert(a[i].first);}
				if(a[i].second==b[j].first||a[i].second==b[j].second){s1[i].insert(a[i].second); s2[j].insert(a[i].second); ss.insert(a[i].second);}
			}
		}
		if(s1[i].size()>1){
			puts("-1"); return 0;
		}
	}
	for(int i=1;i<=m;i++)if(s2[i].size()>1){
		puts("-1"); return 0;
	}
	if(ss.size()>1)puts("0");
	else cout<<*ss.begin()<<endl;
}