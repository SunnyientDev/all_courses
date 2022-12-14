package com.company;

public class MovablePoint implements Movable {
    // We have just four parameters
    int x_Position, y_Position;
    int x_Moving, y_Moving;

    public MovablePoint(int x_Position, int y_Position, int x_Moving, int y_Moving) {
        this.x_Position = x_Position;
        this.y_Position = y_Position;
        this.x_Moving = x_Moving;
        this.y_Moving = y_Moving;
    }

    @Override
    public void MoveLeft()  { x_Position -= x_Moving; }

    @Override
    public void MoveRight() { x_Position += x_Moving; }

    @Override
    public void MoveUp()    { y_Position += y_Moving; }

    @Override
    public void MoveDown()  { y_Position -= y_Moving; }

    @Override
    //as in the example
    public String toString() {
        return "MovablePoint { x = " + x_Position +
                ", y = " + y_Position + " }";
    }
}