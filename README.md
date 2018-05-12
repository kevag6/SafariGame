# SafariGame
The game of life

DEPARTMENT OF ELECTRICAL AND COMPUTER ENGINEERING
EEL 4831 Embedded GUI Programming 
Spring 2018





Kevin Grifo - 4819794
Luciano Caminata - 4734345
Kevin Ugaz - 3867272




Submitted to:

Instructor: Professor Alexander Pons

April 24, 2018
Safari Project Requirement Analysis and Design Phases

Primary Object Definitions

Arena - The arena will be a three-dimensional array of cell objects. These cell objects may be a cell, lion, hyena, gazelle, zebra, rock, and cliff. The arena will be created dynamically by x, y, and z values obtained from the user, where x and y make up the size of the plane based on the number of cells, and z determines the number of planes.  
Cell - The cell objects are what will fill the arenas. Once again the cell objects for our project will be a cell (empty space), lion (predator), hyena (predator), gazelle (prey), zebra (prey), rock (obstacle), and cliff (obstacle).
Lion (predator) - A Lion will be at the top of the food chain and will be able to feed on any other animal object in our game.
Gazelle (prey) - The gazelle will be at the bottom of the food chain and will differ from a zebra in that it will be able to reproduce at a quicker pace. The gazelle will not need to eat to reproduce, they will reproduce based on a timer that will be defined at a later time.
Mountain/Rock (obstacle) - If a cell is populated by a mountain/rock then animal objects will not be able to walk into that cell the whole game.
Bridge (transport) - A bridge can be used by predator and prey to travel from one plane to another. There will be at least one bridge connecting each plane so that predator and prey objects can travel to each plane (or z).


Basic GUI Description

The GUI should be user friendly and visually appealing to make user experience as pleasing as possible. We intend to have a homepage that will give the user three options, those three options are.
Play - the first option will be to play the game. When clicked the user shall be sent to the game that should look like the depiction below.
Quit - When the user hits quit the application will turn off.
How to Play - this page will give the player a brief description of all the objects in the game and how to setup a new game.
When setting up a game and playing the game the GUI that should be displayed should look like the figure below.






First design of the GUI


The player will have options and use sliders to control how many predators, prey, and obstacles will appear in the arena for each game. We will also constantly keep track of the count of all the animal objects in the game, and the winner will be determined as the last animal standing.

Summary of objects and classes hierarchy
    
    In this section we will give a brief summary of the objects and classes that will be included in our game.
Prey, predators, obstacles, and transport are all specialized cells in our game’s arena. 
Every cell will have have and know their prospective x, y, and z locations within our game’s arena.
The arena will be a 3-dimensional array of cell objects, with each cell object knowing it’s x, y, and z location at any given time. There will be specialized cell objects that may move around the arena updating it’s prospective location coordinates while doing so. In order for the cell and container to function properly it is important that we implement a static member variable in our cell class, which is fully aware of the Arena object. The Arena object will also contain the cell instances which will ultimately comprise the arena.

Mini Specifications of the Simulation

    In this section we will go into more detail concerning the actual simulation of cell objects in our game.
The arena, consisting of a 3-dimensional array of cell objects, where a cell can be an instance of the base Cell class or any of Cell’s subclasses (Classes that inherit from Cell): lion, gazelle, obstacle (rocks and waterfalls), and transport (bridges).
By default the game will start off with 3 planes (z = 3), consisting of 30 rows (x = 30), and 75 columns (y = 75). This is what will show on default however the user will have the power to change all these values every time a new game is started. Instance SafariArena1 will be created as a class variable in the Cell class. 
The user will then be prompted to specify the number of predator (lion and hyena), prey (gazelle and zebra), and obstacle objects (mountain/rock and waterfall/cliff) they wish to have. The user will not have control over the number of transport/bridge objects. Transport objects will automatically be added based on the number of planes (the z value) the user wants (one bridge connecting each plane). 
The simulation will continuously iterate until there is only one type of predator or prey remaining. The last species standing will be the winner of our game, and once this is known we will display it as a popup message to the player of our game. An iteration consists of the following steps.

For each Cell in the Arena, there will be an animate process which differs based on the cell type. This is explained in more detail below:
It is important that we define what an adjacent cell is before explaining any further. Adjacent cells are any cells that are above, below, to the right, or to the left of the current cell (which will be centered in between these cells).
Prey will have the ability to move to any random adjacent cell as long as there is no obstacle occupying the cell or the are on the edge where no cell exists. Also after a certain amount of ticks the prey will be able to reproduce to create more prey objects in the arena
Lions movement shall be similar to the movement of gazelles, however they differ from gazelles in that they must feed on prey in order to live and reproduce. In order for a lion to reproduce they must be on a full stomach when it is time to reproduce.
Obstacles, such as cliffs and waterfalls, and empty cells have no specialty function, only to occupy the empty space in the arena.
After every tick process the timeToReproduce value will be decremented for each prey object and predator object. Once the timeToReprouce value reaches zero, for prey objects, they will successfully reproduce creating one child. Predator objects also reproduce but will have a different timeToReproduce starting value so they don’t reproduce as frequent. Predator objects also must continuously feed in order to stay alive. The hunger level of predator objects will be monitored and once the predator reaches starvation they will die. When a predator object eats a cell object there hunger level will be reset back to its highest value.
After each iteration the number of prey, predator, and obstacle objects will be updated and displayed for the player to see.
Our game ends when there is only one species standing. The last species standing will be crowned the King of the Safari.

Details of Objects:

Arena: As stated before, this class represents a three-dimensional array of cell objects that may differ based on the settings and values the player inputs when starting a new game. The player will have the ability to specify the number of predator (lions and hyenas), prey (gazelles and zebras), and obstacle objects they would like the game to start off with. Each prey and predator object will be able to reproduce, move, and die based on the rules that we have defined in our game.

Instance Variables:

Cells: a three-dimensional array of Cell objects. Cell objects will know where they are located in the arena based on x, y, and z locations.

numRows: The number of rows for the game, specified by the user. (x value, maxRows = 15).
numCols: The number of columns for the game, specified by the user. (y value, maxCols = 35).
numPlanes: The number of planes for the game, specified by the user. (z value, maxPlanes = 3).
totalNumCells: The total number of cells in the arena. This is determined by multiplying numRows, numCols, and numPlanes.
numPrey: User specified initial number of gazelles.
numPredator: User specified initial number of lions.
numObstacles: User specified initial number of rock objects.
Random: A random number generator that will be used for the randomization of the tick function call.
Messages:

Accessor/Mutator Methods:
getNumGaz: returns the number of gazelle objects remaining.
setNumGaz: set/update the number of gazelle objects to a passed int number.
getNumLion: returns the number of lion objects remaining in the game.
setNumLion: sets/updates the number of lion objects to a passed int number.

Initialization methods:
Initialize: This method will initialize the arena size based on the parameters the user inputted for the arena size.
initCells: Will ask the user how many lion, gazelle, and obstacle objects they would like to have in this instance of the arena.

addRocks: add the number of obstacles/rocks that the user specified during initialization.
addLions: add the number of predators/lions that the user specified during initialization.
addGazelles: add the number of prey/gazelles that the user specified during initialization.

Displaying Methods:
displayPlane: display the arena plane image that the player has selected as a grid of rows and columns.
displayCells: display the images for the individual cell objects.
displayStats: update the display that depicts the current stats of the game, such as the remaining number of lions, gazelles, and obstacles. We may also want to display the length of the current game using a timer.

Run Methods:
Run: Prompt the user to start the game by clicking a RUN button. The game will continue to run until there is only one species standing.

Cell (Superclass): A superclass of all kinds of cells found in our arena and game. Cells are attached to an Safari Arena which is a 3-dimensional array of cell objects. The default image for a cell object will be an empty cell with nothing in it.


Static Members:

safariArena: An instance of the game’s arena that is a 3-dimensional array of cells. All the cells will be associated with a safariArena for every simulation.

Instance Variables:

Location: The x, y, z coordinate location of the cell object in the arena.
cellImage: An image will be used to display all the cell objects. We will find appropriate images to represent a lion, gazelle, rock, and bridge. An empty cell will just be displayed with nothing in the cell.

Messages:

Accessor/Mutator Methods:
getLocation: return the cell’s location.
setLocation(aCoord): sets/updates the cells location by passing a x, y, z coordinate as the parameter and setting the cells location to aCoord. 
getImage: returns the image of the desired cell object.

Process and Display Methods:
display: display the cell at its current location in the arena
process: process the cell objects move command. The cell object’s move command may differ based on the type of cell object it is.
getEmptyNeighborCoord: find an empty neighbor cell and get their x, y, and z coordinate.
getPredatorNeighborCoord: find a neighbor cell that contains a predator. This is important for a prey object so they know which cell not to go to.
getPreyNeighborCoord: find a neighbor cell that contains a prey. This is important for a predator as this is the cell they need to move to in order to feed.
getCellAt: returns a cell object based on the coordinate locations that was passed as a parameter.
assignCellAt: will assign a cell object to a new location in the SafariArena based on the location parameter that was passed in. This is an important method when cell objects are moving around in our game.

Instance Creation Method:
Cell: default constructor method called each time a new Cell object is created.


Gazelle (Prey): Subclass of cell that is the prey (gazelle) in the game. It can move, reproduce. The default image is of a gazelle.

Instance variables:
reproduce: timer setup to create another prey object in the game. 

Messages:
prey: construct the prey cell and reset the image. 

Process and Display method:

process: move to an empty cell and decrement the reproduce timer. 
move: takes in two parameters, where to move from and where to move to. Moves to coordinate. 
reproduce: same as the previous method but will take a parameter, which is the coordinate it will be placed in in the arena.   

Lion (Predator): Lion is a subclass of Cell. Lions differ from gazelles in that they must eat to survive. Lions can can move, reproduce, and eat prey. The default image for the lion will be determined at a later time.

Instance Variables:

feedingTime: The value that determines the amount of time units that a lion must feed before they die. The default value for feedingTime is feedingTime = 7. If feedTime reaches 0 then then the lion will die.

Messages:

Instance Creation Method:
Lion: Invoke Lion constructor and set instance variables feedingTime to 7 (default value) and assign the instance variable image.

Processing and Displaying Methods:
Animate: check current feedingTime value, if the value is 0 the lion will die, else the lions first priority will be to feed on a prey and find prey in a a, djacent cell, else the lion will move to an empty adjacent cell, else the lion will not move at all. After every tick the lion’s timeToReproduce value will be decremented.
moveFrom(source, destination): The lion will move from the source location to the destination location in the arena.
Reproduce: If the lion’s feedingTime value does not equal 0 AND timeToReproduce equals 0 then the lion will make a duplicate of itself and place it’s duplicate in an empty cell. 


Mountain (Obstacle): The mountain is a subclass of cell and it is an obstacle. This obstacle cannot move and is set to block both the predator and the prey. The image will be a mountain. 

Instance creation method:
obstacle: create cell constructor for the obstacle. Provide the image. 

Coordinates: x and y coordinates of the obstacles will be represented. 

Instance variables:
x coordinate 
y coordinate 
King of the Jungle Flow Chart





