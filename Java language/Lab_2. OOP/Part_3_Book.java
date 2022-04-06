package com.company;

public class Main {
    public static void main(String[] args) {
        Book SomeBook = new Book();
        SomeBook.PrintState();
    }
}

class Book {
    void PrintState() {
        System.out.print("Object is available");
    }
}
