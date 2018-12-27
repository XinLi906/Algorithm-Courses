import edu.princeton.cs.algs4.StdRandom;

import java.util.Iterator;
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
        return size == 0;
    }

    public int size() {
        return size;
    }

    private void resize() {
        if (size < capcity) {
            capcity /= 2;
        } else {
            capcity *= 2;
        }
        Item[] temp = (Item[]) new Object[capcity];
        for (int i = 0; i < size; i++) {
            temp[i] = rq[(head + i) % capcity];
        }
        rq = temp;
        head = 0;
        tail = size;
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

    private int swap(int choice) {
        Item temp = rq[choice];
        int target = tail - 1;
        if (tail < 0) {
            target = capcity - 1;
        }
        rq[choice] = rq[target];
        rq[target] = temp;
        return target;
    }

    public void enqueue(Item item) {
        if (size == capcity) {
            resize();
        }
        validate(item);
        rq[tail++] = item;
        if (tail == capcity) {
            tail = 0;
        }
        size++;
    }

    public Item dequeue() {
        checkRemains();
        if (size <= (capcity / 4)) {
            resize();
        }
        int choice = (head + StdRandom.uniform(size)) % capcity;
        tail = swap(choice);
        size--;
        return rq[tail];
    }

    public Item sample() {
        int choice = (head + StdRandom.uniform(size)) % capcity;
        return rq[choice];
    }

    @Override
    public Iterator<Item> iterator() {
        return new RQIterator();
    }

    private class RQIterator implements Iterator<Item> {
        private Item[] iterQueue;
        private int start;

        private RQIterator() {
            iterQueue = (Item[]) new Object[size];
            for (int i = 0; i < size; i++) {
                iterQueue[i] = rq[(head + i) % capcity];
            }
            StdRandom.shuffle(iterQueue);
            start = 0;
        }

        @Override
        public void remove() {
            throw new UnsupportedOperationException();
        }

        @Override
        public boolean hasNext() {
            return start == size;
        }

        @Override
        public Item next() {
            return iterQueue[start++];
        }
    }
}
