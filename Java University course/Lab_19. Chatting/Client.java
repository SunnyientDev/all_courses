package SourceCode;

import java.io.*;
import java.net.*;
import java.rmi.MarshalException;
import java.util.*;

public class Client {
    public static void main(String[] args) throws IOException {
        String LocalAddress = "127.0.0.1"; //we send data to ourselves
        Scanner Data_IN = new Scanner(System.in);
        DatagramSocket OneSocket = new DatagramSocket();

        System.out.println("Enter your nickname:");
        String OneName = Data_IN.nextLine();
        byte[] UserName = OneName.getBytes();

        DatagramPacket OnePacket = new DatagramPacket(UserName, 0, UserName.length, InetAddress.getByName(LocalAddress), 9087);
        try {
            OneSocket.send(OnePacket);
        } catch (SocketException OneException){
            OneException.printStackTrace();
        }

        //message sending and receiving threads
        Thread RecieveThread = new Thread(new Runnable() {
            public void run(){
                while(true){
                    byte[] buffer = new byte[256];
                    DatagramPacket ToReceive = new DatagramPacket(buffer, 0, buffer.length);

                    try {
                        OneSocket.receive(ToReceive);
                        System.out.println(new String(ToReceive.getData(), 0, ToReceive.getLength()));
                    } catch (IOException OneException){
                        OneException.printStackTrace();
                    }
                }}
        });

        Thread SendThread = new Thread(new Runnable() {
            public void run(){
                while(true){
                    String Message = Data_IN.nextLine();
                    Message = OneName + ": " + Message;
                    byte[] Data = Message.getBytes();

                    try {
                        DatagramPacket ToSend = new DatagramPacket(Data, 0, Data.length, InetAddress.getByName(LocalAddress), 9087);
                        OneSocket.send(ToSend);
                    } catch (IOException OneException){
                        OneException.printStackTrace();
                    }
                }}
        });

        RecieveThread.start();
        SendThread.start();
    }
}
