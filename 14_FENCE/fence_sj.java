import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.ArrayList;

public class fence_sj {
	static StreamTokenizer in;
	static PrintWriter out;
	// 왜 자꾸 오답이라 뜨는거지????????
	public static int solve(int start, int end, ArrayList<Integer> fence) {
		if (start == end)	return fence.get(start);
		
		int mid = (start + end) / 2;
		int ret = Math.max(solve(start, mid, fence), solve(mid + 1, end, fence));
		int left = mid;
		int right = mid + 1;
		int height = Math.min(fence.get(left), fence.get(right));
		
		while (left > start || right < end) {
			if(right < end && (left == start || fence.get(left-1) < fence.get(right+1))){
				++right;
				height = Math.min(height, fence.get(right));
			}else{
				--left;
				height = Math.min(height, fence.get(left));
			}
			ret = Math.max(ret, height * (right - left + 1));
		}
		
		/*
		 * 			int leftHeight = fence.get(left);
			int rightHeight = fence.get(right);
			if (left == start) {
				++right;
				rightHeight = fence.get(right);
				if (rightHeight < height)
					height = rightHeight;

			} else if (right == end) {
				--left;
				leftHeight = fence.get(left);
				if (leftHeight < height)
					height = leftHeight;

			} else {
				if (leftHeight < rightHeight) {
					++right;
					rightHeight = fence.get(right);
					if (rightHeight < height)
						height = rightHeight;
				} else {
					--left;
					leftHeight = fence.get(left);
					if (leftHeight < height)
						height = leftHeight;
				}
			}
		 */
		return ret;
	}

	public static void main(String[] args) throws IOException {
		ArrayList<Integer> fence;
		in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		out = new PrintWriter(new OutputStreamWriter(System.out));
		int testCase = nextInt();
		while (testCase-- > 0) {
			int n = nextInt();
			fence = new ArrayList<>();
			for (int i = 0; i < n; i++)
				fence.add(nextInt());
			out.println(solve(0, n - 1, fence));
			out.flush();
		}

	}

	static int nextInt() throws IOException {
		in.nextToken();
		return (int) in.nval;
	}
}
