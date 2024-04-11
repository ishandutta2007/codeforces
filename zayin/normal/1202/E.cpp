#include<bits/stdc++.h>
#define maxc 26
#define maxn 600050
using namespace std;
typedef long long LL;

struct SAM  {

    int sz,last;

    int len[maxn];
    int fa[maxn];
    int ch[maxn][maxc];

    LL cnt[maxn];
    vector<int> G[maxn];

    int newnode(int l=0)    {
        len[sz]=l;
        fa[sz]=-1;
        cnt[sz]=0;
        G[sz].clear();
        memset(ch[sz],0,sizeof(ch[sz]));
        return sz++;
    }
    void init() {
        sz=0;
        last=newnode();
    }

    void travel(int k=0,string s="")    {
        cout<<k<<":"<<s<<endl;
        for (int c=0;c<maxc;++c)
            if (ch[k][c])
                travel(ch[k][c],s+(char)(c+'a'));
    }

    void extend(int c)  {
        int k=last,leaf=newnode(len[k]);
        for (;~k&&!ch[k][c];k=fa[k])
            ch[k][c]=leaf;
        if (!~k)
            fa[leaf]=0;
        else    {
            int p=ch[k][c];
            if (len[p]==len[k]+1)
                fa[leaf]=p;
            else    {
                int np=newnode(len[k]+1);
                memcpy(ch[np],ch[p],sizeof(ch[p]));
                fa[np]=fa[p];
                fa[p]=fa[leaf]=np;
                for (;~k&&ch[k][c]==p;k=fa[k])
                    ch[k][c]=np;
            }
        }
        last=leaf;
    }

    void insert(const char* s)  {
        init();
        for (int i=1;s[i];++i)
            extend(s[i]-'a');
        // travel();
    }

    void build()    {
        for (int i=1;i<sz;++i)
            G[fa[i]].push_back(i);
    }

    void dfs(int i) {
        // cout<<"dfs:"<<i<<" "<<cnt[i]<<endl;
        for (int j:G[i])   {
            cnt[j]+=cnt[i];
            dfs(j);
        }
    }
} T;

int n,m;
int pos[maxn],len[maxn]={1};
char s[maxn],t[maxn];

LL L[maxn],R[maxn];

int main()  {
    scanf("%s%d",t+1,&n);
    m=strlen(t+1);
    for (int i=1;i<=n;++i)  {
        pos[i]=pos[i-1]+len[i-1];
        scanf("%s",s+pos[i]);
        len[i]=strlen(s+pos[i]);
    }
    auto calc=[&](LL *f) {
        T.insert(t);
        T.build();
        for (int i=1;i<=n;++i)  {
            int k=0,flag=1;
            char *sub=s+pos[i];
            for (int j=0;flag&&j<len[i];++j)  {
                int c=sub[j]-'a';
                if (T.ch[k][c])
                    k=T.ch[k][c];
                else
                    flag=0;
            }
            if (flag)
                ++T.cnt[k];
            // cout<<"add:"<<i<<" "<<k<<endl;
        }
        T.dfs(0);
        int k=0;
        for (int i=1;i<=m;++i)  {
            k=T.ch[k][t[i]-'a'];
            f[i]=T.cnt[k];
            // cout<<i<<":"<<k<<" "<<f[i]<<endl;
        }
    };
    calc(L);
    reverse(t+1,t+m+1);
    for (int i=1;i<=n;++i)
        reverse(s+pos[i],s+pos[i]+len[i]);
    calc(R);
    reverse(R+1,R+m+1);
    LL ans=0;
    for (int i=1;i<=m;++i)
        ans+=L[i-1]*R[i];
    printf("%lld\n",ans);
    return 0;
}