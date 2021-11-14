class CombinationIterator {
    
    vector<string> combination;
    int curIterator;
    int totalOfCombinations;
    string charactersString;
    int n;
    int lenCombination;
    
public:
    
    void generateCombination(int i, string curCombination)
    {
        if(curCombination.size()==lenCombination)
        {
            //cout<<curCombination<<endl;
            combination.push_back(curCombination);
        }
        else
        {
            for(int j = i; j<n; ++j)
            {
                curCombination += charactersString[j];
                generateCombination(j+1, curCombination);
                curCombination = curCombination.substr(0, curCombination.size()-1);
            }
        }
    }
    
    
    CombinationIterator(string characters, int combinationLength) 
    {
        charactersString = characters;
        n = characters.size();
        lenCombination = combinationLength;
        
        generateCombination(0, "");
        curIterator = -1;
        totalOfCombinations = combination.size();
        if(totalOfCombinations==0)
            curIterator = 0;
    }
    
    string next() 
    {
        ++curIterator;
        return combination[curIterator];
    }
    
    bool hasNext() 
    {
        return curIterator<totalOfCombinations-1;   
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */