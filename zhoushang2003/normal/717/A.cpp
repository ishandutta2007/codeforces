#include<bits/stdc++.h>
using namespace std;
const int N=201,D=1e9+7,U=5e8+4,V=4e8+3;
long long t,k,l,r,C[N][N],S[N][N],f,A;
int Q(long long a,int b)
{
	t=1;
	while(b)
	{
		if(b&1)
			(t*=a)%=D;
		(a*=a)%=D,b/=2;
	}
	return t;
}
struct T
{
	long long x,y;
	T(const int X=0,const int Y=0):x(X),y(Y){}
	T operator+(const T &c)const
	{
		return T((x+c.x)%D,(y+c.y)%D);
	}
	T operator-(const T &c)const
	{
		return T((x-c.x+D)%D,(y-c.y)+D%D);
	}
	T operator*(const T &c)const
	{
		return T((x*c.x+5*y*c.y)%D,(x*c.y+y*c.x)%D);
	}
	T V()const
	{
		T A(x,D-y);
		return A*Q(((x*x-5*y*y)%D+D)%D,D-2);
	}
	T operator/(const T &c)const
	{
		return *this*c.V();
	}
	bool operator==(const T &c)const
	{
		return x==c.x&&y==c.y;
	}
};
T a(0,V),b(0,D-V),x(U,U),y(U,D-U);
T P(T a,long long b)
{
	T t(1,0);
	while(b)
	{
		if(b&1)
			t=t*a;
		a=a*a,b/=2;
	}
	return t;
}
T F(T x,long long l,long long r)
{
	if(x==1)
		return (r-l+1)%D;
	return (P(x,r+1)-P(x,l))/(x-1);
}
int main()
{
	cin>>k>>l>>r,S[1][1]=f=1;
	for(int i=2;i<=k;i++)
		for(int j=1;j<=i;j++)
			S[i][j]=((i-1)*S[i-1][j]+S[i-1][j-1])%D;
	for(int i=0;i<=k;i++)
		C[i][0]=1;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%D;
	for(int i=1;i<=k;i++)
		(f*=i)%=D;
	for(int i=0;i<=k;i++)
		for(int j=0;j<=i;j++)
			(A+=Q(-1,k-i)*S[k][i]*C[i][j]%D*(P(a,j)*P(b,i-j)*F(P(x,j)*P(y,i-j),l+2,r+2)).x)%=D;
	cout<<Q(f,D-2)*(A+D)%D;
	return 0;
}