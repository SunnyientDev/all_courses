public class Main 
{
    public static void main(String[] args) {
      float[] Array = new float[10];
      for(int j = 0; j < 10; j++){
        Array[j] = 1/((float)j + 1);
      System.out.printf("%d row number is %f", j+1, Array[j]);
      System.out.println();
      }
    }
} 
