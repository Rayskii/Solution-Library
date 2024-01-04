void gospers_hack(const int& k, const int& n) {
    int curr = (1 << k) - 1;
    int limit = (1 << n);
    while (curr < limit) {
        // Do something.
        int lb = lower_bit(curr);
        int r = curr + lb;
        curr = ((r ^ curr) >> __builtin_ctz(lb) + 2) | r;
    }
}