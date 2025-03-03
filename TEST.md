# Rod Cutting Test Cases

# test1: general value
Input File:
pieces1.txt
Rod Lengths:
50

Pieces (pieces1.txt):
10, 15
15, 25
20, 40

Expected Output:
2 @ 20 = 80
1 @ 10 = 15
Remainder: 0
Value: 95

# test2: short rod length
Input File:
pieces2.txt
Rod Lengths:
5

Pieces (pieces2.txt):
10, 10
15, 20

Expected Output:
Remainder: 5
Value: 0

# test3: exact fit
Input File:
pieces3.txt
Rod Lengths:
25

Pieces (pieces3.txt):
10, 10
15, 25

Expected Output:
1 @ 15 = 25
1 @ 10 = 10
Remainder: 0
Value: 35

# test4: no cutting possible
Input File:
pieces4.txt
Rod Lengths:
12

Pieces (pieces4.txt):
15, 20
30, 50

Expected Output:
Remainder: 12
Value: 0

# test5: best solution
Input File:
pieces5.txt
Rod Lengths:
40

Pieces (pieces5.txt):
10, 10
20, 25
40, 35

Expected Output:
2 @ 20 = 50
Remainder: 0
Value: 50

# test6: large rod length
Input File:
pieces6.txt
Rod Lengths:
100

Pieces (pieces6.txt):
10, 10
20, 25
50, 70

Expected Output:
2 @ 50 = 140
Remainder: 0
Value: 140
