#include<cstdio>
#include<algorithm>
using namespace std;
int n;
struct P
{
    int w, l;
    bool operator < (const P rhs) const
    {
        return w+l<rhs.w+rhs.l;
    }
}a[50005];
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d%d", &a[i].w, &a[i].l);
    sort(a + 1, a + n + 1);
    int sum = 0, ans = -0x3f3f3f3f;
    for(int i = 1; i <= n; i ++)
    {
        ans = max(ans, sum - a[i].l);
        sum += a[i].w;
    }
    printf("%d\n", ans);
    return 0;
}
