package com.company;
import java.lang.Math.*;

public class Main {
    public static void main(String[] args) {

    }
}

abstract class Shape {
    protected String Colour = "red";
    protected boolean Filled = true;

    public Shape(String Colour, boolean Filled){
        this.Colour = Colour;
        this.Filled = Filled;
    }

    public Shape(){}

    public void setColour(){ this.Colour = Colour; }
    public void setFilled(){ this.Filled = Filled; }
    public String getColour(){ return Colour; }
    public boolean isFilled(){ return Filled; }
}

public class Rectangle extends Shape{
    double Width = 1;
    double Length = 1;

    public Rectangle(double Width, double Length, String Colour, boolean Filled){
        this.Width = Width;
        this.Length = Length;
        this.Colour = Colour;
        this.Filled = Filled;
    }

    public Rectangle(double Width, double Length){
        this.Width = Width;
        this.Length = Length;
    }

    public Rectangle(){}
    
    public double getWidth(){ return Width; }
    public double getLength(){ return Length; }
    public double getArea(){ return Length*Width; }
    public double getPerimeter(){ return (Length+Width)*2; }

    public void setWidth(){ this.Width = Width; }
    public void setLength(){ this.Length = Length; }

    public String toString(){ return "Sth"; }
}

public class Circle extends Shape{
    double Radius = 1;

    public Circle(double Radius, String Colour, boolean Filled){
        this.Radius = Radius;
        this.Colour = Colour;
        this.Filled = Filled;
    }

    public Circle(double Radius){
        this.Radius = Radius;
    }

    public Circle(){}

    public double getRadius(){ return Radius; }
    public double getArea(){ return Math.PI * Radius; }
    public double getPerimeter(){ return 2* Math.PI*Radius; }

    public void setRadius(){ this.Radius = Radius; }
    public String toString(){ return "Sth"; }
}

public class Square extends Rectangle{
    public Square(){}

    public Square(double Side) {
        this.Length = Side;
        this.Width = Side;
    }

    public Square(double Side, String Colour, boolean Filled) {
        this.Length = Side;
        this.Colour = Colour;
    }

    public void setSide(double Side){
        this.Length = Side;
        this.Width = Side;
    }

    public double getSide(){ return Length; }
    public void setWidth(double Width){ this.Width = Width; }
    public void setLength(double Length){ this.Length = Length; }
    public String toString(){ return "Sth"; }
}
