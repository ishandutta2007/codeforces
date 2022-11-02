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
const int mod=1000000007;
int tong[64];
string s;
inline int calc(char x){
	if(isdigit(x))return x-'0';
	else if(x>='a'&&x<='z')return x-'a'+36;
	else if(x>='A'&&x<='Z')return x-'A'+10;
	else if(x=='-')return 62; else return 63;
}
int main(){
	for(int i=0;i<64;i++){
		for(int j=0;j<64;j++){
			tong[i&j]++;
		}
	}
	cin>>s; int ans=1;
	for(int i=0;i<s.length();i++){
		ans=(long long)ans*tong[calc(s[i])]%mod;
	}
	cout<<ans<<endl;
}