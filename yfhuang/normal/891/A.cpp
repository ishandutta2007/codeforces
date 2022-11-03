//#include <cstdio>
//#include <algorithm>
//#include <iostream>
//#include <cstring>
//#include <cmath>
//using namespace std;
//typedef double db;
//const db eps = 1e-8;
//
//inline int sign(db a){
//	return a < -eps ? -1 : a > eps;
//}
//
//struct P{
//	db x,y,z;
//	P(){}
//	P(db _x,db _y,db _z):x(_x),y(_y),z(_z){}
//	P operator + (P p) {return P(x + p.x,y + p.y,z + p.z);}
//	P operator - (P p) {return P(x - p.x,y - p.y,z - p.z);}
//	P operator * (db d){return P(x * d,y * d,z * d);}
//	db abs(){
//		return sqrt(x * x + y * y + z * z);
//	}
//	void read(){
//		cin >> x >> y >> z;
//	}
//}p[4];
//db r[2];
//int main(){
//	p[0].read();
//	cin >> r[0];
//	p[1].read();
//	p[2].read();
//	cin >> r[1];
//	p[3].read();
//	P v = p[2] - p[0];
//	v = v * (r[0] / (r[0] + r[1]));
//	P d = p[0] + v;
//	db ans = 2.0 * asin((p[1] - d).abs() / 2 / r[0]) * r[0] + 2.0 * asin((p[3] - d).abs() / 2 / r[1]) * r[1];
//	printf("%.4lf\n",ans);
//	return 0;
//}
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 2005;
int a[maxn];
int n;
const int INF = 0x3f3f3f3f;
int gcd(int a,int b){
    return b == 0 ? a : gcd(b,a % b);
}
int main(){
    cin >> n;
    int num = 0;
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        if(a[i] == 1) num++;
    }
    if(num > 0){
        cout << n - num << endl;
        return 0;
    }
    int ans = INF;
    for(int i = 1;i <= n;i++){
        int tmp = a[i];
        for(int j = i;j <= n;j++){
            tmp = gcd(tmp,a[j]);
            if(tmp == 1){
                ans = min(ans,j - i + 1);
                break;
            }
        }
    }
    if(ans == INF){
        cout << -1 << endl;
        return 0;
    }
    cout << ans - 1 + n - 1 << endl;
    return 0;
}