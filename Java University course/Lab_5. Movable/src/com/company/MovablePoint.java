package com.company;

public class MovablePoint implements Movable {
    // We have just four parameters
    int x_Position, y_Position;
    int x_Speed, y_Speed;

    public MovablePoint(int x_Position, int y_Position, int x_Speed, int y_Speed) {
        this.x_Position = x_Position;
        this.y_Position = y_Position;
        this.x_Speed = x_Speed;
        this.y_Speed = y_Speed;
    }

    @Override
    public void MoveLeft()  { x_Position -= x_Speed; }

    @Override
    public void MoveRight() { x_Position += x_Speed; }

    @Override
    public void MoveUp()    { y_Position += y_Speed; }

    @Override
    public void MoveDown()  { y_Position -= y_Speed; }

    @Override
    //as in the example
    public String toString() {
        return "MovablePoint { x = " + x_Position +
                ", y = " + y_Position + " }";
    }
}