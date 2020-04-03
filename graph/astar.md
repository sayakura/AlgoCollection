
## Manhattan Distance
    when are allowed to move only in four direction(top, down, right, left)
    h = abs(curr.x - goal.x) + 
        abs(curr.y - goal.y)

## Diagonal Distance
    When we are allowed to move in eight directions only (similar to a move of a King in Chess)
    h = max (abs(curr.x - goal.x), abs(curr.y - goal.y))

## Euclidean Distance
    when we are allowed to move in any direction
    h = sqrt( pow(curr.x - goal.x, 2) + pow(curr.y - goal.y, 2) )



LIFO
first in last out
 

FIFO
queue