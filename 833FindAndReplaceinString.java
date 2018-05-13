class Solution {
  public String findReplaceString(String S, int[] indexes, String[] sources,
                                  String[] targets) {
    int len = indexes.length;
    for (int i = 0; i < len; i++) {
      int len1 = sources[i].length();
      String s = S.substring(indexes[i], indexes[i] + len1);
      if (!s.equals(sources[i])) {
        indexes[i] = -1;
      }
    }
    for (int i = 0; i < len - 1; i++) {
      for (int j = 0; j < len - i - 1; j++) {
        if (indexes[j] > indexes[j + 1]) {
          int t = indexes[j];
          indexes[j] = indexes[j + 1];
          indexes[j + 1] = t;
          String t1 = targets[j];
          targets[j] = targets[j + 1];
          targets[j + 1] = t1;
          String t2 = sources[j];
          sources[j] = sources[j + 1];
          sources[j + 1] = t2;
        }
      }
    }
    for (int i = len - 1; i >= 0; i--) {
      if (indexes[i] == -1)
        break;
      S = S.substring(0, indexes[i]) + targets[i] +
          S.substring(indexes[i] + sources[i].length());
    }
    return S;
  }
}
