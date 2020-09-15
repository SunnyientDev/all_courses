package com.company;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        DogNurs OneDogNurs = new DogNurs();

        System.out.print("Name: "); String Name1 = "Holly";
        System.out.print("Age: "); int Age1 = 6;
        Dog Dog1 = new Dog(Name1, Age1);
        Dog1.PrintAge();
        Dog1.PrintInfo1();
        OneDogNurs.Push(Dog1);

        System.out.println("\n----------------------------------------------------");

        String Name2 = "Bobby"; int Age2 = 3;
        System.out.println("Name: " + Name2);
        System.out.print("Age: " + Age2);
        Dog Dog2 = new Dog();
        Dog2.SetAge(Age2);
        Dog2.SetName(Name2);
        Dog2.PrintInfo2();
        OneDogNurs.Push(Dog2);

        System.out.print(OneDogNurs.Dogs.get(0));
        System.out.print(OneDogNurs.Dogs.get(1));
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
