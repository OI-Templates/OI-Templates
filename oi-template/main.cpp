#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn = 1e5 + 5;
int fa[maxn];
template<class T>
inline T find_root(T a)
{
	return a == fa[a] ? a : fa[a] = find_root(fa[a]);
}