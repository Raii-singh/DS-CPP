
class Solution {
    private static final long MOD = 1_000_000_007L;

    public int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int size = 2 * m;

        long[] base = new long[size];

        // Length = 2
        for (int v = 0; v < m; v++) {
            base[v] = v;                 // up[v]
            base[m + v] = m - 1 - v;    // down[v]
        }

        long[][] T = new long[size][size];

        // up[v] = sum(down[u]) for u < v
        for (int v = 0; v < m; v++) {
            for (int u = 0; u < v; u++) {
                T[v][m + u] = 1;
            }
        }

        // down[v] = sum(up[u]) for u > v
        for (int v = 0; v < m; v++) {
            for (int u = v + 1; u < m; u++) {
                T[m + v][u] = 1;
            }
        }

        long[] state = powerApply(T, n - 2, base);

        long ans = 0;
        for (long x : state) {
            ans = (ans + x) % MOD;
        }

        return (int) ans;
    }

    private long[] powerApply(long[][] mat, long exp, long[] vec) {
        int n = mat.length;

        long[][] result = identity(n);

        while (exp > 0) {
            if ((exp & 1) == 1) {
                result = multiply(result, mat);
            }
            mat = multiply(mat, mat);
            exp >>= 1;
        }

        return multiply(result, vec);
    }

    private long[][] identity(int n) {
        long[][] id = new long[n][n];
        for (int i = 0; i < n; i++) {
            id[i][i] = 1;
        }
        return id;
    }

    private long[][] multiply(long[][] A, long[][] B) {
        int n = A.length;
        long[][] C = new long[n][n];

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                long a = A[i][k];

                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] = (C[i][j] + a * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    private long[] multiply(long[][] A, long[] v) {
        int n = A.length;
        long[] res = new long[n];

        for (int i = 0; i < n; i++) {
            long sum = 0;

            for (int j = 0; j < n; j++) {
                if (A[i][j] == 0) continue;
                sum = (sum + A[i][j] * v[j]) % MOD;
            }

            res[i] = sum;
        }

        return res;
    }
}