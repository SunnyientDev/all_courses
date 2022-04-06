/* The report consists of:
1. Identifier (int id)
2. ID of the completed task (int taskId)
3. Worker ID (String worker) - the name of the student who wrote the worker
4. Result - (double result) */

public class Report {
//properties
  private int id;
  private int taskId;
  private String worker;
  private double result;

//constructor
  public Report (int id, int taskId, String worker, double result){
    this.id = id;
    this.taskId = taskId;
    this.worker = worker;
    this.result = result;
  }

//getters and setters
  public int get_ID(){ return id; }
  public int get_TaskID(){ return taskId; }
  public String get_Worker(){ return worker; }
  public double get_Result(){ return result; }

  public void set_ID(int id){ this.id = id; }
  public void set_TaskID(int taskId){ this.taskId = taskId; }
  public void set_Worker(String worker){ this.worker = worker; }
  public void set_Result(double result){ this.result = result; }
}