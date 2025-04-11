/*
[rotation]
5
1 2 1
2 2 1
3 2 1
-1

[rocket]
10
2 2 1
1 2 1
0 2 1
2 1 1
1 0 1
-1
*/
package project1;
import java.util.Scanner;

public class Main {
    static int tableSize;
    static boolean[][] table;
    static void setTable(Scanner in) {
        System.out.println("[table set method called]");
        System.out.println("...enter 3 integers to set up the table");
        System.out.println("...example: [3, 4, 1] > setting the table[3][4] = true/alive");
        System.out.println("...example: [2, 7, 0] > setting the table[2][7] = false/dead");
        System.out.println("...enter [-1] to terminate the method");
        int row, column, value;
        while (true) {
            System.out.println("[current table]");
            viewTable();
            System.out.print("input: ");
            row = in.nextInt();
            if(row < 0 || tableSize <= row) {
                System.out.println("terminating the method\n");
                return;
            }
            column = in.nextInt();
            if(column < 0 || tableSize <= column) {
                System.out.println("terminating the method\n");
                return;
            }
            value = in.nextInt();
            if(value==0) table[row][column]=false;
            else table[row][column]=true;
        }
    }
    static void viewTable() {
        for(int i=0; i<tableSize; i++) {
            for(int j=0; j<tableSize; j++) {
                if(table[i][j]) System.out.print("O");
                else System.out.print("_");
            }
            System.out.println();
        }
    }
    static boolean checkNextGeneration(int row, int column) {
        int count = 0;
        if(table[row][column]) {
            if(table[(row+1+tableSize)%tableSize][(column+1+tableSize)%tableSize]) count++;
            if(table[(row+1+tableSize)%tableSize][(column+tableSize)%tableSize]) count++;
            if(table[(row+1+tableSize)%tableSize][(column-1+tableSize)%tableSize]) count++;
            if(table[(row+tableSize)%tableSize][(column+1+tableSize)%tableSize]) count++;
            if(table[(row+tableSize)%tableSize][(column-1+tableSize)%tableSize]) count++;
            if(table[(row-1+tableSize)%tableSize][(column+1+tableSize)%tableSize]) count++;
            if(table[(row-1+tableSize)%tableSize][(column+tableSize)%tableSize]) count++;
            if(table[(row-1+tableSize)%tableSize][(column-1+tableSize)%tableSize]) count++;
//            System.out.println("🔴 debugging: " + "[" + row + ", " + column + "], true, " + count);
//            viewTable();
            if(count==2 || count==3) return true;
        }
        else {
            if(table[(row+1)%tableSize][(column+1)%tableSize]) count++;
            if(table[(row+1+tableSize)%tableSize][(column+tableSize)%tableSize]) count++;
            if(table[(row+1+tableSize)%tableSize][(column-1+tableSize)%tableSize]) count++;
            if(table[(row+tableSize)%tableSize][(column+1+tableSize)%tableSize]) count++;
            if(table[(row+tableSize)%tableSize][(column-1+tableSize)%tableSize]) count++;
            if(table[(row-1+tableSize)%tableSize][(column+1+tableSize)%tableSize]) count++;
            if(table[(row-1+tableSize)%tableSize][(column+tableSize)%tableSize]) count++;
            if(table[(row-1+tableSize)%tableSize][(column-1+tableSize)%tableSize]) count++;
//            System.out.println("🔴 debugging: " + "[" + row + ", " + column + "], false, " + count);
//            viewTable();
            if(count==3) return true;
        }
        return false;
    }
    static void progressGeneration() {
        boolean[][] newTable = new boolean[tableSize][tableSize];
        for(int i=0; i<tableSize; i++) {
            for(int j=0; j<tableSize; j++) {
                if(checkNextGeneration(i,j)) newTable[i][j]=true;
                else newTable[i][j]=false;
            }
        }
        table = newTable;
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("enter the table size: ");
        tableSize = in.nextInt();
        table = new boolean[tableSize][tableSize];
        for(int i=0; i<tableSize; i++) {
            for(int j=0; j<tableSize; j++) {
                table[i][j] = false;
            }
        }
        setTable(in);

        int loop = 10, count = 0;
        while (true) {
            System.out.println("\n\n[viewing the " + count + "th generation]");
            viewTable();
            progressGeneration();
            count++;
            if(count == loop) break;
        }
        System.out.println("\n\n[viewing the " + loop + "th generation]");
        viewTable();
    }
}