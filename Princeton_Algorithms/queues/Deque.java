import java.util.Iterator;
import java.util.NoSuchElementException;

public class Deque<Item> implements Iterable<Item> {

    private int size;
    private Node<Item> head;
    private Node<Item> tail;

    private class Node<Item> {
        private Item item;
        private Node<Item> next;
        private Node<Item> prev;

    }

    public Deque() {
        head = tail = null;
        size = 0;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int size() {
        return size;
    }

    private void validate(Item item) {
        if (item == null) {
            throw new IllegalArgumentException();
        }
    }

    private void checkRemains() {
        if (!isEmpty()) {
            throw new NoSuchElementException();
        }
    }

    public void addFirst(Item item) {
        validate(item);
        size++;
        Node<Item> newNode = new Node<Item>();
        newNode.item = item;
        newNode.next = newNode.prev = null;
        if (head == null) {
            head = tail = newNode;
            return;
        }
        head.prev = newNode;
        newNode.next = head;
        head = head.prev;
    }

    public void addLast(Item item) {
        validate(item);
        size++;
        Node<Item> newNode = new Node<Item>();
        newNode.item = item;
        newNode.next = newNode.prev = null;
        if (tail == null) {
            head = tail = newNode;
            return;
        }
        tail.next = newNode;
        newNode.prev = tail;
        tail = tail.next;
    }

    public Item removeFirst() {
        checkRemains();
        size--;
        Item temp = head.item;
        if (head == tail) {
            head = tail = null;
        } else {
            head = head.next;
            head.prev = null;
        }
        return temp;
    }

    public Item removeLast() {
        checkRemains();
        size--;
        Item temp = tail.item;
        if (tail == head) {
            head = tail = null;
        } else {
            tail = tail.prev;
            tail.next = null;
        }
        return temp;
    }

    @Override
    public Iterator<Item> iterator() {
        return new queueIterator<Item>(head);
    }

    private class queueIterator<Item> implements Iterator<Item> {
        private Node<Item> current;

        public queueIterator(Node<Item> head) {
            current = head;
        }

        public boolean hasNext() {
            return current != null;
        }

        public void remove() {
            throw new UnsupportedOperationException();
        }

        public Item next() {
            if (!hasNext()) {
                throw new NoSuchElementException();
            }
            Item temp = current.item;
            current = current.next;
            return temp;
        }
    }

    public static void main(String[] args) {
        Deque<Integer> deque = new Deque<Integer>();
        for (int i = 0; i < 70; i++) {
            deque.addLast(i);
        }
        for (int i : deque) {
            System.out.printf("%d, ", i);
        }
    }

}
