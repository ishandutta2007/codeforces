/+ dub.sdl:
    name "F"
    dependency "dcomp" version=">=0.7.3"
+/

import std.stdio, std.algorithm, std.range, std.conv;
// import dcomp.foundation, dcomp.scanner;
import std.typecons;

alias E = Tuple!(int, "to", int, "dist");
alias D = int;

int main() {
    Scanner sc = new Scanner(stdin);
    
    static struct PairingHeapAllAdd {
        alias NP = Node*;
        static struct Node {        
            E e;
            D offset;
            NP head, next;
            this(E e) {
                this.e = e;
                offset = D(0);
            }
        }
        NP n;
        size_t length;
        this(E[] e) {
            length = e.length;            
            foreach (d; e) {
                n = merge(n, new Node(d));
            }
        }
        static NP merge(NP x, NP y) {
            if (!x) return y;
            if (!y) return x;
            if (x.e.dist+x.offset < y.e.dist+y.offset) swap(x, y);
            y.offset -= x.offset;
            y.next = x.head;
            x.head = y;
            return x;
        }
        void C() { assert(n); }
        E front() {C; return n.e; }
        void removeFront() {
            assert(n);
            assert(length > 0);
            length--;
            NP x;
            NP s = n.head;
            while (s) {
                NP a, b;
                a = s; s = s.next; a.next = null; a.offset += n.offset;
                if (s) {
                    b = s; s = s.next; b.next = null; b.offset += n.offset;
                }
                a = merge(a, b);
                assert(a);
                if (!x) x = a;
                else {
                    a.next = x.next;
                    x.next = a;
                }
            }
            n = null;
            while (x) {
                NP a = x; x = x.next;
                n = merge(a, n);
            }
        }
        void meld(PairingHeapAllAdd r) {
            length += r.length;
            n = merge(n, r.n);
        }
        ref D offset() {C; return n.offset; }
    }

    int n, m;
    sc.read(n, m);    
    E[][] g = new E[][n];
    foreach (i; 0..m) {
        int a, b, c;
        sc.read(a, b, c); a--; b--;
        g[a] ~= E(i, c);
        g[b] ~= E(i, c);
    }

    auto heap = new PairingHeapAllAdd[2*n];
    foreach (i; 0..n) {
//        writeln(i, " -> ", g[i]);
        heap[i] = PairingHeapAllAdd(g[i]);
    }

    int[] pre = new int[m]; pre[] = -1;
    bool[] fix = new bool[m];
    long sm = 0;
    int pc = n;
    foreach (i; 0..2*n) {
        if (i == pc) break;
        while (heap[i].length && fix[heap[i].front.to]) heap[i].removeFront;
        if (!heap[i].length) continue;
        auto e = heap[i].front;
        int c = e.dist;
        int x = i;
        if (pre[e.to] == -1) {
            sm += c;
            pre[e.to] = i;
            continue;
        }
        int y = pre[e.to];        
        //merge x, y
        fix[e.to] = true;
        int P = pc++;
        heap[P].meld(heap[x]);
        heap[P].meld(heap[y]);        
    }

    writeln(sm);
    return 0;
}
/* IMPORT /home/yosupo/Program/dcomp/source/dcomp/foundation.d */
// module dcomp.foundation;
 
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
version (X86) static if (__VERSION__ < 2071) {
    import core.bitop : bsf, bsr, popcnt;
    int bsf(ulong v) {
        foreach (i; 0..64) {
            if (v & (1UL << i)) return i;
        }
        return -1;
    }
    int bsr(ulong v) {
        foreach_reverse (i; 0..64) {
            if (v & (1UL << i)) return i;
        }
        return -1;   
    }
    int popcnt(ulong v) {
        int c = 0;
        foreach (i; 0..64) {
            if (v & (1UL << i)) c++;
        }
        return c;
    }
}
/* IMPORT /home/yosupo/Program/dcomp/source/dcomp/scanner.d */
// module dcomp.scanner;

// import dcomp.array;

 
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
                FastAppender!(E[]) buf;
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


 
 

 
/* IMPORT /home/yosupo/Program/dcomp/source/dcomp/array.d */
// module dcomp.array;

 
T[N] fixed(T, size_t N)(T[N] a) {return a;}

 
 

 
struct FastAppender(A, size_t MIN = 4) {
    import std.algorithm : max;
    import std.conv;
    import std.range.primitives : ElementEncodingType;
    import core.stdc.string : memcpy;

    private alias T = ElementEncodingType!A;
    private T* _data;
    private uint len, cap;
     
    @property size_t length() const {return len;}
    bool empty() const { return len == 0; }
     
    void reserve(size_t nlen) {
        import core.memory : GC;
        if (nlen <= cap) return;
        
        void* nx = GC.malloc(nlen * T.sizeof);

        cap = nlen.to!uint;
        if (len) memcpy(nx, _data, len * T.sizeof);
        _data = cast(T*)(nx);
    }
    void free() {
        import core.memory : GC;
        GC.free(_data);
    }
     
    void opOpAssign(string op : "~")(T item) {
        if (len == cap) {
            reserve(max(MIN, cap*2));
        }
        _data[len++] = item;
    }
     
    void insertBack(T item) {
        this ~= item;
    }
     
    void removeBack() {
        len--;
    }
     
    void clear() {
        len = 0;
    }
    ref inout(T) back() inout { assert(len); return _data[len-1]; }
    ref inout(T) opIndex(size_t i) inout { return _data[i]; }
     
    T[] data() {
        return (_data) ? _data[0..len] : null;
    }
}

 
 

/*
This source code generated by dcomp and include dcomp's source code.
dcomp's Copyright: Copyright (c) 2016- Kohei Morita. (https://github.com/yosupo06/dcomp)
dcomp's License: MIT License(https://github.com/yosupo06/dcomp/blob/master/LICENSE.txt)
*/