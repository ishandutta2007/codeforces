//#pragma GCC optimize("Ofast","inline")
#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
                    For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> pii;
LL read(){
    LL x=0,f=0;
    char ch=getchar();
    while (!isdigit(ch))
        f=ch=='-',ch=getchar();
    while (isdigit(ch))
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
const int N=55;
int n;
int a[N][N];
int Ask(int x0,int y0,int x1,int y1){
	cout<<"? "<<x0<<" "<<y0<<" "<<x1<<" "<<y1<<endl;
	fflush(stdout);
	int res;
	cin>>res;
	return res;
}
int main(){
	n=read();
	a[1][1]=1,a[n][n]=0;
	For(i,1,n)
		For(j,1,n){
			if (i==1&&j==1)
				continue;
			if ((i+j)&1)
				continue;
			if (i==n&&j==n)
				continue;
			if (j>=3)
				a[i][j]=a[i][j-2]^1^Ask(i,j-2,i,j);
			else if (i>=3)
				a[i][j]=a[i-2][j]^1^Ask(i-2,j,i,j);
			else
				a[i][j]=a[i-1][j-1]^1^Ask(i-1,j-1,i,j);
		}
	a[1][2]=0;
	a[2][3]=!Ask(1,2,2,3);
	a[2][1]=a[2][3]^1^Ask(2,1,2,3);
	a[3][2]=a[2][1]^1^Ask(2,1,3,2);
	For(i,1,n)
		For(j,1,n){
			if (i<=3&&j<=3)
				continue;
			if (~(i+j)&1)
				continue;
			if (j>=3)
				a[i][j]=a[i][j-2]^1^Ask(i,j-2,i,j);
			else if (i>=3)
				a[i][j]=a[i-2][j]^1^Ask(i-2,j,i,j);
			else
				a[i][j]=a[i-1][j-1]^1^Ask(i-1,j-1,i,j);
		}
	For(i,1,n)
		For(j,1,n){
			For(s,0,7){
				int t[4],x=i,y=j,flag=1;
				t[0]=a[x][y];
				For(q,0,2){
					if (s>>q&1)
						x++;
					else
						y++;
					if (x>n||y>n){
						flag=0;
						break;
					}
					t[q+1]=a[x][y];
				}
				if (!flag)
					continue;
				if (t[0]^t[2]^t[1]^t[3]^1){
					int tmp=a[i][j]^1^Ask(i,j,x,y)^a[x][y];
					For(i,1,n)
						For(j,1,n)
							if ((i+j)&1)
								a[i][j]^=tmp;
					puts("!");
					For(i,1,n){
						For(j,1,n)
							putchar('0'+a[i][j]);
						puts("");
					}
					fflush(stdout);
					return 0;
				}
			}
		}
	return 0;
}