#include <iostream>  
#include <cstdio>  
using namespace std;

const int N = 100005;

struct Elem
{
	long long height;
	long long width;
	int begin;
	int count;
};

Elem stack[N];
int top;

int main()
{
	int num, n;
	long long ans, tmp, tot;
	int ansbeg, ansend, count;
	scanf("%d", &n);
	top = 0;
	ans = 0;
	ansbeg = ansend = 1;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &num);
		tmp = 0;
		count = 0;
		while (top > 0 && stack[top - 1].width >= num)
		{
			stack[top - 1].count += count;
			tot = (stack[top - 1].height + tmp) * stack[top - 1].width;
			if (tot > ans)
			{
				ans = tot;
				ansbeg = stack[top - 1].begin;
				ansend = ansbeg + stack[top - 1].count - 1;
			}
			tmp += stack[top - 1].height;
			count = stack[top - 1].count;
			--top;
		}
		stack[top].height = num + tmp;
		stack[top].width = num;
		stack[top].begin = i + 1 - count;
		stack[top].count = 1 + count;
		++top;
	}
	tmp = 0;
	count = 0;
	while (top > 0)
	{
		stack[top - 1].count += count;
		tot = (stack[top - 1].height + tmp) * stack[top - 1].width;
		if (tot > ans)
		{
			ans = tot;
			ansbeg = stack[top - 1].begin;
			ansend = ansbeg + stack[top - 1].count - 1;
		}
		tmp += stack[top - 1].height;
		count = stack[top - 1].count;
		--top;
	}
	printf("%lld\n%d %d\n", ans, ansbeg, ansend);
	return 0;
}