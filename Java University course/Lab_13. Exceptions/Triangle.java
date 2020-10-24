package com.company;

public class Triangle {
    private int a, b, c;

    public void Make(int a, int b, int c) throws IncorrectDataException {
        if (a + b >= c && a + c >= b && b + c >= a){
            throw new IncorrectDataException();
        }
        this.a = a;
        this.b = b;
        this.c = c;
    }

    @Override
    public String toString() {
        return "Triangle{" +
                "a=" + a +
                ", b=" + b +
                ", c=" + c +
                '}';
    }
}
