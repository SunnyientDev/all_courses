package java_practice.practice_15;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner Data_IN = new Scanner(System.in);
        Pattern OnePattern = new Pattern();
        int Command;

        while(true){
            Command = Data_IN.nextInt();
            if(Command == -1) break;

            OnePattern.Processing(Command);
        }
        OnePattern.getActionCodeName();
    }
}
