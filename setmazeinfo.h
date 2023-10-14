void SetMazeInfo(std::vector<int> inputInfo, int& HEIGHT, int& WIDTH, int& SEED) 
{
    HEIGHT = inputInfo.at(0);
    WIDTH = inputInfo.at(1);
    SEED = inputInfo.at(2);
}