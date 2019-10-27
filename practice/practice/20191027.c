#define _CRT_SECURE_NO_WARNINGS 1
#include"stdio.h"
#include"math.h"
struct fenshu//定义结构体来表示两个分数的分子分母
{
	int fm;
	int fz;
};
int gcd(int m, int n)//函数保证分母大于分子
{
	int t, r;
	if (n > m)
	{
		t = n;
		n = m;
		m = t;
	}
	while ((r = m%n) != 0)
	{
		m = n;
		n = r;
	}
	return n;
}
 struct fenshu add(struct fenshu f1, struct fenshu f2)
{
	struct fenshu f;
	int x, y;
	x = f1.fm*f2.fm;
	y = f1.fz*f2.fm + f2.fz*f1.fm;
	f.fm = x / gcd(x, abs(y));
	f.fz = y / gcd (x, abs(y));
	return f;

 }
 struct fenshu mus(struct fenshu f1, struct fenshu f2)
 {
	 struct fenshu f;
	 int x, y;
	 x = f1.fm*f2.fm;
	 y = f1.fz*f2.fm - f2.fz*f1.fm;
	 f.fm = x / gcd(x, abs(y));
	 f.fz = y / gcd(x, abs(y));
	 return f;
 }
 void main()
 {
	 struct fenshu f1, f2, fadd, fmus;
	 printf("请输入f1的分子和分母：");
	 scanf("%d,%d", &f1.fz, &f1.fm);
	 printf("请输入f2的分子和分母：");
	 scanf("%d,%d", &f2.fz, &f2.fm);
	 fadd = add(f1, f2);
	 fmus = mus(f1, f2);
	 printf("和为%d/%d\n", fadd.fz, fadd.fm);
	 printf("差为%d/%d\n", fmus.fz, fmus.fm);
 }