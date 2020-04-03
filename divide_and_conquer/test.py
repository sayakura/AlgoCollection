import math
 
infinity = float('inf')

def distance(p1, p2):
    d = math.sqrt(math.pow(abs(p1[0] - p2[0]) ,2) + math.pow(abs(p1[1] - p2[1]) ,2))
    return d

def bruteForceClosestPair(point):
    numPoints = len(point)
    mindist = infinity
    pair = (None, None)
    if numPoints < 2:
        return infinity, (None, None)
    for i in range(0, numPoints - 1):
        for j in range(i + 1, numPoints - 1):
            d = distance(point[i], point[j])
            if d < mindist:
                mindist = d
                pair = (point[i], point[j])
    return mindist, pair

 
def _closestPair(xP, yP):
    numPoints = len(xP)
    if numPoints <= 3:
        return bruteForceClosestPair(xP)
    half = int(numPoints/2)
    Pl = xP[:half]
    Pr = xP[half:]
    Yl, Yr = [], []
    xDivider = xP[half][0]
    for p in yP:
        if p[0] <= xDivider:
            Yl.append(p)
        else:
            Yr.append(p)
    dl, pairl = _closestPair(Pl, Yl)
    dr, pairr = _closestPair(Pr, Yr)
    dm, pairm = (dl, pairl) if dl < dr else (dr, pairr)
    closeY = [p for p in yP  if abs(p[0] - xDivider) < dm]
    numCloseY = len(closeY)
    if numCloseY > 1:
        for i in range(numCloseY - 1):
            for j in range(i + 1, min(i + 8 , numCloseY)):
                d = distance(closeY[i], closeY[j])
                if d < dm:
                    dm = d
                    pairm = (closeY[i], closeY[j])
        return dm, pairm
    else:
        return dm, pairm
 
def closestPair(point):
    xP = sorted(point, key=lambda p: p[0] )
    yP = sorted(point, key=lambda p: p[1] )
    return _closestPair(xP, yP)[1]

if __name__ == '__main__':
    pointList = (
                 (2, 2), # A
                (2, 8), # B
                (5, 5), # C
                (5, 5), # C
                (6, 3), # D
                (6, 7), # E
                (7, 4), # F
    )
    print( closestPair(pointList))
    # print '  bruteForceClosestPair:', bruteForceClosestPair(pointList)
    # print '            closestPair:', closestPair(pointList)