#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=2027;
int n,a[N];
vector<int>ans;
inline void op(int i){
	ans.push_back(i);
	reverse(a+1,a+i+1);
}
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)
		if(a[i]%2!=i%2){
			puts("-1");
			return;	
		}
	for(int x=n;x>1;x-=2){
		int i=0;
		for(int k=1;k<=x;k++)
			if(a[k]==x)i=k;
		if(i!=1)op(i);
		for(int k=1;k<=x;k++)
			if(a[k]==x-1)i=k;
		if(i!=2){
			op(i-1);
			op(i+1);
			for(int k=1;k<=x;k++)
				if(a[k]==x)i=k;
			if(i!=1)op(i);
		}
		op(x);
	}
	printf("%lu\n",ans.size());
	for(auto x:ans)printf("%d ",x);
	puts(""),ans.clear();
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}