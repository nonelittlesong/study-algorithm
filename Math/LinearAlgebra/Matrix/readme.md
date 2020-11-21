# 矩阵

## 转置矩阵
```js
const A = [
  [2, 4, 6],
  [8, 9, 9],
  [9, 6, 2]
];

const B = A[0].map(function(col, i) {
  return A.map(function(row) {
    return row[i];
  });
});
```
