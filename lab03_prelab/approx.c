
#include <stdio.h>
void repeatChar(char c, int num);

int main()
{

	/*sub rsp, 0x10*/
	char c;
	int num;
	int i; 

	/*
	   lea    rax,[rip+0xea0]
	   mov    rdi,rax
	   mov    eax,0x0
	   call   0x1040 <printf@plt>
	   */
	printf("Enter a character you would like to have repeated: ");

	/*
	   lea    rax,[rbp-0x5]
	   mov    rsi,rax
	   lea    rax,[rip+0xeb9]        # 0x203c
	   mov    rdi,rax
	   mov    eax,0x0
	   call   0x1050 <__isoc99_scanf@plt>*/
	scanf("%c", &c);


	/*
	   movzx  eax,BYTE PTR [rbp-0x5]
	   cmp    al,0x20
	   jle    0x11e0 <main+135>
	   movzx  eax,BYTE PTR [rbp-0x5]
	   cmp    al,0x7f
	   je     0x11e0 <main+135>*/
	if (c  <= 0x20 || c >= 0x7f){
		printf("Not a number");
	}
	else{	
		/*0x00000000000011a0 <+71>:    lea    rax,[rip+0xe99]        # 0x2040
		  0x00000000000011a7 <+78>:    mov    rdi,rax
		  0x00000000000011aa <+81>:    call   0x1030 <puts@plt>
		  0x00000000000011af <+86>:    lea    rax,[rbp-0xc]
		  0x00000000000011b3 <+90>:    mov    rsi,rax
		  0x00000000000011b6 <+93>:    lea    rax,[rip+0xea9]        # 0x2066
		  0x00000000000011bd <+100>:   mov    rdi,rax
		  0x00000000000011c0 <+103>:   mov    eax,0x0
		  0x00000000000011c5 <+108>:   call   0x1050 <__isoc99_scanf@plt>
		  0x00000000000011ca <+113>:   mov    edx,DWORD PTR [rbp-0xc]
		  0x00000000000011cd <+116>:   movzx  eax,BYTE PTR [rbp-0x5]
		  0x00000000000011d1 <+120>:   movsx  eax,al
		  0x00000000000011d4 <+123>:   mov    esi,edx
		  0x00000000000011d6 <+125>:   mov    edi,eax
		  0x00000000000011d8 <+127>:   call   0x11f6 <repeat_char>*/
		puts("Enter the number of times to repeat: ");
		scanf("%d", &num);
		i = repeatChar(c, num);
	}

	puts("All done\n");
	return 0;

}

/*0x00000000000011f6 <+0>:     push   rbp
  0x00000000000011f7 <+1>:     mov    rbp,rsp*/

int repeatChar(char c, int num){

	/*
	   0x00000000000011fe <+8>:     mov    eax,edi
	   0x0000000000001200 <+10>:    mov    DWORD PTR [rbp-0x18],esi
	   0x0000000000001203 <+13>:    mov    BYTE PTR [rbp-0x14],al
	   0x0000000000001206 <+16>:    mov    DWORD PTR [rbp-0x4],0x0
	   0x000000000000120d <+23>:    jmp    0x122d <repeat_char+55>
	   0x000000000000120f <+25>:    movsx  eax,BYTE PTR [rbp-0x14]
	   0x0000000000001213 <+29>:    mov    esi,eax
	   0x0000000000001215 <+31>:    lea    rax,[rip+0xe57]        # 0x2073
	   0x000000000000121c <+38>:    mov    rdi,rax
	   0x000000000000121f <+41>:    mov    eax,0x0
	   0x0000000000001224 <+46>:    call   0x1040 <printf@plt>
	   0x0000000000001229 <+51>:    add    DWORD PTR [rbp-0x4],0x1
	   0x000000000000122d <+55>:    mov    eax,DWORD PTR [rbp-0x4]
	   0x0000000000001230 <+58>:    cmp    eax,DWORD PTR [rbp-0x18]
	   0x0000000000001233 <+61>:    jl     0x120f <repeat_char+25>
	   0x0000000000001235 <+63>:    mov    eax,DWORD PTR [rbp-0x4]

*/
	for (int i = 0; i < num; i++)
	{
		printf("%c ", c);
	}
	
	return i;
}
