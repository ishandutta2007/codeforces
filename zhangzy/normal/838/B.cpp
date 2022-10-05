#include<bits/stdc++.h>
using namespace std;

namespace fastIO{
    #define BUF_SIZE 100005
    #define OUT_SIZE 100005
    #define ll long long
    //fread->read
    bool IOerror=0;
    inline char nc(){
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if (p1==pend){
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if (pend==p1){IOerror=1;return -1;}
            //{printf("IO error!\n");system("pause");for (;;);exit(0);}
        }
        return *p1++;
    }
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
    inline void read(int &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(ll &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(double &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (ch=='.'){
            double tmp=1; ch=nc();
            for (;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0');
        }
        if (sign)x=-x;
    }
    inline void read(char *s){
        char ch=nc();
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        for (;!blank(ch)&&!IOerror;ch=nc())*s++=ch;
        *s=0;
    }
    inline void read(char &c){
        for (c=nc();blank(c);c=nc());
        if (IOerror){c=-1;return;}
    }
    //getchar->read
    inline void read1(int &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (bo)x=-x;
    }
    inline void read1(ll &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (bo)x=-x;
    }
    inline void read1(double &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (ch=='.'){
            double tmp=1;
            for (ch=getchar();ch>='0'&&ch<='9';tmp/=10.0,x+=tmp*(ch-'0'),ch=getchar());
        }
        if (bo)x=-x;
    }
    inline void read1(char *s){
        char ch=getchar();
        for (;blank(ch);ch=getchar());
        for (;!blank(ch);ch=getchar())*s++=ch;
        *s=0;
    }
    inline void read1(char &c){for (c=getchar();blank(c);c=getchar());}
    //scanf->read
    inline void read2(int &x){scanf("%d",&x);}
    inline void read2(ll &x){
        #ifdef _WIN32
            scanf("%I64d",&x);
        #else
        #ifdef __linux
            scanf("%lld",&x);
        #else
            puts("error:cant recognize the system!");
        #endif
        #endif
    }
    inline void read2(double &x){scanf("%lf",&x);}
    inline void read2(char *s){scanf("%s",s);}
    inline void read2(char &c){scanf(" %c",&c);}
    inline void readln2(char *s){gets(s);}
    //fwrite->write
    struct Ostream_fwrite{
        char *buf,*p1,*pend;
        Ostream_fwrite(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;}
        void out(char ch){
            if (p1==pend){
                fwrite(buf,1,BUF_SIZE,stdout);p1=buf;
            }
            *p1++=ch;
        }
        void print(int x){
            static char s[15],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1);
        }
        void println(int x){
            static char s[15],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1); out('\n');
        }
        void print(ll x){
            static char s[25],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1);
        }
        void println(ll x){
            static char s[25],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1); out('\n');
        }
        void print(double x,int y){
            static ll mul[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,
                1000000000,10000000000LL,100000000000LL,1000000000000LL,10000000000000LL,
                100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL};
            if (x<-1e-12)out('-'),x=-x;x*=mul[y];
            ll x1=(ll)floor(x); if (x-floor(x)>=0.5)++x1;
            ll x2=x1/mul[y],x3=x1-x2*mul[y]; print(x2);
            if (y>0){out('.'); for (size_t i=1;i<y&&x3*mul[i]<mul[y];out('0'),++i); print(x3);}
        }
        void println(double x,int y){print(x,y);out('\n');}
        void print(char *s){while (*s)out(*s++);}
        void println(char *s){while (*s)out(*s++);out('\n');}
        void flush(){if (p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}}
        ~Ostream_fwrite(){flush();}
    }Ostream;
    inline void print(int x){Ostream.print(x);}
    inline void println(int x){Ostream.println(x);}
    inline void print(char x){Ostream.out(x);}
    inline void println(char x){Ostream.out(x);Ostream.out('\n');}
    inline void print(ll x){Ostream.print(x);}
    inline void println(ll x){Ostream.println(x);}
    inline void print(double x,int y){Ostream.print(x,y);}
    inline void println(double x,int y){Ostream.println(x,y);}
    inline void print(char *s){Ostream.print(s);}
    inline void println(char *s){Ostream.println(s);}
    inline void println(){Ostream.out('\n');}
    inline void flush(){Ostream.flush();}
    //puts->write
    char Out[OUT_SIZE],*o=Out;
    inline void print1(int x){
        static char buf[15];
        char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x;
        while(x)*p1++=x%10+'0',x/=10;
        while(p1--!=buf)*o++=*p1;
    }
    inline void println1(int x){print1(x);*o++='\n';}
    inline void print1(ll x){
        static char buf[25];
        char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x;
        while(x)*p1++=x%10+'0',x/=10;
        while(p1--!=buf)*o++=*p1;
    }
    inline void println1(ll x){print1(x);*o++='\n';}
    inline void print1(char c){*o++=c;}
    inline void println1(char c){*o++=c;*o++='\n';}
    inline void print1(char *s){while (*s)*o++=*s++;}
    inline void println1(char *s){print1(s);*o++='\n';}
    inline void println1(){*o++='\n';}
    inline void flush1(){if (o!=Out){if (*(o-1)=='\n')*--o=0;puts(Out);}}
    struct puts_write{
        ~puts_write(){flush1();}
    }_puts;
    inline void print2(int x){printf("%d",x);}
    inline void println2(int x){printf("%d\n",x);}
    inline void print2(char x){printf("%c",x);}
    inline void println2(char x){printf("%c\n",x);}
    inline void print2(ll x){
        #ifdef _WIN32
            printf("%I64d",x);
        #else
        #ifdef __linux
            printf("%lld",x);
        #else
            puts("error:cant recognize the system!");
        #endif
        #endif
    }
    inline void println2(ll x){print2(x);printf("\n");}
    inline void println2(){printf("\n");}
    #undef ll
    #undef OUT_SIZE
    #undef BUF_SIZE
};

int n,q,u[404000],v[404000],w[404000],bak[404000];
struct R{
	int to,val,nex;
}r[202000];
int hea[202000],cnt=1;
int df1[202000],df2[202000],dft=0;
long long an,ans;

namespace D{
	long long d[202000];
	inline void RE(){
		memset(d,0,sizeof d);
	}
	inline void add(int x,int v){
		for (;x<=n;x+=x&(-x)) d[x]+=v;
	}
	inline void A(int st,int en,int val){
		add(st,val); add(en+1,-val);
	}
	inline long long Q(int x){
		long long t=0;
		for (;x>0;x-=x&-x) t+=d[x];
		return t;
	}
}

namespace tr{
	long long mn[808000],laz[808000];
	inline void D(int x){
		if (!laz[x]) return;
		mn[x<<1]+=laz[x];
		laz[x<<1]+=laz[x];
		mn[x<<1|1]+=laz[x];
		laz[x<<1|1]+=laz[x];
		mn[x]=min(mn[x<<1],mn[x<<1|1]);
		laz[x]=0;
	}
	inline void B(int x,int l,int r){
		laz[x]=0;
		if (l==r){
			mn[x]=D::Q(l)+bak[l];
			return;
		}
		int mid=(l+r)>>1;
		B(x<<1,l,mid);
		B(x<<1|1,mid+1,r);
		mn[x]=min(mn[x<<1],mn[x<<1|1]);
	}
	inline long long que(int x,int l,int r,int st,int en){
		if (st>en) return 10000000000000000;
		if (l==st&&r==en) return mn[x];
		D(x);
		int mid=(l+r)>>1;
		return min(
			que(x<<1,l,mid,max(st,l),min(en,mid)),
			que(x<<1|1,mid+1,r,max(st,mid+1),min(en,r))
		);
	}
	inline long long Q(int st,int en){
		return que(1,1,n,st,en);
	}
	inline void chg(int x,int l,int r,int st,int en,int val){
		if (st>en) return;
		if (l==st&&r==en){
			mn[x]+=val;
			laz[x]+=val;
			return;
		}
		D(x);
		int mid=(l+r)>>1;
		chg(x<<1,l,mid,max(st,l),min(en,mid),val);
		chg(x<<1|1,mid+1,r,max(st,mid+1),min(en,r),val);
		mn[x]=min(mn[x<<1],mn[x<<1|1]);
	}
	inline void C(int st,int en,int val){
		chg(1,1,n,st,en,val);
	}
}

inline void dfs(int x){
	df1[x]=++dft;
	for (int i=hea[x];i>0;i=r[i].nex) dfs(r[i].to);
	df2[x]=dft;
}

int main(){
	D::RE();
	fastIO::read(n);fastIO::read(q);
	int x,y,z;
	for (int i=1;i<n;i++){
		fastIO::read(u[i]);fastIO::read(v[i]);fastIO::read(w[i]);
		r[++cnt]=(R){v[i],w[i],hea[u[i]]}; hea[u[i]]=cnt;
	}
	dfs(1);
	for (int i=n;i<=n*2-2;i++){
		fastIO::read(u[i]);fastIO::read(v[i]);fastIO::read(w[i]);
		bak[df1[u[i]]]=w[i];
	}
	for (int i=1;i<n;i++){
		D::A(df1[v[i]],df2[v[i]],w[i]);
	}
	tr::B(1,1,n);
	
	for (int t;q--;){
		fastIO::read(t);fastIO::read(x);fastIO::read(y);
		if (t==1){
			if (x<n){
				D::A(df1[v[x]],df2[v[x]],y-w[x]);
				tr::C(df1[v[x]],df2[v[x]],y-w[x]);
				w[x]=y;
			}else{
				tr::C(df1[u[x]],df1[u[x]],y-bak[df1[u[x]]]);
				bak[df1[u[x]]]=y;
			}
		}else{
			if (df1[x]<=df1[y]&&df2[x]>=df2[y]){
				fastIO::println(D::Q(df1[y])-D::Q(df1[x]));
			}else{
				fastIO::println(tr::Q(df1[x],df2[x])-D::Q(df1[x])+D::Q(df1[y]));
			}
		}
	}
}