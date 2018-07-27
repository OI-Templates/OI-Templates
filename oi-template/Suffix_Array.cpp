//luogu P3809
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 1e6 + 5;
char str[maxn], a[maxn];
int x[maxn], y[maxn], c[maxn], sa[maxn];
void SA(int n, int m)
{
    for (int i = 0; i <= m; i++)
        c[i] = 0;
    for (int i = 1; i <= n; i++)
        c[x[i] = a[i]]++;
    for (int i = 1; i <= m; i++)
        c[i] += c[i - 1];
    for (int i = n; i; i--)
        sa[c[x[i]]--] = i;
    for (int k = 1; k <= n; k <<= 1)
    {
        int p = 0;
        for (int i = 0; i <= m; i++)
            y[i] = 0;
        for (int i = n - k + 1; i <= n; i++)
            y[++p] = i;
        for (int i = 1; i <= n; i++)
            if (sa[i] > k)
                y[++p] = sa[i] - k;
        for (int i = 0; i <= m; i++)
            c[i] = 0;
        for (int i = 1; i <= n; i++)
            c[x[y[i]]]++;
        for (int i = 1; i <= m; i++)
            c[i] += c[i - 1];
        for (int i = n; i; i--)
            sa[c[x[y[i]]]--] = y[i];
        swap(x, y);
        x[sa[1]] = p = 1;
        for (int i = 2; i <= n; i++)
            x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) ? p : ++p;
        if (p >= n)
            break;
        m = p;
    }
}
int main()
{
    scanf("%s", str);
    int n = strlen(str);
    for (int i = 0; i < n; i++)
        a[i + 1] = str[i];
    SA(n, 'z');
    for (int i = 1; i <= n; i++)
        printf("%d ", sa[i]);
    return 0;
}