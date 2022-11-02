#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
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
const int N=405;
char a[N][N],b[N][N];
int n,m,r,c;
bitset<N> ans[N][N];
bitset<N> t1[26],t2;
void kmp(char a[],char b[],int i,int j){
	int n=strlen(a),m=strlen(b);
	for(int i=0;i<26;i++)t1[i].reset();
	for(int i=0;i<n;i++){
		t1[a[i]-'a'].set(i); 
	}
	t2.set();
	for(int k=0;k<m;k++){
		t2=t2<<1; t2[0]=t2[n];
		if(b[k]!='?')t2=t2&t1[b[k]-'a'];
		//cout<<t2.count()<<" "<<i<<" "<<j<<" "<<k<<endl;
		//if(!t2[m-1])cout<<i<<" "<<k-m<<" "<<j<<endl;
	}
	for(int k=0;k<n;k++)if(t2[k])ans[i][(k-m%n+1+n)%n].set(j);
	//if(i==2&&j==1)for(int k=0;k<n;k++)if(t2[k])cout<<i<<" "<<j<<" "<<k<<" "<<(k-m+1+n)%n<<endl;
}
int main(){
	//writeln(pd('?','a')); return 0;
	n=read(); m=read();
	for(int i=0;i<n;i++)scanf("%s",a[i]);
	r=read(); c=read();
	for(int i=0;i<r;i++)scanf("%s",b[i]);
	for(int i=0;i<n;i++){
		for(int j=0;j<r;j++){
			kmp(a[i],b[j],i,j);
		}
	}
	for(int i=2*n-1;i>=0;i--){
		for(int j=0;j<m;j++){
			ans[(i+1)%n][j][r]=1;
			ans[i%n][j]=ans[i%n][j]&(ans[(i+1)%n][j]>>1);
			//cout<<ans[i][j].count()<<endl;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			putchar(ans[i][j][0]+'0');
		}
		putchar('\n');
	}
}