#include <bits/stdc++.h>
using namespace std;

int main(){
    int q;
    scanf("%d", &q);

    vector <int> v;
    set <int> mono;
    set < pair <int, int> > poly;
    bool first = true;

    while(q--){
        int t;
        scanf("%d", &t);

        if(t == 1){
            int m;
            scanf("%d", &m);

            v.push_back(m);
            mono.insert((int)v.size() - 1);
            poly.insert(make_pair(-m, (int)v.size() - 1));
        }else if(t == 2){
            if(first)first = false;
            else printf(" ");

            printf("%d", (*mono.begin()) + 1);

            poly.erase(make_pair(-v[*mono.begin()], *mono.begin()));
            mono.erase(mono.begin());
        }else{
            if(first)first = false;
            else printf(" ");

            printf("%d", poly.begin()->second + 1);

            mono.erase(poly.begin()->second);
            poly.erase(poly.begin());
        }
    }
    printf("\n");

    return 0;
}