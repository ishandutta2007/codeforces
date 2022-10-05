#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 3e5;

int n, a[maxn];

namespace trie {
  struct Node {
    int ch[2], size;
  } node[maxn * 30];

  int nd;

  int New(void) {
    node[nd] = {-1, -1, 0};
    return nd++;
  }

  void Init(void) {
    nd = 0;
    New();
  }

  void Insert(int x) {
    int u = 0;
    for (int i = 29; i >= 0; --i) {
      int y = x >> i & 1;
      int &v = node[u].ch[y];
      if (v == -1) {
        v = New();
      }
      u = v;
      ++node[u].size;
    }
  }

  int Query(int x) {
    // min xor x
    int u = 0, ans = 0;
    for (int i = 29; i >= 0; --i) {
      int y = x >> i & 1;
      if (node[u].ch[y] != -1 && node[node[u].ch[y]].size) {
        ans |= x & 1 << i;
        u = node[u].ch[y];
      } else {
        ans |= ~x & 1 << i;
        u = node[u].ch[!y];
      }
      --node[u].size;
    }
    return ans;
  }
}

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  trie::Init();
  for (int i = 0; i < n; ++i) {
    int p;
    scanf("%d", &p);
    trie::Insert(p);
  }
  for (int i = 0; i < n; ++i) {
    int x = trie::Query(a[i]);
    printf("%d\n", x ^ a[i]);
  }
  return 0;
}