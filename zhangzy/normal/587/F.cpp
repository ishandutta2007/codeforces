#include<bits/stdc++.h>
using namespace std;

int ch[101000][26],fai[101000],cnt,dep[101000];
int qu[101000],tot;
vector<int>vec[101000],G[101000],toans[101000];

void init(){
    memset(ch,0,sizeof ch);
    cnt=1; for (int i=0;i<26;++i) ch[0][i]=1;
    memset(fai,0,sizeof fai);
}
int add(string &s,int l=-1){
    if (l==-1) l=s.length(); int p=1,c;
    for (int i=0;i<l;++i){
        c=s[i]-'a';
        if (!ch[p][c]) ch[p][c]=++cnt;
        p=ch[p][c];
    }
    return p;
}
void build(){
    queue<int>q;
    for (;!q.empty();) q.pop();
    q.push(1); tot=0;
    int x,y;
    for (;!q.empty();){
    x=q.front(); q.pop(); qu[++tot]=x;
    for (int i=0;i<26;++i)
        if (y=ch[x][i]){
            fai[y]=ch[fai[x]][i];
            q.push(y);
        }else{
            ch[x][i]=ch[fai[x]][i];
        }
    }
    for (int i=2;i<=cnt;++i)
        G[fai[i]].push_back(i);
}

int n, q, li[101000], ri[101000], ki[101000];
long long ans[101000], tong[101000];

string s[101000];

const int sb=200;

void fuck(int w){
    static int cov[101000];
    memset(cov,0,sizeof cov);
    int p=1;
    for (auto c:s[w]){
        p=ch[p][c-'a'];
        ++cov[p];
    }
    for (int i=cnt;i>=2;--i){
        int x=qu[i];
        cov[fai[x]]+=cov[x];
        for (auto o:vec[x]) tong[o]=cov[x];
    }
    for (int i=2;i<=n;++i) tong[i]+=tong[i-1];
    for (int i=1;i<=q;++i)
        if (ki[i]==w){
            ans[i]=tong[ri[i]]-tong[li[i]-1];
        }
}

int c[101000];
void add(int x,int v){
    for (;x<=n;x+=x&-x) c[x]+=v;
}
int que(int x){
    int t=0;
    for (;x;x-=x&-x) t+=c[x];
    return t;
}
void dfs(int x){
    for (auto o:vec[x]) add(o,1);
    for (auto o:toans[x]) ans[o]+=que(ri[o])-que(li[o]-1);
    for (auto y:G[x]) dfs(y);
    for (auto o:vec[x]) add(o,-1);
}

int main(){
    // ios::sync_with_stdio(0);
    cin>>n>>q;
    init();
    for (int i=1;i<=n;++i){
        cin>>s[i];
        vec[add(s[i])].push_back(i);
    }
    build();
    for (int i=1;i<=q;++i){
        cin>>li[i]>>ri[i]>>ki[i];
    }
    for (int i=1;i<=n;++i)
        if (s[i].length()>sb){
            fuck(i);
        }
    for (int i=1;i<=q;++i)
        if (s[ki[i]].length()<=sb){
            int p=1;
            for (auto c:s[ki[i]]){
                p=ch[p][c-'a'];
                toans[p].push_back(i);
            }
        }
    dfs(1);
    for (int i=1;i<=q;++i)
        cout<<ans[i]<<endl;
}