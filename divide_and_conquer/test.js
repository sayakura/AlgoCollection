var cp = function _cp(Px, Py) {
	if(Px.length < 2) return { distance: Infinity, pair: [ [0, 0], [0, 0] ] };
	if(Px.length < 3) {
		//find euclid distance
		var d = Math.sqrt( Math.pow(Math.abs(Px[1][0] - Px[0][0]), 2) + Math.pow(Math.abs(Px[1][1] - Px[0][1]), 2) );
		return {
			distance: d,
			pair: [ Px[0], Px[1] ]
		};
	}
 
	var	n = Px.length,
		leftN = Math.floor(n / 2),
		rightN = leftN;
 
	var Xl = Px.slice(0, leftN),
		Xr = Px.slice(rightN),
		Xm = Xl[leftN - 1],
		Yl = [],
		Yr = [];

	for(var i = 0; i < Py.length; i += 1) {
		if(Py[i][0] <= Xm[0])
			Yl.push(Py[i]);
		else
			Yr.push(Py[i]);
	}
 
	var dLeft = _cp(Xl, Yl),
		dRight = _cp(Xr, Yr);
 
	var minDelta = dLeft.distance,
		cp = dLeft.pair;
	if(dLeft.distance > dRight.distance) {
		minDelta = dRight.distance;
		cp = dRight.pair;
	}
 
 
	//filter points around Xm within delta (minDelta)
	var closeY = [];
	for(i = 0; i < Py.length; i += 1) {
		if(Math.abs(Py[i][0] - Xm[0]) < minDelta) closeY.push(Py[i]);
	}
	//find min within delta. 8 steps max
	for(i = 0; i < closeY.length; i += 1) {
		for(var j = i + 1; j < Math.min( (i + 8), closeY.length ); j += 1) {
			var d = Math.sqrt( Math.pow(Math.abs(closeY[j][0] - closeY[i][0]), 2) + Math.pow(Math.abs(closeY[j][1] - closeY[i][1]), 2) );
			if(d < minDelta) {
				minDelta = d;
				cp = [ closeY[i], closeY[j] ]
			}
		}
	}
 
	return {
		distance: minDelta,
		pair: cp
	};
};


function main(inputs){
    var Px =  inputs.sort((a, b) =>  a[0] < b[0])
    var Py =  inputs.sort((a, b) =>  a[1] < b[1])
    return cp(Px, Py).pair;
}

let out = main([[2,2], // A
    [2,8], // B
    [5,5], // C
    [6,3], // D
    [6,7], // E
    [7,4], // F
    [7,9]]);

console.log(out)