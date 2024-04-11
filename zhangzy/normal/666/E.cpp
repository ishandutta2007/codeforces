#include<bits/stdc++.h>
using namespace std;

#define N 1101000
int n, m;

vector<int>COV[N];
int an1[505000], an2[505000];
struct OPT{
    int id, l, r;
};
vector<OPT>opt[N];

int rt[N], cntr;
struct TR{
    int lc, rc, mx;
}tr[1001000];

void U(int x){
    tr[x].mx=max(tr[tr[x].lc].mx,tr[tr[x].rc].mx);
}
void addt(int &x,int l,int r,int p){
    if (!x) x=++cntr;
    if (l==r){
        ++tr[x].mx;
        return;
    }
    int mid=l+r>>1;
    if (p<=mid) addt(tr[x].lc,l,mid,p);
    else addt(tr[x].rc,mid+1,r,p);
    U(x);
}
void mg(int &x,int y,int l,int r){
    if (!y) return;
    if (!x){
        x=y; return;
    }
    if (l==r){
        tr[x].mx+=tr[y].mx;
        return;
    }
    int mid=l+r>>1;
    mg(tr[x].lc,tr[y].lc,l,mid);
    mg(tr[x].rc,tr[y].rc,mid+1,r);
    U(x);
}
int que(int x,int l,int r,int st,int en){
    st=max(st,l); en=min(en,r);
    if (st>en||!x) return 0;
    if (st==l&&en==r) return tr[x].mx;
    int mid=l+r>>1;
    return max(
        que(tr[x].lc,l,mid,st,en),
        que(tr[x].rc,mid+1,r,st,en)
    );
}
int fin(int x,int l,int r,int st,int en,int aim){
    st=max(st,l); en=min(en,r);
    if (st>en||tr[x].mx<aim) return 0;
    if (l==r) return l;
    int mid=l+r>>1;
    int res=fin(tr[x].lc,l,mid,st,en,aim);
    if (res) return res;
    return fin(tr[x].rc,mid+1,r,st,en,aim);
}

namespace sam{
    int ch[N][26], dep[N], fa[N], cnt=1, las=1, p, np, q, nq, d;
    int cov[N], tid[N], sum[N];
    int FA[N][20];
    vector<int>G[N];

    int add(int x){
        if (ch[las][x]&&dep[ch[las][x]]==dep[las]+1){
            las=ch[las][x]; ++cov[las];
            return las;
        }
        int fl=!!ch[las][x];
        p=las, np=++cnt, las=np;
        ++cov[las], dep[np]=dep[p]+1;
        for (;p&&!ch[p][x];p=fa[p]) ch[p][x]=np;
        if (!p) {
            fa[np]=1; return las;
        }
        if (dep[q=ch[p][x]]==dep[p]+1) {
            fa[np]=q; return las;
        }
        nq=fl? np: ++cnt;
        dep[nq]=dep[p]+1; fa[nq]=fa[q]; memcpy(ch[nq],ch[q],sizeof ch[q]);
        fa[q]=nq; if (!fl) fa[np]=nq;
        for (;p&&ch[p][x]==q;p=fa[p]) ch[p][x]=nq;
        return las;
    }
    
    int build(){
        for (int i=1;i<=cnt;++i) sum[dep[i]]++;
        for (int i=1;i<=cnt;++i) sum[i]+=sum[i-1];
        for (int i=1;i<=cnt;++i) tid[sum[dep[i]]--]=i;
        int x, aim;
        for (int i=cnt;i;--i) x=tid[i], cov[fa[x]]+=cov[x];
        for (int i=1;i<=cnt;++i){
            x=tid[i];
            FA[x][0]=fa[x];
            for (int j=1;j<=19;++j)
                FA[x][j]=FA[FA[x][j-1]][j-1];
        }
    }
    int gogogo(int x,int len){
        for (int i=19;i>=0;--i)
            if (dep[FA[x][i]]>=len)
                x=FA[x][i];
        return x;
    }

    void dfs(int x){
        for (auto y:G[x]){
            dfs(y);
            mg(rt[x],rt[y],1,n);
        }
        for (auto o:COV[x])
            addt(rt[x],1,n,o);
        for (auto o:opt[x]){
            int mx=que(rt[x],1,n,o.l,o.r);
            int mw=fin(rt[x],1,n,o.l,o.r,mx);
            an1[o.id]=mx;
            an2[o.id]=mw;
        }
    }

    void fuck(){
        for (int i=2;i<=cnt;++i)
            G[fa[i]].push_back(i);
        dfs(1);
    }
}


char s[505000]; int id[505000];

int main(){
    {
        sam::las=1;
        scanf("%s",s+1); int l=strlen(s+1);
        for (int i=1;i<=l;++i){
            id[i]=sam::add(s[i]-'a');
        }
    }
    cin>>n;
    for (int w=1;w<=n;++w){
        sam::las=1;
        scanf("%s",s+1); int l=strlen(s+1);
        for (int i=1;i<=l;++i){
            COV[sam::add(s[i]-'a')].push_back(w);
        }
    }
    sam::build();
    cin>>m;
    for (int w=1;w<=m;++w){
        int l, r, pl, pr;
        cin>>l>>r>>pl>>pr;
        int x=sam::gogogo(id[pr],pr-pl+1);
        opt[x].push_back({w,l,r});
    }
    sam::fuck();
    for (int i=1;i<=m;++i)
        printf("%d %d\n",an2[i],an1[i]);
}