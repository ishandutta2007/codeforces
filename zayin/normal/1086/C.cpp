#include<bits/stdc++.h>
#define maxc 300
#define maxn 1000050
using namespace std;

int n,m;

char s[maxn],a[maxn],b[maxn];
char mp[maxc];
bool vis[maxc];

vector<char> C;

bool va[maxc],vb[maxc];
char ma[maxc],mb[maxc];

void init()
{
    scanf("%d%s%s%s",&m,s,a,b);
    n=strlen(s);
}

void print(char mp[])
{
    C.clear();
    puts("YES");
    memset(vis,0,sizeof(vis));
    for (char i='a';i<'a'+m;++i)
        vis[mp[i]]=1;
    for (char i='a';i<'a'+m;++i)
        if (!vis[i])
            C.push_back(i);
    char c=0;
    for (char i='a';i<'a'+m;++i)
    {
        if (!mp[i])
            mp[i]=C[c++];
        putchar(mp[i]);
    }
    putchar('\n');
}

bool solve()
{
    memset(mp,0,sizeof(mp));
    memset(vis,0,sizeof(vis));
    int p;
    for (p=0;p<n&&a[p]==b[p];++p)
    {
        // cout<<p<<" "<<mp[s[p]]<<" "<<vis[a[p]]<<endl;
        if ((mp[s[p]]&&mp[s[p]]!=a[p])||(!mp[s[p]]&&vis[a[p]]))
            return 0;
        vis[mp[s[p]]=a[p]]=1;
    }

    // cout<<p<<endl;

    if (p==n)
    {
        print(mp);
        return 1;
    }

    if (!mp[s[p]])
    {
        bool flag=0;
        for (char c=a[p]+1;c<=b[p]-1;++c)
            if (!vis[c])
                flag=1,mp[s[p]]=c;
        if (flag)
        {
            print(mp);
            return 1;
        } else
        {
            if (vis[a[p]]&&vis[b[p]])
                return 0;
        }
    } else
    {
        if (mp[s[p]]>a[p]&&mp[s[p]]<b[p])
        {
            print(mp);
            return 1;
        } else
        {
            // cout<<mp[s[p]]<<" "<<a[p]<<" "<<
            if (mp[s[p]]<a[p]||mp[s[p]]>b[p])
                return 0;
        }
    }
    if (p==n-1)
    {
        if (!mp[s[p]])
        {
            if (!vis[a[p]])
                mp[s[p]]=a[p];
            else
                mp[s[p]]=b[p];
        }
        print(mp);
        return 1;
    }

    memcpy(ma,mp,sizeof(ma));
    memcpy(va,vis,sizeof(va));
    memcpy(mb,mp,sizeof(mb));
    memcpy(vb,vis,sizeof(vb));

    bool fa=0,fb=0;
    if ((!ma[s[p]]&&!va[a[p]])||(ma[s[p]]&&ma[s[p]]==a[p]))
    {
        // cout<<"a"<<endl;
        va[ma[s[p]]=a[p]]=1;
        int i;
        for (i=p+1;!fa&&i<n;++i)
        {
            // cout<<i<<" "<<ma[s[i]]<<" "<<a[i]<<endl;
            if (!ma[s[i]])
            {
                bool flag=0;
                for (char c=a[i]+1;c<'a'+m;++c)
                    if (!va[c])
                        flag=1,ma[s[i]]=c;
                if (flag)
                {
                    fa=1;
                    break;
                } else
                {
                    if (va[a[i]])
                        break;
                    else
                        va[ma[s[i]]=a[i]]=1;
                }
            } else
            {
                if (ma[s[i]]>a[i]) fa=1;
                if (ma[s[i]]<a[i]) break;
            }
        }
        if (i==n)
            fa=1;
    }

    if (fa)
    {
        print(ma);
        return 1;
    }

    if ((!mb[s[p]]&&!vb[b[p]])||(mb[s[p]]&&mb[s[p]]==b[p]))
    {
        vb[mb[s[p]]=b[p]]=1;
        int i;
        for (i=p+1;!fb&&i<n;++i)
        {
            // cout<<i<<" "<<mb[s[i]]<<endl;
            if (!mb[s[i]])
            {
                bool flag=0;
                for (char c='a';c<b[i];++c)
                    if (!vb[c])
                        flag=1,mb[s[i]]=c;
                if (flag)
                {
                    fb=1;
                    break;
                } else
                {
                    if (vb[b[i]])
                        break;
                    else
                        vb[mb[s[i]]=b[i]]=1;
                }
            } else
            {
                if (mb[s[i]]<b[i]) fb=1;
                if (mb[s[i]]>b[i]) break;
            }
        }
        if (i==n)
            fb=1;
    }

    if (fb)
    {
        print(mb);
        return 1;
    }
    return 0;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        init();
        if (!solve())
            puts("NO");
    }
    return 0;
}