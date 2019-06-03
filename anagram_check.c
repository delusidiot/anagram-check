#include <stdio.h>
#include <string.h>
int check_anagram(char[], char[]);
int main()
{
	char a[100], b[100];
	int flag;

	printf("Enter first string\n");
	gets_s(a);

	printf("Enter second string\n");
	gets_s(b);

	flag = check_anagram(a, b);

	printf(" %d \n",flag);
	if (flag > 0)
		printf("\"%s\" and \"%s\" are anagrams.\n", a, b);
	else
		printf("\"%s\" and \"%s\" are not anagrams.\n", a, b);

	return 0;
}

int check_anagram(char a[], char b[])
{
	int first[26] = { 0 }, second[26] = { 0 }, a_c = 0, c=0,result = 0;
	int a_count = strlen(a);
	int b_count = strlen(b);
	int count = 0;
	bool comp = true;

	while (b[c] != '\0')
	{
		second[b[c] - 'a']++;
		c++;
	}
	c = 0;

	do
	{
		for (int i = 0; i < b_count; i++)
		{
			first[a[c+i] - 'a']++;
		}

		for (int i = 0; i < 26; i++)
		{
			if (first[i] != second[i])
			{
				comp = false;
			}
		}
		if (comp) result++;
		comp = true;
		c++;
		for (int i = 0; i < 26; i++)
		{
			first[i] = 0;
		}
		a_count--;
	} while (a_count - b_count >= 0);
	return result;
}
