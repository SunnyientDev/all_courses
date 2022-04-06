package Lab_27_28;

import com.google.gson.*;
import com.google.gson.reflect.*;

import java.io.*;
import java.util.*;
import java.lang.reflect.*;
import java.util.stream.*;

public class MainClass {
    public static void main(String[] args) throws Exception {
        Gson gson = new Gson();

        WorkerClass Worker = new WorkerClass();
        Class<WorkerClass> workerClass = WorkerClass.getClass();

        Type TaskType = new TypeToken<ArrayList<Task>>(){}.getType();
        ArrayList<Task> Tasks = gson.fromJson(Worker.getTask(), TaskType);

        List<Method> Declared = Arrays.stream(workerClass.getDeclaredMethods())
                .filter(m -> Arrays.stream(m.getAnnotations()).anyMatch(a -> a instanceof RetInterface))
                .collect(Collectors.toList());

        for (Task CurrentTask : Tasks)
            for (Method CurrentMethod : Declared)
                if (CurrentTask.getType().equals(CurrentMethod.getName()))
                    CurrentMethod.invoke(Worker, CurrentTask.getData());
    }
}