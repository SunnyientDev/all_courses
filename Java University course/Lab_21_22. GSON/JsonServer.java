//This JavaClass we use to working with JsonServer: http://80.87.199.76:3000/objects

import com.google.gson.Gson;
import java.io.*;
import java.net.*;
import java.net.http.HttpResponse;
import java.util.*;

public class JsonServer implements ItemsStore {
  Gson gson = new Gson();
  HttpClient httpClient = HttpClient.newHttpClient();

  String Source = "http://80.87.199.76:3000/objects";

  //set up everything in order
  public List<Item> getAll() throws IOException, InterruptedException {
    HttpRequest request = HttpRequest.newBuilder().GET().uri(URI.create(Source)).build();
    HttpResponse<String> response = httpClient.send(request, List.class);
    List<Item> ItemList = gson.fromJson(response.body(), List.class);
    return ItemList;
  }

  //all as in the previous set, despite the uri
  public Item get(int ID) throws IOException, InterruptedException {
    HttpRequest request = HttpRequest.newBuilder().GET().uri(URI.create(Source + "/" + ID)).build();
    HttpResponse<String> response = httpClient.send(request, List.class);
    return gson.fromJson(response.body(), Item.class);
  }

  public Item addItem(Item item) throws IOException, InterruptedException {
    String bodyPubliisher = gson.toJson(item);
    HttpRequest request = HttpRequest.newBuilder()
      .POST(HttpRequest.BodyPublishers.ofString(bodyPubliisher))
      .uri(URI.create(Source))
      .setHeader("Content-Type", "application/json")
      .build();

    HttpResponse<String> response = httpClient.send(request, HttpResponse.BodyHandlers.ofString());
    return gson.fromJson(response.body(), Item.class);
  }

  public Item editItem(Item item, int ID) throws IOException, InterruptedException {
    System.out.println(gson.toJson(item));
    HttpRequest request = HttpRequest.newBuilder()
      .POST(HttpRequest.BodyPublishers.ofString(bodyPubliisher))
      .uri(URI.create(Source + "/" + ID))
      .setHeader("Content-Type", "application/json")
      .build();

    HttpResponse<String> response = httpClient.send(request, HttpResponse.BodyHandlers.ofString());
    return get(item.getId());
  }

  public void deleteItem(int ID) throws IOException, InterruptedException {
    HttpRequest request = HttpRequest.newBuilder()
      .DELETE()
      .uri(URI.create(Source + "/" + ID))
      .build();
    HttpResponse<String> response = httpClient.send(request, HttpResponse.BodyHandlers.ofString());
    }
}