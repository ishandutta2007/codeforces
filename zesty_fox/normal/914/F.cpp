#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=100010;

char p[N];
int n,m;
bitset<N> b;

bitset<N> vis[26];

void init(){
    n=strlen(p+1);
    for(int i=1;i<=n;i++) vis[p[i]-'a'][i]=1;
}

void modify(int x,char ch){
    vis[p[x]-'a'][x]=0;
    p[x]=ch;
    vis[p[x]-'a'][x]=1;
}

int main(){
    scanf("%s",p+1);m=rdi();init();
    for(int i=1;i<=m;i++){
        int op=rdi();
        if(op==1){
            int x;char s[2];
            scanf("%d%s",&x,s);
            modify(x,s[0]);
        }
        else{
            int L=rdi(),R=rdi();
            string s;cin>>s;
            
            b.set();
            for(auto ch:s) b=(b<<1)&vis[ch-'a'];

            L+=s.length()-1;
            b>>=L;b<<=(N-R-1+L);
            cout<<b.count()<<'\n';
        }
    }
    return 0;
}