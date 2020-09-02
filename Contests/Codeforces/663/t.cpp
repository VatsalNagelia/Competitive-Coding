int factorial(n, m)
{
    int res=1;
    for (int i=2;i<=n;i++)
    {
        res*=(i%m);
        res%=m;
    }
    return res;
}