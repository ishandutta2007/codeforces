#include<bits/stdc++.h>
using namespace std;


int X,Y;

int where(int x,int y){
	if(y==Y)
		return x<X;
	else
		return y<Y;
}
struct Point{
	int x,y;
	Point(int x_=0,int y_=0):x(x_),y(y_){}
	bool operator<(const Point& rhs)const{
		int w1=where(x,y),w2=where(rhs.x,rhs.y);
		if(w1==w2)
			return (long long int)(x-X)*(rhs.y-Y)>(long long int)(rhs.x-X)*(y-Y);
		else
			return w1<w2;
	}
}P[2500];

int v[5000];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	long long int ans=(long long int)(n-3)*(n-1)*(n-2)/6*n;
	for(int i=0;i<n;i++)
		cin>>P[i].x>>P[i].y;
	for(int i=0;i<n;i++){
		X=P[i].x,Y=P[i].y;
		int top=0;
		for(int j=0;j<n;j++)
			if(i!=j)
				v[top++]=j;
		sort(v,v+n-1,[&](int a,int b){return P[a]<P[b];});
		for(int j=n-1;j<2*(n-1);j++)
			v[j]=v[j-(n-1)];
		int rb=0;
		for(int j=0;j<n-1;j++){
			while(rb!=j+n-1&&(long long int)(P[v[j]].x-X)*(P[v[rb]].y-Y)>=(long long int)(P[v[j]].y-Y)*(P[v[rb]].x-X))	rb++;
			ans-=(long long int)(rb-j-1)*(rb-j-2)/2;
		}
	}
	cout<<ans*(n-4)/2<<endl;
}