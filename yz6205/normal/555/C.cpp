#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

#ifdef __LOCALE__
#define see(a) std::cout << #a << "=" << a << std::endl
#else
#define see(a) //std::cout << #a << "=" << a << std::endl
#endif
#define foreach(a,b) for (int a=0;a<(int)b.size();a++)
#define rep(i,n) for (int i=0;i<n;i++)
#define repa(i,n) for (int i=1;i<=n;i++)
#define repi(i,a,b) for (int i=a;i<=b;i++) 
typedef pair < int , int > Point;

struct Node {
    int s , e;
    int u , l;
    Node () {}
    Node (int s , int e , int u , int l) : s(s) , e(e) , u(u) , l(l) {}
    friend bool operator < (const Node A , const Node B) {
        return A.s == B.s ? ( A.e == B.e ? (A.u == B.u ? A.l < B.l : A.u < B.u) : A.e < B.e ) : A.s < B.s;
    }   
};

int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    Node inital = Node (1 , n , n , n);
    set < Node > st;
    set < int > isQ;
    st.insert (inital);
    rep (i,q) {
        int a , b ;
        char  opt;
        cin >> a >> b >> opt;

        if (isQ.count(a)) {
            puts("0");
            continue;
        }
        isQ.insert(a);
        
        set < Node > :: iterator it = st.upper_bound ( Node(a,0x3f3f3f3f,0,0) );
        --it;
        Node pos = *it;
        int s = pos.s , e = pos.e , u = pos.u , l = pos.l;
        st.erase(it);

        if (opt == 'U') {
            printf("%d\n",u - (a - s));
            if (a != s) st.insert ( Node ( s , a - 1 , u , l - (e - a + 1)) );
            if (a != e) st.insert ( Node ( a + 1 , e , u - (a - s + 1) , e - a) );
        }
        if (opt == 'L') {
            printf("%d\n",l - (e - a));
            if (a != s) st.insert ( Node ( s , a - 1 , a - s , l - (e - a + 1)) );
            if (a != e) st.insert ( Node ( a + 1 , e , u - (a - s + 1) , l) );
        }   
    }
    return 0;
}