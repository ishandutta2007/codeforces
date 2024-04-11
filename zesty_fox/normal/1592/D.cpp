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
vi e[N];

int ask(const vi& v){
	printf("? %lu ",v.size());
	for(auto x:v) printf("%d ",x);
	puts("");fflush(stdout);
	return rdi();
}

void print_ans(int x,int y){
	printf("! %d %d\n",x,y);
	fflush(stdout);
}

int euler[N<<1],pos,ans;
void dfs(int x,int fa){
    euler[++pos]=x;
    for(auto y:e[x]){
        if(y==fa) continue;
        dfs(y,x);
        euler[++pos]=x;
    }
}

bool check(int l,int r){
    vi tmp(euler+l,euler+r+1);
    sort(tmp.begin(),tmp.end()),tmp.resize(unique(tmp.begin(),tmp.end())-tmp.begin());
    return ask(tmp)>=ans;
}

int main(){
	n=rdi();
	for(int i=1;i<n;i++){
		int x=rdi(),y=rdi();
	    e[x].pb(y),e[y].pb(x);
    }
    dfs(1,0);
	vi tmp;
	for(int i=1;i<=n;i++) tmp.pb(i);
    ans=ask(tmp);
    
    int l=1,r=2*n-1;
    while(l+1<r){
        int mid=(l+r)>>1;
        if(check(l,mid)) r=mid;
        else l=mid;
    }
    print_ans(euler[l],euler[l+1]);
    return 0;
}