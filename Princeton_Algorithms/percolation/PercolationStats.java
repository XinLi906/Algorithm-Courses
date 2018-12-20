/* *****************************************************************************
 *  Name: Xin Li
 *  Date: 20/12/2018
 *  Description: Basic percolation statistics
 **************************************************************************** */

import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;

public class PercolationStats {

    private final double mean;
    private final double stddev;
    private final double confidenceLo;
    private final double confidenceHi;

    public PercolationStats(int n, int trails) {
        if (n <= 0 || trails <= 0) {
            throw new IllegalArgumentException();
        }
        double[] experimentSeries = new double[trails];

        for (int i = 0; i < trails; i++) {
            Percolation perc = new Percolation(n);
            while (!perc.percolates()) {
                int row = StdRandom.uniform(n) + 1;
                int col = StdRandom.uniform(n) + 1;
                perc.open(row, col);
            }
            experimentSeries[i] = perc.numberOfOpenSites() / ((double) (n * n));
        }

        this.mean = StdStats.mean(experimentSeries);
        this.stddev = StdStats.stddev(experimentSeries);
        this.confidenceLo = this.mean - ((1.96 * this.stddev) / Math.sqrt(trails));
        this.confidenceHi = this.mean + ((1.96 * this.stddev) / Math.sqrt(trails));
    }

    public double mean() {
        return this.mean;
    }

    public double stddev() {
        return this.stddev;
    }

    public double confidenceLo() {
        return this.confidenceLo;
    }

    public double confidenceHi() {
        return this.confidenceHi;
    }

    public static void main(String[] args) {
        if (args.length != 2) {
            throw new IllegalArgumentException();
        }
        int n = Integer.parseInt(args[0]);
        int trails = Integer.parseInt(args[1]);

        // StdOut.printf("%d, %d", n, trails);

        PercolationStats ps = new PercolationStats(n, trails);

        StdOut.println("mean:\t\t\t\t\t\t= " + ps.mean());
        StdOut.println("stddev:\t\t\t\t\t\t= " + ps.stddev());
        StdOut.println("95%% confidence interval:\t= " +
                               ps.confidenceLo() + ", " + ps.confidenceHi());
    }
}
