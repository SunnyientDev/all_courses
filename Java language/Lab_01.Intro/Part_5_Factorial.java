import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner Data_In = new Scanner(System.in);
        
        System.out.print("Enter the number to calculate factorial: ");
        int N = Data_In.nextInt();
        long Fact = Fact(N);

        System.out.println("The factorial of N is: "+ Fact);
    }

    public static long Fact(int N){
        if(N == 0) return 1;
        return N * Fact(N-1);
    }
}
