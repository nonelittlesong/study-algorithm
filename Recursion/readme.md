# 递归

参考：

- [全面理解递归 | 知乎](https://zhuanlan.zhihu.com/p/150562212)
- [什么是尾递归？ | 贾贾贾的回答 - 知乎](https://www.zhihu.com/question/20761771/answer/1094636184)

## 优化

- 记忆化
- 尾递归

### 记忆化

解决重复计算问题。

以斐波那契函数 F(n) 为例。我们可以使用哈希表来跟踪每个以 n 为键的 F(n) 的结果。

```java
import java.util.HashMap;

public class Main {
  HashMap<Integer, Integer> cache = new HashMap<Integer, Integer>();
  private int fib(int N) {
    if (cache.containsKey(N)) {
      return cache.get(N)
    }
    int result;
    if (N < 2) {
      result = N;
    } else {
      result = fib(N-1) + fib(N-2);
    }
    cache.put(N, result);
    return result;
  }
}
```

## 1. 杨辉三角

首先，用公式表达递推关系：

```
f(i, j) = f(i-1, j-1) + f(i-1, j)
```

其次，考虑基本情况/临界点：

```
f(i, j) = 1 where j = 1 or j = i
```

代码：

```java
public List<List<Integer>> generate(int numRows) {
  if (numRows == 0) return Collections.emptyList();
  int[][] mem = new int[numRows][numRows];
  List<List<Integer>> res = new ArrayList<>(numRows);
  for (int i = 0; i < numRows; i++) {
    List<Integer> subList = new ArrayList<>(i + 1);
    for (int j = 0; j <= i; j++) {
      subList.add(f(i, j, mem));
    }
    res.add(subList);
  }
  return res;
}

private int f(int i, int j, int[][] mem) {
  if (mem[i][j] != 0) return mem[i][j];
  if (j == 0 || j == i) {
    mem[i][j] = 1;
    return mem[i][j];
  }
  mem[i][j] = f(i - 1, j - 1, mem) + f(i - 1, j, mem);
  return mem[i][j];
}
```

## 2. 两两交换链表中的节点

给定

```
1 -> 2 -> 3 -> 4
```

返回

```
2 -> 1 -> 4 -> 3
```

代码：

```java
public ListNode swapPairs(ListNode head) {
  if (head == null || head.next == null) return head;
  int temp = head.val;
  head.val = head.next.val;
  head.next.val = temp;

  ListNode nextHead = swapPairs(head.next.next);
  head.next.next = nextHead;
  return head;
}
```

## 3. 反转链表

输入：`1 -> 2 -> 3 -> 4 -> 5 -> NULL`

输出：`5 -> 4 -> 3 -> 2 -> 1 -> NULL`

代码：

```java
public ListNode reverseList(ListNode head) {
  if (head == null || head.next == null) return head;
  ListNode p = reverseList(head.next);
  head.next.next = head;
  head.next = null;
  return p;
}
```

## 4. 合并两个有序链表

代码：

```java
public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
  if (l1 == null) return l2;
  if (l2 == null) return l1;

  if (l1.val < l2.val) {
    ListNode subList = mergeTwoLists(l1.next, l2);
    l1.next = subList;
    return l1;
  } else {
    ListNode subList = mergeTwoLists(l1, l2.next);
    l2.next = subList;
    return l2;
  }
}
```

## 5. 爬楼梯

假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

代码：

```java
public int climbStairs(int n) {
  int[] mem = new int[n + 1];
  return help(n, mem);
}

private int help(int n, int[] mem) {
  if (n <= 0) return 0;
  if (mem[n] > 0) return mem[n];

  if (n < 4) {
    mem[n] = n;
  } else {
    mem[n] = help(n - 1, mem) + help(n - 2, mem);
  }
  return mem[n];
}
```

## 6. 二叉树的最大深度

代码：

```java
public int maxDepth(TreeNode root) {
  if (root == null) return 0;
  if (root.left == null && root.right == null) return 1;
  return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
}
```

## 7. 计算 x 的 n 次幂函数

代码：

```java
public double myPow(double x, int n) {
  return n > 0 ? help(x, n) : 1.0 / help(x, n);
}
 
private double help(double x, int n) {
  if (n == 0) return 1;
  return n % 2 == 0 ? help(x * x, n / 2) : x * help(x * x, n / 2);
}
```

## 8. 第 K 个语法符号

在第一行我们写上一个 0。接下来的每一行，将前一行的 0 替换为 01，1 替换为 10。

给定行数 N 和序号 K，返回第 N 行中第 K 个字符。

```java
public int kthGrammar(int N, int K) {
  if (N == 1 && K == 1) return 0;

  int rmd = K % 2;  
  int p = kthGrammar(N - 1, rmd == 0 ? K / 2 : (K + 1) / 2);
  if (p == 0) return rmd == 0 ? 1 : 0;
  else return rmd == 0 ? 0 : 1;
}
```
