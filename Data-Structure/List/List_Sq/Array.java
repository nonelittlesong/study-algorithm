public class Array<T> {
    private static final int DEFAULT_CAPACITY = 10;
    private int size;
    private T[] data;

    public Array() {
      size = 0;
      ensureCapacity(DEFAULT_CAPACITY);
    }

    public int getSize() {
      return size;
    }

    public int getCapacity() {
      return data.length;
    }

    public boolean isEmpty() {
      return size == 0;
    }

    public void addFirst(T element) {
      add(0, element);
    }

    public void addLast(T element) {
      add(size, element);
    }

    public void add(int idx, T element) {
      if (size == getCapacity()) {
        ensureCapacity(getCapacity * 2);
      }
      for (int i = size; i > idx; i--) {
        data[i] = data[i - 1];
      }
      data[idx] = element;
      size++;
    }

    public T removeFirst() {
      remove(0);
    }

    public T removeLast() {
      remove(size - 1);
    }

    public T remove(int idx) {
      if (isEmpty() || idx >= size) throw new IllegalArgumentException("index 不合法");
      T ret = data[idx];
      if (idx != size - 1) {
        for (int i = idx; i < size; i++) {
          data[i] = data[i + 1];
        }
      }
      size--;
      if (size == getCapacity() / 4 && getCapacity() / 2 != 0) {
        ensureCapacity(getCapacity() / 2);
      }
      return ret;
    }

    public boolean contains(T element) {
      for (int i = 0; i < size; i++) {
        if (data[i] == element) {
          return true;
        }
      }
      retrun false;
    }

    public int find(T element) {
      for (int i = 0; i < size; i++) {
        if (data[i] == element) {
          return i;
        }
      }
      return -1;
    }

    public T get(int idx) {
      return data[idx];
    }

    public void delete(T element) {
      int idx = find(element);
      if (idx == -1) {
        return;
      }
      remove(idx);
    }

    @Override
    public String toString() {
      String s = new String();
      StringBuilder stringBuilder = new StringBuilder();
      stringBuilder.append("size:" + size + "\n");
      stringBuilder.append("capacity:" + getCapacity() + "\n");
      stringBuilder.append("[");
      for (int i = 0; i < size; i++) {
        stringBuilder.append(data[i]);
        if (i != size - 1) {
          stringBuilder.append(",");
        }
      }
      stringBuilder.append("]");
      s = stringBuilder.toString();
      return s;
    }

    private void ensureCapacity(int newCapacity) {
      if (newCapacity < size) {
        return;
      }
      T[] old = data;
      data = (T) new Object[newCapacity]; // ?
      for(int i = 0; i < size; i++) {
        data[i] = old[i];
      }
    }
}
