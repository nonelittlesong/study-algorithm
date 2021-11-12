## 1. 抽象数据类型 ADT

圆：

```
ADT Circle {
  数据对象: D = {r, x, y | r, x, y 均为实数}
  数据关系: R = {<r, x, y> | r 是半径, <x, y> 是圆心坐标}
  基本操作:
  Circle(%C, r, x, y)
    操作结果: 构造一个圆
  double Area(C)
    初始条件: 圆已存在
    操作结果: 计算面积
  double Circumference(C)
    初始条件: 圆已存在
    操作结果: 计算周长
  ...
} ADT Circle
```

复数：

```
ADT Complex {
  D = {r1, r2 | r1, r2 都是实数}
  R = {<r1, r2> | r1 是实部，r2 是虚部}
  assign(&C, v1, v2)
    初始条件: 空的复数 C 已存在
    操作结果: 构造复数，r1, r2 的值分别赋以 v1, v2
  ...
} ADT Complex
```

## 2. 算法

特性：

1. 有穷性
2. 确定性
3. 可行性
4. 输入 — 0 个或多个输入
5. 输出 — 1 个或多个输出

要求：

1. 正确性（Correct）
2. 可读性（Readable）
3. 健壮性（Robust）
4. 高效性（Efficiency）
