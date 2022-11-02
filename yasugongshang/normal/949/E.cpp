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
int n,tong[100005],tot;
vector<int>::iterator it;
vector<int> solve(int dep,vector<int> s){
	for(it=s.begin();it!=s.end();it++)if((*it)==0){s.erase(it); break;}
	/*if(s.size()==1&&tong[abs(*s.begin())]){
		vector<int> v; v.clear();
		v.push_back(*s.begin());
		return v;
	}*/
	if(s.size()==0||(s.size()==1&&tong[abs(s[0])]))return s;
	if(dep==17){
		vector<int> v; v.clear();
		for(it=s.begin();it!=s.end();it++)v.push_back(*it);
		return v;
	}
	int flag=0;
	for(it=s.begin();it!=s.end();it++)if((*it)&1)flag=1;
	vector<int> ss; ss.clear();
	if(!flag){
		int last=-1e9;
		for(it=s.begin();it!=s.end();it++)if(((*it)>>1)!=last){
			ss.push_back(last=((*it)>>1));
		}
		vector<int> v=solve(dep+1,ss);
		for(unsigned i=0;i<v.size();i++)v[i]<<=1;
		return v;
	}
	int last=-1e9;
	for(it=s.begin();it!=s.end();it++)if(((*it)>>1)!=last){
		ss.push_back(last=((*it)>>1));
	}
	vector<int> v1,v2;
	v1=solve(dep+1,ss); for(unsigned i=0;i<v1.size();i++)v1[i]<<=1; v1.push_back(1);
	ss.clear(); last=-1e9;
	for(it=s.begin();it!=s.end();it++)if(((*it+1)>>1)!=last){
		ss.push_back(last=((*it+1)>>1));
	}
	v2=solve(dep+1,ss); for(unsigned i=0;i<v2.size();i++)v2[i]<<=1; v2.push_back(-1);
	return v1.size()<v2.size()?v1:v2;
}
inline int rnd(int n){
	return (rand()<<16|rand())%n;
}
int main(){
	n=read();
	vector<int> s; s.clear();
	for(int i=1;i<=n;i++)s.push_back(read());
	for(int i=1;i<=100000;i*=2)tong[i]=1;
	sort(s.begin(),s.end());
	vector<int> ans=solve(0,s);
	writeln(ans.size());
	for(unsigned i=0;i<ans.size();i++){
		write(ans[i]); putchar(' ');
	}
}