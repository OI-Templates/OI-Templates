#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
template<typename T>
class ufset
{
private:
	vector<T>fa;
public:
	void make_set(T const& maxn)
	{
		fa.push_back((T)0);
		for (T i = 1; i <= maxn; i++)
			fa.push_back((T)i);
	}
	T find_root(T const& a)
	{
		return a == fa[a] ? a : fa[a] = find_root(fa[a]);
	}
	void union_set(T const& a, T const& b)
	{
		if (find_root(a) != find_root(b))
			fa[find_root(a)] = find_root(b);
	}
};
