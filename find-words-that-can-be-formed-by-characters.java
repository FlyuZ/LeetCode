class Solution {
    public int countCharacters(String[] words, String chars) {
        int[] temp = new int[26];
        for (int i = 0; i < chars.length(); i++) {
            int index = chars.charAt(i) - 'a';
            temp[index]++;
        }
        int ans = 0;
        for (int i = 0; i < words.length; i++) {
            int[] cur = new int[26];
            int flag = 1;
            for (int j = 0; j < words[i].length(); j++) {
                int index = words[i].charAt(j) - 'a';
                cur[index]++;
                if (cur[index] > temp[index]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
                ans += words[i].length();
        }
        return ans;
    }
}