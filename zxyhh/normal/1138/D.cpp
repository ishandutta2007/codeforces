/*
    >Author: zxy_hhhh
    >blog: zxy-hhhh.cn
    >date: 2019/03/08
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<ctime>
#define rep(x,a,b) for (int x=int(a);x<=(int)(b);x++)
#define drp(x,a,b) for (int x=int(a);x>=(int)(b);x--)
#define cross(x,a) for (int x=hd[a];x;x=nx[x])
#define ll long long
using namespace std;
inline ll rd() {
    ll _x=0;int _ch=getchar(),_f=1;
    for(;!isdigit(_ch)&&(_ch!='-')&&(_ch!=EOF);_ch=getchar());
    if (_ch=='-'){_f=-1;_ch=getchar();}
    for(;isdigit(_ch);_ch=getchar()) _x=_x*10+_ch-'0';
    return _f*_x;
}
void write(ll _x){if (_x>=10) write(_x/10),putchar(_x%10+'0'); else putchar(_x+'0'); }
inline void wrt(ll _x,char _p){if (_x<0) putchar('-'),_x=-_x; write(_x); if (_p) putchar(_p);}
char s1[500005],s2[500005];
int nx[500005];
int len1,len2;
inline void KMP()
{
    int j=0;
    for(int i=2;i<=len2;i++){
        while(j&&s2[j+1]!=s2[i]) j=nx[j];
        if (s2[j+1]==s2[i]) j++;
        nx[i]=j;
    }
}
int sum1,sum0,tm0,tm1,jp0,jp1;
char ans[500005];
int L;
int main() {
    scanf("%s",s1+1);
    scanf("%s",s2+1);
    len1=strlen(s1+1),len2=strlen(s2+1);
    rep(i,1,len1) sum1+=s1[i]=='1',sum0+=s1[i]=='0';
    KMP();
    rep(i,1,nx[len2]) 
        tm1+=s2[i]=='1',tm0+=s2[i]=='0';
    
    rep(i,nx[len2]+1,len2) 
        jp1+=s2[i]=='1',jp0+=s2[i]=='0';
    if (sum1>=tm1+jp1&&sum0>=tm0+jp0) {
        rep(i,1,len2) ans[++L]=s2[i];
        sum1-=tm1+jp1,sum0-=tm0+jp0;
    }
    while(sum1>=jp1&&sum0>=jp0) {
        rep(i,nx[len2]+1,len2) ans[++L]=s2[i];
        sum1-=jp1,sum0-=jp0;
    }
    printf("%s",ans+1);
    rep(i,1,sum1) putchar('1');
    rep(i,1,sum0) putchar('0');
}