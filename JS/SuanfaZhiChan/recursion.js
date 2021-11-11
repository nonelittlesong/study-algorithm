// 递推 / 迭代
const sum = (target) => {
  let s = 0;
  for (let i = 0; i < target; i++) s += i;
  return s;
}

// 递归
const sum2 = (target) => (target ? target + sum(target - 1) : 0);

// 递推代码实现递归


