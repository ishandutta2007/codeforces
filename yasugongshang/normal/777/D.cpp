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
const int N=500005;
string s[N],ans;
int n,len[N],vis[N];
inline void update(int pos){
	//if(pos==2)cout<<len[pos]<<" "<<vis[pos-1]<<" "<<len[pos-1]<<endl;
	if(len[pos]<vis[pos-1]&&len[pos-1]>len[pos])len[pos-1]=len[pos],update(pos-1);
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	cin>>s[1]; len[1]=s[1].length()-1;
	for(int i=2;i<=n;i++){
		cin>>s[i]; int wz=0; len[i]=s[i].length()-1;
		for(int j=1;j<s[i].length()&&j<=len[i-1];j++)if(s[i-1][j]!=s[i][j]){
			wz=j; break;
		} 
		if(!wz){
			if(len[i-1]>len[i])len[i-1]=len[i]; vis[i-1]=len[i]; 
		}else if(s[i-1][wz]>s[i][wz]){
			len[i-1]=wz-1; vis[i-1]=1e9;
		}else vis[i-1]=wz;
		update(i-1);
	}
	for(int i=1;i<=n;i++){
		s[i]+='\n';
		s[i][len[i]+1]='\n';
		ans+=s[i].substr(0,len[i]+2);
	}
	cout<<ans<<endl;
}