package com.company;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner DAta_In = new Scanner(System.in);

        Book OneBook = new Book();
        int Age_Limit = 12, DateOfWriting = 1898, Volume = 190;
        String ISBN = "978-5-17-080103-9", Translator = "Mikhail Zenkevich", Credit = "AST Publishing House", Title = "War of the Worlds", Author = "H.G. Wells";

        OneBook.Setter(Age_Limit, DateOfWriting, Volume, ISBN, Translator, Credit, Title, Author);
        OneBook.PrintInfo();
    }
}

class Book {
    private int Age_Limit, DateOfWriting, Volume;
    private String Translator, Credit, ISBN, Title, Author;

    void Setter(int m_Age_Limit, int m_DateOfWriting, int m_Volume,
                String m_ISBN, String m_Translator, String m_Credit, String m_Title, String m_Author){

        Age_Limit = m_Age_Limit;
        DateOfWriting = m_DateOfWriting;
        Volume = m_Volume;
        ISBN = m_ISBN;
        Translator = m_Translator;
        Credit = m_Credit;
        Title = m_Title;
        Author = m_Author;
    }

    void PrintInfo(){
        System.out.println("Title: " + Title + "\nAuthor: " + Author);
        System.out.println("ISBN: " + ISBN + "\nCredit: " + Credit);
        System.out.println("Translator: " + Translator + "\nAge limit: " + Age_Limit + "+\nDate of Writing: " + DateOfWriting + "\nVolume: " + Volume + " pages");
    }
}
