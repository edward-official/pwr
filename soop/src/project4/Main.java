package project4;

import java.util.Vector;

public class Main {
    public static void main(String[] args) {
        Vector<TreeDetail> treeDetails = new Vector<TreeDetail>();
        TreeDetail tree1 = new TreeDetail(4, 2, 2);
        TreeDetail tree2 = new TreeDetail(2, 4, 6);
        treeDetails.add(tree1);
        treeDetails.add(tree2);
        TreeBoard.drawTree(tree2);
        TreeBoard.drawMultipleTrees(treeDetails);
    }
}
