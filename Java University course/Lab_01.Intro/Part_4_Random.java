import java.util.Arrays; 
import java.util.Random; 

public class Main 
{
    public static void main(String[] args) {
      double number = Math.random() * 10 + 1;
      System.out.println("Array1 size: " + (int)number);
      int Array_Size1 = (int)number;

      int[] Array1 = new int[Array_Size1];
      System.out.println("Array1 (Math.random(): ");
      for(int i = 0; i < Array_Size1; i++){
        Array1[i] = (int)(Math.random() * 10 + 1);
        System.out.print(Array1[i] + " ");
      }
      Arrays.sort(Array1);
      System.out.println();
      System.out.printf("Modified array: %s", Arrays.toString(Array1)); 

      System.out.println();
      System.out.println();

      Random random = new Random();
      //System.out.println("A random int: " + random.nextInt(10));
      int Array_Size2 = random.nextInt(10);
      int[] Array2 = new int[Array_Size2];

      System.out.println("Array2 size: " + Array_Size2);
      System.out.println("Array2 (Random class): ");
      for(int i = 0; i < Array_Size2; i++){
        Array2[i] = random.nextInt(10) + 1;
        System.out.print(Array2[i] + " ");
      }      

      Arrays.sort(Array2);
      System.out.println();
      System.out.printf("Modified array: %s", Arrays.toString(Array2)); 

      System.out.println();
    }
} 
