#include<bits/stdc++.h>
using namespace std;
const double eps=1e-10;
inline int dcmp(double x){return fabs(x)<eps?0:(x>0?1:-1);}
struct poi{
	double x,y;
	poi(double _x=0,double _y=0):x(_x),y(_y){}
	bool operator==(const poi&rhs){return !dcmp(x-rhs.x) && !dcmp(y-rhs.y);}
};
struct vec{
	double x,y;
	vec(double _x=0,double _y=0):x(_x),y(_y){}
	double len(){return sqrt(x*x+y*y);}
	vec operator*(double k){return vec(x*k,y*k);}
	vec fa(){return vec(y,-x);}
};
vec operator-(const poi&a,const poi&b){return vec(a.x-b.x,a.y-b.y);}
poi operator+(const poi&a,const vec&b){return poi(a.x+b.x,a.y+b.y);}
poi operator+(const vec&a,const poi&b){return poi(a.x+b.x,a.y+b.y);}
double area(double x,double y,double z){
	double p=(x+y+z)/2;
	return sqrt(p*(p-x)*(p-y)*(p-z));
}
struct circle{
	double x,y,r;
	inline void in(){cin>>x>>y>>r;}
	vector<poi> operator&(const circle&rhs){
		poi o1(x,y),o2(rhs.x,rhs.y);
		double d=(o1-o2).len(),r1=r,r2=rhs.r;if(r1>r2)swap(r1,r2),swap(o1,o2);
		vector<poi>ans;ans.clear();
		if(d==r1+r2)ans.push_back((o2-o1)*(r1*1.0/d)+o1);
		if(d==r2-r1)ans.push_back((o1-o2)*(r2*1.0/d)+o2);
		if(r2-r1<d && d<r2+r1){
			double h=area(r1,r2,d)*2/d,w=sqrt(r2*r2-h*h);
			vec u=o1-o2,v=u.fa();v=v*(h/v.len());u=u*(w/u.len());
			ans.push_back(o2+u+v);ans.push_back(o2+u+v*-1);
		}
		return ans;
	}
}c[3];
int ans=1,n,i,j,f[3],k;
bool cmp(const poi&a,const poi&b){return dcmp(a.x-b.x)==-1 || (dcmp(a.x-b.x)==0 && dcmp(a.y-b.y)==-1);}
vector<poi>a,b,v;
int gfa(int x){return f[x]==x?x:f[x]=gfa(f[x]);}
inline int S(vector<poi>v){
	sort(v.begin(),v.end(),cmp);
	v.erase(unique(v.begin(),v.end()),v.end());
	return v.size();
}
int main(){
	cin>>n;for(i=0;i<n;++i)c[i].in(),f[i]=i;
	for(i=0;i<n;++i){
		v.clear();
		for(j=0;j<n;++j)if(i!=j){
			b=c[i]&c[j];
			if(b.size()){
				f[gfa(i)]=gfa(j);
				a.insert(a.end(),b.begin(),b.end());
				v.insert(v.end(),b.begin(),b.end());
			}
		}
		ans+=S(v);
	}
	ans-=S(a);
	for(i=0;i<n;++i)ans+=gfa(i)==i;printf("%d\n",ans);
	return 0;
}