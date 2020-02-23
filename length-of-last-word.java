class Solution {
    public int lengthOfLastWord(String s) {
        String[] newStr = s.split("\\s+");
        if (newStr.length == 0)
            return 0;
        else
            return newStr[newStr.length - 1].length();
    }
}