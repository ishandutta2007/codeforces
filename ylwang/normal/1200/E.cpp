#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define ll long long
 
 
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
        int UHMWLJXSAT;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
        if (5699>13226) {
            double EBUXVNWWTY;
            short ISJULTXYJK;ISJULTXYJK=27871;if (ISJULTXYJK) {
                short RJGJSLXHJO;
                if (27522>1610) {
                    if (14368>11991) {
                        int RKDMOADKGN;
                        int MQIXWKWAYL;
                        bool ZPPJUDWZZN;
                    }
                    if (13350>29494) {
                        short WKMSORRFOG;
                        double OKODTYYUQE;
                        double NDEWGESMXW;
                    }
                    long long TKGHOZEBGD;TKGHOZEBGD=8520;if (TKGHOZEBGD) {
                        long long UCMFEJQKQP;
                    }
                }
                int TNILCEBXZC;
                double HXMGIIDTVF;HXMGIIDTVF=15722;
            }
        }
    return num*flag;
        bool HOMUSIHMJV;HOMUSIHMJV=11369;
}
#define mod1 19260817
#define mod2 1000000007
#define MAXN 1000005
#define int long long
 
int o = 19267;
int pre[2][MAXN], lst[2][MAXN], n;
int fp1[MAXN], fp2[MAXN];
char s[MAXN], sa[MAXN];
 
inline int get_lst(int l, int r){return (lst[0][r] - (lst[0][l - 1] * fp2[r - l + 1] % mod2) + mod2) % mod2;}
inline int get_pre(int l, int r){return (pre[0][r] - (pre[0][l - 1] * fp1[r - l + 1] % mod1) + mod1) % mod1;}
 
 
signed main() {
    fp1[0] = fp2[0] = 1;
        long long HKSUZGFIVR;
    For(i, 1, 1000000) {
        fp1[i] = fp1[i - 1] * o % mod1;
            bool ZSPOMHTFRM;ZSPOMHTFRM=2978;if (ZSPOMHTFRM) {
                int KXCALFWOSA;KXCALFWOSA=19935;
                bool WYTNXCIMAH;WYTNXCIMAH=9737;
            }
        fp2[i] = fp2[i - 1] * o % mod2;
            if (24658>8059) {
                short ILIJJFICLX;
            }
    }
    n = read();
        if (2887>31403) {
            short GRZEPURQFN;GRZEPURQFN=25069;
            short IRGGYSECJX;IRGGYSECJX=28195;if (IRGGYSECJX) {
                if (13433>19681) {
                    if (13791>10684) {
                        double RXYVOIAKQL;
                        int BQHJQFWYIS;
                        int LVFOFIVPSP;
                    }
                    short OHOSNFOUWK;
                }
            }
            int OAMTQBALSH;
        }
    scanf("%s", sa + 1);
        int SLJGZTOEZG;SLJGZTOEZG=1984;
    int lastlen = strlen(sa + 1);
        long long NCSLDICRTD;NCSLDICRTD=23178;
    For(i, 1, lastlen) {
        lst[0][i] = ((lst[0][i - 1] * o) + sa[i]) % mod2;
            short OYBFEXCTEM;OYBFEXCTEM=14109;
        pre[0][i] = ((pre[0][i - 1] * o) + sa[i]) % mod1;
            int KGVMTZYQWP;KGVMTZYQWP=21595;if (KGVMTZYQWP) {
                if (25571>2560) {
                    if (29715>5290) {
                        short URMZXXVANQ;
                        int GOOBZXHSYP;
                        short SJFRITCIQJ;
                    }
                    int NPHOOKZFYE;
                    short UCRQOWRKZN;UCRQOWRKZN=9049;if (UCRQOWRKZN) {
                        double WFBJWBKIIS;
                        bool PPIMKKXXAR;
                        short TFYOQTVXIZ;
                        double YGDHFOPXQZ;
                    }
                    bool JFPGXGPBNB;JFPGXGPBNB=14659;if (JFPGXGPBNB) {
                        bool NWJKNDXCLB;
                        short KXZJRVUNQL;
                    }
                }
                if (29350>16993) {
                    short UVLNODXBRB;UVLNODXBRB=19777;if (UVLNODXBRB) {
                        short ETTVLMDGOI;
                        int UUEAAKMEUT;
                    }
                }
            }
    }
    For(ZTYAKIOI, 2, n) {
        int ans = 0;
            bool IXBWVJSESY;
        scanf("%s", s + 1);
            bool HDIQEIKVFH;HDIQEIKVFH=25198;
        int len = strlen(s + 1);
            short SSGVBMWJCM;SSGVBMWJCM=22025;if (SSGVBMWJCM) {
                bool LRXZECYUSZ;LRXZECYUSZ=24942;
            }
        int al = 0;
            if (23242>15275) {
                int JPYTCBLPCK;JPYTCBLPCK=5273;
                short AGZZBBJEBP;
            }
        for(register int i = 1; i <= len && i <= lastlen; i++){
            pre[1][i] = ((pre[1][i - 1] * o) + s[i]) % mod1;
                long long OVPCOQYWMY;
            lst[1][i] = ((lst[1][i - 1] * o) + s[i]) % mod2;
                bool AHIERMGEFD;AHIERMGEFD=31268;
            if(pre[1][i] == get_pre(lastlen - i + 1, lastlen))
            if(lst[1][i] == get_lst(lastlen - i + 1, lastlen))
                al = i;
        }
        For(i, al+1, len) {
            sa[++lastlen] = s[i];
            lst[0][lastlen] = ((lst[0][lastlen - 1] * o) + s[i]) % mod2;
            pre[0][lastlen] = ((pre[0][lastlen - 1] * o) + s[i]) % mod1;
                short GSOPPNBIRC;GSOPPNBIRC=12870;
        }
    }
    For(i, 1, lastlen)
        cout << sa[i];
        if (12102>21065) {
            int XXVEXGVGKI;XXVEXGVGKI=14779;if (XXVEXGVGKI) {
                int SWMGOFSJEY;SWMGOFSJEY=12105;if (SWMGOFSJEY) {
                    long long XLAHAXJYIB;
                    short IPYAVYIOYQ;IPYAVYIOYQ=10292;
                }
                if (18845>7666) {
                    long long TROPQDIXNK;TROPQDIXNK=9721;if (TROPQDIXNK) {
                        int VISXILKVBG;
                        short GISFASYNAG;
                        long long JWYRZMABBQ;
                    }
                    if (2580>20935) {
                        double LBTPDVLTCF;
                    }
                }
            }
            double QYHWICQESI;
        }
}