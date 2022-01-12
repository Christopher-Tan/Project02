### Project 02
**Theodore Fahey, Christopher Tan**  
**Period 05**

---

**Project Description**: Ultimate Tic-Tac-Toe with a modified win condition that a victory in any one of the nine subgames results in a win for the concerned player.  
Someone who wants to play Ultimate Tic-Tac-Toe would connect to a server that will pair the player with another and be presented with an interactive user interface.  

**Technical Design**: A main server accepts clients and forks off subservers, pairs of these subservers will use shared memory to share moves between each other. The main server will o_creat and manage these shared memories & share the s.m. id's with the subservers during forking. It will also leave precedence to the first player connected (this player will move first). The two subservers will alternately block on reading from the client and reading from the shared memory and also be in charge of determining wins and losses.  

**Important Concepts Utilized**: Memory allocation (our board will be an array of arrays, and our functions will work correctly with this board), Working with files (to read to and write from the shared memory as well as the sockets), Processes (subservers), Shared Memory, Sockets, and potentially Semaphores, though that seems more like a precautionary measure for the moment.

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
