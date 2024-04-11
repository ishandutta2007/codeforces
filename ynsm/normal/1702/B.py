def main():
    t = int(input())
    for i in range(t):
        s = input()
        chars = []
        days = 1
        for c in s:
            if c in chars:
                continue
            if len(chars) < 3:
                chars.append(c)
            else:
                chars = [c]
                days += 1
        print(days)

if __name__ == "__main__":
    main()