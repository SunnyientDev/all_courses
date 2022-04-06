/* Task for practics No. 21-22.

You need to implement the ItemsStore.java interface in two ways
Store the entire collection of Items in the Data.json file Use the API of the service available at http://80.87.199.76:3000/

It is necessary to create a program that, when launched, it will be possible to choose which implementation to use, and in the future to work with the Data warehouse. 

Namely:
-Display all entries (no description field)
-Display one single entry (including the description field)
-Edit any entry
-Delete any entry

The interface can be implemented both in the console version and using a library of graphic elements (for example, swing).
*/

@autor CAPCHIK
@version 2.1
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException, InterruptedException {
        //scanner
        Scanner Data_IN = new Scanner(System.in);
        
        //variables
        String Act;
        ItemsStore ItemsStorage; 

        //storage type
        System.out.println("Choose storage type: \n File\n Server");
        Act = Data_IN.next();
        
        while(!Act.equals("File") && !Act.equals("Server")){
            System.out.println("Invalid type!");
            System.out.println("Choose storage type: \n File\n Server");
            Act = Data_IN.next();
        }

        if(Act.equals("Server")) ItemsStorage = new JsonServer();
        if(Act.equals("File")) ItemsStorage = new JsonFile();
        System.out.println("Chosen storage type: " + Act);
        
        while(true) {
          Act = Data_IN.nextLine();

          switch(Act){
                case "add":
                    int ID; String Data, description; boolean Condition;

                    System.out.print("Item ID: ");           ID = Data_IN.nextInt();
                    System.out.print("Item Data: ");         Data = Data_IN.next();
                    System.out.print("Is this item good: "); Condition = Data_IN.nextBoolean();
                    System.out.print("Item description: ");  description = Data_IN.next();
                    System.out.println("Item added: " + ItemsStorage.addItem(new Item(ID, Data, Condition, description)));
                    break;

                case "get":
                    int getID;
                    System.out.print("Enter item ID: "); getID = Data_IN.nextInt();
                    
                    Item answer = ItemsStorage.get(getID);

                    if (answer == null) {
                        System.out.println("Not found");
                    } else System.out.println(answer + " Description: " + answer.getDescription());
                    break;

                case "getAll":
                    List<Item> Items = ItemsStorage.getAll();
                    for (Object i: Items) System.out.println(i);
                    break;

                case "edit":
                    int edit_ID, ID_edited;
                    boolean Condition_edited;
                    String Data_edited, Description_edited;

                    System.out.print("Enter item ID (you want to change): "); edit_ID = Data_IN.nextInt();
                    Item current_Item = ItemsStorage.get(edit_ID);
                    System.out.println(current_Item);

                    System.out.print("Enter new Data: ");        Data_edited = Data_IN.next();
                    System.out.print("Enter new ID: ");          ID_edited = Data_IN.nextInt();
                    System.out.print("Enter new condition: ");   Condition_edited = Data_IN.nextBoolean();
                    System.out.print("Enter new description: "); Description_edited = Data_IN.next();

                    ItemsStorage.editItem(new Item(ID_edited, Data_edited, Condition_edited, Description_edited), edit_ID);
                    break;

                case "delete":
                    System.out.print("Enter item ID (you want to delete): ");
                    int To_delete = Data_IN.nextInt();
                    
                    if(ItemsStorage.get(To_delete) != null) System.out.println("Item with ID " + To_delete + " was deleted");
                    ItemsStorage.deleteItem(To_delete);
                    break;
            }
        }
    }
}