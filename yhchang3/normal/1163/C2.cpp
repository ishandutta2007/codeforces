#include<bits/stdc++.h>
using namespace std;

struct Point{
	int x,y;
	Point(){}
	Point(int _x,int _y):x(_x),y(_y){}
	Point operator+(const Point& rhs)const{
		return Point(x+rhs.x,y+rhs.y);
	}
	Point operator-(const Point& rhs)const{
		return Point(x-rhs.x,y-rhs.y);
	}
	double operator/(const Point& rhs)const{
		return double (rhs.y-y)/double(rhs.x-x);
	}
}P[1000];

int cross(Point A,Point B){
	return A.x*B.y-A.y*B.x;
}

struct Line{
	Point p1,p2;
	bool operator<(const Line& rhs)const{
		if(p1.x==p2.x)
			return rhs.p1.x==rhs.p2.x?p1.x<rhs.p1.x:false;
		if(rhs.p1.x==rhs.p2.x)	return true;
		return p2/p1==rhs.p2/rhs.p1?p1.y-(p2/p1)*p1.x<rhs.p1.y-(rhs.p2/rhs.p1)*rhs.p1.x:p2/p1<rhs.p2/rhs.p1;
	}
	bool operator==(const Line& rhs)const{
		if(p1.x==p2.x&&rhs.p1.x==rhs.p2.x)	return true;
		return p2/p1==rhs.p2/rhs.p1;
	}
	bool on(const Point& rhs)const{
		return cross(rhs-p1,rhs-p2)==0;
	}
}L;

vector<Line> v;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>P[i].x>>P[i].y;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			L.p1=P[i],L.p2=P[j],v.emplace_back(L);
	sort(v.begin(),v.end());
	long long int ans=0;
	int now=0,tmp=1;
	for(int i=1;i<v.size();i++){
		if(v[i]==v[i-1])
			if(v[i-1].on(v[i].p1))
				continue;
			else
				tmp++;
		else
			now+=tmp,tmp=1;
		ans+=now;
	}
	cout<<ans<<endl;
}