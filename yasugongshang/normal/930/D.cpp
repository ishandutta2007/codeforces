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
int n;
vector<int> v[2][N<<1];
multiset<int> s[2];
ll ans;
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		int ff=read(),ss=read();
		v[abs(ff+ss)&1][ff+ss+N].push_back(ff-ss);
	}
	for(int i=0;i<(N<<1);i++)for(unsigned j=0;j<v[0][i].size();j++)s[0].insert(v[0][i][j]);
	for(int i=1;i<(N<<1);i+=2){
		for(unsigned j=0;j<v[0][i].size();j++){
			s[1].insert(v[0][i][j]); s[0].erase(s[0].find(v[0][i][j]));
		}
		if(s[0].size()&&s[1].size()){
			int t1=max(*s[0].begin(),*s[1].begin()),t2=min(*s[0].rbegin(),*s[1].rbegin());
			if(t1<=t2)ans+=(t2-t1)/2;
		}
	}
	s[0].clear(); s[1].clear();
	for(int i=0;i<(N<<1);i++){
		//if(v[1][i].size())cout<<i<<" "<<v[1][i].size()<<endl;
		for(unsigned j=0;j<v[1][i].size();j++)s[0].insert(v[1][i][j]);
	}
	for(int i=0;i<(N<<1);i+=2){
		for(unsigned j=0;j<v[1][i].size();j++){
			s[1].insert(v[1][i][j]); s[0].erase(s[0].find(v[1][i][j]));
		}
		if(s[0].size()&&s[1].size()){
			int t1=max(*s[0].begin(),*s[1].begin()),t2=min(*s[0].rbegin(),*s[1].rbegin());
			//cout<<i<<" "<<t1<<" "<<t2<<endl;
			if(t1<=t2)ans+=(t2-t1)/2;
		}
		//cout<<s[0].size()<<" "<<s[1].size()<<endl;
	}
	cout<<ans<<endl;
}