package com.company;
import javax.swing.*;

public class Main {
    public static void main(String[] args){
        //user interaction
        SwingUtilities.invokeLater(()->{
            Calculator Calc = new Calculator();
            Calc.setVisible(true);
        });
    }
}