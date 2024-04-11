if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    ans = -1
    c = 1
    small = True
    while small:
        current_ans = 0
        pw = 1
        for idx in range(n):
            current_ans += abs(a[idx]-pw)
            pw *= c
            if pw >= 1e14 and idx+1 < n:
                small = False
                break
        if c > 1e5:
            break
        if small:
            if ans == -1 or current_ans < ans:
                ans = current_ans
            c += 1
        else:
            break
    print(ans)