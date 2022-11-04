#include<cstdio>
using namespace std;
typedef long long ll;
const int N=1001000,P=1000000007;
int i,j,k,n,m,ch,ff,sum,tmp,ans;
ll tot;
struct cc {
	int x,y;
	ll operator * (const cc &n) const {
		return (ll) x*n.y-(ll) n.x*y;
	}
} A[N];
ll sx[N],sy[N],s1[N],s2[N];
void R(int &x) {
	ff=x=0;ch=getchar();
	while (ch<'0' || '9'<ch) { if (ch=='-') ff=1;ch=getchar();}
	while ('0'<=ch && ch<='9') x=x*10+ch-'0',ch=getchar();
	if (ff) x=-x;
}
int main() {
	R(n);
	for (i=n;i;i--) R(A[i].x),R(A[i].y);
	for (i=1;i<=n;i++) A[n+i]=A[i];
	for (i=1;i<=n;i++) tot+=A[i]*A[i+1];
	for (i=1;i<=n;i++) {
		sx[i]=sx[n+i]=A[i].x;
		sy[i]=sy[n+i]=A[i].y;
		s1[i]=s1[n+i]=A[i]*A[i+1];
	}
	m=n+n;
	for (i=1;i<m;i++) s2[i]=(s1[i]%P*(m-i)%P+P)%P;
	for (i=1;i<m;i++) {
		sx[i]+=sx[i-1];
		sy[i]+=sy[i-1];
		s1[i]+=s1[i-1];
		s2[i]+=s2[i-1];
		sx[i]=(sx[i]%P+P)%P;
		sy[i]=(sy[i]%P+P)%P;
		s2[i]%=P;
	}
	j=1;
	for (i=1;i<=n;i++) {
		while (j+1<n+i) {
			if (j+1<=n)	{
				if (s1[j]-s1[i-1]+A[j+1]*A[i]<=tot/2) j++;
				else break;
			}
			else {
				if (s1[j]-s1[i-1]+A[j+1]*A[i]<=(tot-1)/2) j++;
				else break;
			}
		}
		tmp=((s2[j-1]-s2[i-1])-(s1[j-1]-s1[i-1])%P*(m-j))%P;
		tmp=(tmp+P)%P;
		tmp=((ll) (P+A[i].y)*(sx[j]+P-sx[i-1])-(ll) (P+A[i].x)*(sy[j]+P-sy[i-1])+tmp)%P;
		tmp=(tmp+P)%P;
		sum=(tmp+sum)%P;
	}
	sum=(sum+sum)%P;
	ans=(ll) n*(n-3)/2%P*(tot%P)%P;
	ans=(ans+P)%P;
	ans=(ans+P-sum)%P;
	printf("%d\n",ans);
}