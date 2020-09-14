package com.company;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner Data_In = new Scanner(System.in);

        Head Head1 = new Head(); Head1.Setter("Blue", 20, 57);
        Leg Leg1 = new Leg(); Leg1.Setter(122, 20);
        Hand Hand1 = new Hand(); Hand1.Setter(40, 14);
        Leg Leg2 = new Leg(); Leg2.Setter(122, 20);
        Hand Hand2 = new Hand(); Hand2.Setter(40, 14);

        //Head1.HeadInfo();
        //Leg1.LegsInfo();
        //Hand1.HandsInfo();

        Human OneHuman = new Human(Head1, Leg1, Leg2, Hand1, Hand2);
        OneHuman.GetInfo();
    }
}

class Human {
    //properties
    Head OneHead;
    Leg LeftLeg; Leg RightLeg;
    Hand LeftHand; Hand RightHand;

    Human(Head OneHead, Leg LeftLeg, Leg RightLeg, Hand LeftHand, Hand RightHand){
        this.OneHead = OneHead;
        this.LeftHand = LeftHand;
        this.LeftLeg = LeftLeg;
        this.RightHand = RightHand;
        this.RightLeg = RightLeg;
    }

    void GetInfo(){
        OneHead.HeadInfo(); System.out.print("\n");
        LeftLeg.LegsInfo(); System.out.print("\n");
        LeftHand.HandsInfo();
    }
}

class Head {
    private String HairColour;
    private int HairLength, Size;

    void Setter(String m_HairColour, int m_HairLength, int m_Size){
        HairColour = m_HairColour;
        HairLength = m_HairLength;
        Size = m_Size;
    }

    void HeadInfo(){
        System.out.printf("Head parameters:\n Hair colour: " + HairColour + "\n Hair length: " + HairLength + " cm\n Head size: " + Size + " cm\n");
    }
}

class Leg {
    private int Length, Width;

    void Setter(int m_Length, int m_Width){
        Length = m_Length;
        Width = m_Width;
    }

    void LegsInfo(){
        System.out.printf("Legs parameters:\n Length: " + Length + " cm\n Width: " + Width + " cm\n");
    }
}

class Hand {
    private int Length, Width;

    void Setter(int m_Length, int m_Width){
        Length = m_Length;
        Width = m_Width;
    }

    void HandsInfo(){
        System.out.printf("Hands parameters:\n Length: " + Length + " cm\n Width: " + Width + " cm\n");
    }
}
