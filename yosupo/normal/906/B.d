/+ dub.sdl:
    name "B"
    dependency "dunkelheit" version=">=0.9.0"
+/

import std.stdio, std.algorithm, std.range, std.conv;
// import dkh.foundation, dkh.scanner;

import std.math;

int n, m;
int[2][][] res;

int[] getBig(int n) {
    int[] v;
    foreach (i; 0..n) {
        if (i % 2 == 0) continue;
        v ~= i;
    }
    foreach (i; 0..n) {
        if (i % 2) continue;
        v ~= i;
    }
    return v;
}

// import dkh.dungeon;

bool check() {
    bool nei(int[2] id1, int[2] id2) {
        int dr = abs(id1[0] - id2[0]);
        int dc = abs(id1[1] - id2[1]);
        if (dr == 0 && dc == 1) return true;
        if (dr == 1 && dc == 0) return true;
        return false;
    }
    foreach (i; 0..n) {
        foreach (j; 0..m) {
            foreach (np; neighbors4([i, j], Dungeon(n, m))) {
                if (nei(res[i][j], res[np[0]][np[1]])) {
                    writeln("same ", i, " ", j, " ", np);
                    return false;
                }
            }
        }
    }
    return true;
}

bool solve() {
    if (n >= 4) {
        auto h = getBig(n);
        auto w = getBig(m);
        foreach (i; 0..n) {
            foreach (j; 0..m) {
                res[i][j] = [h[i], w[j]];
            }
        }
        return true;
    }
    if (n == 1 && m >= 4) {
        auto w = getBig(m);
        foreach (j; 0..m) {
            res[0][j] = [0, w[j]];
        }
        return true;
    }
    if (m >= 4) {
        foreach (i; 0..n) {
            foreach (j; 0..m) {
                res[i][j] = [i, j];
            }
        }            
        foreach (i; 0..n) {
            if (i % 2) continue;
            bringToFront(res[i][0..2], res[i][2..$]);
        }
        foreach (j; 0..m) {
            if (j % 2) continue;
            int[2][] buf = new int[2][n];
            foreach (k; 0..n) {
                buf[k] = res[k][j];
            }
            bringToFront(buf[0..1], buf[1..$]);
            foreach (k; 0..n) {
                res[k][j] = buf[k];
            }
        }
        return true;
    }

    int[] idxBase = iota(n * m).array;
    foreach (idx; idxBase.permutations) {
        foreach (i; 0..n) {
            foreach (j; 0..m) {
                int u = idx[i*m+j];
                res[i][j] = [u/m, u%m];
            }
        }
        bool nei(int[2] id1, int[2] id2) {
            int dr = abs(id1[0] - id2[0]);
            int dc = abs(id1[1] - id2[1]);
            if (dr == 0 && dc == 1) return true;
            if (dr == 1 && dc == 0) return true;
            return false;
        }
        bool ok = true;
        foreach (i; 0..n) {
            foreach (j; 0..m) {
                foreach (np; neighbors4([i, j], Dungeon(n, m))) {
                    if (nei(res[i][j], res[np[0]][np[1]])) {
                        ok = false;
                        break;
                    }
                }
            }
        }
        if (ok) return true;
    }
    return false;
}
/*
void main() {
    foreach (d; 1..10) {
        foreach (e; d..10) {
            n = d; m = e;
            res = new int[2][][](n, m);
            bool f = solve();
//            writeln(d, " ", e, " ", f);
//            writeln(res);
            if (f) assert(check());
        }
    }
}*/

int main() {
    Scanner sc = new Scanner(stdin);
    sc.read(n, m);
    bool rev = (n > m);
    if (rev) swap(n, m);
    res = new int[2][][](n, m);
    bool f = solve();
    if (!f) {
        writeln("NO");
        return 0;
    }
    writeln("YES");
    if (rev) {
        swap(n, m);
        auto nres = new int[2][][](n, m);
        foreach (i; 0..n) {
            foreach (j; 0..m) {
                nres[i][j] = res[j][i];
                swap(nres[i][j][0], nres[i][j][1]);
            }
        }
        res = nres;
    }

    int[][] idx = new int[][](n, m);
    foreach (i; 0..n) {
        foreach (j; 0..m) {
            idx[i][j] = res[i][j][0] * m + res[i][j][1] + 1;
        }
        writeln(idx[i].map!(to!string).join(" "));
    }
    assert(check());
    return 0;
}
/* IMPORT /Users/yosupo/Program/dunkelheit/source/dkh/container/stackpayload.d */
// module dkh.container.stackpayload;

 
struct StackPayload(T, size_t MINCAP = 4) if (MINCAP >= 1) {
    import core.exception : RangeError;

    private T* _data;
    private uint len, cap;

    @property bool empty() const { return len == 0; }
    @property size_t length() const { return len; }
    alias opDollar = length;

     
    inout(T)[] data() inout { return (_data) ? _data[0..len] : null; }
    
    ref inout(T) opIndex(size_t i) inout {
        version(assert) if (len <= i) throw new RangeError();
        return _data[i];
    }  
    ref inout(T) front() inout { return this[0]; }  
    ref inout(T) back() inout { return this[$-1]; }  

    void reserve(size_t newCap) {
        import core.memory : GC;
        import core.stdc.string : memcpy;
        import std.conv : to;
        if (newCap <= cap) return;
        void* newData = GC.malloc(newCap * T.sizeof);
        cap = newCap.to!uint;
        if (len) memcpy(newData, _data, len * T.sizeof);
        _data = cast(T*)(newData);
    }  
    void free() {
        import core.memory : GC;
        GC.free(_data);
    }  
     
    void clear() {
        len = 0;
    }

    void insertBack(T item) {
        import std.algorithm : max;
        if (len == cap) reserve(max(cap * 2, MINCAP));
        _data[len++] = item;
    }  
    alias opOpAssign(string op : "~") = insertBack;  
    void removeBack() {
        assert(!empty, "StackPayload.removeBack: Stack is empty");
        len--;
    }  
}

 
/* IMPORT /Users/yosupo/Program/dunkelheit/source/dkh/foundation.d */
 
// module dkh.foundation;

 
static if (__VERSION__ <= 2070) {
    /*
    Copied by https://github.com/dlang/phobos/blob/master/std/algorithm/iteration.d
    Copyright: Andrei Alexandrescu 2008-.
    License: $(HTTP boost.org/LICENSE_1_0.txt, Boost License 1.0).
    */
    template fold(fun...) if (fun.length >= 1) {
        auto fold(R, S...)(R r, S seed) {
            import std.algorithm : reduce;
            static if (S.length < 2) {
                return reduce!fun(seed, r);
            } else {
                import std.typecons : tuple;
                return reduce!fun(tuple(seed), r);
            }
        }
    }
     
}
/* IMPORT /Users/yosupo/Program/dunkelheit/source/dkh/dungeon.d */
// module dkh.dungeon;

 
immutable static int[2][4] direction4 = [
    [1, 0], [0, 1], [-1, 0], [0, -1],
];

 
immutable static int[2][8] direction8 = [
    [1, 0],
    [1, 1],
    [0, 1],
    [-1, 1],
    [-1, 0],
    [-1, -1],
    [0, -1],
    [1, -1],
];

static int[2] addInt2(in int[2] a, in int[2] b) {
    int[2] c;
    c[] = a[] + b[];
    return c;
}

 
struct Dungeon {
     
    static int[2] move4(int[2] p, int dir) {
        return addInt2(p, direction4[dir]);
    }
     
    static int[2] move8(int[2] p, int dir) {
        return addInt2(p, direction8[dir]);
    }

    immutable int R, C;
     
    this(int R, int C) {
        this.R = R;
        this.C = C;
    }
     
    bool isInside(int[2] p) const {
        int r = p[0], c = p[1];
        return 0 <= r && r < R && 0 <= c && c < C;
    }
     
    int getID(int[2] p) const {
        int r = p[0], c = p[1];
        return r*R+c;
    }
}

 
auto neighbors4(int[2] p) {
    static struct Rng {
        int[2] center;
        size_t i;
        bool empty() const { return i == 4;}
        int[2] front() const { return addInt2(center, direction4[i]); }
        void popFront() { i++; }
    }
    return Rng(p, 0);
}

 
 

 
auto neighbors4(int[2] p, in Dungeon dg) {
    static struct Rng {
        int[2] center;
        Dungeon dg;
        size_t i;
        this(in int[2] center, in Dungeon dg) {
            this.center = center;
            this.dg = dg;
            while (!empty() && !dg.isInside(front)) i++;
        }
        bool empty() const { return i == 4;}
        int[2] front() const { return addInt2(center, direction4[i]); }
        void popFront() {
            i++;
            while (!empty() && !dg.isInside(front)) i++;
        }
    }
    return Rng(p, dg);
}

 
 
/* IMPORT /Users/yosupo/Program/dunkelheit/source/dkh/scanner.d */
// module dkh.scanner;

// import dkh.container.stackpayload;

 
class Scanner {
    import std.stdio : File;
    import std.conv : to;
    import std.range : front, popFront, array, ElementType;
    import std.array : split;
    import std.traits : isSomeChar, isStaticArray, isArray; 
    import std.algorithm : map;
    File f;
    this(File f) {
        this.f = f;
    }
    char[512] lineBuf;
    char[] line;
    private bool succW() {
        import std.range.primitives : empty, front, popFront;
        import std.ascii : isWhite;
        while (!line.empty && line.front.isWhite) {
            line.popFront;
        }
        return !line.empty;
    }
    private bool succ() {
        import std.range.primitives : empty, front, popFront;
        import std.ascii : isWhite;
        while (true) {
            while (!line.empty && line.front.isWhite) {
                line.popFront;
            }
            if (!line.empty) break;
            line = lineBuf[];
            f.readln(line);
            if (!line.length) return false;
        }
        return true;
    }

    private bool readSingle(T)(ref T x) {
        import std.algorithm : findSplitBefore;
        import std.string : strip;
        import std.conv : parse;
        if (!succ()) return false;
        static if (isArray!T) {
            alias E = ElementType!T;
            static if (isSomeChar!E) {
                 
                 
                auto r = line.findSplitBefore(" ");
                x = r[0].strip.dup;
                line = r[1];
            } else static if (isStaticArray!T) {
                foreach (i; 0..T.length) {
                    bool f = succW();
                    assert(f);
                    x[i] = line.parse!E;
                }
            } else {
                StackPayload!E buf;
                while (succW()) {
                    buf ~= line.parse!E;
                }
                x = buf.data;
            }
        } else {
            x = line.parse!T;
        }
        return true;
    }
    int read(T, Args...)(ref T x, auto ref Args args) {
        if (!readSingle(x)) return 0;
        static if (args.length == 0) {
            return 1;
        } else {
            return 1 + read(args);
        }
    }
}


 
 

 

/*
This source code generated by dunkelheit and include dunkelheit's source code.
dunkelheit's Copyright: Copyright (c) 2016- Kohei Morita. (https://github.com/yosupo06/dunkelheit)
dunkelheit's License: MIT License(https://github.com/yosupo06/dunkelheit/blob/master/LICENSE.txt)
*/