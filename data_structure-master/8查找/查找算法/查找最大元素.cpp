#include<stdio.h>
#include<string.h> 
int main(void)
{
	char s[300];
	
	gets(s);
	int n;
	int i;
	n = strlen(s);
	
	char max = '@';
	for( i = 0; s[i] != '\0'; i++)
	{
	   if(s[i] > max)
	   {
	   	 max = s[i];
	   }
		
	}
	
	for(i = 0; s[i] != '\0'; i++)
	{
		if(s[i] == max)
		{
		
			n=n+5;
			
			for(int j = n-1;j > i+5; j--)
			{
			    
				s[j] =  s[j-5];
				s[j-1] = s[j-6];
				s[j-2] = s[j-7];
				s[j-3] = s[j-8];
				s[j-4] = s[j-9];
			}
			
				s[i+1] = '(';
				s[i+2] = 'm';
				s[i+3] = 'a';
				s[i+4] = 'x';
				s[i+5] = ')';
		  
		}
	}
	s[n] = '\0';
	
	puts(s);
}
