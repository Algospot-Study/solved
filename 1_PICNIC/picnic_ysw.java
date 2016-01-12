import java.util.Scanner;
 
public class Main {
 
    private static int student;
    private static boolean[][] isFriends = new boolean[10][10];
    private static boolean[] isFinished = new boolean[10];
 
    public static void main(String[] args) {
        int caseSize;
        Scanner mScanner = new Scanner(System.in);
        caseSize = mScanner.nextInt();
 
        for (int i = 0; i < caseSize; i++) {
            int asFriends;
            student = mScanner.nextInt();
            asFriends = mScanner.nextInt();
 
            for (int j = 0; j < asFriends; j++) {
                int a = mScanner.nextInt(), b = mScanner.nextInt();
                isFriends[a][b] = true;
                isFriends[b][a] = true;
            }
 
            System.out.println(getMateNumber(isFinished, 0));
 
        }
    }
 
    private static boolean isDone(boolean[] isFinished) {
        for (boolean element : isFinished) {
            if (!element) return false;
        }
        return true;
    }
 
    private static int getMateNumber(boolean[] isFinished, int startFlag) {
        int ret = 0;
        if (isDone(isFinished)) return 1;
        for (int i = startFlag; i < student; i++) {
            if (!isFinished[i]) {
                for (int j = i + 1; j < student; ++j) {
                    if ((isFriends[i][j]) && (!isFinished[j])) {
                        isFinished[i] = true;
                        isFinished[j] = true;
                        ret += getMateNumber(isFinished, i + 1);
                        isFinished[i] = false;
                        isFinished[j] = false;
                    }
                }
            }
        }
        return ret;
    }
}