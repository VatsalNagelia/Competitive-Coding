int tree[N + 1]; // one indexed tree
int pre[N + 1];  // prefix-sum of the input array
int sum(int k)
{
    int s = 0;
    while (k >= 1)
    {
        s += tree[k];
        k -= (k & -k);
    }
    return s;
}
void add(int k, int x, int n)
{
    while (k <= n)
    {
        tree[k] += x;
        k += k & -k;
    }
}
void formTree(int n)
{
    for (int k = 1; k <= n; k++)
    {
        tree[k] = pre[k] - pre[k - (k & -k)];
    }
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> tree[i];
        pre[i] = pre[i - 1] + tree[i];
    }
    formTree(n);
}