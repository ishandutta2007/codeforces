#include<bits/stdc++.h>
#define inf 5202333
#define pii pair<int,int>
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

int n,L,R,bas[101000],now,ht[101000],totht=0,die[101000]={0},sz[101000],an1,an2;
vector<pii>r[101000],ch[101000];

inline void S(int x,int fff){
	int y;
	sz[x]=1;
	for (int i=0;i<(int)r[x].size();i++){
		y=r[x][i].first; if (y==fff||die[y]) continue;
		S(y,x);
		sz[x]+=sz[y];
	}
}

inline int FH(int x,int fff,int totsz){
	int y;
	for (int i=0;i<(int)r[x].size();i++){
		y=r[x][i].first; if (y==fff||die[y]) continue;
		if (sz[y]*2>=totsz) return FH(y,x,totsz);
	}
	return x;
}

bool cmp(pii p1,pii p2){
	return sz[p1.first]<sz[p2.first];
}

inline void ddd(int x){
	ht[++totht]=x;
	die[x]=1;
	int y;
	for (int i=0;i<(int)r[x].size();i++){
		y=r[x][i].first; if (die[y]) continue;
		ch[x].push_back(r[x][i]);
	}
	S(x,0);
	sort(ch[x].begin(),ch[x].end(),cmp);
	for (int i=0;i<(int)ch[x].size();i++){
		y=ch[x][i].first;
		ddd(FH(y,x,sz[y]));
	}
}

int v[101000],mx[101000],d;
int vid[101000],mxid[101000];
inline int pre(int x,int fff,int dep){
	int y,t=dep;
	for (int i=0;i<(int)r[x].size();i++){
		y=r[x][i].first; if (y==fff||die[y]) continue;
		t=max(t,pre(y,x,dep+1));
	}
	return t;
}

inline void dfs(int x,int fff,int dep,int val){
	if (val>v[dep]){
		v[dep]=val;
		vid[dep]=x;
	}
	int y;
	for (int i=0;i<(int)r[x].size();i++){
		y=r[x][i].first; if (y==fff||die[y]) continue;
		dfs(y,x,dep+1,val+(r[x][i].second>=now?1:-1));
	}
}

int q[101000],he,ta,p1,p2,aim1,aim2;
inline void add(int v){
	while (he<ta&&v>q[ta-1]) ta--;
	q[ta++]=v;
}
inline void del(int v){
	if (q[he]==v) he++;
}

inline bool C(int x){
	//printf("%d(%d)--\n",x,now);
	int thed=0,y,est;
	est=pre(x,0,0);
	for (int i=0;i<=est;i++) mx[i]=-inf;
	for (int i=0;i<(int)ch[x].size();i++){
		y=ch[x][i].first;
		d=pre(y,x,1);
		for (int j=0;j<=d;j++) v[j]=-inf;
		dfs(y,x,1,ch[x][i].second>=now?1:-1);
		//printf(" %d::",y,now);for (int j=1;j<=d;j++) printf(" %d",v[j]);printf("\n");
		
		he=ta=0;
		p1=p2=1;
		for (int j=min(d,R);j>0;j--){
			if (j>=L&&j<=R) {
				if (v[j]>=0){
					an1=vid[j]; an2=x;
					return 1;
				};
			}
			aim1=max(1,L-j); aim2=min(thed,R-j);
			if (aim1>aim2) continue;
			while (p2<=aim2) add(mx[p2++]);
			while (p1<aim1) del(mx[p1++]);
			if (he<ta&&v[j]+q[he]>=0){
				an1=vid[j];
				for (an2=p1;mx[an2]!=q[he];an2++);
				an2=mxid[an2];
				return 1;
			}
		}
		
		thed=max(thed,d);
		for (int i=1;i<=thed;i++){
			if (v[i]>mx[i]){
				mx[i]=v[i];
				mxid[i]=vid[i];
			}
		}
	}
	return 0;
}

inline bool doit(){
	memset(die,0,sizeof die);
	for (int i=1;i<=n;i++){
		if (C(ht[i])) return 1;
		die[ht[i]]=1;
	}
	return 0;
}

bool bigger(int x,int y){
	return x>y;
}

int main(){
	fastIO::read(n);fastIO::read(L);fastIO::read(R);
	if (n==2) return 0*printf("1 2\n");
	int x,y,z;
	for (int i=1;i<n;i++){
		fastIO::read(x);fastIO::read(y);fastIO::read(z);
		r[x].push_back((pii){y,z});
		r[y].push_back((pii){x,z});
		bas[i]=z;
	}
	S(1,0);
	ddd(FH(1,0,sz[1]));
	
	sort(bas+1,bas+n,bigger);
	int l,r,mid;
	for (l=1,r=n-1;l<r;doit()?r=mid:l=mid+1) now=bas[mid=l+r>>1];
	printf("%d %d\n",an1,an2);
	//printf("%d",bas[l]);
}