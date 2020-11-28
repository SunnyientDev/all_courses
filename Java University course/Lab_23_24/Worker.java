/*"Worker" executes tasks stored on a remote server.

Functions:
1. The Worker should poll the server for new tasks at intervals from  
    1 second to 2 seconds. For each expectation, choose a random interval within the described boundaries.

2. The result of the expression execution must be saved in the 
    “reports” collection.

3. Each worker keeps a list of already completed tasks in the db.json 
    file, when polling for new tasks, it checks against the tasks that have already been completed, and if there are new ones, executes them with the subsequent sending of a report.

The address of the collection with tasks is 
http://gitlessons2020.rtuitlab.ru:3000/tasks 
ONLY GET REQUESTS IS PERMITTED 

The address of the collection with reports is http://gitlessons2020.rtuitlab.ru:3000/reports 
ONLY POST REQUESTS IS PERMITTED */
import java.util.ArrayList;
import java.util.List;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

import com.google.gson.Gson;
import com.google.gson.JsonArray;
import com.google.gson.JsonElement;
import com.google.gson.JsonObject;
import com.google.gson.reflect.TypeToken;
import com.google.gson.stream.JsonReader;
import java.lang.reflect.Type;

import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;

public class Worker {
  HttpClient httpclient = HttpClient.newHttpClient();
  Gson gson = new Gson();

  ArrayList<JsonObject> Tasks = new ArrayList<>();
  List<Integer> IDs = new ArrayList<>();
  private String WorkerName = "Oronovskaya";
  
//default in this project, we don't need to create new File
//File outFile = new File("db.json"); 
  FileWriter ToFile;
  FileReader FromFile;
  JsonReader FromJson;
  
//constructor
  Worker(){
    Type type = new TypeToken<List<Integer>>(){}.getType();
    
    try {
      ToFile = new FileWriter("db.json", true);
      FromFile = new FileReader("db.json");
      FromJson= new JsonReader(FromFile);
      
      if(FromFile.read() == -1) {
        ToFile.write("[]");
        ToFile.flush();
      }
    } catch (Exception exception) {
            exception.printStackTrace();
    }
    IDs = gson.fromJson(FromJson, type);
  }

//get all information
  void getInfo() throws IllegalStateException, IOException, InterruptedException {
    HttpRequest request = HttpRequest.newBuilder()
      .GET()
      .uri(URI.create("http://80.87.199.76:3000/tasks"))
      .build();
    
    HttpResponse<String> response = httpclient.send(request,HttpResponse.BodyHandlers.ofString());
    JsonArray jsonArray = gson.fromJson(response.body(), JsonArray.class);

    Tasks.clear();
    for(JsonElement i: jsonArray) Tasks.add(i.getAsJsonObject());
  }

//Execute yout operation
  double Execute(String act){
    String Action;
    int num1, num2;
    
    act = act.replace(" ", "");
    String[] Actions = act.split("(?<=\\d)(?=\\D)|(?<=\\D)(?=\\D)|(?<=\\d\\D)(?=\\d)");
    
    Action = Actions[1];
    num1 = Integer.parseInt(Actions[0]);
    num2 = Integer.parseInt(Actions[2]);
    
    switch(Action){
      case"+":  return num1 + num2;
      case"-":  return num1 - num2;
      case "*": return num1 * num2;
      case "/": return (int)(num1 / num2);
    }
    return 0;
  }

//add new report 
void addReport(int taskID, double result) throws IOException, InterruptedException {
  HttpClient httpclient = HttpClient.newHttpClient();
  
  HttpRequest request = HttpRequest.newBuilder()
    .POST(HttpRequest.BodyPublishers.ofString(gson.toJson(new Report(0, taskID, WorkerName, result))))
    .uri(URI.create("http://80.87.199.76:3000/reports"))
    .setHeader("Content-Type", "application/json")
    .build();
       
  try {
    HttpResponse<String> response = httpclient.send(request, HttpResponse.BodyHandlers.ofString());
  } catch(Exception exception){
    exception.printStackTrace();
  }
}

  void DoOperations() throws IOException, InterruptedException {
    double Result;
          
    for (JsonObject i : Tasks) {
      if(!IDs.contains(i.get("id").getAsInt())){
          Result = Execute(i.get("expression").getAsString());
          
          IDs.add(i.get("id").getAsInt());
          addReport(i.get("id").getAsInt(), Result);
          
          System.out.println(i.get("taskDescription") + " was performed by Worker");
      }
    }
    
    try(FileWriter ToFile = new FileWriter("db.json")) {
      ToFile.write("[");
      ToFile.write(gson.toJson(IDs));
      ToFile.write("]");
      ToFile.flush();
    } catch (Exception exception){ exception.printStackTrace();}
  }
}