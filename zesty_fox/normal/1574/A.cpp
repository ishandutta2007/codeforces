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

const int N=1010;
int n;
char s[N];
void solve(){
	n=rdi();s[1]='(';
	for(int i=2;i<=2*n;i+=2){
		s[i]=')';
		for(int j=2;j<=i-1;j++) s[j]=(j&1?')':'(');
		for(int j=i+1;j<=2*n;j++) s[j]=((j&1)^1?')':'(');
		s[2*n+1]='\0';
		printf("%s\n",s+1);
	}
}

int T;
int main(){
	T=rdi();
	while(T--) solve();
    return 0;
}