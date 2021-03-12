#include <stdio.h>
#include "fox.h"


void test_alltrim();
void test_left();
void test_right();
int main()
{
	test_right();
	return 0;
}
void test_right()
{
	printf("%s\n", right("Irwin", 3));
	printf("%s\n", right("Serelys", 5));
}
void test_left()
{
	printf("%s\n", left("Irwin", 2));
	printf("%s\n", left("PEPE", 3));
}
void test_alltrim()
{
	char* str = alltrim("    Amor");
	char* str1 = alltrim("Amor   ");
	char* str2 = alltrim("   Amor   ");
	printf("len('%s') = %d\n", str, len(str));
	printf("len('%s') = %d\n", str1, len(str1));
	printf("len('%s') = %d\n", str2, len(str2));
	free(str);
	free(str1);
	free(str2);
}