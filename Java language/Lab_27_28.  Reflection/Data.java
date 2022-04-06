package Lab_27_28;
import java.util.*;

public class Data {
    // Let's name all the variables the same as in the json file
    private ArrayList<Integer> numbers;
    private ArrayList<String> words;
    private String delimeter;

    public Data(ArrayList<Integer> numbers, ArrayList<String> words, String delimeter) {
        this.numbers = numbers;
        this.words = words;
        this.delimeter = delimeter;
    }

    //generate all
    public String getDelimeter() {
        return delimeter;
    }

    public void setDelimeter(String delimeter) {
        this.delimeter = delimeter;
    }

    public ArrayList<Integer> getNumbers() {
        return numbers;
    }

    public void setNumbers(ArrayList<Integer> numbers) {
        this.numbers = numbers;
    }

    public ArrayList<String> getWords() {
        return words;
    }

    public void setWords(ArrayList<String> words) {
        this.words = words;
    }

    public String toString() {
        return "Data{" +
                "delimeter='" + delimeter + '\'' +
                ", numbers=" + numbers +
                ", words=" + words +
                '}';
    }
}
