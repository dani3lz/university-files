import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    private ServerSocket serverSocket;

    public Server(ServerSocket serverSocket) {
        this.serverSocket = serverSocket;
    }

    public void startServer(){
        try{

            while(!serverSocket.isClosed()){

                Socket socket = serverSocket.accept();
                ClientHandler clientHandler = new ClientHandler(socket);
                String username = clientHandler.getClientUsername();
                System.out.println("[SERVER]: " + username + " - A new client has connected!");

                Thread thread = new Thread(clientHandler);
                thread.start();
            }

        } catch (IOException e){
            closeServerSocket();
        }
    }

    public void closeServerSocket(){
        try{
            if(serverSocket != null){
                serverSocket.close();
            }
        }catch (IOException e){
            e.printStackTrace();
        }
    }

    public static void main(String[] args) throws IOException {

        ServerSocket serverSocket = new ServerSocket(1234);
        Server server = new Server(serverSocket);
        server.startServer();
    }
}
