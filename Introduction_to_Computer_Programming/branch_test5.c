#include <stdio.h>

int main(void)
{
  int i,error;
	char password[10];
	char enteredPassword[10];

  printf("Enter a new password:\n");
	scanf("%s", password);
	printf("Enter your password:\n");
	while(scanf("%s", enteredPassword))
	{
	  i=0, error=0;
		while(1)
		{
		  if(password[i]!=enteredPassword[i])
			{
			  error=1;
				break;
			}
			else if(password[i]=='\0' && password[i]=='\0'){ break; }
			i++;
		}
		if(error){ printf("Password Error!!\n"); }
		else{ printf("Password Certified!!\n"); }
	}

  return 0;
}
