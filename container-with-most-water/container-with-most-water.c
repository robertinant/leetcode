
// #define BRUTE_FORCE 1

/* 
 * Initial brute force solution.
 * Submission exceeds execution time limit.
 */ 
#ifdef BRUTE_FORCE
int maxArea(int* height, int heightSize)
{
    int i, j = 0;
    int distance = 0;

    unsigned int vol = 0;
    unsigned int max_vol = 0;
    unsigned int mul;

    for(j = 0; j < heightSize; j++) {
        for(i = j; i < heightSize - 1; i++) {
            mul = height[j] > height[i+1] ? height[i+1] : height[j];
            vol = mul * ((i - j) + 1);
            max_vol = vol > max_vol ? vol:max_vol;
        }
    }

    return max_vol;
}
#else

/*
 * Optimized 2 vector solution.
 */
int maxArea(int* height, int heightSize)
{
    /*
     * max vol = 10^4 * 10^5 = 10^9 which 
     * does not fit an integer
     */
    long vol = 0;
    long max_vol = 0;
    int dist = heightSize - 1;
    int *p1;
    int *p2;

    /* Start vectors */
    p1 = height;
    p2 = &height[heightSize - 1];

    while(p1 != p2) {        

        vol = dist * (*p1 < *p2 ? *p1 : *p2);
        max_vol = vol > max_vol ? vol : max_vol;

        *p1 < *p2 ? p1++ : p2--;
        dist--;
    }

    return max_vol;
}
#endif
