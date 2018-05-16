class Solution {
  /*
  原来的两个数的异或值，也就是不需要进位的那些位的值，
  下面的数是原来两个数的取与的值向左移一位，
  也就是进位后的值。重复这个操作，直到进位制为0
  */
    public int getSum(int a, int b) {
        while(a != 0){
          int temp = (a & b) << 1;  //  与 左移一位
          b = a ^ b; //  异或
          a = temp;
        }
        return b;
    }
}
