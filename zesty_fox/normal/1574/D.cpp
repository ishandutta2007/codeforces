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

const int N=12,M=200010;

int n,m,a[N][M],siz[N];
struct Node{
	ll sum;
	vi ch;
	Node(){}
	Node(const vi &ch1){
		ch=ch1,sum=0;
		for(int i=0;i<n;i++) sum+=a[i+1][ch[i]];
	}
	bool operator < (const Node &rhs)const{
		return sum<rhs.sum;
	}
};
set<vi> s,s1;
priority_queue<Node> q;
int main(){
	n=rdi();
	for(int i=1;i<=n;i++){
		siz[i]=rdi();
		for(int j=1;j<=siz[i];j++) a[i][j]=rdi();
	}
	m=rdi();
	for(int i=1;i<=m;i++){
		vi tmp;
		for(int j=1;j<=n;j++) tmp.pb(rdi());
		s.insert(tmp);
	}
	vi tmp;
	for(int i=1;i<=n;i++) tmp.pb(siz[i]);
	q.push(Node(tmp));
	while(!q.empty()){
		auto x=q.top();q.pop();
		if(s.find(x.ch)==s.end()){
			for(auto tmp:x.ch) printf("%d ",tmp);
			return 0;
		}
		if(s1.find(x.ch)!=s1.end()) continue;
		s1.insert(x.ch);
		for(int i=0;i<n;i++){
			if(x.ch[i]>1){
				x.ch[i]--;
				q.push(Node(x.ch));
				x.ch[i]++;
			}
		}
	}
    return 0;
}