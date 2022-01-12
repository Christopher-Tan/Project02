### Project 02
**Theodore Fahey, Christopher Tan**  
**Period 05**

---

**Project Description**: Ultimate Tic-Tac-Toe with a modified win condition that a victory in any one of the nine subgames results in a win for the concerned player.  
Someone who wants to play Ultimate Tic-Tac-Toe would connect to a server that will pair the player with another and be presented with an interactive user interface.  

**Technical Design**: A main server accepts clients and forks off subservers, pairs of these subservers will use named pipes to share moves between each other. The main server will o_creat and manage these shared memories & share the s.m. id's with the subservers during forking. It will also leave precedence to the first player connected (this player will move first). The two subservers will alternately block on reading from the client and reading from the pipes and also be in charge of determining wins and losses.  

**Important Concepts Utilized**: Memory allocation (our board will be an array of arrays, and our functions [verifying wins, sharing moves, and subfunctions]  will work correctly with this board), Working with files (to read to and write from the pipes as well as the sockets), Processes (our subservers will be forked off our main server with the correct data [pipe name, order of players, etc.]), Named Pipes (we plan to send an array of two chars between the two subservers [and to the clients] representing the move that the opponent makes), Sockets (accepting and communicating with clients, each server will be perform a different function), and potentially Semaphores, though that seems more like a precautionary measure for the moment.

---

**Group Work Division**  
C: Mostly in charge of server side  
T: Mostly in charge of clients, graphics (including win/lose, turns, etc.), and program closing

---

**Timeline**  
1/16: Finished with match making  
1/17: Finished with server side protocols  
1/18: Finished with graphics (fully functioning game)  
1/20: Improved graphics (more refined game)
