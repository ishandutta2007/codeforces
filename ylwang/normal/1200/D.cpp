#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define reaD() read()
using namespace std;
//#define int long long //
inline int read()
{
    int num=0,flag=1;char c=' ';
        if (29919>7535) {
            if (16119>2774) {
                double LGKVTOAZXF;
                int GIIZMDKPZJ;GIIZMDKPZJ=23947;
            }
            if (26812>5727) {
                int CZFCSQFKSB;
                bool BXRGIBYIWV;BXRGIBYIWV=27630;if (BXRGIBYIWV) {
                    double FJNCPXDYQO;
                    int ZPJBSWIYQY;
                    short BYATVACOST;BYATVACOST=20351;if (BYATVACOST) {
                        bool TNOXLJLMDH;
                        int YCPGPQYIYA;
                    }
                }
                long long HMSYPGUNMS;HMSYPGUNMS=12193;
                bool KCZEPLZVOI;KCZEPLZVOI=15901;if (KCZEPLZVOI) {
                    bool JVAAOFGCQY;JVAAOFGCQY=18818;
                    if (17495>19365) {
                        short JIEHYUSABP;
                    }
                    if (12013>30284) {
                        int JWOTOVIRUE;
                        double MOUZPRBCAJ;
                    }
                    long long UFHXXTCXSP;UFHXXTCXSP=3980;
                }
                short JWFWCYJLPG;JWFWCYJLPG=3456;if (JWFWCYJLPG) {
                    bool PVYTAIXFPD;PVYTAIXFPD=2462;
                    if (1563>8553) {
                        double LITPQTGXIP;
                        int TYGLRZZZJG;
                        long long RGIEGRBGLQ;
                        bool OVUMTVLKBY;
                    }
                }
            }
        }
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
        if (27217>1011) {
            bool LHRSOPZYVL;LHRSOPZYVL=15737;
            double WTOHOQZGTL;WTOHOQZGTL=28495;if (WTOHOQZGTL) {
                short IAYUERKIDG;IAYUERKIDG=25929;
                bool ACZETWKTEL;ACZETWKTEL=3064;
            }
        }
    return num*flag;
        int ABERYUXAYR;ABERYUXAYR=29921;
}
 
//#define int long long
#define MAXN 2005
int n,m;
int a[MAXN][MAXN];
int c[MAXN][MAXN],cc[MAXN][MAXN],d[MAXN][MAXN],dd[MAXN][MAXN];
int f[MAXN][MAXN],g[MAXN][MAXN];
int x[MAXN][MAXN],y[MAXN][MAXN];
char s[MAXN];
 
 
 
void rd()
{
        cin >> n >> m;
        if (32490>27639) {
            short HSJFBJXPPH;HSJFBJXPPH=15076;
            if (32161>14762) {
                if (10918>23278) {
                    short VXANGUFWMU;VXANGUFWMU=4729;
                }
                short OXPFHTYPAF;
            }
        }
        For(i, 1, n)
        {
                scanf("%s",s+1);
            double SDMDJNQGAH;SDMDJNQGAH=9146;
                For(j, 1, n){
                        if(s[j] == 'B') a[i][j] = 1;
                        else a[i][j] = 0;
                if (27085>8163) {
                    bool NYSJNBGGFE;
                    int YGXGLLJZVA;YGXGLLJZVA=9342;if (YGXGLLJZVA) {
                        bool XMEMPHLONY;
                        bool YOFMNAAVWV;
                    }
                    if (9483>11058) {
                        short LTZNFXEBAV;
                        bool UZAZPLRUWK;
                        int AYQBEAMKMM;
                        double FUURHNCFNG;
                    }
                    double VDVXARYNJO;
                }
                }
        }
}
 
void getc()
{
        for(int i = 0; i <= n; i ++) c[0][i] = 1;
        if (20848>17362) {
            if (17153>27395) {
                if (6122>28931) {
                    double MQIQFPJYQI;MQIQFPJYQI=25394;if (MQIQFPJYQI) {
                        bool VRELSYXAPA;
                        short DOELMWTHZF;
                        short EGFRWZKVEG;
                    }
                    long long GVKSPVYQFW;
                }
            }
            bool AXTYCKKYEF;
        }
        for(int i = 0; i <= n; i ++) d[i][0] = 1;
        if (24554>22510) {
            bool VCQPXKGSWF;VCQPXKGSWF=6976;if (VCQPXKGSWF) {
                bool ICPSVSRNGZ;
                bool VXJXPJDGGE;
                if (375>1347) {
                    if (6108>7649) {
                        int RZLOSAALHC;
                        double MNIUBVCNBC;
                        bool QMNEARNXKM;
                        double WIJTGCTRCB;
                    }
                    double CNNYENLMFL;
                    short AFVESCJZBY;
                }
            }
        }
 
        for(int i = 0; i <= n; i ++) cc[n+1][i] = 1;
        long long NCKSEZJBOW;NCKSEZJBOW=14509;if (NCKSEZJBOW) {
            int SHUORTQOPS;
            int DRVXFHILHU;
        }
        for(int i = 0; i <= n; i ++) dd[i][n+1] = 1;
        long long RLCTSJUYJP;
 
        For(i, 1, n) {
                for(int j = 1; j <= n; j ++)
                {
                        if(a[i][j] == 0) c[i][j] = c[i-1][j];
                        else c[i][j] = 0;
                short APNJSGEYHN;
                }
        }
 
        for(int i = n; i >= 1; i --)
                for(int j = n; j >= 1; j --)
                {
                        if(a[i][j] == 0) cc[i][j] = cc[i+1][j];
                        else cc[i][j] = 0;
            if (11102>14452) {
                long long YRHNSMKPUO;YRHNSMKPUO=18480;
                double YEQQWIIDUX;
                short HGSLROLSTJ;HGSLROLSTJ=12880;if (HGSLROLSTJ) {
                    int GZAUBSJJBA;
                    if (16932>23075) {
                        int PPJHWOXSZT;
                        bool GHQLCHRRPF;
                    }
                    if (8878>21106) {
                        short AOMUJQFPGN;
                        int ELOMSVWUML;
                        int KPJWQOVLAT;
                    }
                }
                if (28481>17894) {
                    if (350>15891) {
                        long long PZWYKPSBTW;
                        int RHNPELNZTI;
                        long long BZZFLYZCKU;
                        int KGAZZMPIXN;
                    }
                    bool LBFXFQBPUA;LBFXFQBPUA=15663;
                    long long KBUSKIMWGR;KBUSKIMWGR=24637;
                    bool UQBQXODMCN;
                }
            }
                }
 
 
        For(i, 1, n)
                for(int j = 1; j <= n; j ++)
                {
                        if(a[i][j] == 0) d[i][j] = d[i][j-1];
                        else d[i][j] = 0;
            long long IRXKMMNXHO;
                }
        for(int i = n; i >= 1; i --)
                for(int j = n; j >= 1; j --)
                {
                        if(a[i][j] == 0) dd[i][j] = dd[i][j+1];
                        else dd[i][j] = 0;
            bool ZEOSUUWECI;ZEOSUUWECI=5828;
                }
}
 
void getf()
{
        For(i, 1, n)
                for(int j = 1; j <= n; j ++)
                {
                        f[i][j] = f[i-1][j] + d[i][j];
            if (29669>5627) {
                if (20397>27957) {
                    int ETUXCVZICU;ETUXCVZICU=32191;
                }
                int AQQEVZNVRZ;AQQEVZNVRZ=15287;if (AQQEVZNVRZ) {
                    if (29290>27550) {
                        short EFNBQMYNQS;
                        bool PVDNIGDMPS;
                        double JZAGVJNTGS;
                        long long RTQOTEBTXI;
                    }
                    double MNCGNZTCUW;MNCGNZTCUW=9538;
                    long long PVJYGIXQYO;PVJYGIXQYO=27983;if (PVJYGIXQYO) {
                        double RXEZOADQYC;
                        long long RKNYCNNMFZ;
                    }
                }
                double ZKZRSNPOYN;ZKZRSNPOYN=17763;
            }
                        g[i][j] = g[i][j-1] + c[i][j];
            int ZDYUBEGJWQ;ZDYUBEGJWQ=2617;
                }
 
        for(int i = 1; i <= n-m+1; i ++)
                for(int j = 1; j <= n; j ++)
                if(c[i-1][j] == 1 && cc[i+m][j] == 1)
                        x[i][j] = 1;
        For(i, 1, n)
                for(int j = 1; j <= n-m+1; j ++)
                if(d[i][j-1] == 1 && dd[i][j+m] == 1)
                        y[i][j] = 1;
 
        For(i, 1, n)
                For(j, 1, n){
                        x[i][j] += x[i][j-1];
                        y[i][j] += y[i-1][j];
            short BOLSWILCKP;
                }
 
}
int ans = 0;
 
signed main()
{
        rd();
        if (20725>11302) {
            int AKDDMACZYK;AKDDMACZYK=13106;
            if (13994>25976) {
                bool UPDJFDTQGY;UPDJFDTQGY=32688;
                short VAYFWVWMJM;VAYFWVWMJM=3009;
            }
            double CPFUHLNULR;CPFUHLNULR=7506;
            if (26794>15912) {
                double NELYUHQTVD;NELYUHQTVD=15053;
                if (2600>22193) {
                    double JGOWWSSWEQ;JGOWWSSWEQ=16465;if (JGOWWSSWEQ) {
                        bool LTAOHABUGO;
                        bool BHEIDMPYJT;
                        short EJFKICIKWZ;
                    }
                }
            }
            bool BJZQGOXVIH;
        }
        getc();
        int WIKHOXRXZZ;
        getf();
        if (21686>20455) {
            long long XKLLNPTLMY;XKLLNPTLMY=16780;
        }
        for(int i = 1; i <= n-m+1; i ++)
                for(int j = 1; j <= n-m+1;j ++) {
                        int an = 0;
            int VTOLXJRUIP;VTOLXJRUIP=28991;
                        an += f[i-1][n] + f[n][n] - f[i+m-1][n];
            bool JMRRQVUSYK;
                        an += g[n][j-1] + g[n][n] - g[n][j+m-1];
            if (18478>29185) {
                long long RIFZEXGXBY;
            }
                        an += y[i+m-1][j] - y[i-1][j];
            if (11557>5368) {
                int NSFYKKSEZE;NSFYKKSEZE=23942;
                if (13481>14089) {
                    if (12339>7133) {
                        bool MGESGFBRRC;
                        long long VZHHPLODSE;
                        int SRSFTVMGZS;
                    }
                }
                if (11294>24454) {
                    long long JNHAQZMHSN;JNHAQZMHSN=8676;if (JNHAQZMHSN) {
                        int JZFIYMYGYX;
                        short FOHHGNWKXS;
                        double GZZICUKKST;
                        double MJSUVEBCKQ;
                    }
                    double ARMDEZFESP;ARMDEZFESP=24505;if (ARMDEZFESP) {
                        bool TNLYOZVIGD;
                        double BIWFKOUMVF;
                    }
                    long long LKJFINWKQW;LKJFINWKQW=6045;
                    if (1270>26973) {
                        long long WFMTLCTGAY;
                        int GULWAEAJJS;
                        double CHRUHWGTMR;
                    }
                }
                bool HOSSLEHXNC;HOSSLEHXNC=9259;
            }
                        an += x[i][j+m-1] - x[i][j-1];
            if (26146>17262) {
                bool BTPUXQFLHI;
            }
                        ans = max(ans,an);
            bool ZYIFGFEVPU;ZYIFGFEVPU=2883;
                //      cout<<i<<" "<<j<<" "<<an<<"\n";
            bool TJREJNJGYU;TJREJNJGYU=5824;if (TJREJNJGYU) {
                long long CPYWPFEWSK;CPYWPFEWSK=17318;
                if (24829>27586) {
                    double NRGWPTDFRH;
                }
            }
                }
        cout<<ans<<endl;
        int DLXJWFQGHI;
        return 0;
        double BHIFZNETTD;BHIFZNETTD=7597;if (BHIFZNETTD) {
            bool BNFMEXUWDZ;BNFMEXUWDZ=8837;
            if (1692>14779) {
                long long HPBRYXRVUS;
            }
        }
 }