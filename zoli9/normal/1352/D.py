tests = int(input())
for test in range(tests):
    n = int(input())
    a = list(map(int, input().split()))
    moves = 0
    alice = 0
    bob = 0
    first = 0
    last = n-1
    turn = 0
    prevalice = 0
    prevbob = 0
    while True:
        if first>last:
            break
        moves += 1
        if turn == 0:
            prevalice = 0
            while first <= last and prevalice <= prevbob:
                prevalice += a[first]
                alice += a[first]
                first += 1
            if prevalice <= prevbob:
                break
        else:
            prevbob = 0
            while first <= last and prevalice >= prevbob:
                prevbob += a[last]
                bob += a[last]
                last -= 1
            if prevalice >= prevbob:
                break
        turn = 1-turn
    print(moves, alice, bob)