function range(start, end) {
  const result = []
  for (let i = start; i < end; i++) {
    result.push(i)
  }
  return result
}

function closestPair(points) {
  points.sort((a, b) => a[0] < a[1])
  const [idx1, idx2] = divideAndConquer(0, points.length - 1)
  return [points[idx1], points[idx2]]

  function divideAndConquer(start, end) {
    if (end - start === 1) {
      return [start, end]
    } else if (end === start) {
      return null
    }
    const mid = Math.floor((start + end) / 2)
    const leftIdxPair = divideAndConquer(start, mid)
    const rightIdxPair = divideAndConquer(mid + 1, end)

    const dist1 = leftIdxPair == null ? Infinity : distanceByIdxPair(leftIdxPair)
    const dist2 = rightIdxPair == null ? Infinity : distanceByIdxPair(rightIdxPair)

    let minDistance
    let minDistanceIdxPair
    if (dist1 < dist2) {
      minDistance = dist1
      minDistanceIdxPair = leftIdxPair
    } else {
      minDistance = dist2
      minDistanceIdxPair = rightIdxPair
    }

    const d = minDistance
    const centerX = (points[mid][0] + points[mid + 1][0]) / 2

    const inStripeIds = range(start, end + 1).filter(idx => {
      const p = points[idx]
      return Math.abs(p[0] - centerX) <= d
    })
    const leftStripeIds = inStripeIds.filter(idx => idx <= mid).sort((a, b) => a[1] < b[1])
    const rightStripeIds = inStripeIds.filter(idx => idx > mid).sort((a, b) => a[1] < b[1])

    let i = 0
    let j = 0
    while (i < leftStripeIds.length) {
      const leftPoint = points[leftStripeIds[i]]
      const y = leftPoint[1]

      while (j > 0 && points[rightStripeIds[j - 1]][1] >= y - d) {
        j--
      }
      while (j < rightStripeIds.length && points[rightStripeIds[j]][1] < y - d) {
        j++
      }
      while (j < rightStripeIds.length && points[rightStripeIds[j]][1] <= y + d) {
        const rightPoint = points[rightStripeIds[j]]
        const cntDistance = pointDistance(leftPoint, rightPoint)
        if (cntDistance < minDistance) {
          minDistance = cntDistance
          minDistanceIdxPair = [leftStripeIds[i], rightStripeIds[j]]
        }
        j++
      }
      i++
    }

    return minDistanceIdxPair
  }

  function distanceByIdxPair([idx1, idx2]) {
    return pointDistance(points[idx1], points[idx2])
  }

  function pointDistance(p1, p2) {
    return Math.sqrt((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2)
  }

}
