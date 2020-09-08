package com.company;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner Data_In = new Scanner(System.in);
        Shape SomeObject = new Shape();

        System.out.print("Enter the height of the object: ");
        int N = Data_In.nextInt();
        SomeObject.Height = N;

        System.out.print("Enter the width of the object: ");
        N = Data_In.nextInt();
        SomeObject.Width = N;

        System.out.print("Enter the length of the object: ");
        N = Data_In.nextInt();
        SomeObject.Length = N;

        SomeObject.intoString();
    }
}

class Shape{
    public int Width, Height, Length;
    void intoString(){
        System.out.printf("Object properties: %d x %d x %d", Width, Height, Length);
    }
}
