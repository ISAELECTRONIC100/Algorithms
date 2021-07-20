//Date: 20/July/2021

// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

#define MASK        (1u)
#define FALSE       (1u==0u)
#define TRUE        (1u==1u)

/* Function prototype */ 
int getLength(int N);

int solution(int N) {
    int longest_binary_gap = 0;
    int binary_gap_counter_current = 0;
    char start_flag = FALSE;
    int max_length;
    int index;

    /* Get max bit length of N */
    max_length = getLength(N);

    for(index = 0u; index < max_length; index++)
    {
        if(0u == (N & MASK))
        {
            /* Check if it´s a valid gap */
            if(start_flag)
            {
                binary_gap_counter_current++;
            }
        }
        else
        {
            /* set indication flag to start counting a valid binary gap */
            start_flag = TRUE;
            /* reset binary gap counter */
            binary_gap_counter_current = 0;
        }
        /* shift N to the right by one until we reach the MSB bit. */
        N = N >> 1u;

        /* Check for longest binary gap */
        if(binary_gap_counter_current > longest_binary_gap)
        {
            longest_binary_gap = binary_gap_counter_current;
        }       
    }

    return longest_binary_gap;    
}

int getLength(int N)
{
   int count = 0;
   while (N)
   {
        count++;
        N >>= 1;
    }
    return count;
}
