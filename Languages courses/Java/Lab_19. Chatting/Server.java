package SourceCode;

import java.io.*;
import java.net.*;
import java.text.SimpleDateFormat;
import java.util.*;

public class Server {
    public static void main(String[] args) throws IOException {
        ArrayList<InetAddress> AllAddresses = new ArrayList<>();
        ArrayList<Integer> AllPorts = new ArrayList<>();
        PrintWriter OneWriter = new PrintWriter("ChatHistory.txt");

        byte[] Buffer = new byte[256];
        String Message, Data, Date;

        DatagramSocket OneSocket = new DatagramSocket(9087);
        DatagramPacket OnePacket = new DatagramPacket(Buffer, 0, Buffer.length);

        while(true){
            DatagramPacket ToChat = null;

            try {
                OneSocket.receive(OnePacket);
            } catch (IOException OneException){
                OneException.printStackTrace();
            }

            System.out.println("Address: " + OnePacket.getAddress());
            System.out.println("Port: " + OnePacket.getPort());

            int Counter = 0;
            for (int i = 0; i < AllPorts.size(); i++)
                if(OnePacket.getPort() == AllPorts.get(i) && OnePacket.getAddress() ==  AllAddresses.get(i)) Counter++;

            if(Counter == 0){
                AllAddresses.add(OnePacket.getAddress());
                AllPorts.add(OnePacket.getPort());
            } else {
                Message = new String(Buffer, 0 , OnePacket.getLength());
                Date = new SimpleDateFormat("hh:mm").format(new Date());
                Data = Date + "  " + Message;

                System.out.println(Data);
                for (int i = 0; i < AllPorts.size(); i++) {
                    if(OnePacket.getPort() == AllPorts.get(i) && !(OnePacket.getAddress() == AllAddresses.get(i)));
                        ToChat = new DatagramPacket(Data.getBytes(), 0, Data.getBytes().length, InetAddress.getByName("255.255.255.255"), AllPorts.get(i));

                        try {
                            OneSocket.send(OnePacket);
                        } catch (IOException OneException){
                            OneException.printStackTrace();
                        }
                }
                OneWriter.write(Data + "\n");
            }
            OneWriter.flush();
        }
    }
}
