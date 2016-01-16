package ch06;

import java.util.Arrays;
import java.util.Scanner;

public class BoardCover {
	static final int block[][][] = {
			{{1, 0}, {1, 1}},
			{{0, 1}, {1, 1}},
			{{0, 1}, {1, 0}},
			{{1, -1}, {1, 0}}
	};
	public static int cnt = 0;
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int testCase = sc.nextInt();
		int h, w;
		while(testCase > 0){
			h = sc.nextInt();
			w = sc.nextInt();
			char board[][] = new char[h+2][w+2];
			for(int i = 0; i < h+2; i++)
				Arrays.fill(board[i], '#');
			cnt = 0;
			// Making Board
			for(int i = 0; i < h; i++){
				String input = sc.next();
				for (int j = 0; j < w; j++)
					board[i+1][j+1] = input.charAt(j);
			}
			checkBoard(board, h, w, 1, 1);
			System.out.println(cnt);
			--testCase;
		}
		sc.close();
	}
	
	public static boolean isAllChecked(char[][] board, int h, int w){
		for(int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
				if(board[i][j] == '.') return false;
		return true;
	}
	
	public static void checkBoard(char[][] board, int h, int w, int x, int y){
		if(isAllChecked(board, h, w)) {
			cnt++;
			return;
		}
		if(x > w) {
			y++;
			x = 1;
		}
		if(y > h) {
			return;
		}
		for(int i = 0; i < 4; i++){
			boolean canFill = true;
			
			if(board[y][x] == '.'){
				for(int j = 0; j < 2; j++){
					if(board[y + block[i][j][0]][x + block[i][j][1]] != '.'){
						canFill = false;
						break;
					}
				}
			}else canFill = false;
			if(canFill){
				board[y][x] = '#';
				for (int j = 0; j < 2; j++){
					board[y + block[i][j][0]][x + block[i][j][1]] = '#';
				}
				checkBoard(board, h, w, x+1, y);
				
				board[y][x] = '.';
				for (int j = 0; j < 2; j++){
					board[y + block[i][j][0]][x + block[i][j][1]] = '.';
				}
			}
		}
	}
}
