#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T;

int n;

char s[N];

int cnt[26];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        for(int i=0;i<26;i++)
            cnt[i]=0;
        scanf("%s",s+1);
        n=strlen(s+1);
        for(int i=1;i<=n;i++)
            cnt[s[i]-'a']++;
        int ok=-1;
        for(int i=0;i<26;i++)
            if(cnt[i]==1)
            {
                ok=i;
                break;
            }
        int tot=0;
        for(int i=0;i<26;i++)
            tot+=cnt[i]!=0;
        if(tot==1)
        {
            for(int i=1;i<=n;i++)
                putchar(s[i]);
        }
        else if(ok!=-1)
        {
            putchar(ok+'a');
            cnt[ok]--;
            for(int i=0;i<26;i++)
                while(cnt[i]--)
                    putchar(i+'a');
        }
        else
        {
            int st=-1;
            for(int i=0;i<26;i++)
                if(cnt[i])
                {
                    st=i;
                    break;
                }
            int sec=-1,trd=-1;
            for(int i=st+1;i<26;i++)
                if(cnt[i])
                {
                    sec=i;
                    break;
                }
            for(int j=sec+1;j<26;j++)
                if(cnt[j])
                {
                    trd=j;
                    break;
                }
            int num=0;
            for(int i=st+1;i<26;i++)
                num+=cnt[i];
            if(cnt[st]<=num+2)
            {
                putchar('a'+st);
                putchar('a'+st);
                cnt[st]-=2;
                int flg=0;
                for(int i=st+1;i<26;i++)
                {
                    while(cnt[i]||(flg&&cnt[st]))
                    {
                        if(flg&&cnt[st])
                        {
                            putchar(st+'a');
                            cnt[st]--;
                            flg^=1;
                        }
                        else
                        {
                            putchar(i+'a');
                            cnt[i]--;
                            flg^=1;
                        }
                    }
                }
            }
            else
            {
                if(trd==-1)
                {
                    putchar(st+'a');
                    cnt[st]--;
                    while(cnt[sec])
                        putchar(sec+'a'),cnt[sec]--;
                    while(cnt[st])
                        putchar(st+'a'),cnt[st]--;
                    
                }
                else
                {
                    putchar(st+'a');
                    cnt[st]--;
                    putchar(sec+'a');
                    cnt[sec]--;
                    while(cnt[st])
                        putchar(st+'a'),cnt[st]--;
                    putchar(trd+'a');
                    cnt[trd]--;
                    while(cnt[sec])
                        putchar(sec+'a'),cnt[sec]--;
                    for(int i=trd;i<26;i++)
                        while(cnt[i])
                            putchar(i+'a'),cnt[i]--;
                }
            }
        }
        puts("");
    }
}