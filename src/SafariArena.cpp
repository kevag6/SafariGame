#include "SafariArena.h"

SafariArena::SafariArena()
{

}

SafariArena::SafariArena(int numCols, int numRows, int numPlanes)
{
    //ctor
    this->numPlanes = numPlanes;
    this->numRows = numRows;
    this->numCols = numCols;
    arenaSize = numPlanes * numRows * numCols;


}

void SafariArena::initCells(int numLions, int numGazelles, int numObstacles) {
    this->numL = numLions;
    this->numG = numGazelles;
    this->numObstacles = numObstacles;
}

void SafariArena::setLions(int lions) {
    numL = lions;
}

void SafariArena::setGazelles(int gazelles) {
    numG = gazelles;
}

void SafariArena::setObstacles(int obstacles) {
    numObstacles = obstacles;
}

int SafariArena::getLions() {
     return numL;
}

int SafariArena::getGazelles() {
     return numG;
}

int SafariArena::getObstacles() {
     return numObstacles;
}

int SafariArena::getArenaSize(){
    return arenaSize;
}

SafariArena::~SafariArena()
{
    //dtor
}



void SafariArena::initialize(wxWindow *arenaGrid, wxWindowID id) {
//    check = new bool**[numCols];
//    for(int i = 0;  i < numCols; i++) {
//        check[i] = new bool*[numRows];
//        for(int j = 0; j < numRows; j++) {
//            check[i][j] = new bool[numPlanes];
//            for(int k = 0; k < numPlanes; k++) {
//                check[i][j][k] = false;
//            }
//        }
//    }
    check = new int**[numRows];
        for(int i = 0;  i < numRows; i++) {
            check[i] = new int*[numCols];
            for(int j = 0; j < numCols; j++) {
                check[i][j] = new int[numPlanes];
                for(int k = 0; k < numPlanes; k++) {
                    check[i][j][k] = 0;
                }
            }
        }

    wxPoint gridPos(0,0);
    for(int i = 0; i < numPlanes; i++){
        gridArray[i] = new wxGrid(arenaGrid, id,  gridPos, wxSize( 700, 800));
        gridArray[i]->CreateGrid( numRows, numCols);
        gridArray[i]->DisableDragColMove();
        gridArray[i]->DisableDragColSize();
        gridArray[i]->DisableDragRowSize();
        gridArray[i]->DisableDragRowSize();
        gridArray[i]->SetRowLabelSize(1);
        gridArray[i]->SetColLabelSize(1);
        gridArray[i]->SetDefaultRowSize(18, true);
        gridArray[i]->SetDefaultColSize(18, true);
        gridArray[i]->SetReadOnly( 0, 3 );
        gridPos.y += 18 * numRows + 5;
    }
    cellArr = new Cell***[numRows];
    for(int i = 0; i < numRows; i++){
        cellArr[i] = new Cell**[numCols];
        for(int j = 0; j < numCols; j++){
            cellArr[i][j] = new Cell*[numPlanes];
            for(int k = 0; k < numPlanes; k++){
                cellArr[i][j][k] = new Cell(i, j, k);
                //gridArray[k]->SetCellValue(i, j, cellArr[i][j][k]->cellImage);

            }
        }
    }
    srand(time(NULL));
    int lionIterate = 0;
//    wxString test;
//    test.Printf(wxT("Number of lions is %d"), numLions);
//    wxMessageBox(test);



    //Cell *cellSouth = newLion->cellSouth();
    if(numPlanes == 2){
        delete cellArr[numRows - 1][numCols - 1][0];
        cellArr[numRows - 1][numCols - 1][0] = NULL;

        cellArr[numRows - 1][numCols - 1][0] = new Bridge(numRows - 1, numCols - 1, 0);
        check[numRows - 1][numCols - 1][0] = 4;

        delete cellArr[0][numCols - 1][1];
        cellArr[0][numCols - 1][1] = NULL;

        cellArr[0][numCols - 1][1] = new Bridge(0, numCols - 1, 1);
        check[0][numCols - 1][1] = 4;

    }
    if(numPlanes == 3){
        //creating first bridge connection
        delete cellArr[numRows - 1][numCols - 1][0];
        cellArr[numRows - 1][numCols - 1][0] = NULL;

        cellArr[numRows - 1][numCols - 1][0] = new Bridge(numRows - 1, numCols - 1, 0);
        check[numRows - 1][numCols - 1][0] = 4;
        //creating second bridge connection
        delete cellArr[0][numCols - 1][1];
        cellArr[0][numCols - 1][1] = NULL;

        cellArr[0][numCols - 1][1] = new Bridge(0, numCols - 1, 1);
        check[0][numCols - 1][1] = 4;

        delete cellArr[numRows - 1][numCols - 1][1];
        cellArr[numRows - 1][numCols - 1][1] = NULL;

        cellArr[numRows - 1][numCols - 1][1] = new Bridge(numRows - 1, numCols - 1, 1);
        check[numRows - 1][numCols - 1][1] = 4;

        delete cellArr[0][numCols - 1][2];
        cellArr[0][numCols - 1][2] = NULL;

        cellArr[0][numCols - 1][2] = new Bridge(0, numCols - 1, 2);
        check[0][numCols - 1][2] = 4;
    }
    while(lionIterate < numLions){
        int x = rand() % numRows;
        int y = rand() % numCols;
        int z = rand() % numPlanes;
        if(!check[x][y][z]){

            delete cellArr[x][y][z];
            cellArr[x][y][z] = NULL;

            cellArr[x][y][z] = new Lion(x,y,z);
            /*wxString test;
            test.Printf(wxT("Lion is inserted in x %d y %d z %d"),cellArr[x][y][z]->getLocation().getX(), cellArr[x][y][z]->getLocation().getY(), cellArr[x][y][z]->getLocation().getZ());
            wxMessageBox(test);*/
            //gridArray[z]->SetCellValue(x, y, cellArr[x][y][z]->getImage());
            check[x][y][z] = 1;
            ++lionIterate;
        }
    }
    int gazelleIterate = 0;
    while(gazelleIterate < numGazelles){
        int x = rand() % numRows;
        int y = rand() % numCols;
        int z = rand() % numPlanes;
        if(!check[x][y][z]){

            delete cellArr[x][y][z];
            cellArr[x][y][z] = NULL;

            cellArr[x][y][z] = new Gazelle(x,y,z);
            //gridArray[z]->SetCellValue(x, y, cellArr[x][y][z]->getImage());
            check[x][y][z] = 2;
            ++gazelleIterate;
        }
    }
    int obstacleIterate = 0;
    while(obstacleIterate < numObstacles){
        int x = rand() % numRows;
        int y = rand() % numCols;
        int z = rand() % numPlanes;
        if(!check[x][y][z]){

            delete cellArr[x][y][z];
            cellArr[x][y][z] = NULL;

            cellArr[x][y][z] = new Obstacles(x,y,z);
            //gridArray[z]->SetCellValue(x, y, cellArr[x][y][z]->getImage());
            check[x][y][z] = 3;
            ++obstacleIterate;
        }
    }

    displayCells();


}

void SafariArena::displayCells()
{
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            for(int k = 0; k < numPlanes; k++){
                gridArray[k]->SetCellValue(i, j, cellArr[i][j][k]->getImage());
            }
        }
    }
}

int numMoves;

void SafariArena::displayStats()
{
    wxString lionStatString = wxString::Format(wxT("%i"),numLions);
    wxString gazelleStatString = wxString::Format(wxT("%i"),numGazelles);
    wxString moveStat = wxString::Format(wxT("%i"), numMoves);

    lionText->SetLabel(lionStatString);
    gazText->SetLabel(gazelleStatString);
    moveText->SetLabel(moveStat);
}



void SafariArena::run()
{
    int i = 0;
    numMoves = 0;
    wxString temp;

    while(numLions > 0 && numGazelles > 0){
//        temp.Printf(wxT("numLions is %d"), numLions);
//        wxMessageBox(temp);
        ++numMoves;
        wxString temp;
        temp.Printf(wxT("Movement: %d"), numMoves);
        wxMessageBox(temp);
        //updateTimer.Start(2000, 0);

        for(int i = 0; i < numRows; i++){

            for(int j = 0; j < numCols; j++){
                for(int k = 0; k < numPlanes; k++){
                    if(cellArr[i][j][k]->getProcessed() == 0)
                        cellArr[i][j][k]->process();

                }
            }
        }
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < numCols; j++){
                for(int k = 0; k < numPlanes; k++){
                    cellArr[i][j][k]->setProcess(0);
                }
            }
        }
        displayCells();
        displayStats();
        //wxSleep(1);
        i++;
    }
    if(numLions == 0){
        wxMessageBox(wxT("Gazelles Win!"));
    }
    if(numGazelles == 0){
        wxMessageBox(wxT("Lions Win!"));
    }
    return;
}
