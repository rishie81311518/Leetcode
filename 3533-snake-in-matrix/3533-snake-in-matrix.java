class Solution {
    public int finalPositionOfSnake(int n, List<String> commands) {
        int s = 0;
        for (String command: commands) {
            if (command.equals("UP")) s -=n;
            else if(command.equals("DOWN")) s +=n;
            else if(command.equals("LEFT")) s -= 1;
            else s +=1;
        }
        return s;
    }
}