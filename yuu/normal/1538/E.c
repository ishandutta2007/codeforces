#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buffer[10];
typedef struct string {
    char* data;
    int len;
};

char* free_list[100000];
int free_list_size;

void empty_free_list() {
    while (free_list_size > 0) free(free_list[free_list_size--]);
}

struct string get_string() {
    scanf("%s", buffer);
    struct string res;
    res.len = strlen(buffer);
    res.data = malloc(sizeof(char) * res.len);
    free_list[++free_list_size] = res.data;
    memcpy(res.data, buffer, sizeof(char) * res.len);
    return res;
}

struct string add_string(struct string left, struct string right) {
    struct string res;
    res.len = left.len + right.len;
    res.data = malloc(sizeof(char) * res.len);
    free_list[++free_list_size] = res.data;
    memcpy(res.data, left.data, sizeof(char) * left.len);
    memcpy(res.data + sizeof(char) * left.len, right.data, sizeof(char) * right.len);
    return res;
}

bool is_equal_string(struct string left, struct string right) {
    if (left.len != right.len) return false;
    for (int i = 0; i < left.len; i++)
        if (left.data[i] != right.data[i]) return false;
    return true;
}

struct string get_prefix(const struct string str, int len) {
    struct string res;
    res.len = len;
    if (res.len > str.len) res.len = str.len;
    res.data = str.data;
    return res;
}

struct string get_suffix(const struct string str, int len) {
    struct string res;
    res.len = len;
    if (res.len > str.len) res.len = str.len;
    res.data = str.data + (str.len - res.len) * sizeof(char);
    return res;
}

int count_haha(const struct string str) {
    int ans = 0;
    for (int i = 3; i < str.len; i++) {
        if (str.data[i] == 'a') {
            if (str.data[i - 1] == 'h') {
                if (str.data[i - 2] == 'a') {
                    if (str.data[i - 3] == 'h') {
                        ans++;
                    }
                }
            }
        }
    }
    return ans;
}

typedef struct combine_string {
    int64_t haha_count;
    struct string prefix;
    struct string suffix;
};

struct combine_string combine_string_from_string(struct string str) {
    struct combine_string res;
    res.haha_count = count_haha(str);
    res.prefix = get_prefix(str, 3);
    res.suffix = get_suffix(str, 3);
    return res;
}
struct combine_string combine_combine_string(struct combine_string left, struct combine_string right) {
    struct combine_string res;
    res.haha_count = left.haha_count + right.haha_count + count_haha(add_string(left.suffix, right.prefix));
    res.prefix = get_prefix(add_string(left.prefix, right.prefix), 3);
    res.suffix = get_suffix(add_string(left.suffix, right.suffix), 3);
    return res;
}

struct string name[50];
struct combine_string count[50];
int name_count;
int get_name_index(struct string str) {
    for (int i = 0; i < name_count; i++) {
        if (is_equal_string(name[i], str)) return i;
    }
    return -1;
}

void solve() {
    int n;
    scanf("%d", &n);
    name_count = 0;
    empty_free_list();
    int64_t ans = 0;
    while (n--) {
        struct string lhs = get_string();
        int lhs_idx = get_name_index(lhs);
        if (lhs_idx == -1) {
            lhs_idx = name_count++;
            name[lhs_idx] = lhs;
        }

        struct string op = get_string();
        if (op.len == 2) {  // assign
            struct string value = get_string();
            count[lhs_idx] = combine_string_from_string(value);
        } else {  // add
            int idx_1 = get_name_index(get_string());
            get_string();
            int idx_2 = get_name_index(get_string());
            count[lhs_idx] = combine_combine_string(count[idx_1], count[idx_2]);
        }
        ans = count[lhs_idx].haha_count;
    }
    printf("%lld\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}