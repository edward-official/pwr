package project4;
import java.util.*;


class TreeDetail {
    private int segmentQuantity, segmentHeight, offsetX;
    TreeDetail(int segmentQuantity, int segmentHeight, int offsetX) {
        this.segmentQuantity = segmentQuantity;
        this.segmentHeight = segmentHeight;
        this.offsetX = offsetX;
    }
    int getSegmentQuantity() {return segmentQuantity;}
    int getSegmentHeight() {return segmentHeight;}
    int getOffsetX() {return offsetX;}
}
public class TreeBoard {
    static void drawTree(TreeDetail treeDetail) {
        int segmentQuantity = treeDetail.getSegmentQuantity();
        int segmentHeight = treeDetail.getSegmentHeight();
        int offsetX = treeDetail.getOffsetX();
        for (int i = 0; i < segmentQuantity; i++) {
            for (int j = 0; j < segmentHeight; j++) {
                int stars = 1 + 2 * j;
                int spaces = offsetX + segmentHeight - j - 1;
                System.out.println(" ".repeat(spaces) + "*".repeat(stars));
            }
        }
        System.out.println(" ".repeat(offsetX + segmentHeight - 1) + "|");
    }
    static void drawMultipleTrees(Vector<TreeDetail> treeDetails) {
        int maxHeight = 0, maxWidth = 0;
        for (TreeDetail treeDetail : treeDetails) {
            maxHeight = Math.max(maxHeight, treeDetail.getSegmentQuantity() * treeDetail.getSegmentHeight());
            maxWidth = Math.max(maxWidth, treeDetail.getOffsetX() + treeDetail.getSegmentHeight() * 2);
        }
        char[][] board = new char[maxHeight+1][maxWidth];
        for (char[] row : board) java.util.Arrays.fill(row, ' ');
        for (TreeDetail treeDetail : treeDetails) {
            int segmentHeight = treeDetail.getSegmentHeight();
            int segmentQuantity = treeDetail.getSegmentQuantity();
            int offsetX = treeDetail.getOffsetX();
            for (int i = 0; i < segmentQuantity; i++) {
                for (int j = 0; j < segmentHeight; j++) {
                    int stars = 1 + 2 * j;
                    int spaces = offsetX + segmentHeight - j - 1;
                    for (int k = 0; k < stars; k++) {
                        board[i * segmentHeight + j][spaces + k] = '*';
                    }
                }
            }
            board[segmentQuantity * segmentHeight][offsetX + segmentHeight - 1] = '|';
        }
        for (char[] row : board) System.out.println(new String(row));
    }
}
