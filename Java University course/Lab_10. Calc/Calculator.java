package com.company;
import java.awt.event.*;
import javax.swing.*;
import java.awt.*;

public class Calculator extends JFrame{
    //Parameters
    private double num1, num2, Result;

    public Calculator() {
        //Frame settings
        setTitle("Calculator");
        setLocation(500, 500);
        setSize(256, 256);

        //Labels
        JLabel Label1 = new JLabel("Значение А");
        JLabel Label2 = new JLabel("Значение Б");
        JLabel Label3 = new JLabel("Результат");

        Label1.setHorizontalAlignment(JLabel.CENTER);
        Label1.setHorizontalAlignment(JLabel.CENTER);
        Label1.setHorizontalAlignment(JLabel.CENTER);

        //Buttons
        JButton ButtonPlus = new JButton("+");
        JButton ButtonMulti = new JButton("*");
        JButton ButtonMinus = new JButton("-");
        JButton ButtonDiv = new JButton("/");

        //Text fields
        JTextField Text1 = new JTextField(15);
        JTextField Text2 = new JTextField(15);

        //Create our panel
        JPanel MainPanel = new JPanel();
        add(MainPanel);

        //set the same cell size by columns
        // and individually customize each cell of the table
        MainPanel.setLayout(new GridLayout(6,0));

        MainPanel.add(Label1); MainPanel.add(Text1);

        JPanel Panel = new JPanel();
        Panel.add(ButtonPlus);
        Panel.add(ButtonMinus);
        Panel.add(ButtonMulti);
        Panel.add(ButtonDiv);

        MainPanel.add(Panel);
        MainPanel.add(Label2);
        MainPanel.add(Text2);

        ButtonPlus.addActionListener(action->{
            if(Text1.getText().equals("") || Text2.getText().equals(""))
                JOptionPane.showMessageDialog (this, "Error! Do not leave the input fields empty!");
            else {
                try {
                    num1 = Double.parseDouble(Text1.getText());
                    num2 = Double.parseDouble(Text2.getText());
                    Result = num1 + num2;
                    Label3.setText("Result: " + Result);
                } catch  (NumberFormatException e){
                    JOptionPane.showMessageDialog (this, "Error! Invalid input data!");
                }
            }
        });

        ButtonDiv.addActionListener(action->{
            try {
                num1 = Double.parseDouble(Text1.getText());
                num2 = Double.parseDouble(Text2.getText());
                Result = num1 / num2;
                Label3.setText("Result: " + Result);
            }catch (Exception  e){
                Label3.setText("Error!");}
        });

        ButtonMinus.addActionListener(action->{
            if(Text1.getText().equals("") || Text2.getText().equals(""))
                JOptionPane.showMessageDialog (this, "Error! Do not leave the input fields empty!");
            else {
                try {
                    num1 = Double.parseDouble(Text1.getText());
                    num2 = Double.parseDouble(Text2.getText());
                    Result = num1 - num2;
                    Label3.setText("Result: " + Result);
                } catch  (NumberFormatException e){
                    JOptionPane.showMessageDialog (this, "Error! Invalid input data!");
                }
            }
        });

        ButtonMulti.addActionListener(action->{
            if(Text1.getText().equals("") || Text2.getText().equals(""))
                JOptionPane.showMessageDialog (this, "Error! Do not leave the input fields empty!");
            else {
                try {
                    num1 = Double.parseDouble(Text1.getText());
                    num2 = Double.parseDouble(Text2.getText());
                    Result = num1 * num2;
                    Label3.setText("Result: " + Result);
                } catch  (NumberFormatException e){
                    JOptionPane.showMessageDialog (this, "Error! Invalid input data!");
                }
            }
        });
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
    }
}
