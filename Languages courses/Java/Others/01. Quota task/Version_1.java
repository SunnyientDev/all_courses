//Be careful there is O(n^3)
import java.util.Scanner;

public class Main
{
	public static void main(String[] args) {
	    Scanner Data_In = new Scanner(System.in);
		int Count = 0; 
		
		System.out.print("Please, enter N: ");
		int Number = Data_In.nextInt();
        int num1 = 0, num3 = 0, num5 = 0;
        
        while(num5 <= Number/5){
            num1 = 0; num3 = 0;
            while(num3 <= Number/3){
                num1 = 0;
                while(num1 <= Number/1){
                    if((num1 + num3*3 + num5*5) == Number){
                        Count+=1;
                        System.out.printf("\n%d method: %d ⋅ 1 + %d ⋅ 3 + %d ⋅ 5 = %d ", Count, num1, num3, num5, Number);
                    }
                    num1++;
                }
            num3++;
            }
        num5++;
        }
        System.out.printf("\nCount of ways: %d", Count);
	}
}
