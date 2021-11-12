public class LinkedList<T> {
  
  private class Node {
    T data;
    Node next;
    public Node() {
      data = null;
      next = null;
    }
    public Node(T data, Node next) {
      this.data = data;
      this.next = next;
    }
  }

  private Node head;
  private int size;

  public LinkedList() {
    head = new Node();
    size = 0;
  }

  public boolean isEmpty() {
    return head.next == null;
  }

  public int getSize() {
    return size;
  }

  public boolean contains(T data) {
    if (isEMpty()) {
      return false;
    }
    Node prev = head;
    while (prev.next != null) {
      prev = prev.next;
      if (prev.data == data) {
        return true;
      }
    }
    return false;
  }

  public T getFirst() {
    Node prev = head.next;
    return prev.data;
  }

  public T get(int idx) {
    Node prev = getNode(idx);
    return prev.data;
  }

  public T getLast() {
    return get(size - 1);
  }

  public void addFirst(T data) {
    add(0, data);
  }

  public void addLast(T data) {
    add(size, data);
  }

  public void add(int idx, T data) {
    Node prev;
    if (idx == 0) {
      prev = head;
    } else {
      prev = getNode(idx - 1);
    }
    Node node = new Node(data, prev.next);
    prev.next = node;
    size++;
  }

  public void removeFirst() {
    remove(0);
  }

  public void removeLast() {
    remove(size - 1);
  }

  public void remove(int idx) {
    Node prev;
    if (idx == 0) {
      prev = head;
    } else {
      prev = getNode(idx - 1);
    }
    Node outNode = prev.next;
    prev.next = outNode.next;
    outNode.next = null;
    size--;
  }

  public int find(T data) {
    Node prev = head.next;
    int idx = 0;
    while (prev != null) {
      if (prev.data == data) {
        break;
      }
      prev = prev.next;
      idx++;
    }
    return idx;
  }

  private Node getNode(int idx) {
    if (idx >= size || idx < 0) {
      throw new IllegalArgumentException("index out of bound");
    }
    Node prev = head.next;
    while (prev != null) {
      if (idx == 0) {
        break;
      }
      prev = prev.next;
      idx--;
    }
    return prev;
  }

  public String toString() {
    StringBuilder strb = new StringBuilder();
    strb.append("链表: ");
    strb.append("size = " + size + "\n");
    strb.append("[");
    Node prev = head;
    while (prev.next != null) {
      prev = prev.next;
      strb.append(prev.data);
      if (prev.next != null) {
        strb.append(",");
      }
    }
    strb.append("]");
    return strb.toString();
  }
}
