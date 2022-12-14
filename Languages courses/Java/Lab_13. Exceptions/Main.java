package com.company;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Triangle OneTriangle = new Triangle();
        int Sides[] = new int[3];

        Scanner Data_IN = new Scanner(System.in);

        try {
            int a = Data_IN.nextInt();
            int b = Data_IN.nextInt();
            int c = Data_IN.nextInt();
            OneTriangle.Make(a, b, c);
        } catch (IncorrectDataException OneException){
            System.out.println("This triangle doesn't exist!");
        } catch (Exception OneException){
            System.out.println("Error!");
        } finally {
            OneTriangle.toString();
        }
        throw new MyRuntimeException();
    }
}
