class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if (z == 0)
            return true;
        if (x + y < z || x == 0 || y == 0)
            return false;
        if (z % gcd(x, y) == 0)
            return true;
        else
            return false;
    }

    int gcd(int x, int y) {
        if (x == y)
            return x;
        else if (x > y)
            return gcd(x - y, y);
        else
            return gcd(y - x, x);
    }
}