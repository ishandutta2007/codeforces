/+ dub.sdl:
    name "B"
    dependency "dunkelheit" version=">=0.9.0"
+/

import std.stdio, std.algorithm, std.range, std.conv;
// import dkh.foundation, dkh.scanner;

// import dkh.array, dkh.dungeon;

int main() {
    Scanner sc = new Scanner(stdin);
    scope(exit) sc.read!true;

    int h, w;
    sc.read(h, w);
    char[][] g = new char[][](h, w);
    foreach (r; 0..h) sc.read(g[r]);

    string _s;
    sc.read(_s);
    int[] s = _s.map!(c => c-'0').map!(to!int).array;

    int ans = 0;
    foreach (idx; iota(4).permutations) {
        int[2] sv = g.findFirst2D('S');
        int[2] tv = g.findFirst2D('E');
        auto dh = Dungeon(h, w);
        bool f = true;
        foreach (_d; s) {
            int d = idx[_d];
            sv = dh.move4(sv, d);
            if (!dh.isInside(sv)) {
                f = false;
                break;
            }
            if (g.at2D(sv) == '#') {
                f = false;
                break;
            }
            if (sv == tv) break;
        }
        if (!f) continue;
        if (sv != tv) continue;
        ans++;
    }
    writeln(ans);
    return 0;
}
/* IMPORT /Users/yosupo/Program/dunkelheit/source/dkh/array.d */
// module dkh.array;

 
T[N] fixed(T, size_t N)(T[N] a) {return a;}

 
 

 
int[2] findFirst2D(T, U)(in T mp, in U c) {
    import std.conv : to;
    int R = mp.length.to!int;
    int C = mp[0].length.to!int;
    foreach (i; 0..R) {
        foreach (j; 0..C) {
            if (mp[i][j] == c) return [i, j];
        }
    }
    assert(false);
}

 
 

 
auto ref at2D(T, U)(ref T mp, in U idx) {
    return mp[idx[0]][idx[1]];
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

    int unsafeRead(T, Args...)(ref T x, auto ref Args args) {
        if (!readSingle(x)) return 0;
        static if (args.length == 0) {
            return 1;
        } else {
            return 1 + read(args);
        }
    }
    void read(bool enforceEOF = false, T, Args...)(ref T x, auto ref Args args) {
        import std.exception;
        enforce(readSingle(x));
        static if (args.length == 0) {
            enforce(enforceEOF == false || !succ());
        } else {
            read!enforceEOF(args);
        }
    }
    void read(bool enforceEOF = false, Args...)(auto ref Args args) {
        import std.exception;
        static if (args.length == 0) {
            enforce(enforceEOF == false || !succ());
        } else {
            enforce(readSingle(args[0]));
            read!enforceEOF(args);
        }
    }
}


 
 

 

/*
This source code generated by dunkelheit and include dunkelheit's source code.
dunkelheit's Copyright: Copyright (c) 2016- Kohei Morita. (https://github.com/yosupo06/dunkelheit)
dunkelheit's License: MIT License(https://github.com/yosupo06/dunkelheit/blob/master/LICENSE.txt)
*/