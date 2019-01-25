http://geomalgorithms.com/a03-_inclusion.html  
js代码：  
```js
function is_inside_polygon(all_points_x, all_points_y, px, py) {
  var wn = 0; // the winding number counter
  
  // loop through all edge of the polygon
  for (var i = 0; i < all_points_x.length-1; ++i) { // edge from V[i] to V[i+1]
    var is_left_value = is_left(all_points_x[i], all_points_y[i],
                                all_points_x[i+1], all_points_y[i+1],
                                px, py);
    if (all_points_y[i] <= py) {
      if (all_points_y[i+1] > py && is_left_value > 0) {
        ++wn;
      }
    }
    else {
      if (all_points_y[i+1] <= py && is_left_value < 0) {
        --wn;
      }
    }
  }
  if (wn === 0) {
    return 0;
  }
  else {
    return 1;
  }
}

// returns
// >0 if (x2,y2) lies on the left side of line joining (x0,y0) and (x1,y1)
// =0 if (x2,y2) lies on the line joining (x0,y0) and (x1,y1)
// >0 if (x2,y2) lies on the right side of line joining (x0,y0) and (x1,y1)
// source: http://geomalgorithms.com/a03-_inclusion.html
function is_left(x0, y0, x1, y1, x2, y2) {
    return ( ((x1 - x0) * (y2 - y0))  - ((x2 -  x0) * (y1 - y0)) );
}
```
