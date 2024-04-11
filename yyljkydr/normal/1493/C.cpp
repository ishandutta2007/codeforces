#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,k;

char s[N];

int cnt[N],res[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        scanf("%s",s+1);
        if(n%k)
        {
            puts("-1");
            continue;
        }
        for(int i=0;i<26;i++)
            cnt[i]=0;
        for(int i=1;i<=n;i++)
            cnt[s[i]-'a']++;
        int ok=1;
        for(int i=0;i<26;i++)
            ok&=!(cnt[i]%k);
        if(ok)
        {
            puts(s+1);
            continue;
        }
        for(int i=n;i>=1;i--)
        {
            cnt[s[i]-'a']--;
            int fd=0;
            for(int j=s[i]-'a'+1;j<26;j++)
            {
                cnt[j]++;
                int sum=0;
                for(int t=0;t<26;t++)
                    if(cnt[t]%k)
                        sum+=k-cnt[t]%k,res[t]=k-cnt[t]%k;
                    else
                        res[t]=0;
                if(sum<=n-i)
                {
                    fd=1;
                    res[0]+=n-i-sum;
                    string ans;
                    for(int t=1;t<i;t++)
                        ans+=s[t];
                    ans+=j+'a';
                    for(int t=0;t<26;t++)
                        while(res[t])
                            ans+=t+'a',res[t]--;
                    cout<<ans<<endl;
                    break;
                }
                cnt[j]--;
            }
            if(fd)
                break;
        }
    }
}