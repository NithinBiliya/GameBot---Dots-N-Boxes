//	This file contains the different variables used in the game.

struct LINE								//	Stores a line with end points p1 and p2
{
	int p1,p2;
};

int move=-1,b1_pts=0,b2_pts=0;

/*	

All the 36 dots are considered to be nodes of a graph. So a 36X36 matrix is used to represent it.

LINE : structure that has p1 and p2 to store the starting and ending points of the line
line : variable of type line
move : variable that indicates which bot's chance to draw the line
	move=-1 : bot 1 chance to draw line
	move=1  : bot 2 chance to draw line
b1_pts : variable to store the points of bot 1 (number of squares formed by bot 1)
b2_pts : variable to store the points of bot 2 (number of squares formed by bot 2)
grid : it is a 2D integer matrix that stores the adjacency matrix of the graph.
grid2 : it is a copy of the grid. It is used for error checking. Programmer need not bother about this
box : it is a 2D 5X5 integer matrix that stores which and all squares are occupied by which bots. 
	box[i][j]=0 means the square is not yet formed
	box[i][j]=-1 means the square is formed by bot1
	box[i][j]=1 means the square is formed by bot2

NOTE : your bot function should not modify the value of move or b1_pts or b2_pts or grid or box variables. 
       It should only return the line which has to be drawn

*/
