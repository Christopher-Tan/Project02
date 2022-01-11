# Project02
**Theodore Fahey, Christopher Tan** \
**Period 05** \
**Project Description**: Ultimate Tic-Tac-Toe with a modified win condition that a victory in any one of the nine subgames results in a win for the concerned player. \
Someone who wants to play Ultimate Tic-Tac-Toe would connect to a server that will pair the player with another and be presented with an interactive user interface. \
**Technical Design**: A main server accepts clients and forks off subservers, pairs of these subservers will use shared memory to share moves between each other. The main server will o_creat and manage these shared memories & share the s.m. id's with the subservers during forking.
