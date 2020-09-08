package com.company;
import java.util.Scanner;

public class CircleClass {
    public static void main(String[] args) {
        Scanner Data_In = new Scanner(System.in);

        System.out.print("Enter the radius of your circle (it may be real number): ");
        float Data = Data_In.nextFloat();
        Circle SomeCircle = new Circle();

        SomeCircle.Setter(Data);
        SomeCircle.PrintState();
        System.out.print(SomeCircle.Getter());
    }
}

class Circle {
    private float Radius;

    void Setter(float m_Radius){
        Radius = m_Radius;
    }

    float Getter(){
        return Radius;
    }

    void PrintState(){
        System.out.println("Class is available");
        System.out.print("Radius is equal to ");
    }
}
