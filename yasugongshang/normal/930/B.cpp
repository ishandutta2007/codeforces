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
const int N=5005;
double ans;
vector<int> v[26];
int n,tong[26];
char ch[N];
int main(){
	scanf("%s",ch);
	n=strlen(ch);
	for(int i=0;i<n;i++)v[ch[i]-'a'].push_back(i);
	for(int i=0;i<26;i++){
		int mx=0;
		for(int j=0;j<n;j++){
			int sum=0; memset(tong,0,sizeof(tong));
			for(uint k=0;k<v[i].size();k++){
				int t=(v[i][k]+j)%n;
				tong[ch[t]-'a']++;
			}
			for(int k=0;k<26;k++)if(tong[k]==1)sum++;
			mx=max(mx,sum);
		}
		//cout<<mx<<" "<<v[i].size()<<endl;
		ans+=(double)mx/n;
	}
	printf("%.7lf\n",ans);
}