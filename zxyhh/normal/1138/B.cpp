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
using namespace std;
#define maxn 50005
int b[maxn],c[maxn],d[maxn];
char s[maxn],t[maxn];
int n;
void OUT() {
    rep(i,1,n){
        if(d[b[i]]){
            wrt(i,' ');--d[b[i]];
        }
    }
    putchar('\n');
    exit(0);
}
int main(){
    n=rd();
    scanf("%s",s+1);
    scanf("%s",t+1);
	rep(i,1,n){
        if (s[i]=='1'&&t[i]=='0') b[i]=0;
        if (s[i]=='0'&&t[i]=='1') b[i]=1;
        if (s[i]=='1'&&t[i]=='1') b[i]=2;
        if (s[i]=='0'&&t[i]=='0') b[i]=3;
        c[b[i]]++;
    }
	bool flag=false;
	rep(i,0,c[0])
		rep(j,0,c[1])
			if(i+j<=n/2&&c[1]+c[2]-j-i>=0&&(c[1]+c[2]-j-i)%2==0){
				int k=(c[1]+c[2]-j-i)/2;
				if(k<=c[2]&&i+j+k<=n/2){
					d[0]=i;d[1]=j;d[2]=k;d[3]=n/2-i-j-k;
					if(d[3]<=c[3]) OUT();
				}
			}
    wrt(-1,'\n');
    return 0;
}