import java.util.Scanner;

public class HelpKingdom {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		while (scan.hasNext()) {
			String input = scan.next();
			int point = 0;
			if (input.contains(".")) {
				for (int i = 0; i < input.length(); i++) {
					if (input.charAt(i) == '.') {
						point = i - 1;
						if (input.length() - i == 2)
							input = input.substring(0, i + 2) + "0";
						else
							input = input.substring(0, i + 3);
					}
				}
			} else {
				input = input + ".00";
				point = input.length() - 4;
			}
			// before point
			int counter = 0;
			boolean isNegative = false;
			if (input.charAt(0) == '-') {
				input = input.substring(1);
				isNegative = true;
				point--;
			}
			for (int i = point; i > 0; i--) {
				counter++;
				if (counter == 3) {
					input = input.substring(0, i) + ","
							+ input.substring(i, input.length());
					counter = 0;
				}
			}
			if (isNegative)
				input = "($" + input + ")";
			else
				input = "$" + input;
			System.out.println(input);
		}
	}
}// -211514515170.9279827682