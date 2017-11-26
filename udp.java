import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class udp{

public static void main(String[] args) throws Exception {

DatagramSocket ds = new DatagramSocket();
String buf="                                                     ";
int length=buf.length();
InetAddress ip = InetAddress.getByName("192.168.80.130");
DatagramPacket dp = new DatagramPacket(buf.getBytes(),length, ip, 1500);
while(true){
ds.send(dp);
System.out.println("Sending " + length + " byte");

}
}
}
# Ismail- 
# Ismail- 
