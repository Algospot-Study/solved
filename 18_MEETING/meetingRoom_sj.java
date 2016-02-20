import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class meetingRoom {
	static class Pair implements Comparable<Pair> {
		int start, end;
		Pair(int a, int b) {
			start = a;
			end = b;
		}
		@Override
		public int compareTo(Pair pair) {
			// TODO Auto-generated method stub
			if (this.end - pair.end > 0)return 1;
			else	return -1;
		}
	}
	public static int greedy(ArrayList<Pair> team){
		int earliest = 0, selected = 0;
		for(Pair pair : team){
			int start = pair.start;
			int end = pair.end;
			
			if(earliest <= start){
				earliest = end;
				selected++;
			}
		}
		return selected;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int room = sc.nextInt();
		ArrayList<Pair> team = new ArrayList<>();
		for (int i = 0; i < room; i++) {
			team.add(new Pair(sc.nextInt(), sc.nextInt()));
		}
		Collections.sort(team);
		System.out.println(greedy(team));
		sc.close();
	}
}
