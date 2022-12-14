package com.company;
import java.awt.*;
import java.util.Scanner;

public class Main {
    public static final String ANSI_WHITE = "\u001B[32m";
    public static void main(String[] args){
        Scanner Data_IN = new Scanner(System.in);
        String YourText = Data_IN.nextLine();
        ToConsole(YourText, Colors.RED);
        ToConsole(YourText, Colors.GREEN);
        ToConsole(YourText, Colors.BLUE);
    }

    public static void ToConsole(String ColorNum, Colors OneColor){
        String YourColor = "\u001B[" + OneColor.getValue() + "m";
        System.out.println(YourColor + ColorNum + ANSI_WHITE);
    }
}
