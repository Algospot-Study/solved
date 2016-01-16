package ch19;

import java.util.Scanner;
import java.util.Stack;

public class Brackets2 {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		int testCase = sc.nextInt();
		
		outer:
		while(testCase > 0){
			Stack<String> _stack = new Stack<>();
			String brackets = sc.next();
			
			for(int i = 0; i < brackets.length(); i++){
				String bracket = brackets.substring(i,i+1);
				
				if(bracket.equals("(") || bracket.equals("{") || bracket.equals("["))
					_stack.push(bracket);
				else{
					try{
						String tmp = _stack.pop();
						if(bracket.equals(")") && tmp.equals("("))
							continue;
						else if(bracket.equals("]") && tmp.equals("["))
							continue;
						else if(bracket.equals("}") && tmp.equals("{"))
							continue;
						else{
							System.out.println("NO");
							--testCase;
							continue outer;
						}
					}catch(Exception e){
						System.out.println("NO");
						--testCase;
						continue outer;
					}
					
				}
			}
			if(_stack.isEmpty()){
				System.out.println("YES");
			}
			else
				System.out.println("NO");
			
			--testCase;
		}
		sc.close();
		
	}
}
