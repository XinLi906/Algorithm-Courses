import java.util.NoSuchElementException;

public class RandomizedQueue<Item> implements Iterable<Item> {

    private Item[] rq;
    private int size;
    private int capcity;
    private int head;
    private int tail;

    public RandomizedQueue() {
        capcity = 2;
        rq = (Item[]) new Object[capcity];
        size = head = tail = 0;
    }

    public boolean isEmpty() {
        return (boolean) size;
    }

    public int size() {
        return size;
    }

    private void resize() {
        capcity *= 2;
        Item[] temp = (Item[]) new Object[capcity];
        for (int i = 0; i < size; i++) {
            temp[i] = rq[(first + i) % q.length];
        }
        rq = temp;
        head = 0;
        last = size;
    }

    private void validate(Item item) {
        if (item == null) {
            throw new IllegalArgumentException();
        }
    }

    private void checkRemains() {
        if (isEmpty()) {
            throw new NoSuchElementException();
        }
    }

    public void enqueue(Item item) {
        if (size == rq.length) {
            resize();
        }
        validate(item);
        rq[last++] = item;
        if (last == capcity) {
            last = 0;
        }
        size++;
    }

    public Item dequeue() {
        checkRemains();
        Item randomItem = 
    }

    public Item sample() {

    }

    public Iterator<Item> Iterator() {

    }
}