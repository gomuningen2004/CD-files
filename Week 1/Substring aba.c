# include <stdio.h>
# include <conio.h>
int main()
{
	char a[5];
	int i, flag, length;
	printf("Enter only a's and b's : ");
	scanf("%s", a);
	
	for (length = 0; a[length] != '\0'; length++);
	
	for(i = 0; i < 5; i++)
	{
		if(a[i] == 'a' && a[i+1] == 'b' && a[i+2] == 'a')
		{
			flag = 1;
			break;
		}
	}
	
	if(flag == 1)
	{
		printf("String contains aba as substring");
	}
	else
	{
		printf("String doesnt contains aba as substring");
	}
	
	return 0;
}


