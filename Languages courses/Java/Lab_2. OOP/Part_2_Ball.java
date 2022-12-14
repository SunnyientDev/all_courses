package com.company;

public class Main {
    public static void main(String[] args) {
        Ball SomeBall = new Ball();
        SomeBall.PrintState();
    }
}

class Ball {
    void PrintState() {
        System.out.print("Object is available");
    }
}
