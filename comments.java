import java.nio.file.*;

class Solution {
    public String simplifyPath(String path) {
        return Paths.get(path).normalize().toString();
    }
}