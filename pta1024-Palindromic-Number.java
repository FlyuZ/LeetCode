import java.math.BigInteger;
import java.util.*;

public class Main {
	static boolean judge(String s) {
		int len = s.length();
		for (int i = 0; i < len / 2; i++) {
			if (s.charAt(i) != s.charAt(len - i - 1)) {
				return false;
			}
		}
		return true;
	}

	static String re(String s) {
		String r = "";
		for (int i = s.length() - 1; i >= 0; i--) {
			r += s.charAt(i);
		}
		return r;
	}

	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		BigInteger a = cin.nextBigInteger();
		if (judge(a.toString())) {
			System.out.println(a);
			System.out.println(0);
			return;
		}
		int b = cin.nextInt();
		cin.close();
		BigInteger ans = a;
		String s = a.toString();
		for (int i = 1; i <= b; i++) {
			s = re(s);
			BigInteger temp = new BigInteger(s);
			ans = ans.add(temp);
			s = ans.toString();
			if (judge(ans.toString())) {
				System.out.println(ans);
				System.out.println(i);
				return;
			}
		}
		System.out.println(ans);
		System.out.println(b);
	}
}
