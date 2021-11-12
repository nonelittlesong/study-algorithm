import {DataType, List} from 'List';

class SeqList implements List {
  private MAXSIZE: number = 100;

  data: Array<DataType>;
  length: number;

  constructor(data = []) {
    this.data = data;
    this.length = data.length;
  }

  // 遍历
  show() {
    console.log('data:');
    for (let i = 0; i < this.length; i++) {
      console.log('\t', this.data[i]);
    }
    console.log('length:\n\t', this.length);
  }

  // 插入
  insert(x: DataType, index: number) {
    if (index > this.length + 1 || index < 1) {
      throw new Error('index is out of bound');
    }
    if (this.length === this.MAXSIZE) {
      throw new Error('not enough space');
    }
    for (let i = this.length; i >= index; i--) {
      this.data[i] = this.data[i - 1];
    }
    this.data[inidex - 1] = x;
    this.length++;
  }

  // 删除
  delete(index: number) {
    if (index > this.length + 1 || index < 1) {
      throw new Error('index is out of bound');
    }
    for (let i = index; i < this.length; i++) {
      this.data[i - 1] = this.data[i];
    }
    this.length--;
  }

  // 查询
  locate(x: DataType, key = 'num'): number {
    let i = 0;
    while (i < this.length && this.data[i][key] != x[key]) {
      i++;
    }
    if (i < this.length) return i + 1;
    return -1;
  }
}
