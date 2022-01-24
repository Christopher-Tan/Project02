### Project 02
**Theodore Fahey, Christopher Tan**  
**Period 05**

---

**Project Description**: Ultimate Tic-Tac-Toe with a modified win condition that a victory in any one of the nine subgames results in a win for the concerned player.  
Someone who wants to play Ultimate Tic-Tac-Toe would connect to a server that will pair the player with another and be presented with an interactive user interface.  

**Technical Design**: A main server accepts clients and uses select to communicate between players. The main server will handle new clients and pass moves between clients, there will be a record of opponent pairs. It will also leave precedence to the first player connected (this player will move first). The boards of our clients will be rendered using SDL2. A struct containing all of the important game information is stored, on victory a green screen is displayed, on loss a red screen and an L will be displayed instead, on draw, a gray screen will be shown. Every move is checked before it is allowed to be made.

**Important Concepts Utilized**: Memory allocation (our board will be an array of arrays, and our functions [verifying wins, sharing moves, and subfunctions]  will work correctly with this board), Linked List (our pairings will be stored in a linked list, as it is extendable "indefinitely"), Working with files (reading and writing to clients and servers), and Sockets (accepting and communicating with clients, usage of select permits the usage of one central server and no subservers).

**Group Work Division**  
C: Mostly in charge of server side  
T: Mostly in charge of clients, graphics (including win/lose, turns, etc.), and program closing

**Timeline**  
1/16: Finished with match making  
1/17: Finished with server side protocols  
1/18: Finished with graphics (fully functioning game)  
1/20: Improved graphics (more refined game)

---

**Required Libraries**  
***SDL2***  
sudo apt-get install libsdl2-2.0  
***SDL2 Dev***  
sudo apt-get install libsdl2-dev  

---

**Usage**  
Install the package on all devices.  
_Note: The server and client are not necessarily different devices, if this is the case, ignore the following step, unless you wish to change the port number._  
On the server device, find its IP Address and an available port (default 9001), in the networking.h file of both devices, change the IP and PORT variables according to the ___server's___ configuration.  
Run makefile.  
On the server run ./server and on the clients run ./client

---

**Bibliograhy** 
Major Credits to Tscoding and his Tic-Tac-Toe tutorial. Helped me get acquainted with SDL.
https://www.youtube.com/watch?v=gCVMkKgs3uQ  
Our circle drawing algorithm was taken from the following source.  
https://stackoverflow.com/a/48291620  
