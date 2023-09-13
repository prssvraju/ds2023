int isp(char c)
{
    switch (c)
    {
        case '(':return 0;
        case '+': 
        case '-':return 1;
        case '*': 
        case '/':return 2;  
        case '$': 
        case '^':return 3;
    }
}
int icp(char c)
{
    switch (c)
    {
        case '+': 
        case '-':return 1;
        case '*': 
        case '/':return 2;  
        case '$': 
        case '^':return 3;
    }
}