// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
#define INACTIVE            (0)
#define ACTIVE              (1)
#define NUMBER_OF_HOUSES    (8)

/*
typedef struct BoundedArray
{
    int size;
    int *arr;
}boundedarray;
*/


boundedarray* cellCompete(int* states, int days) 
{
    int d, h;
    int currentHouseState = INACTIVE;
    int leftNeighborState = INACTIVE;
    int rightNeighborState = INACTIVE;
    static int arr[NUMBER_OF_HOUSES];//make it static to avoid loosing the pointed memory after function exits    
    boundedarray* ptrcellStates = malloc(sizeof(boundedarray));
    ptrcellStates->size = NUMBER_OF_HOUSES;
    ptrcellStates->arr = arr;
    
    for(d = 0; d < days; d++)
    {
        for(h = 0; h < NUMBER_OF_HOUSES; h++)
        {
            currentHouseState = states[h];
            
            //if first house
            if( h == 0 )
            {
                //Assume that the unocuppied space on the opposite site is an INACTIVE cell.
                leftNeighborState = INACTIVE;
                rightNeighborState = states[h+1];
            }
            //if last house
            else if( h == (NUMBER_OF_HOUSES - 1) )
            {
                //Assume that the unocuppied space on the opposite site is an INACTIVE cell.
                leftNeighborState = states[h-1];
                rightNeighborState = INACTIVE;
            }
            //rest of houses
            else
            {
                leftNeighborState = states[h-1];
                rightNeighborState = states[h+1];
            }

            // if the neighbors on both the sides of a cell are either ACTIVE or INACTIVE, 
            // the cell becomes INACTIVE on the next day; otherwise the cell becomes ACTIVE.
            if( ((leftNeighborState == INACTIVE) && (rightNeighborState == INACTIVE)) ||
                ((leftNeighborState == ACTIVE) && (rightNeighborState == ACTIVE)) )
            {
                currentHouseState = INACTIVE;
            }
            else
            {
                currentHouseState = ACTIVE;
            }
            
            //save current house state
            ptrcellStates->arr[h] = currentHouseState;
        }
        
        //Update states for houses on the next day
        for(h = 0; h < NUMBER_OF_HOUSES; h++)
        {
            states[h] = ptrcellStates->arr[h];
        }
    }
    
    return ptrcellStates;
}
// FUNCTION SIGNATURE ENDS
