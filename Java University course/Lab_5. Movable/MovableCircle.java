package com.company;

public class MovableCircle implements Movable {
    // The center of the circle is a Point, we can use it!
    MovablePoint CircleCenter;
    int Radius;

    public MovableCircle(MovablePoint circleCenter, int radius) {
        CircleCenter = circleCenter;
        Radius = radius;
    }

    @Override
    public void MoveLeft()  { CircleCenter.x_Position -= CircleCenter.x_Speed; }

    @Override
    public void MoveRight() { CircleCenter.x_Position += CircleCenter.x_Speed; }

    @Override
    public void MoveUp()    { CircleCenter.y_Position += CircleCenter.y_Speed; }

    @Override
    public void MoveDown()  { CircleCenter.y_Position -= CircleCenter.y_Speed; }

    @Override
    //as in the example
    public String toString() {
        return "MovablePoint { x = " + CircleCenter.x_Position +
                ", y = " + CircleCenter.y_Position + " }";
    }
}
