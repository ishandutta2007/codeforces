#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<ctime>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
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
char ch[N];
int n,tot;
set<int> s0,s1;
set<int>::iterator it;
vector<int> v[N];
int main(){
	scanf("%s",ch);
	n=strlen(ch);
	for(int i=0;i<n;i++){
		if(ch[i]=='0')s0.insert(i); else s1.insert(i);
	}
	while(1){
		int now=0,mx=-1; tot++;
		while(1){
			if(!now){
				it=s0.lower_bound(mx);
				if(it==s0.end()){
					puts("-1"); return 0;
				}
				v[tot].push_back(mx=*it); s0.erase(it);
			}else{
				it=s1.lower_bound(mx);
				if(it==s1.end())break;
				v[tot].push_back(mx=*it); s1.erase(it);
			}
			now^=1;
		}
		if(!s0.size()&&!s1.size())break;
	}
	writeln(tot);
	for(int i=1;i<=tot;i++){
		write(v[i].size()); putchar(' ');
		for(unsigned j=0;j<v[i].size();j++){
			write(v[i][j]+1); putchar(' ');
		}
		puts("");
	}
}