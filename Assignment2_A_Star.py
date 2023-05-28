g = 0
def printBoard(board):
    for i in range(9):
        if i%3==0:
            print()
        if board[i] == -1:
            print("_", end=" ")
        else:
            print(board[i], end=" ")
    print()

def solvable(start):
    inter = 0
    
    for i in range(9):
        if start[i] <= 1:
            continue
        for j in range(i+1,9):
            if start[j] == -1:
                continue
            if start[i]>start[j]:
                inter+=1
    if inter%2==0:
        return True
    return False

def heuristic(start, goal):
    global g
    h = 0
    for i in range(9):
        for j in range(9):
            if start[i] == goal[j] and start[i] != -1:
                h += (abs(j-i))//3 + (abs(j-i))%3
    return g+h

def moveLeft(start, position):
    start[position], start[position-1] = start[position-1], start[position]

def moveRight(start, position):
    start[position], start[position+1] = start[position+1], start[position]

def moveDown(start, position):
    start[position], start[position+3] = start[position+3], start[position]

def moveUp(start, position):
    start[position], start[position-3] = start[position-3], start[position]


def moveTile(start, goal):
    emptyIndex = start.index(-1)
    emptyRow = emptyIndex//3
    emptyCol = emptyIndex%3
    f1, f2, f3, f4 = 100, 100, 100, 100
    duplicateStart1, duplicateStart2, duplicateStart3, duplicateStart4 = start[:], start[:], start[:], start[:]
    
    if emptyCol>=1:
        moveLeft(duplicateStart1, emptyIndex)
        f1 = heuristic(duplicateStart1, goal)
    if emptyCol<2:
        moveRight(duplicateStart2, emptyIndex)
        f2 = heuristic(duplicateStart2, goal)
    if emptyRow<2:
        moveDown(duplicateStart3, emptyIndex)
        f3 = heuristic(duplicateStart3, goal)
    if emptyRow>=1:
        moveUp(duplicateStart4, emptyIndex)
        f4 = heuristic(duplicateStart4, goal)
    
    minHeuristic = min(f1, f2, f3, f4)
    
    if f1==minHeuristic:
        moveLeft(start, emptyIndex)
    elif f2==minHeuristic:
        moveRight(start, emptyIndex)
    elif f3==minHeuristic:
        moveDown(start, emptyIndex)
    elif f4==minHeuristic:
        moveUp(start, emptyIndex)


def solveEight(start, goal):
    global g
    g+=1
    moveTile(start, goal)
    printBoard(start)
    f = heuristic(start, goal)
    if f==g:
        print("Solveg in {} moves.".format(g))
        return

    solveEight(start, goal)

start = []
goal = []
print("Enter the start state (enter -1 for empty)")
for i in range(9):
    start.append(int(input("> ")))

print("Enter the goal state (enter -1 for empty)")
for i in range(9):
    goal.append(int(input("> ")))
    
printBoard(start)


if(solvable(start)):
    solveEight(start, goal)
    
else:
    print("Puzzle not solvable.")

