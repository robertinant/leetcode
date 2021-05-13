/*
 * Algorithm:
 * Use three pointers tailp, swapp and headp to keep track.
 * End condition is that swapp is headp and that *tailp is smaller or equal to swapp.
 * While not end condition:
 *   switch tailp:
 *    0) keep in place, advance tailp and (re)set swapp to tailp + 1.
 *    1) swap *tailp and *swapp, advance swapp in search of either a 0 or 2.
 *    2) swap *tailp and headp, recede headp and (re)set swapp to tailp + 1.
 * Note: In all cases prevent:
 *    - tailp going right of headp.
 *    - headp going left of swapp.
 */


void sortColors(int* nums, int numsSize){
    if(numsSize == 1) return nums;
    
    int lpcnt = 0;
    int num = 0;
    int *headp = &nums[numsSize - 1];
    int *tailp = nums;
    int *swapp = nums + 1;

#ifdef DEBUG
    printf("--------- Start vectors ---------\n");
    printf("tailp: %p -> %d\n", tailp, *tailp);
    printf("swapp: %p -> %d\n", swapp, *swapp);
    printf("headp: %p -> %d\n", headp, *headp);
#endif
    
    /*
     * If swapp is headp and *tailp is smaller or equal to *swapp
     * then we have reached the end condiion.
     */
    while( !( (swapp == headp) && (*tailp <= *swapp) ) ) {
        lpcnt++;
        switch(*tailp) {
            /* don't move 0, increment tailp */
            case 0:
                tailp++;
                /* Prevent swapp going right headp */
                swapp = swapp < headp ? tailp + 1 : tailp;
                break;
            /* Swap *tailp with *swapp, increment swapp in search of either 0 or 2 */
            case 1:
                num = *swapp;
                *swapp = *tailp;
                *tailp = num;
                /* Prevent swapp going right of headp */
                swapp < headp ? swapp++ : swapp;
                break;
            /* Swap head and tail, decrement tailp */
            case 2:
                num = *headp;
                *headp = *tailp;
                *tailp = num;
                /* Protect headp going left of swapp */
                headp--;
                swapp = tailp < headp ? tailp + 1 : tailp;
            break;
        }
#ifdef DEBUG
        printf("---------   loop # %d  -------\n", lpcnt);
        printf("tailp: %p -> %d\n", tailp, *tailp);
        printf("swapp: %p -> %d\n", swapp, *swapp);
        printf("headp: %p -> %d\n", headp, *headp);
#endif
    };

#ifdef DEBUG
    printf("\ntotal # of loops: %d\n", lpcnt);
#endif
    
    return nums;
}