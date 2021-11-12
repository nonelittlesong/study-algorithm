export default interface DataType {
  num: number;
  name: string;
  age: number;
}

export default interface List {
  data: Array<DataType>;
  length: number;
}
