#include"../include/calculator.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	/*if((1 || 0 )&& 1)
		printf("TRUE\n");
	else
		printf("FALSE\n");*/
	char * expression;
	expression = malloc(sizeof(char));
	scanf("%s",expression);
	int flag=0;
	float res=0;
	while(strcmp(expression,"q") && strcmp(expression,"e") && strcmp(expression,"quit") && strcmp(expression,"exit"))
	{
		int i=0;
		float a=0,b=0,dec=1;
		int term1=0,op=0,term2=0,t1_sign_flag=0,t2_sign_flag=0,sign_flag=0;
		int error=1,dec_flag=1;
		while(expression[i] != '\0')
		{
			if(expression[i]=='.' || expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '%')
			{
				if(expression[i]=='.')
					if(dec_flag)
						dec_flag=0;
					else
					{
						error = 0;
						break;
					}
				else if((!dec_flag && expression[i-1]=='.'))
				{
					error=0;
					break;
				}
				else if(op && t1_sign_flag)
				{
					op = expression[i];
					//t1_sign_flag=0;
					term1=term2;
				}
				else if(expression[i]=='-')
				{
					if(term1)
					{
						if(op)
							t2_sign_flag=1;
						else
							op=expression[i];
					}
					else
					{
						op = expression[i];
						t1_sign_flag = 1;
					}
				}
				else if((op || expression[i]=='%') && (!( op =='*' && expression[i]=='%')) )
				{
					printf("negative");
					error=0;
					break;
				}
				else
				{
					op = expression[i];
					dec=1;
					dec_flag=1;
				}
			}
			else
			{
				if(expression[i]<48 || expression[i]>57)
				{
					error=0;
					break;
				}
				if(dec_flag)
				{
					if(!op)
					{
						term1 = 1;
						a=a*10;
						a=a+expression[i]-48;
					}
					else
					{
						term2=1;
						b=b*10;
						b=b+expression[i]-48;
					}
				}
				else
				{
					dec=dec*10;
					if(!op)
					{
						term1 = 1;
						a=a+(expression[i]-48)/dec;
					}
					else
					{
						term2=1;
						b=b+(expression[i]-48)/dec;
					}
				}
				
			}
			i+=1;
		}
		if(error && (term1 || flag) && op && term2)
		{
			flag=1;
			if(!term1)
			{
				a = res;
				if(t1_sign_flag)
					b=-b;
			}
			else
			{
				if(t1_sign_flag)
					a = -a;
				if(t2_sign_flag)
					b = -b;
			}
			switch(op)
			{
				case '+' : res = add(a,b);
					printf("%g\n",res);
					break;
				case '-' : res = subtract(a,b);
					printf("%g\n",res);
					break;
				case '*' : res = multiply(a,b);
					printf("%g\n",res);
					break;
				case '/' : res = divide(a,b);
					printf("%g\n",res);
					break;
				case '%' : res = percentage(a,b);
					printf("%g\n",res);
					break;
				/*case '^' : res = power(a,b);
					printf("%g\n",res);
					break;*/
			}
		}
		else
			printf("Incorrect Input\n");
		free(expression);
		expression =  (char *)malloc(sizeof(char));
		scanf("%s",expression);		
	}
}
