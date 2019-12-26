class Solution {
    public boolean isValid(String s) {
        if (s.isEmpty()) {
            return true;
        }
        Stack<Character> stack = new Stack<Character>();
        int size = s.length();
        int i = 0;
        for (i = 0; i<size; i++) {
            char c1 = s.charAt(i);
            char c2;
            if (!stack.empty())
                c2 = stack.peek();
            else 
                c2 = '*';
            if (c1 == '(' || c1 == '{' || c1 == '[') {
                stack.push(c1);
            } else if (c1 == ')' && c2 == '(') {
                stack.pop();
            } else if (c1 == '}' && c2 == '{') {
                stack.pop();
            } else if (c1 == ']' && c2 == '[') {
                stack.pop();
            } else {
                return false;
            }
        }
        if (stack.empty()) {
            return true;
        } else {
            return false;
        }
    }
}
