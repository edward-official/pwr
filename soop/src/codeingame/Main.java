package codeingame;
import java.util.*;

class Main {

    static final int sizeX = 40, sizeY = 18;
    static int[][] map = new int[sizeX][sizeY];

    static void change(int x1, int y1, int x2, int y2) {
        int t;
        t = map[x1][y1];
        map[x1][y1] = map[x2][y2];
        map[x2][y2] = t;
    }
    static boolean isAroungEmpty(int x, int y) {
        if(x==0 && y==0) {
            if(map[x+1][y]==2) return false;
            else if(map[x+1][y+1]==2) return false;
            else if(map[x][y+1]==2) return false;
            else return true;
        }
        else if(x==0 && y==17) {
            if(map[x+1][y]==2) return false;
            else if(map[x+1][y-1]==2) return false;
            else if(map[x][y-1]==2) return false;
            else return true;
        }
        else if(x==39 && y==0) {
            if(map[x-1][y]==2) return false;
            else if(map[x-1][y+1]==2) return false;
            else if(map[x][y+1]==2) return false;
            else return true;
        }
        else if(x==39 && y==17) {
            if(map[x-1][y]==2) return false;
            else if(map[x-1][y-1]==2) return false;
            else if(map[x][y-1]==2) return false;
            else return true;
        }
        else if(x==0) {
            if(map[x][y+1]==2) return false;
            else if(map[x][y-1]==2) return false;
            else if(map[x+1][y+1]==2) return false;
            else if(map[x+1][y]==2) return false;
            else if(map[x+1][y-1]==2) return false;
            else return true;
        }
        else if(x==39) {
            if(map[x][y+1]==2) return false;
            else if(map[x][y-1]==2) return false;
            else if(map[x+1][y+1]==2) return false;
            else if(map[x+1][y]==2) return false;
            else if(map[x+1][y-1]==2) return false;
            else return true;
        }
        else if(y==0) {
            if(map[x+1][y]==2) return false;
            else if(map[x-1][y]==2) return false;
            else if(map[x+1][y+1]==2) return false;
            else if(map[x][y+1]==2) return false;
            else if(map[x-1][y+1]==2) return false;
            else return true;
        }
        else if(y==17) {
            if(map[x+1][y]==2) return false;
            else if(map[x-1][y]==2) return false;
            else if(map[x+1][y-1]==2) return false;
            else if(map[x][y-1]==2) return false;
            else if(map[x-1][y-1]==2) return false;
            else return true;
        }
        else {
            if(map[x+1][y+1]==2) return false;
            if(map[x+1][y]==2) return false;
            if(map[x+1][y-1]==2) return false;
            if(map[x][y+1]==2) return false;
            if(map[x][y-1]==2) return false;
            if(map[x-1][y+1]==2) return false;
            if(map[x-1][y]==2) return false;
            if(map[x-1][y-1]==2) return false;
            else return true;
        }
    }
    static boolean isAroundNotEmpty(int x, int y) {
        if(x==0 && y==0) {
            if(map[x+1][y]==2) return true;
            else if(map[x+1][y+1]==2) return true;
            else if(map[x][y+1]==2) return true;
            else return false;
        }
        else if(x==0 && y==17) {
            if(map[x+1][y]==2) return true;
            else if(map[x+1][y-1]==2) return true;
            else if(map[x][y-1]==2) return true;
            else return false;
        }
        else if(x==39 && y==0) {
            if(map[x-1][y]==2) return true;
            else if(map[x-1][y+1]==2) return true;
            else if(map[x][y+1]==2) return true;
            else return false;
        }
        else if(x==39 && y==17) {
            if(map[x-1][y]==2) return true;
            else if(map[x-1][y-1]==2) return true;
            else if(map[x][y-1]==2) return true;
            else return false;
        }
        else if(x==0) {
            if(map[x][y+1]==2) return true;
            else if(map[x][y-1]==2) return true;
            else if(map[x+1][y+1]==2) return true;
            else if(map[x+1][y]==2) return true;
            else if(map[x+1][y-1]==2) return true;
            else return false;
        }
        else if(x==39) {
            if(map[x][y+1]==2) return true;
            else if(map[x][y-1]==2) return true;
            else if(map[x+1][y+1]==2) return true;
            else if(map[x+1][y]==2) return true;
            else if(map[x+1][y-1]==2) return true;
            else return false;
        }
        else if(y==0) {
            if(map[x+1][y]==2) return true;
            else if(map[x-1][y]==2) return true;
            else if(map[x+1][y+1]==2) return true;
            else if(map[x][y+1]==2) return true;
            else if(map[x-1][y+1]==2) return true;
            else return false;
        }
        else if(y==17) {
            if(map[x+1][y]==2) return true;
            else if(map[x-1][y]==2) return true;
            else if(map[x+1][y-1]==2) return true;
            else if(map[x][y-1]==2) return true;
            else if(map[x-1][y-1]==2) return true;
            else return false;
        }
        else {
            if(map[x+1][y+1]==2) return true;
            if(map[x+1][y]==2) return true;
            if(map[x+1][y-1]==2) return true;
            if(map[x][y+1]==2) return true;
            if(map[x][y-1]==2) return true;
            if(map[x-1][y+1]==2) return true;
            if(map[x-1][y]==2) return true;
            if(map[x-1][y-1]==2) return true;
            else return false;
        }
    }

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int TX = in.nextInt();
        int TY = in.nextInt();

        // Initializing the map
        for(int i=0; i<sizeX; i++) for(int j=0; j<sizeY; j++) map[i][j] = -1;
        map[TX][TY] = 1;
        // game loop
        while (true) {
            int H = in.nextInt(); // the remaining number of hammer strikes.
            int N = in.nextInt(); // the number of giants which are still present on the map.
            for (int i = 0; i < N; i++) {
                int X = in.nextInt();
                int Y = in.nextInt();
                map[X][Y] = 2;
            }

            // Write an action using System.out.println()
            // To debug: System.err.println("Debug messages...");


            // The movement or action to be carried out: WAIT STRIKE N NE E SE S SW W or N
            System.out.println("WAIT");
        }
    }
}