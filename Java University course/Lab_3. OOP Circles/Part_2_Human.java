package com.company;
import java.util.Scanner;

public class Human {
    public static void main(String[] args) {
        Scanner Data_In = new Scanner(System.in);

        Head Head1 = new Head(); Head1.Setter("Blue", 20, 57);
        Leg Leg1 = new Leg(); Leg1.Setter(122, 20);
        Hand Hand1 = new Hand(); Hand1.Setter(40, 14);

        Head1.HeadInfo();
        Leg1.LegsInfo();
        Hand1.HandsInfo();
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
