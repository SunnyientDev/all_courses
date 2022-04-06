## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_01_Intro/Array.java
```java
package Lab_01_Intro;
import java.util.Scanner;

public class Array {
    public static void main(String[] args) 
    {
      Scanner Data_In = new Scanner(System.in);

      System.out.println("First Task");
        System.out.println();
        System.out.print("Input array size: ");
        int Array_Size = Data_In.nextInt();
        int Array[] = new int[Array_Size];

        System.out.print("Input " + Array_Size + " elements: ");
        for(int i = 0; i < Array_Size; i++) Array[i] = Data_In.nextInt();
        System.out.println("You entered: ");
        for (int i = 0; i < Array_Size; i++) System.out.print (" " + Array[i]);
        System.out.println();
        int For_Sum = 0, While_Sum = 0, Do_Sum = 0;

        for(int i = 0; i < Array_Size; i++) For_Sum += Array[i];
        int i = 0;
        while(i < Array_Size){ While_Sum += Array[i]; i++; }

        i = 0;
        do { Do_Sum += Array[i]; i++;
        } while(i < Array_Size);

        System.out.println("For: " + For_Sum + ", While: " + While_Sum + ", Do while: " + Do_Sum);    
    }
} 
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_01_Intro/CommandLine.java
```java
package Lab_01_Intro;
public class CommandLine {
    public static void main(String[] args) {
        for (String str : args) {
            System.out.println("Arguments: " + str);
        }
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_01_Intro/Factorial.java
```java
package Lab_01_Intro;
import java.util.Scanner;

public class Factorial {
    public static void main(String[] args) {
        Scanner Data_In = new Scanner(System.in);
        
        System.out.print("Enter the number to calculate factorial: ");
        int N = Data_In.nextInt();
        long Fact = Fact(N);

        System.out.println("The factorial of N is: "+ Fact);
    }

    public static long Fact(int N){
        if(N == 0) return 1;
        return N * Fact(N-1);
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_01_Intro/Format.java
```java
package Lab_01_Intro;

public class Format {
    public static void main(String[] args) {
      float[] Array = new float[10];
      for(int j = 0; j < 10; j++){
        Array[j] = 1/((float)j + 1);
      System.out.printf("%d row number is %f", j+1, Array[j]);
      System.out.println();
      }
    }
} 
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_01_Intro/Randoma.java
```java
package Lab_01_Intro;
import java.util.Arrays;
import java.util.Random;

public class Randoma {
    public static void main(String[] args) {
      double number = Math.random() * 10 + 1;
      System.out.println("Array1 size: " + (int)number);
      int Array_Size1 = (int)number;

      int[] Array1 = new int[Array_Size1];
      System.out.println("Array1 (Math.random(): ");
      for(int i = 0; i < Array_Size1; i++){
        Array1[i] = (int)(Math.random() * 10 + 1);
        System.out.print(Array1[i] + " ");
      }
      Arrays.sort(Array1);
      System.out.println();
      System.out.printf("Modified array: %s", Arrays.toString(Array1)); 

      System.out.println();
      System.out.println();

      Random random = new Random();
      //System.out.println("A random int: " + random.nextInt(10));
      int Array_Size2 = random.nextInt(10);
      int[] Array2 = new int[Array_Size2];

      System.out.println("Array2 size: " + Array_Size2);
      System.out.println("Array2 (Random class): ");
      for(int i = 0; i < Array_Size2; i++){
        Array2[i] = random.nextInt(10) + 1;
        System.out.print(Array2[i] + " ");
      }      

      Arrays.sort(Array2);
      System.out.println();
      System.out.printf("Modified array: %s", Arrays.toString(Array2)); 

      System.out.println();
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_02_OOP/Ball.java
```java
package Lab_02_OOP;

public class Ball {
    void PrintState() {
        System.out.print("Object is available");
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_02_OOP/Book.java
```java
package Lab_02_OOP;

public class Book {
    void PrintState() {
        System.out.print("Object is available");
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_02_OOP/Dogs.java
```java
package Lab_02_OOP;

class Dogs{
    private String DogName;
    private int DogAge;

    Dogs(String DogName,int DogAge){
        this.DogName = DogName;
        this.DogAge = DogAge;
    }

    void getName(String DogName){ this.DogName = DogName; }
    void getAge(int DogAge){ this.DogAge = DogAge; }
    String getName(){ return DogName; }

    int gatAge(){ return DogAge; }
    int HumanMetrics(){ return 7 * DogAge; }

    public String toString() {
        return "* Dog Name: " + DogName
                + "\n" + "Age = " + DogAge + "\n";
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_02_OOP/Ken.java
```java
package Lab_02_OOP;
import java.util.ArrayList;

public class Ken {
        ArrayList<Dogs> Dogs=new ArrayList<Dogs>();
        void Add(Dogs OneDog){ Dogs.add(OneDog); }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_02_OOP/Main.java
```java
package Lab_02_OOP;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Ball SomeBall = new Ball();
        SomeBall.PrintState();

        Book SomeBook = new Book();
        SomeBook.PrintState();

        Ken OneKennel = new Ken();
        Dogs OneDog = new Dogs("Charlie", 7); OneKennel.Add(OneDog);
        Dogs AnotherDog = new Dogs("Teddy", 3); OneKennel.Add(AnotherDog);

        System.out.print("Information about dogs in kennels: \n");
        System.out.print(OneKennel.Dogs.get(0));
        System.out.print("\n");
        System.out.print(OneKennel.Dogs.get(1));

        Scanner Data_In = new Scanner(System.in);
        Shape SomeObject = new Shape();

        System.out.print("Enter the height of the object: ");
        int N = Data_In.nextInt();
        SomeObject.Height = N;

        System.out.print("Enter the width of the object: ");
        N = Data_In.nextInt();
        SomeObject.Width = N;

        System.out.print("Enter the length of the object: ");
        N = Data_In.nextInt();
        SomeObject.Length = N;

        SomeObject.intoString();
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_02_OOP/Shape.java
```java
package Lab_02_OOP;

public class Shape {
    public int Width, Height, Length;
    void intoString(){
        System.out.printf("Object properties: %d x %d x %d", Width, Height, Length);
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_03_OOP_Circles/Book.java
```java
package Lab_03_OOP_Circles;

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
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_03_OOP_Circles/Circle.java
```java
package Lab_03_OOP_Circles;
import java.util.Scanner;

class Circle {
    private float Radius;

    void Setter(float m_Radius){
        Radius = m_Radius;
    }

    float Getter(){
        return Radius;
    }

    void PrintState(){
        System.out.println("Class is available");
        System.out.print("Radius is equal to ");
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_03_OOP_Circles/Human.java
```java
package Lab_03_OOP_Circles;

class Human {
    Head OneHead = new Head();
    Leg LegL = new Leg(); Leg LegR = new Leg();
    Hand HandL = new Hand(); Hand HandR = new Hand();

    void MakeHuman(){
        LegL.Setter(22, 12);
        LegR.Setter(22, 12);
        HandL.Setter(22, 4);
        HandR.Setter(22, 4);
        OneHead.Setter("Dark", 4, 22);
    }

    void GetInfo(){
        OneHead.HeadInfo(); System.out.print("\n");
        LegL.LegsInfo();    System.out.print("\n");
        LegR.LegsInfo();    System.out.print("\n");
        HandL.HandsInfo();  System.out.print("\n");
        HandR.HandsInfo();
    }

    class Head {
        private String HairColour;
        private int HairLength, Size;

        void Setter(String HairColour, int HairLength, int Size){
            this.HairColour = HairColour;
            this.HairLength = HairLength;
            this.Size = Size;
        }

        void HeadInfo(){
            System.out.printf("Head parameters:\n Hair colour: " + HairColour + "\n Hair length: " + HairLength + " cm\n Head size: " + Size + " cm\n");
        }
    }

    class Leg {
        private int Length, Width;

        void Setter(int m_Length, int m_Width){
            Length = m_Length;
            Width = m_Width;
        }

        void LegsInfo(){
            System.out.printf("Legs parameters:\n Length: " + Length + " cm\n Width: " + Width + " cm\n");
        }
    }

    class Hand {
        private int Length, Width;

        void Setter(int m_Length, int m_Width){
            Length = m_Length;
            Width = m_Width;
        }

        void HandsInfo(){
            System.out.printf("Hands parameters:\n Length: " + Length + " cm\n Width: " + Width + " cm\n");
        }
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_03_OOP_Circles/Main.java
```java
package Lab_03_OOP_Circles;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner Data_In = new Scanner(System.in);

        Book OneBook = new Book();
        int Age_Limit = 12, DateOfWriting = 1898, Volume = 190;
        String ISBN = "978-5-17-080103-9", Translator = "Mikhail Zenkevich", Credit = "AST Publishing House", Title = "War of the Worlds", Author = "H.G. Wells";

        OneBook.Setter(Age_Limit, DateOfWriting, Volume, ISBN, Translator, Credit, Title, Author);
        OneBook.PrintInfo();

        System.out.print("Enter the radius of your circle (it may be real number): ");
        float Data = Data_In.nextFloat();
        Circle SomeCircle = new Circle();

        SomeCircle.Setter(Data);
        SomeCircle.PrintState();
        System.out.print(SomeCircle.Getter());

        Human OneHuman = new Human(); OneHuman.MakeHuman();
        OneHuman.GetInfo();
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_04_UML/Circle.java
```java
package Lab_04_UML;
import java.lang.Math.*;

class Circle extends Shape{
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
    public String toString(){
        return "Circle parameters:\nRadius: " + Radius + "\nArea: " + getArea() + "\nPerimeter: " + getPerimeter() + "\n";
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_04_UML/Main.java
```java
package Lab_04_UML;
import java.lang.Math.*;

public class Main {
    public static void main(String[] args) {
        Circle OneCircle = new Circle(7,"Coral",true); //If False, OUTPUT: " "
        Rectangle OneRectangle = new Rectangle(6,5,"Azure",true);
        Square NewSquare = new Square(7,"Maroon",true);

        System.out.print(OneCircle.toString()+"\n" + OneRectangle.toString() + "\n" + NewSquare.toString());
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_04_UML/Rectangle.java
```java
package Lab_04_UML;
import java.lang.Math.*;

class Rectangle extends Shape{
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

    public String toString(){
        return "Rectangle parameters:\nWidth: " + Width + "\nLength: " + Length + "\nArea: " + getArea() + "\nPerimeter: " + getPerimeter() + "\n";
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_04_UML/Shape.java
```java
package Lab_04_UML;
import java.lang.Math.*;

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
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_04_UML/Square.java
```java
package Lab_04_UML;
import java.lang.Math.*;

class Square extends Rectangle{
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
    public String toString(){
        return "Square parameters:\nSide: " + Length + "\nArea: " + getArea() + "\nPerimeter: " + getPerimeter() + "\n";
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_05_Movable/Main.java
```java
/*
* You need to write two classes MovablePoint and MovableCircle -
* which implement the Movable interface based on the classes you
* developed in Practice no 4.
* */
package Lab_05_Movable;

public class Main {
    public static void main(String[] args){
        //1st task
        MovablePoint OneCenter = new MovablePoint(1, 2, 3, 5);
        MovableCircle OneCircle = new MovableCircle(OneCenter, 6);
        System.out.println(OneCenter.toString());
        OneCircle.MoveRight();
        System.out.println(OneCircle.CircleCenter.toString());

        //2nd task
        MovableRectangle OneRectangle = new MovableRectangle(1,2,3,4,5,6);
        System.out.println(OneRectangle.toString());
        OneRectangle.MoveUp();
        System.out.print(OneRectangle.toString());
    }
}




```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_05_Movable/Movable.java
```java
package Lab_05_Movable;

public interface Movable {
    public void MoveLeft();
    public void MoveRight();
    public void MoveUp();
    public void MoveDown();
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_05_Movable/MovableCircle.java
```java
package Lab_05_Movable;

public class MovableCircle implements Movable {
    // The center of the circle is a Point, we can use it!
    MovablePoint CircleCenter;
    int Radius;

    public MovableCircle(MovablePoint circleCenter, int radius) {
        CircleCenter = circleCenter;
        Radius = radius;
    }

    @Override
    public void MoveLeft()  { CircleCenter.x_Position -= CircleCenter.x_Moving; }

    @Override
    public void MoveRight() { CircleCenter.x_Position += CircleCenter.x_Moving; }

    @Override
    public void MoveUp()    { CircleCenter.y_Position += CircleCenter.y_Moving; }

    @Override
    public void MoveDown()  { CircleCenter.y_Position -= CircleCenter.y_Moving; }

    @Override
    //as in the example
    public String toString() {
        return "MovablePoint { x = " + CircleCenter.x_Position +
                ", y = " + CircleCenter.y_Position + " }";
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_05_Movable/MovablePoint.java
```java
package Lab_05_Movable;

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
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_05_Movable/MovableRectangle.java
```java
package Lab_05_Movable;

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
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_06_Math_problem/Main.java
```java
package Lab_06_Math_problem;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner Data_In = new Scanner(System.in);
        
        System.out.print("Please, enter the field size: ");
        int FieldSize = Data_In.nextInt();
        int Field[][] = new int[FieldSize][FieldSize];
        int Max = 10, Min = 0; //you can change it
        
        for(int x = 0; x < FieldSize; x++)
            for (int y = 0; y < FieldSize; y++)
                Field [x][y] = (int)((Math.random() * ((Max - Min) + 1)) + Min);
            
        System.out.println("\nOriginal array:");
        for(int x = 0; x < FieldSize; x++){
            for (int y = 0; y < FieldSize; y++) System.out.print(Field[x][y] + "\t");
            System.out.println();
        }
        
        for(int x = 0; x < FieldSize; x++)
          for(int y = 0; y < FieldSize; y++){
            if(x > 0 && y > 0) Field[x][y] += Math.max(Field[x-1][y], Field[x][y-1]);
            else {
              if(x > 0) Field[x][y] += Field[x - 1][y];
              else if(y > 0) Field[x][y] += Field[x][y - 1];
            }
          }
        
        System.out.println("\nAuxiliary array:");
        for(int x = 0; x < FieldSize; x++){
            for (int y = 0; y < FieldSize; y++) System.out.print(Field[x][y] + "\t");
            System.out.println();
        }

      System.out.print("\nOur summ: ");
      System.out.print(Field[FieldSize - 1][FieldSize - 1]);
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_07a08_Company_and_workers/Company.java
```java
package Lab_07a08_Company_and_workers;
import java.util.*;

public class Company {
    private String CompanyName;
    private long CompanyIncome;

    //List with employers
    private ArrayList <Employee> Employees = new ArrayList<>();
    Vector <Integer> Employee_ID = new Vector<>();

    public Company(String companyName, long companyIncome) {
        CompanyName = companyName;
        CompanyIncome = companyIncome;
    }

    void hire(Employee OneEmployee){
        int New_ID = (int)(Math.random() * (1000000));
        //if this ID is exist, we must generate another one
        while(Employee_ID.contains(New_ID))
            New_ID = (int)(Math.random() * (1000000));

        Employee_ID.add(New_ID);

        //Set ID to our new worker
        OneEmployee.setID(New_ID);
        Employees.add(OneEmployee);
    }

    void hireAll(List<Employee> Employees){
        for(Employee Worker: Employees) hire(Worker);
    }

    void fire(int NumberOfWorkers){
        Employee OneEmployee = null;
        for(Employee Worker: Employees){
            if(NumberOfWorkers == Worker.getID()) OneEmployee = Worker;
        }
        Employees.remove(OneEmployee);
        Employee_ID.remove((Integer)NumberOfWorkers);
    }

    //Company income is depends of managers
    public double getIncome() {
        long CompanyIncome = 0;

        for(Employee Worker: Employees){
            if(Worker.getEmployeePosition() instanceof Manager)
                CompanyIncome += ((Manager) Worker.getEmployeePosition()).getIncome();
        }
        return CompanyIncome;
    }

    public void setIncome(long companyIncome) {
        CompanyIncome = companyIncome;
    }

    public ArrayList<Employee> getEmployees() {
        return Employees;
    }

    public void setEmployees(ArrayList<Employee> employees) {
        Employees = employees;
    }

    public void sortList(){
        Employees.sort(Comparator.comparing(Employee::getFixSalary).reversed());
    }

    List <Employee> getTopSalaryStaff(int count){
        if(count > 0){
            this.sortList();
            return Employees.subList(0, count);
        } else {
            System.out.println("You've entered an incorrect number of employees");
            return null;
        }
    }


    List <Employee> getLowestSalaryStaff(int count){
        if(count > 0){
            this.sortList();
            return Employees.subList(Employees.size() - count, Employees.size());
        } else {
            System.out.println("You've entered an incorrect number of employees");
            return null;
        }
    }

    public Vector<Integer> getEmployee_ID() {
        return Employee_ID;
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_07a08_Company_and_workers/Employee.java
```java
package Lab_07a08_Company_and_workers;

public class Employee {
    private String Surname, Name;
    private double FixSalary;
    private int ID;
    EmployeePosition OnePosition;

    public Employee(String surname, String name, int fixSalary, EmployeePosition onePosition) {
        Surname = surname;
        Name = name;
        FixSalary = fixSalary;
        OnePosition = onePosition;
    }

    public String getSurname() { return Surname; }
    public void setSurname(String surname) { Surname = surname; }

    public String getName() { return Name; }
    public void setName(String name) { Name = name; }

    public double getFixSalary() { return OnePosition.calcSalary(FixSalary); }
    public void setFixSalary(double fixSalary) { FixSalary = fixSalary; }

    public EmployeePosition getEmployeePosition() { return OnePosition; }
    public void setEmployeePosition(EmployeePosition onePosition) {
        OnePosition = onePosition;
    }

    public int getID() { return ID; }
    public void setID(int ID) { this.ID = ID; }

    @Override
    public String toString() {
        return "Employee{" +
                "Surname = " + Surname + '\'' +
                ", Name = " + Name + '\'' +
                ", FixSalary = " + FixSalary +
                ", ID = " + ID +
                ", OnePosition = " + OnePosition +
                '}';
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_07a08_Company_and_workers/EmployeePosition.java
```java
package Lab_07a08_Company_and_workers;

public interface EmployeePosition {
    String getJobTitle();
    double calcSalary(double baseSalary);
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_07a08_Company_and_workers/Main.java
```java
package Lab_07a08_Company_and_workers;
import java.util.*;

public class Main {
    public static void main(String[] args){
        //let's make a company
        Company OurCompany = new Company("MIREA", 100000000);
        List<Employee> Workers = new ArrayList<>();

        //hire 180 operators with name is equal to their number, fixSalary may be [1000; 50 000)
        for(int i = 0; i < 180; i++){
            OurCompany.hire(new Employee(
                            "Operator",
                            Integer.toString(i + 1),
                            (int)(Math.random()*50000 + 1000),
                            new Operator(OurCompany)));
        }

        //hire 80 managers with name is equal to their number, fixSalary may be [10000; 50 000)
        for(int i = 0; i < 80; i++){
            OurCompany.hire(new Employee(
                    "Manager",
                    Integer.toString(i + 1),
                    (int)(Math.random()*50000 + 10000),
                    new Manager(OurCompany)));
        }

        //hire 10 managers with name is equal to their number, fixSalary may be [50 000; 100 000)
        for(int i = 0; i < 10; i++){
            OurCompany.hire(new Employee(
                    "Top Manager",
                    Integer.toString(i + 1),
                    (int)(Math.random()*100000 + 50000),
                    new TopManager(OurCompany)));
        }

        //Sort tasks
        Workers = OurCompany.getTopSalaryStaff(10);
        System.out.println("Sorted by Top salary: ");
        for(Employee index: Workers){
            System.out.println((int) index.getFixSalary() + " rubles");
        }

        System.out.println();
        Workers = OurCompany.getLowestSalaryStaff(30);
        System.out.println("Sorted by Lowest salary: ");
        for(Employee index: Workers){
            System.out.println((int) index.getFixSalary() + " rubles");
        }

        System.out.println();
        //Fire task
        for (int i = 0; i < OurCompany.getEmployee_ID().size()/2; i++) {
            OurCompany.fire((int)Math.random()*10);
        }

        //Sort tasks
        Workers = OurCompany.getTopSalaryStaff(10);
        System.out.println("Sorted by Top salary: ");
        for(Employee index: Workers){
            System.out.println((int) index.getFixSalary() + " rubles");
        }

        System.out.println();
        Workers = OurCompany.getLowestSalaryStaff(30);
        System.out.println("Sorted by Lowest salary: ");
        for(Employee index: Workers){
            System.out.println((int) index.getFixSalary() + " rubles");
        }
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_07a08_Company_and_workers/Manager.java
```java
package Lab_07a08_Company_and_workers;

public class Manager implements EmployeePosition{
    private Company OneCompany;
    private int Income;

    public Manager(Company oneCompany) {
        OneCompany = oneCompany;
        Income = (int)((Math.random() * ((140000 - 115000) + 1)) + 115000);
    }

    @Override
    public String getJobTitle() {
        return "Manager";
    }

    @Override
    public double calcSalary(double baseSalary) {
        return baseSalary + 0.05*Income;
    }

    public int getIncome() {
        return Income;
    }

    public void setIncome(int income) {
        Income = income;
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_07a08_Company_and_workers/Operator.java
```java
package Lab_07a08_Company_and_workers;

public class Operator implements EmployeePosition{
    private Company OneCompany;

    public Operator(Company oneCompany) {
        OneCompany = oneCompany;
    }

    @Override
    public double calcSalary(double baseSalary) {
        return baseSalary;
    }

    @Override
    public String getJobTitle() {
        return "Operator";
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_07a08_Company_and_workers/TopManager.java
```java
package Lab_07a08_Company_and_workers;

public class TopManager implements EmployeePosition {
    private Company OneCompany;

    public TopManager(Company oneCompany) {
        OneCompany = oneCompany;
    }

    @Override
    public String getJobTitle() {
        return "Top Manager";
    }

    @Override
    public double calcSalary(double baseSalary) {
        if(OneCompany.getIncome() > 10000000) return 2.5*baseSalary;
        else return baseSalary;
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_09_Сontinuation/Company.java
```java
package Lab_09_Сontinuation;
import java.util.ArrayList;

public class Company {
    private ArrayList<Employee> Employeers = new ArrayList<>();

    public void fire(int ObjectIndex){
        Employeers.remove(ObjectIndex);
    }

    public void hire(Employee OneEmployee){
        Employeers.add(OneEmployee);
    }

    public void DoAnything(SelectorEmployee OneSelector, HandlerEmployee OneHandler){
        int Count = 0;
        for(Employee Worker: Employeers){
            if(OneSelector.isNeed(Worker)){
                OneHandler.Handler(Worker);
                System.out.println(Worker.toString());
                Count++;
            }
        }
    }

    @Override
    public String toString() {
        return "Company{" +
                "Employeers =" + Employeers +
                '}';
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_09_Сontinuation/Employee.java
```java
package Lab_09_Сontinuation;
import java.time.LocalDate;

public class Employee {
    private String Name, Surname, Residence, PhoneNumber;
    private int Salary;
    private LocalDate Birthday;

    public Employee(String name, String surname, String residence, String phoneNumber, int salary, LocalDate birthday) {
        Name = name;
        Surname = surname;
        Residence = residence;
        PhoneNumber = phoneNumber;
        Salary = salary;
        Birthday = birthday;
    }

    public String getName() {
        return Name;
    }

    public void setName(String name) {
        Name = name;
    }

    public String getSurname() {
        return Surname;
    }

    public void setSurname(String surname) {
        Surname = surname;
    }

    public String getResidence() {
        return Residence;
    }

    public void setResidence(String residence) {
        Residence = residence;
    }

    public String getPhoneNumber() {
        return PhoneNumber;
    }

    public void setPhoneNumber(String phoneNumber) {
        PhoneNumber = phoneNumber;
    }

    public int getSalary() {
        return Salary;
    }

    public void setSalary(int salary) {
        Salary = salary;
    }

    public LocalDate getBirthday() {
        return Birthday;
    }

    public void setBirthday(LocalDate birthday) {
        Birthday = birthday;
    }

    @Override
    public String toString() {
        return "Employee{" +
                "Name='" + Name + '\'' +
                ", Surname='" + Surname + '\'' +
                ", Residence='" + Residence + '\'' +
                ", PhoneNumber='" + PhoneNumber + '\'' +
                ", Salary=" + Salary +
                ", Birthday=" + Birthday +
                '}';
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_09_Сontinuation/HandlerEmployee.java
```java
package Lab_09_Сontinuation;

public interface HandlerEmployee {
    void Handler(Employee OneEmployee);
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_09_Сontinuation/Main.java
```java
package Lab_09_Сontinuation;
import java.time.LocalDate;

public class Main {
    public static void main(String[] args){
        Company OneCompany = new Company();

        for(int i = 0; i < 5; i++){
            OneCompany.hire(new Employee(
                    "FirstName",
                    "SecondName",
                    "Country, City",
                    "654-645-234",
                    (int)(Math.random()*1000),
                    LocalDate.of(2000, 1, i + 1)));
        }

        OneCompany.DoAnything(new SelectorEmployee() {
            @Override
            public boolean isNeed(Employee OneEmployee) {
                return OneEmployee.getSalary() < 6_000;
            }
        },OneEmployee -> OneEmployee.getSalary());
        OneCompany.DoAnything(new SelectorSalary(4000), OneEmployee -> OneEmployee.getSalary());
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_09_Сontinuation/SelectorEmployee.java
```java
package Lab_09_Сontinuation;

public interface SelectorEmployee {
    boolean isNeed(Employee OneEmployee);
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_09_Сontinuation/SelectorSalary.java
```java
package Lab_09_Сontinuation;

public class SelectorSalary implements SelectorEmployee{
    private double MinSalary;

    public SelectorSalary(double minSalary) {
        MinSalary = minSalary;
    }

    @Override
    public boolean isNeed(Employee OneEmployee) {
        return MinSalary > OneEmployee.getSalary();
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_10_Calc/Calculator.java
```java
package Lab_10_Calc;
import java.awt.event.*;
import javax.swing.*;
import java.awt.*;

public class Calculator extends JFrame{
    //Parameters
    private double num1, num2, Result;

    public Calculator() {
        //Frame settings
        setTitle("Calculator");
        setLocation(500, 500);
        setSize(256, 256);

        //Labels
        JLabel Label1 = new JLabel("Значение А");
        JLabel Label2 = new JLabel("Значение Б");
        JLabel Label3 = new JLabel("Результат");

        Label1.setHorizontalAlignment(JLabel.CENTER);
        Label1.setHorizontalAlignment(JLabel.CENTER);
        Label1.setHorizontalAlignment(JLabel.CENTER);

        //Buttons
        JButton ButtonPlus = new JButton("+");
        JButton ButtonMulti = new JButton("*");
        JButton ButtonMinus = new JButton("-");
        JButton ButtonDiv = new JButton("/");

        //Text fields
        JTextField Text1 = new JTextField(15);
        JTextField Text2 = new JTextField(15);

        //Create our panel
        JPanel MainPanel = new JPanel();
        add(MainPanel);

        //set the same cell size by columns
        // and individually customize each cell of the table
        MainPanel.setLayout(new GridLayout(6,0));

        MainPanel.add(Label1); MainPanel.add(Text1);

        JPanel Panel = new JPanel();
        Panel.add(ButtonPlus);
        Panel.add(ButtonMinus);
        Panel.add(ButtonMulti);
        Panel.add(ButtonDiv);

        MainPanel.add(Panel);
        MainPanel.add(Label2);
        MainPanel.add(Text2);

        ButtonPlus.addActionListener(action->{
            if(Text1.getText().equals("") || Text2.getText().equals(""))
                JOptionPane.showMessageDialog (this, "Error! Do not leave the input fields empty!");
            else {
                try {
                    num1 = Double.parseDouble(Text1.getText());
                    num2 = Double.parseDouble(Text2.getText());
                    Result = num1 + num2;
                    Label3.setText("Result: " + Result);
                } catch  (NumberFormatException e){
                    JOptionPane.showMessageDialog (this, "Error! Invalid input data!");
                }
            }
        });

        ButtonDiv.addActionListener(action->{
            try {
                num1 = Double.parseDouble(Text1.getText());
                num2 = Double.parseDouble(Text2.getText());
                Result = num1 / num2;
                Label3.setText("Result: " + Result);
            }catch (Exception  e){
                Label3.setText("Error!");}
        });

        ButtonMinus.addActionListener(action->{
            if(Text1.getText().equals("") || Text2.getText().equals(""))
                JOptionPane.showMessageDialog (this, "Error! Do not leave the input fields empty!");
            else {
                try {
                    num1 = Double.parseDouble(Text1.getText());
                    num2 = Double.parseDouble(Text2.getText());
                    Result = num1 - num2;
                    Label3.setText("Result: " + Result);
                } catch  (NumberFormatException e){
                    JOptionPane.showMessageDialog (this, "Error! Invalid input data!");
                }
            }
        });

        ButtonMulti.addActionListener(action->{
            if(Text1.getText().equals("") || Text2.getText().equals(""))
                JOptionPane.showMessageDialog (this, "Error! Do not leave the input fields empty!");
            else {
                try {
                    num1 = Double.parseDouble(Text1.getText());
                    num2 = Double.parseDouble(Text2.getText());
                    Result = num1 * num2;
                    Label3.setText("Result: " + Result);
                } catch  (NumberFormatException e){
                    JOptionPane.showMessageDialog (this, "Error! Invalid input data!");
                }
            }
        });
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_10_Calc/Main.java
```java
package Lab_10_Calc;
import javax.swing.*;

public class Main {
    public static void main(String[] args){
        //user interaction
        SwingUtilities.invokeLater(()->{
            Calculator Calc = new Calculator();
            Calc.setVisible(true);
        });
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_11_Threads/Main.java
```java
package Lab_11_Threads;

import javax.swing.*;
import java.util.ArrayList;
import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.atomic.AtomicInteger;

public class Main {
    static AtomicInteger totalSum = new AtomicInteger(); //0 as default

    public static void main(String[] args) throws InterruptedException { //working with blocking method
        long startTime = System.currentTimeMillis();
        ArrayList<Thread> Threads = new ArrayList<>();

        for (int i = 0; i < 10; i++) {
            final int localI = i; //value of the variable cannot be changed
            Thread OneThread = new Thread(()->Work(localI));
            OneThread.start();
            Threads.add(OneThread);
        }

        for (Thread OneThread : Threads){
            System.out.println(OneThread.getState());
            OneThread.join();
        }

        long endTime = System.currentTimeMillis();
        System.out.println("Total time: " + (endTime - startTime));
        System.out.println("Total sum: " + totalSum);
    }

    private static void Work(int index){
        long startTime = System.currentTimeMillis();
        long Result = DoHardWork(index * 1000, 1_000_000);
        long endTime = System.currentTimeMillis();
        System.out.println(index + ": " + Result + " | " + (endTime - startTime));
    }

    private static long DoHardWork(int Start, int Count){
        long number = 0;
        for (int i = 0; i < Count; i++) {
            number += Math.sqrt(Start + i) * Math.pow(i, Start);
            totalSum.incrementAndGet();
        }
        return number;
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_12_Colors/Colors.java
```java
package Lab_12_Colors;

public enum Colors {
    RED(31), YELLOW(33), BLUE(34), GREEN(32); //with constructor

    private int value;
    private Colors(){}

    private Colors(int value) {
        this.value = value;
    }

    public int getValue() {
        return value;
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_12_Colors/Main.java
```java
package Lab_12_Colors;
import java.awt.*;
import java.util.Scanner;

public class Main {
    public static final String ANSI_WHITE = "\u001B[32m";
    public static void main(String[] args){
        Scanner Data_IN = new Scanner(System.in);
        String YourText = Data_IN.nextLine();
        ToConsole(YourText, Colors.RED);
        ToConsole(YourText, Colors.GREEN);
        ToConsole(YourText, Colors.BLUE);
    }

    public static void ToConsole(String ColorNum, Colors OneColor){
        String YourColor = "\u001B[" + OneColor.getValue() + "m";
        System.out.println(YourColor + ColorNum + ANSI_WHITE);
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_13_Exceptions/IncorrectDataException.java
```java
package Lab_13_Exceptions;

public class IncorrectDataException extends Exception{
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_13_Exceptions/Main.java
```java
package Lab_13_Exceptions;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Triangle OneTriangle = new Triangle();
        int Sides[] = new int[3];

        Scanner Data_IN = new Scanner(System.in);

        try {
            int a = Data_IN.nextInt();
            int b = Data_IN.nextInt();
            int c = Data_IN.nextInt();
            OneTriangle.Make(a, b, c);
        } catch (IncorrectDataException OneException){
            System.out.println("This triangle doesn't exist!");
        } catch (Exception OneException){
            System.out.println("Error!");
        } finally {
            OneTriangle.toString();
        }
        throw new MyRuntimeException();
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_13_Exceptions/MyRuntimeException.java
```java
package Lab_13_Exceptions;

public class MyRuntimeException extends RuntimeException {
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_13_Exceptions/Triangle.java
```java
package Lab_13_Exceptions;

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
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_14_Regular_Expressions/WithExpressions.java
```java
package Lab_14_Regular_Expressions;
import javax.xml.crypto.Data;
import java.util.*;
import java.util.regex.*;

public class WithExpressions {
    public static void main(String[] args){
        Scanner Data_IN = new Scanner(System.in);
        String Word;

        int RulesCount = Data_IN.nextInt();
        Map<String, String> Rule = new HashMap<>();
        String Key, Value;
        //rule entry
        while(true){
            if(RulesCount == 0) break;
            Key = Data_IN.next();
            Value = Data_IN.next();
            Rule.put(Key, Value);
            RulesCount--;
        }

        Word = Data_IN.next();
        //convert Map to Array list for convenience of working with iterators
        List<Map.Entry<String, String>> RuleConverted = new ArrayList<>(Rule.entrySet());
        StringBuilder RegEx = new StringBuilder();

        for (int i = 0; i < RuleConverted.size(); i++) {
            RegEx.append(RuleConverted.get(i).getKey());

            if(i < RuleConverted.size() - 1){
                RegEx.append("|");
            }
        }

        Pattern OnePattern = Pattern.compile(RegEx.toString());
        Matcher OneMathcer = OnePattern.matcher(Word);

        //result
        String Result = OneMathcer.replaceAll(index->Rule.get(index.group()));
        System.out.println("Result: " + Result);
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_14_Regular_Expressions/WithoutExpression.java
```java
package Lab_14_Regular_Expressions;
import javax.xml.crypto.Data;
import java.util.*;
import java.util.regex.*;

public class WithoutExpression {
    public static void main(String[] args){
        Scanner Data_IN = new Scanner(System.in);

        Map<String, String> Rule = new HashMap<>();
        String Key, Value;
        String Word;

        String SubString;
        boolean Condition = false; //we're checking substring and key equivalence for match task
        String Result = "";

        int RulesCount = Data_IN.nextInt();
        //rule entry
        while(true){
            if(RulesCount == 0) break;
            Key = Data_IN.next();
            Value = Data_IN.next();
            Rule.put(Key, Value);
            RulesCount--;
        }

        Word = Data_IN.next();
        //convert Map to Array list for convenience of working with iterators
        List<Map.Entry<String, String>> RuleConverted = new ArrayList<>(Rule.entrySet());

        for (int i = 0; i < Word.length(); i++) {
            Condition = false;

            for (int j = 0; j < RuleConverted.size(); j++) {

                //if key length plus i is not greater than word length, make new substring
                if (!(RuleConverted.get(j).getKey().length() + i > Word.length())) {
                    //SubString is equal to substring from i to Key length
                    SubString = Word.substring(i, i + RuleConverted.get(j).getKey().length());

                    if (SubString.equals(RuleConverted.get(j).getKey())) { //if it matches, condition is performed
                        Condition = true;
                        Result += RuleConverted.get(j).getValue();
                        i += RuleConverted.get(j).getKey().length() - 1;
                        break;
                    }
                }
            }
            if(!Condition) Result += Word.charAt(i);
        }
        System.out.println(Result);
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_15a16_Graph/Main.java
```java
package Lab_15a16_Graph;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner Data_IN = new Scanner(System.in);
        Pattern OnePattern = new Pattern();
        int Command;

        while(true){
            Command = Data_IN.nextInt();
            if(Command == -1) break;

            OnePattern.Processing(Command);
        }
        OnePattern.getActionCodeName();
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_15a16_Graph/Pattern.java
```java
package Lab_15a16_Graph;
import javax.swing.*;
import java.util.ArrayList;

public class Pattern {
    private State S1, S2, S3, S4, S5 = new State();

    public Pattern() {
        S1.Settings(1, S5,"add_library"); S1.Settings(0, S2,"create_project");
        S2.Settings(1, S4,"drop_db");     S2.Settings(0, S3, "test");
        S3.Settings(1, S5,"add_library"); S3.Settings(0, S4, "drop_db");
        S4.Settings(1, S5,"deploy");      S4.Settings(0, S3,"restart");
        S5.Settings(1, S3,"restart");     S5.Settings(0, S1,"deploy");
    }

    private ArrayList<String> ActionCodeName = new ArrayList<>();
    State CurrentBlock = new State();

    public void getActionCodeName() {
        for(String CurrentName: ActionCodeName) System.out.println(ActionCodeName);
    }

    public void Processing(int CommandName){
        for (int i = 0; i < S1.getConnections().size(); i++)
            if (S1.getConnections().get(i) == CommandName){
                ActionCodeName.add(S1.getCommandNames().get(i));
                S1 = S1.getStates().get(i);
            }
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_15a16_Graph/State.java
```java
package Lab_15a16_Graph;
import java.lang.reflect.Array;
import java.util.ArrayList;

public class State {
    private ArrayList<Integer> Connections = new ArrayList<>();
    private ArrayList<State> States = new ArrayList<>();
    private ArrayList<String> CommandNames = new ArrayList<>();

    public void Settings(int Connection, State State, String CommandName){
        Connections.add(Connection);
        States.add(State);
        CommandNames.add(CommandName);
    }

    public ArrayList<Integer> getConnections() {
        return Connections;
    }

    public ArrayList<State> getStates() {
        return States;
    }

    public ArrayList<String> getCommandNames() {
        return CommandNames;
    }
}
```
## D:\Work\\IntelliJ IDEA projects\Java_Test\src\Lab_17_Files_vs_Markdown/Main.java
```java
package Lab_17_Files_vs_Markdown;

import java.io.*;

public class Main {
    static PrintWriter printWriter;

    static {
        try {
            printWriter = new PrintWriter("AllFiles.md");
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    public static void getFiles(String path){
        File file = new File(path);
        if(file.isDirectory()){
            String[] contents = file.list();
            for (String s:contents) {
                getFiles(path+"/"+s);
            }
        }
        if(file.isFile() ) {
            if (file.getName().substring(file.getName().lastIndexOf(".")).equals(".java")) {
                try (BufferedReader reader = new BufferedReader(new FileReader(path))) {
                    printWriter.write("## " + path + "\n```java\n");
                    String line = reader.readLine();
                    while (line != null) {
                        printWriter.write(line + "\n");
                        line = reader.readLine();
                    }
                    printWriter.write("```\n");


                } catch (FileNotFoundException e) {
                    e.printStackTrace();
                } catch (IOException e) {
                    e.printStackTrace();
                }

            }
        }

    }

    public static void main(String[] args) {

        String basePath = "D:\\Work\\\\IntelliJ IDEA projects\\Java_Test\\src";
        File file = new File(basePath);

        String[] files = file.list();
        String[]  filePaths = new String[files.length];

        for (int i = 0; i <files.length ; i++) {
            filePaths[i]=basePath+"\\"+files[i];
            getFiles(filePaths[i]);
        }

        printWriter.close();
    }
}
```
