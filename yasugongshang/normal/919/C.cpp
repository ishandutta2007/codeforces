#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;

inline int read(){
	int k=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){k=k*10+ch-'0';ch=getchar();}
	return k*f;
}

inline void write(int x){
	if(x<0)x=-1,putchar('-');
	if(x>9)write(x/10);putchar(x%10+'0');
}

inline void writeln(int x){
	write(x);puts("");
}

int n,m,k,now;
ll ans;
char a[2005][2005];

int main(){
	n=read();m=read();k=read();
	for(int i=1;i<=n;i++){
		scanf("%s",a[i]+1);
	}
	for(int i=1;i<=n;i++){
		now=0;
		for(int j=1;j<=m;j++){
			if(a[i][j]=='.'){
				++now;
			}else{
				ans+=max(0,now-k+1);
//				cout<<now<<endl;
				now=0;
			}
		}
		ans+=max(0,now-k+1);
	}
	for(int j=1;j<=m;j++){
		now=0;
		for(int i=1;i<=n;i++){
			if(a[i][j]=='.'){
				++now;
			}else{
				ans+=max(0,now-k+1);
//				cout<<now<<endl;
				now=0;
			}
		}
		ans+=max(0,now-k+1);
	}
	if(k==1)ans/=2; cout<<ans;
}