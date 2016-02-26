/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab3;
import java.net.*;
import java.io.*;
import java.util.Scanner;

/**
 *
 * @author aliaqat.bscs13seecs
 */
public class client {

    private static Socket socket;
 
    public static void main(String args[])
    {
        try
        {
            String host = "localhost";
            int port = 9500;
            InetAddress address = InetAddress.getByName(host);
            socket = new Socket(address, port);
 
            BufferedReader input = new BufferedReader(new InputStreamReader(socket.getInputStream()));

PrintWriter out = new PrintWriter(socket.getOutputStream(),true);
PrintWriter out2 = new PrintWriter(socket.getOutputStream(),true);
System.out.println("Kindly enter your name :");
String uname;
BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

uname = br.readLine();

System.out.println("Kindly enter your notes:");
String note;
note = br.readLine();


out.println(uname);
out2.println(note);
System.out.println("Notes " +  note);
String serverMsg = input.readLine()+"|=>|";
out.println("GoodBye Server");


            
            //Send the message to the server
         /*   OutputStream os = socket.getOutputStream();
            OutputStreamWriter osw = new OutputStreamWriter(os);
            BufferedWriter bw = new BufferedWriter(osw);
 
            String number = "2";
 
            String sendMessage = number + "\n";
            bw.write(sendMessage);
            bw.flush();
            System.out.println("Message sent to the server : "+sendMessage);
 
            //Get the return message from the server
            InputStream is = socket.getInputStream();
            InputStreamReader isr = new InputStreamReader(is);
            BufferedReader br = new BufferedReader(isr);
            String message = br.readLine();
            System.out.println("Message received from the server : " +message); */
        }
        catch (Exception exception)
        {
            exception.printStackTrace();
        }
        finally
        {
            //Closing the socket
            try
            {
                socket.close();
            }
            catch(Exception e)
            {
                e.printStackTrace();
            }
        }
    }
    
    
}
