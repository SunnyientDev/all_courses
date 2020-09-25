import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner Data_In = new Scanner(System.in);
        System.out.print("Enter field size: ");
        int Field_Size = Data_In.nextInt();
        
        //Generate our Field
        int[][] Field = new int[Field_Size][Field_Size];
        int Max = 100, Min = -100; //you can change it

        for(int i = 0; i < Field_Size; i++){
            for(int j = 0; j < Field_Size; j++){
                Field[i][j] = (int)((Math.random() * ((Max - Min) + 1)) + Min);
                System.out.print(Field[i][j] + "\t");
            }
            System.out.print("\n");
        }
    }
}
