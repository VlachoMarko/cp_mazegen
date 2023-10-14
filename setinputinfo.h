void SetInputInfo(std::vector<int>& inputInfo, const char* inputHeight, const char* inputWidth, const char* inputSeed = 0) 
{
    
    inputInfo.at(0) = std::atoi(inputHeight);
    inputInfo.at(1) = std::atoi(inputWidth);

    if ( inputSeed == 0 )
    {
        srand(time(0));
        inputInfo.at(2) = rand();
    }
    else 
    {
        inputInfo.at(2) = std::atoi(inputSeed);
    }
       
    return;
}