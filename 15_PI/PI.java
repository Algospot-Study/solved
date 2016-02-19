package pi;

import java.io.IOException;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class PI {
	static StreamTokenizer in;
	static PrintWriter out;
	static String pi;
	
	static Map<Pair, Integer> adj;
	
	static final int INF = 987654321;
	public static class Pair{
		int val_1;
//		int val_2;
		Pair(int a){
			val_1 = a;
//			val_2 = b;
		}
	}
	public static void main(String[] args) throws IOException {

//		in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
//		out = new PrintWriter(new OutputStreamWriter(System.out));
//		int testCase = nextInt();
		Scanner sc = new Scanner(System.in);
		int testCase = sc.nextInt();
		while (testCase-- > 0) {
			adj = new HashMap<Pair, Integer>();
//			pi = Integer.toString(nextInt());
			pi = sc.next();
//			pair = new int[pi.length()];
//			out.println(Math.min(solve(0,3), Math.min(solve(0,4), solve(0,5))));
//			out.flush();
			int ret = Math.min(solve(0,3), Math.min(solve(0,4), solve(0,5)));
			System.out.println(ret);

		}
	}

	static int solve(int start, int end) {
		int ret = INF;
		
		Pair pair = new Pair(start);
		// base case
		// 남은 것이랑 end로 들어온거랑 매치 안될 경우 inf return
		if(pi.length() < end){
			return INF;
		}
		
		if(adj.containsKey(pair)){
			return adj.get(pair);
		}
		
		
		int myRank = rank(pi.substring(start, end));
		
		if(pi.length() == end){
			adj.put(pair, myRank);
			return myRank;
		}
		else{
			ret = Math.min(Math.min(solve(end, end+3),  solve(end, end+4)), solve(end, end+5));
			adj.put(pair, myRank + ret);
			return myRank + ret;
		}
	}

	static int rank(String token){
		int[] _d = new int[token.length()-1];
		for (int i = 0; i < token.length()-1; i++){
			_d[i] = token.substring(i,i+1).compareTo(token.substring(i+1, i+2)); 
		}
		// 난이도 1
		int rank_1 = 1;
		int rank_2_up = 2;
		int rank_2_down = 2;
		int rank_4 = 4;
		int rank_5 = 5;
		int rank_10 = 10;
		
		for(int i = 0; i < token.length()-1; i++){
			if(_d[i] != 0 && rank_1 == 1) rank_1 = INF;
			if(_d[i] != -1 && rank_2_up == 2){
				rank_2_up = INF;
			}
			if(_d[i] != 1 && rank_2_down == 2){
				rank_2_down = INF;
			}
			if(i+1<token.length()-1&&_d[i] != -1*_d[i+1] && rank_4 == 4){
				rank_4 = INF;
			}
			if(i+1<token.length()-1 && _d[i] != _d[i+1] && rank_5 == 5){
				rank_5 = INF;
			}
		}
		return Math.min(rank_1, Math.min(rank_2_down, Math.min(rank_2_up, Math.min(rank_4, Math.min(rank_5, rank_10)))));
	}

	static int nextInt() throws IOException {
		in.nextToken();
		return (int) in.nval;
	}
}
