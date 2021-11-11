# 尾递归

尾递归是指在一个方法的内部，递归调用后直接 return，没有任何多余的指令。

比如，一个递归实现的累加函数：

```java
public static int acc(int n) {
  if (n == 1) {
    return 1;
  }
  return n + acc(n - 1);
}
```

请问这是一个尾递归吗？答案是否定的。

实际上，你看到的最后一个步骤，不代表从指令层面上来讲的最后一步。这个方法的 return 先拿到 `acc(n - 1)` 的值，然后再将 n 与其相加，所以求 `acc(n - 1)` 并不是最后一步，因为最后还有一个 add 操作。

把上面的代码做个等价逻辑转换就很清晰了：

```java
public static int acc(int n) {
  if (n == 1) {
    return 1;
  }
  int r = acc(n - 1);
  return n + r;
}
```

累加的尾递归算法是下面这样子的：

```java
public static int accTail(int n, int sum) {
  if (n == 1) {
    return sum + n;
  }
  return accTail(n - 1, sum + n);
}
```

## 为什么尾递归容易优化

尾递归将外层方法的结果传递给了内层方法，那外层方法实际上没有任何利用价值了，可以直接从栈里踢出。所以，可以保证同时只有一个栈帧在栈里存活，节省了大量栈空间。
