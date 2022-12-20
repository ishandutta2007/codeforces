#include <bits/stdc++.h>

using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x*10)+(ch^48),ch=getchar();
    return !f?x:-x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=300010;

struct Node{int ch[26],fail,siz;};
struct AC_automaton{
    vector<Node> t;
    vector<string> str;
    int rt;
    AC_automaton() {t.resize(2),rt=1;}
    int size() {return str.size();}
    bool empty() {return str.empty();}
    int newnode(){
        t.pb(Node());
        return t.size()-1;
    }
    void clear() {t.clear();str.clear();}
    void insert(const string &s){
        int now=rt;
        for(auto c:s){
            if(!t[now].ch[c-'a']){
                int tmp=newnode();
                t[now].ch[c-'a']=tmp;
            }
            now=t[now].ch[c-'a'];
        }
        t[now].siz++,str.pb(s);
    }
    void build(){
        queue<int> q;
        t[rt].fail=0;
        for(int i=0;i<26;i++)
            if(t[rt].ch[i]) t[t[rt].ch[i]].fail=rt,q.push(t[rt].ch[i]);
            else t[rt].ch[i]=rt;
        while(!q.empty()){
            int x=q.front();q.pop();
            for(int i=0;i<26;i++){
                if(!t[x].ch[i]) t[x].ch[i]=t[t[x].fail].ch[i];
                else{
                    int y=t[x].ch[i];
                    t[y].fail=t[t[x].fail].ch[i];
                    t[y].siz+=t[t[y].fail].siz;
                    q.push(y);
                }
            }
        }
    }
    int query(const string &s){
        int now=rt;ll res=0;
        for(auto c:s)
            now=t[now].ch[c-'a'],res+=t[now].siz;
        return res;
    }
    void merge(const AC_automaton &rhs){
        for(auto s:rhs.str) insert(s);
    }
};

struct Group{
    static const int N=31;
    AC_automaton t[N];
    void insert(const string &s){
        AC_automaton tmp;tmp.insert(s);
        for(int i=0;i<N;i++){
            if(t[i].empty()){
                t[i]=tmp,t[i].build();
                break;
            }
            else tmp.merge(t[i]),t[i].clear();
        }
    }
    ll query(const string &s){
        ll res=0;
        for(int i=0;i<N;i++)
            if(!t[i].empty()) res+=t[i].query(s);
        return res;
    }
}add,sub;

int m;
char s[N];

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    m=rdi();
    while(m--){
        int typ;string s;
        cin>>typ>>s;
        if(typ==1) add.insert(s);
        else if(typ==2) sub.insert(s);
        else cout<<add.query(s)-sub.query(s)<<endl;
    }
    return 0;
}