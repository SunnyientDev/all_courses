package com.company;

public class MovableRectangle implements Movable {
    MovablePoint RectLeft, RectRight;

    public MovableRectangle(int x1Pos, int y1Pos, int x2Pos, int y2Pos, int x_Moving, int y_Moving) {
        RectLeft = new MovablePoint(x1Pos, y1Pos, x_Moving, y_Moving);
        RectRight = new MovablePoint(x2Pos, y2Pos, x_Moving, y_Moving);
    }

    @Override
    public void MoveLeft() {
        RectLeft.MoveLeft();
        RectRight.MoveLeft();
    }

    @Override
    public void MoveRight() {
        RectLeft.MoveRight();
        RectRight.MoveRight();
    }

    @Override
    public void MoveUp() {
        RectLeft.MoveUp();
        RectRight.MoveUp();
    }

    @Override
    public void MoveDown() {
        RectLeft.MoveDown();
        RectRight.MoveDown();
    }

    @Override
    //as in the example
    public String toString() {
        return "MovableRectangle { Left position = " + RectLeft.toString() +
                ", Right position = " + RectRight.toString() + " }";
    }
}
