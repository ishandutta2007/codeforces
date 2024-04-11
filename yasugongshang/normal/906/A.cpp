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
int n,ans[26],anss,sum,tong[26];
char a[100005],b[100005];
int main(){
	int nn=read();
	for(int i=0;i<26;i++)ans[i]=1; sum=26;
	for(int i=1;i<=nn;i++){
		scanf("%s",&a);
		scanf("%s",&b);
		n=strlen(b); 
		if(a[0]=='!'){
			memset(tong,0,sizeof(tong));
			for(int i=0;i<n;i++){
				tong[b[i]-'a']=1;
			}
			if(sum==1)anss++;
			for(int i=0;i<26;i++)if(!tong[i]&&ans[i]){
				ans[i]=0; sum--;
			}
		}else if(a[0]=='.'){
			for(int i=0;i<n;i++)if(ans[b[i]-'a']){
				ans[b[i]-'a']=0; sum--;
			}
		}else{
			if(sum==1&&!ans[b[0]-'a'])anss++;
			if(i<nn&&ans[b[0]-'a']){
				ans[b[0]-'a']=0; sum--;
			}
		}
	}
	cout<<anss<<endl;
}