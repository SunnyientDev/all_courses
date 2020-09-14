package com.company;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner Data_In = new Scanner(System.in);
        System.out.print("Please, enter name and age of the dog \n");
        System.out.print("Name: "); String Name1 = Data_In.nextLine();
        System.out.print("Age: "); int Age1 = Data_In.nextInt();

        DogNurs OneDogNurs = new DogNurs();   
        
        Dog Dog1 = new Dog(Name1, Age1);
        OneDogNurs.Push(Dog1);
        
        Dog1.PrintAge();
        Dog1.PrintInfo1();

        System.out.println("\n----------------------------------------------------");
        //System.out.print("Please enter name and age of another dog \n");String Name2 = "Bobby";
        String Name2 = "Bobby"; int Age2 = 3;
        System.out.println("Name: " + Name2);
        System.out.print("Age: " + Age2);

        Dog Dog2 = new Dog();
        OneDogNurs.Push(Dog2);
        
        Dog2.SetAge(Age2);
        Dog2.SetName(Name2);
        Dog2.PrintInfo2();

        System.out.print(OneDogNurs.Dogs.get(0));
        //Dog[] Nursery = new Dog [] {Dog1, Dog2};
    }
}

class Dog {
    private String Name;
    private int Age;

    Dog(String m_Name, int m_Age) {
        Name = m_Name;
        Age = m_Age;
    }

    Dog(){

    }

    void SetName(String s_Name){ Name = s_Name; }
    void SetAge(int s_Age){ Age = s_Age; }

    void PrintAge(){ System.out.print("Age (human metrics): " + Age * 7 + " ages \n"); }
    void PrintInfo1(){
        System.out.println("--------------------Constructor---------------------");
        System.out.printf("Information about dog: \nAge: %d\nName: " + Name, Age);
    }

    void PrintInfo2(){
        System.out.println("\n----------------------Setters-----------------------");
        System.out.printf("Information about dog: \nAge: %d\nName: " + Name, Age);
    }
}

class DogNurs{
    ArrayList<Dog> Dogs = new ArrayList<Dog>();
    void Push(Dog OneGog){
        Dogs.add(OneDog);
    }
}
