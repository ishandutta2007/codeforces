//
//  main.cpp
//  E
//
//  Created by  on 16/5/26.
//  Copyright  2016 . All rights reserved.
//

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 100000 + 5;
const int INF=0x3f3f3f3f;

int a[maxn];
char s[15];
int n,k,cnt;

int main()
{
    cnt = 0;
    scanf("%d%d",&n,&k);
    for(int i = 0;i <= n;i++)
    {
        scanf("%s",s);
        if(s[0] == '?') a[i] = INF;
        else
        {
            int flag = 0;
            if(s[0] == '-') flag = 1;
            for(int j = flag;s[j];j++)
                a[i] = a[i] * 10 + (s[j] - '0');
            if(flag)a[i] = - a[i];
            cnt++;
        }
    }
    if(k == 0)
    {
        if(a[0] < INF)printf("%s\n",(a[0] ? "No" : "Yes"));
        else printf("%s\n",(cnt & 1 ? "Yes" : "No"));
    }
    else
    {
        if(cnt < n + 1)printf("%s\n",((n + 1) & 1 ? "No" : "Yes"));
        else
        {
            long long now = 0;
            for(int i = n;i >= 0 && abs(now) < 1e18;i--)
                now = 1LL * now * k + a[i];
            printf("%s\n",(now ? "No" : "Yes"));
        }
    }
    return 0;
}