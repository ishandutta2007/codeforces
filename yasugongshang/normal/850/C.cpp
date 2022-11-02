#include<bits/stdc++.h>
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

int ti,n,tong[105];
map<int,int> sg,M;
map<int,int>::iterator it;
inline int solve(int x){
	if(x==0)return 0;
	if(sg.count(x))return sg[x];
	int t[31];
	for(int i=1;((x>>i)|(x&((1<<(i-1))-1)))!=x;i++){
		t[i]=solve((x>>i)|(x&((1<<(i-1))-1)));
		//if(x==1)cout<<x<<" "<<((x>>i)|(x&((1<<i)-1)))<<" "<<t[i]<<endl;
	}
	ti++;
	for(int i=1;((x>>i)|(x&((1<<(i-1))-1)))!=x;i++)tong[t[i]]=ti;
	for(int i=0;;i++)if(tong[i]!=ti){return sg[x]=i;}
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		int x=read();
		for(int i=2;i*i<=x;i++)if(x%i==0){
			int t=-1;
			while(x%i==0){
				x/=i; t++;
			}
			M[i]|=1<<t;
		}
		if(x>1)M[x]|=1;
	}
	int ans=0;
	//cout<<solve(1)<<endl;
	for(it=M.begin();it!=M.end();it++){
		//cout<<it->first<<" "<<it->second<<" "<<solve(it->second)<<endl;
		ans^=solve(it->second);
	}
	puts(ans?"Mojtaba":"Arpa");
}