package com.company;

public class Main {
    public static void main(String[] args) {
        Human OneHuman = new Human(); OneHuman.MakeHuman();
        OneHuman.GetInfo();
    }
}

class Human {
    Head OneHead = new Head();
    Leg LegL = new Leg(); Leg LegR = new Leg();
    Hand HandL = new Hand(); Hand HandR = new Hand();

    void MakeHuman(){
        LegL.Setter(22, 12);
        LegR.Setter(22, 12);
        HandL.Setter(22, 4);
        HandR.Setter(22, 4);
        OneHead.Setter("Dark", 4, 22);
    }

    void GetInfo(){
        OneHead.HeadInfo(); System.out.print("\n");
        LegL.LegsInfo();    System.out.print("\n");
        LegR.LegsInfo();    System.out.print("\n");
        HandL.HandsInfo();  System.out.print("\n");
        HandR.HandsInfo();
    }

    class Head {
        private String HairColour;
        private int HairLength, Size;

        void Setter(String HairColour, int HairLength, int Size){
            this.HairColour = HairColour;
            this.HairLength = HairLength;
            this.Size = Size;
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
}
