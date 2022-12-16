#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=10010;
int n,p[N];
int ask(int t,int i,int j,int x){
	printf("? %d %d %d %d\n",t,i,j,x);
	fflush(stdout);
	return rdi();
}

void print_ans(){
	printf("!");
	for(int i=1;i<=n;i++) printf(" %d",p[i]);
	puts("");
	fflush(stdout);
}

void solve(){
	n=rdi();int pos=n;
	for(int i=1;i<=n-1;i+=2){
		int val=ask(2,i,i+1,1);
		if(val==1){pos=i;break;}
		else if(val==2){
			if(ask(2,i+1,i,1)==1) {pos=i+1;break;}
		}
	}
	p[pos]=1;
	for(int i=1;i<=n;i++){
		if(i==pos) continue;
		p[i]=ask(1,pos,i,n-1);
	}
	print_ans();
}

int T;
int main(){
	T=rdi();
	while(T--) solve();
    return 0;
}