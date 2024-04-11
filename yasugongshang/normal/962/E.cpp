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
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define getchar gc
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
ll ans;
vector<int> s[3];
#define en(i) s[i][s[i].size()-1]
int main(){
	int n=read();
	for(int i=1;i<=n;i++){
		int t=read(); char ch=getchar();
		if(ch=='R')s[0].push_back(t);
		else if(ch=='B')s[1].push_back(t);
		else s[2].push_back(t);
	}
	if(s[2].size()==0){
		for(unsigned i=1;i<s[0].size();i++)ans+=s[0][i]-s[0][i-1];
		for(unsigned i=1;i<s[1].size();i++)ans+=s[1][i]-s[1][i-1];
		cout<<ans<<endl; return 0;
	}
	if(s[0].size()&&s[0][0]<s[2][0])ans+=s[2][0]-s[0][0];
	if(s[1].size()&&s[1][0]<s[2][0])ans+=s[2][0]-s[1][0];
	if(s[0].size()&&en(0)>en(2))ans+=en(0)-en(2);
	if(s[1].size()&&en(1)>en(2))ans+=en(1)-en(2);
	int j=lower_bound(s[0].begin(),s[0].end(),s[2][0])-s[0].begin(),k=lower_bound(s[1].begin(),s[1].end(),s[2][0])-s[1].begin();
	for(unsigned i=1;i<s[2].size();i++){
		int jj=j,mj=0,lsj=s[2][i-1];
		while(jj<s[0].size()&&s[0][jj]<s[2][i]){
			mj=max(mj,s[0][jj]-lsj); lsj=s[0][jj++];
		}
		mj=max(mj,s[2][i]-lsj);
		int kk=k,mk=0,lsk=s[2][i-1];
		while(kk<s[1].size()&&s[1][kk]<s[2][i]){ 
			mk=max(mk,s[1][kk]-lsk); lsk=s[1][kk++];
		}
		mk=max(mk,s[2][i]-lsk);
		ans+=min((ll)3*(s[2][i]-s[2][i-1])-mj-mk,(ll)2*(s[2][i]-s[2][i-1]));
		j=jj; k=kk;
	}
	cout<<ans<<endl;
}