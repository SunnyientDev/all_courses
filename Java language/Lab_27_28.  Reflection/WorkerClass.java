package Lab_27_28;

import java.lang.annotation.Retention;
import java.util.*;
import java.net.*;
import java.net.http.*;
import java.io.*;

public class WorkerClass {

    @RetInterface
    public void print(Data CurrentDate) {
        ArrayList<String> OUTPUT = CurrentDate.getWords();
        for (int i = 0; i < OUTPUT.size()-1; i++) System.out.print(OUTPUT.get(i) + CurrentDate.getDelimeter());
        System.out.println(OUTPUT.get(OUTPUT.size()-1));
    }

    @RetInterface
    public void sum(Data CurrentDate) {
        int Sum = 0;

        ArrayList<Integer> numbers = CurrentDate.getNumbers();
        for (Integer number : numbers) Sum += number;

        System.out.println(Sum);
    }

    public static String getTask() throws Exception {
        HttpClient httpClient = HttpClient.newHttpClient();

        HttpRequest request = HttpRequest.newBuilder()
                .GET()
                .uri(URI.create("http://gitlessons2020.rtuitlab.ru:3000/reflectionTasks"))
                .build();

        HttpResponse<String> response = httpClient.send(request, HttpResponse.BodyHandlers.ofString());
        return response.body();
    }
}