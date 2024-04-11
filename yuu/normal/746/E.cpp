#include <stdio.h>
#include <locale>
template <typename T> inline void read(T &x){
    char c;
    while(!isdigit(c=getchar()));
    x=c-48;
    while(isdigit(c=getchar()))
        x=x*10+c-48;
}
template <typename T> inline void write(T x){
    if(x>9) write(x/10);
    putchar(x%10+48);
}

#include <algorithm>
#include <deque>
using namespace std;
struct card{
    int v, pos;
} c[200001];
int n, m, h;
deque <int> odd, even, del;
bool cmp(card a, card b){
    return a.v<b.v;
}
bool d[200001];
int ans[200001];
int main(){
//    freopen("E.INP", "r", stdin);
    read(n);
    read(m);
    m=min(m, 200000);
    for(int i=1; i<=n; i++){
        read(c[i].v);
        c[i].pos=i;
    }
    sort(c+1, c+n+1, cmp);
    for(int i=1; i<=n; i++){
        if(c[i].v<=m) d[c[i].v]=1;
        if(c[i].v%2)
            odd.push_back(i);
        else even.push_back(i);
        int j=i+1;
        while(j<=n){
            if(c[j].v==c[i].v){
                c[j].v=-1;
                del.push_back(j);
                j++;
            }
            else break;
        }
        i=j-1;
    }
    h=n/2;
    while(odd.size()>h){
        del.push_back(odd.front());
        odd.pop_front();
    }
    while(even.size()>h){
        del.push_back(even.front());
        even.pop_front();
    }
    int res=del.size();
    int oddp=1, evenp=2;
    for(int i=odd.size()+1; i<=h; i++){
        while(oddp<=m&&d[oddp]) oddp+=2;
        if(oddp>m){
            printf("-1");
            return 0;
        }
        d[oddp]=1;
        c[del.back()].v=oddp;
        del.pop_back();
    }
    for(int i=even.size()+1; i<=h; i++){
        while(evenp<=m&&d[evenp]) evenp+=2;
        if(evenp>m){
            printf("-1");
            return 0;
        }
        d[evenp]=1;
        c[del.back()].v=evenp;
        del.pop_back();
    }
    for(int i=1; i<=n; i++)
        ans[c[i].pos]=c[i].v;
    write(res);
    putchar('\n');
    for(int i=1; i<=n; i++){
        write(ans[i]);
        putchar(' ');
    }
}