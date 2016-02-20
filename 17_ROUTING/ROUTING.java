package routing;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class ROUTING {
	static final int INF = 987654321;

	static class Pair {
		int vertex;
		double edge;

		Pair(int a, double b) {
			vertex = a;
			edge = b;
		}
	}

	static int n;
	static int m;
	static ArrayList<ArrayList<Pair>> adj;

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int testCase = sc.nextInt();
		while(testCase-- > 0){
			n = sc.nextInt();
			m = sc.nextInt();
			adj = new ArrayList<>(n);
			for(ArrayList<Pair> ar : adj){
				ar = new ArrayList<>(n);
			}
			for (int i = 0; i < m; i++){
				int a = sc.nextInt();
				int b = sc.nextInt();
				double c = sc.nextFloat();
				Pair pair1 = new Pair(b, c);
				Pair pair2 = new Pair(a, c);
				if(adj.isEmpty())
					adj.get(a).add(pair1);
				else{
					ArrayList<Pair> al = new ArrayList<>();
					al.add(pair1);
					adj.add(a, al);
				}
					
				if(adj.isEmpty())
					adj.get(b).add(pair2);
				else{
					ArrayList<Pair> al = new ArrayList<>();
					al.add(pair2);
					adj.add(b, al);
				}
					
				
			}
			System.out.println(dijkstra());
			
		}
		sc.close();
	}

	static double[] dijkstra() {
		double[] dist = new double[n];
		Arrays.fill(dist, INF);

		PriorityQueue<Pair> pq = new PriorityQueue<>();
		pq.add(new Pair(0, 1));
		dist[0] = 1;

		while (!pq.isEmpty()) {
			int v = pq.peek().vertex;
			double e = -pq.peek().edge;
			pq.remove();

			if (dist[v] < e)
				continue;

			for (int i = 0; i < adj.get(v).size(); ++i) {
				int there = adj.get(v).get(i).vertex;
				double nextDist = e * adj.get(v).get(i).edge;

				if (dist[there] > nextDist) {
					dist[there] = nextDist;
					pq.add(new Pair(there, -nextDist));
				}
			}
		}
		return dist;
	}

}
