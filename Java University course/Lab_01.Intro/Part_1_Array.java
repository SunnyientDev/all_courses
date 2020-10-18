import java.util.Scanner;

public class Main 
{
    public static void main(String[] args) 
    {
      Scanner Data_In = new Scanner(System.in);

      System.out.println("First Task");
        System.out.println();
        System.out.print("Input array size: ");
        int Array_Size = Data_In.nextInt();
        int Array[] = new int[Array_Size];

        System.out.print("Input " + Array_Size + " elements: ");
        for(int i = 0; i < Array_Size; i++) Array[i] = Data_In.nextInt();
        System.out.println("You entered: ");
        for (int i = 0; i < Array_Size; i++) System.out.print (" " + Array[i]);
        System.out.println();
        int For_Sum = 0, While_Sum = 0, Do_Sum = 0;

        for(int i = 0; i < Array_Size; i++) For_Sum += Array[i];
        int i = 0;
        while(i < Array_Size){ While_Sum += Array[i]; i++; }

        i = 0;
        do { Do_Sum += Array[i]; i++;
        } while(i < Array_Size);

        System.out.println("For: " + For_Sum + ", While: " + While_Sum + ", Do while: " + Do_Sum);    
    }
} 
