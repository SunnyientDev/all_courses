/*
* You need to write two classes MovablePoint and MovableCircle -
* which implement the Movable interface based on the classes you
* developed in Practice no 4.
* */
package com.company;

public class Main {
    public static void main(String[] args){
        MovablePoint OneCenter = new MovablePoint(1, 2, 3, 5);
        MovableCircle OneCircle = new MovableCircle(OneCenter, 6);
        System.out.println(OneCenter.toString());
        OneCircle.MoveRight();
        System.out.print(OneCircle.CircleCenter.toString());
    }
}
