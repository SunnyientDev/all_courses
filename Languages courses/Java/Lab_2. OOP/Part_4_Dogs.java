package com.company;
import java.util.ArrayList;

public class Main{
    public static void main(String[]args){
        Kennel OneKennel = new Kennel();
        Dog OneDog = new Dog("Charlie", 7); OneKennel.Add(OneDog);
        Dog AnotherDog = new Dog("Teddy", 3); OneKennel.Add(AnotherDog);

        System.out.print("Information about dogs in kennels: \n");
        System.out.print(OneKennel.Dogs.get(0));
        System.out.print("\n");
        System.out.print(OneKennel.Dogs.get(1));
    }
}

class Kennel{
    ArrayList<Dog> Dogs=new ArrayList<Dog>();
    void Add(Dog OneDog){ Dogs.add(OneDog); }
}

class Dog{
    private String DogName;
    private int DogAge;

    Dog(String DogName,int DogAge){
        this.DogName = DogName;
        this.DogAge = DogAge;
    }

    void getName(String DogName){ this.DogName = DogName; }
    void getAge(int DogAge){ this.DogAge = DogAge; }
    String getName(){ return DogName; }

    int gatAge(){ return DogAge; }
    int HumanMetrics(){ return 7 * DogAge; }

    public String toString() {
        return "* Dog Name: " + DogName
                + "\n" + "Age = " + DogAge + "\n";
    }
}
