/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.net.*;
import java.io.*;

public class Server 
{
    
    
    
    
   
private static Socket socket;
 
    public static void main(String[] args)
    {
        try
        {
 
            int port = 9500;
            ServerSocket serverSocket = new ServerSocket(port);
            System.out.println("Server Started and listening to the port 9900");
 
            //Server is running always. This is done using this while(true) loop
            while(true)
            {
                //Reading the message from the client
                socket = serverSocket.accept();
                InputStream is = socket.getInputStream();
                InputStreamReader isr = new InputStreamReader(is);
                BufferedReader br = new BufferedReader(isr);
                String uname = br.readLine();
                System.out.println("Message received from client is "+uname);
                 String note = br.readLine();
                 System.out.println("Message received from client is "+uname);
 
                //Multiplying the number by 2 and forming the return message
               
 
                //Sending the response back to the client.
                OutputStream os = socket.getOutputStream();
                OutputStreamWriter osw = new OutputStreamWriter(os);
                BufferedWriter bw = new BufferedWriter(osw);
                bw.flush();
            }
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
        finally
        {
            try
            {
                socket.close();
            }
            catch(Exception e){}
        }
    }
}