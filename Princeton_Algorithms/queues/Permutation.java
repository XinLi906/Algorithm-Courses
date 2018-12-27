import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Permutation {
    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        StdOut.print(n);
        RandomizedQueue<String> rq = new RandomizedQueue<>();
        String input[] = StdIn.readAllLines();
        for (int i = 0; i < input.length; i++) {
            rq.enqueue(input[i]);
        }
        for (int i = 0; i < n; i++) {
            StdOut.println(rq.dequeue());
        }
    }
}
