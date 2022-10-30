#include<bits/stdc++.h>
#define maxc 26
#define maxn 1000050
using namespace std;

int all,text[maxn];
int sz,last;

int len[maxn];
int diff[maxn];
int fail[maxn],anc[maxn];
int ch[maxn][maxc];

int pre[maxn];

int newnode(int l=0)  {
    len[sz]=l;
    fail[sz]=anc[sz]=0;
    memset(ch[sz],0,sizeof(ch[sz]));
    return sz++;
}

void init() {
    sz=last=all=0;
    newnode(0),newnode(-1);
    fail[0]=1;
    text[all]=-1;
}

int getfail(int x)  {
    while (text[all-1-len[x]]!=text[all]) x=fail[x];
    return x;
}

void extend(int w)  {
    text[++all]=w;
    int x=getfail(last);
    if (!ch[x][w]) {
        int y=newnode(len[x]+2);
        fail[y]=ch[getfail(fail[x])][w];
        ch[x][w]=y;
        diff[y]=len[y]-len[fail[y]];
        anc[y]=(diff[y]==diff[fail[y]]?anc[fail[y]]:fail[y]);
    }
    last=ch[x][w];
}

void travel(int k,string s="")  {
    cout<<k<<":"<<s<<endl;
    for (int c=0;c<maxc;++c)
        if (ch[k][c])
            travel(ch[k][c],string(1,c+'a')+s+string(1,c+'a'));
}

int n;
char s[maxn],t[maxn];
char comb[maxn];

int dp[maxn],lst[maxn];

int main()  {
    scanf("%s%s",s+1,t+1),n=strlen(s+1);
    for (int i=1;i<=n;++i) comb[2*i-1]=s[i],comb[2*i]=t[i];

    // printf("%s\n",comb+1);

    init(),n<<=1;
    for (int i=1;i<=n;++i)    {
        dp[i]=maxn;
        extend(comb[i]-'a');
        // travel(0);
        // for (int c=0;c<maxc;++c)
        //     if (ch[1][c])
        //         travel(ch[1][c],string(1,c+'a'));
        for (int j=last;len[j]>0;j=anc[j])    {
            pre[j]=i-len[anc[j]]-diff[j];
            if (diff[j]==diff[fail[j]]&&dp[pre[j]]>dp[pre[fail[j]]])
                pre[j]=pre[fail[j]];
            // cout<<i<<" "<<j<<" ("<<len[j]<<","<<fail[j]<<","<<anc[j]<<","<<diff[j]<<" ~ "<<pre[j]<<")"<<endl;
            if ((~i&1)&&dp[i]>dp[pre[j]]+1)
                dp[i]=dp[pre[j]]+1,lst[i]=pre[j];
        }
        if ((~i&1)&&comb[i-1]==comb[i]&&dp[i]>dp[i-2])
            dp[i]=dp[i-2],lst[i]=i-2;
        // cout<<"dp["<<i<<"]="<<dp[i]<<" "<<sz<<endl;
        // cout<<endl;
    }

    if (dp[n]==maxn)
        puts("-1");
    else    {
        printf("%d\n",dp[n]);
        for (int i=n;i;i=lst[i]) {
            if (i-2==lst[i]) continue;
            printf("%d %d\n",lst[i]/2+1,i/2);
        }
    }
    return 0;
}