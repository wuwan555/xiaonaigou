#define _CRT_SECURE_NO_WARNINGS 1
#include"stdio.h"
#include"math.h"
struct fenshu//����ṹ������ʾ���������ķ��ӷ�ĸ
{
	int fm;
	int fz;
};
int gcd(int m, int n)//������֤��ĸ���ڷ���
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
	 printf("������f1�ķ��Ӻͷ�ĸ��");
	 scanf("%d,%d", &f1.fz, &f1.fm);
	 printf("������f2�ķ��Ӻͷ�ĸ��");
	 scanf("%d,%d", &f2.fz, &f2.fm);
	 fadd = add(f1, f2);
	 fmus = mus(f1, f2);
	 printf("��Ϊ%d/%d\n", fadd.fz, fadd.fm);
	 printf("��Ϊ%d/%d\n", fmus.fz, fmus.fm);
 }