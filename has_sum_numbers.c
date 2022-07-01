#include "has_sum_numbers.h"

#define LIST_SIZE 4

static int8_t *finishBound_ = NULL;

static void
printResult_(int8_t rc)
{
    switch (rc)
    {
    case TRUE:
        printf("Has sum numbers? YES\n");
        break;

    case FALSE:
        printf("Has sum numbers? NO\n");
        break;

    default:
        break;
    }
}

int main()
{
    int8_t listOfNumbers[LIST_SIZE] = {10, 15, 3, 7};
    int8_t sumResult = 17;

    vsBool rc = hasSumNumbers(listOfNumbers, LIST_SIZE, &sumResult);

    printResult_(rc);

    return 0;
}

static vsBool
findedSolution_(const int8_t *firstDigit,
                const int8_t *secondDigit,
                const int8_t *sumResult)
{
    printf("%d + %d\t= %d\n", *firstDigit, *secondDigit, *sumResult);

    if ((*firstDigit + *secondDigit) == *sumResult)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static vsBool
isValidSum_(const int8_t *firstDigit,
            const int8_t *secondDigit,
            const int8_t *sumResult)
{
    if (firstDigit == finishBound_ && secondDigit >= finishBound_)
    {
        return FALSE;
    }
    /* LIST HAS NO VALID SUM */
    else if (findedSolution_(firstDigit, secondDigit, sumResult))
    {
        return TRUE;
    }

    if (secondDigit == finishBound_)
    {
        return isValidSum_((firstDigit + 1), (firstDigit + 2), sumResult);
    }

    return isValidSum_(firstDigit, (secondDigit + 1), sumResult);
}

vsBool
hasSumNumbers(const int8_t *listOfNumbers, const int32_t listSize, const int8_t *sumResult)
{
    vsBool rc = FALSE;

    if (NULL != listOfNumbers)
    {
        finishBound_ = (int8_t *)listOfNumbers + (int32_t)listSize - 1;
        // printf("finishBound_ %d\n", *finishBound_);

        // If list is not empty
        if (finishBound_ != &listOfNumbers[0])
        {
            rc = isValidSum_(&listOfNumbers[0], &listOfNumbers[1], sumResult);
        }

        finishBound_ = NULL;
    }

    return rc;
}

/*
class ListOfNumbers{
    private int finishBound;
    private List<int> numbers;

    public ListOfNumbers(...){
        ...;
    }

    public List getNumbers(...){
        ...;
    }

    public int getFinishBound(...){
        ...;
    }

    public vsBool hasOnlyOneDigit(...){
        ...;
    }
}

class FindSum {
    private Stack<ListOfNumbers> listStack;

    public void addList(...){
        ...;
    }

    public vsBool hasSumNumbers(){
        vsBool rc = False;

        if (!listStack.top().hasOnlyOneDigit())
        {
            rc = isValidSum_(&listOfNumbers[0], &listOfNumbers[1], sumResult);
            printResult(rc);
            popList();
        }

        return rc;
    }

    private void popList(...){
        ...;
    }

    private void printResult(...){
        ...;
    }

    private vsBool isValidSum_(...){
        ...;
    }
    private vsBool findedSolution_(...){
        ...;
    }
}
*/
