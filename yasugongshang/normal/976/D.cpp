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
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=305;
int n,m,tot,last,d[N];
vector<PI> ans;
int main(){
	m=read();
	for(int i=1;i<=m;i++)d[i]=read();
	n=d[m]+1;
	for(int l=1,r=m,i=1;i<=n&&l<=r;i++){
		if(tot+n-i==d[r]){
			r--; last=1; tot++;
			for(int j=i+1;j<=n;j++)ans.push_back(mp(i,j));
		}else if(tot==d[l]){
			l++; last=0;
		}else{
			tot+=last;
			if(last)for(int j=i+1;j<=n;j++)ans.push_back(mp(i,j));
		}
		if(l>r&&last){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++)ans.push_back(mp(j,k));
			}
		}
	}
	writeln(ans.size());
	for(unsigned i=0;i<ans.size();i++){
		write(ans[i].first); putchar(' '); writeln(ans[i].second);
	}
}