//cpp
int factorial(int num)
{
    int loopStart = num;
    for(int i = (loopStart - 1); i > 0; i--)
    {
        num *= i;
    }
    return num;
}