/* *****************************************************************************
 *  Name: Xin Li
 *  Date: 20/12/2018
 *  Description: A naive implemention of percolation system.
 **************************************************************************** */

import edu.princeton.cs.algs4.ResizingArrayBag;
import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {

    private final int head;
    private final int tail;
    private final int n;
    private final WeightedQuickUnionUF wquuf;
    private final WeightedQuickUnionUF wquufWithoutBottom;

    private int numOfOpenedSites;
    private boolean[] opened;

    public Percolation(int n) {
        if (n <= 0) {
            throw new IllegalArgumentException();
        }
        this.head = 0;
        this.n = n;
        this.tail = n * n + 1;
        this.numOfOpenedSites = 0;
        opened = new boolean[n * n + 2];
        opened[0] = true;
        opened[n * n + 1] = true;
        wquuf = new WeightedQuickUnionUF(n * n + 2);
        wquufWithoutBottom = new WeightedQuickUnionUF(n * n + 1);
    }

    private boolean validate(int row, int col) {
        return (row >= 1 && row <= this.n && col >= 1 && col <= this.n);
    }

    private int flatten(int row, int col) {
        if (this.validate(row, col)) {
            return (row - 1) * this.n + col;
        }
        else {
            throw new IllegalArgumentException();
        }
    }

    private Iterable<Integer> neighbours(int row, int col) {
        ResizingArrayBag<Integer> bag = new ResizingArrayBag<Integer>();
        if (validate(row - 1, col)) {
            bag.add(this.flatten(row - 1, col));
        }
        if (validate(row + 1, col)) {
            bag.add(this.flatten(row + 1, col));
        }
        if (validate(row, col - 1)) {
            bag.add(this.flatten(row, col - 1));
        }
        if (validate(row, col + 1)) {
            bag.add(this.flatten(row, col + 1));
        }

        return bag;
    }

    private boolean isCeil(int row, int col) {
        return this.flatten(row, col) <= n;
    }

    private boolean isFloor(int row, int col) {
        return this.flatten(row, col) > ((n - 1) * n);
    }

    public void open(int row, int col) {
        int current = this.flatten(row, col);
        if (this.opened[current]) {
            return;
        }
        numOfOpenedSites++;
        this.opened[current] = true;
        if (this.isCeil(row, col)) {
            this.wquuf.union(this.head, current);
            this.wquufWithoutBottom.union(this.head, current);
        }
        if (this.isFloor(row, col)) {
            this.wquuf.union(this.tail, current);
        }
        for (int neighbour : this.neighbours(row, col)) {
            if (this.opened[neighbour]) {
                wquuf.union(current, neighbour);
                wquufWithoutBottom.union(current, neighbour);
            }
        }
    }

    public boolean isOpen(int row, int col) {
        return opened[this.flatten(row, col)];
    }

    public boolean isFull(int row, int col) {
        return this.wquufWithoutBottom.connected(this.head,
                                                 this.flatten(row, col));
    }

    public int numberOfOpenSites() {
        return numOfOpenedSites;
    }

    public boolean percolates() {
        return this.wquuf.connected(this.head, this.tail);
    }
}
